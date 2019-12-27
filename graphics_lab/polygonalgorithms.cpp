#include "polygonalgorithms.h"

#include "linealgorithms.h"

#include <iostream>
#include <chrono>

PolygonAlgorithms::PolygonAlgorithms()
{
    // empty constructor, do not instantiate this class
}

void PolygonAlgorithms::drawPolygon(GridModel *grid, std::vector<std::pair<int, int>> vertices)
{
    vertices.push_back(vertices[0]);

    for (unsigned int i = 0; i < vertices.size()-1; ++i)
    {
        int x1, y1, x2, y2;
        std::tie(x1, y1) = vertices[i];
        std::tie(x2, y2) = vertices[i+1];

        LineAlgorithms::drawBresenhamLine(grid, x1, y1, x2, y2);
    }
}

void PolygonAlgorithms::floodFill(GridModel *grid, int x, int y, QColor oldColor, QColor newColor)
{
    if (isSafe(grid, x, y) && grid->getColor(x, y) == oldColor)
    {
        grid->setPixel(x, y);
        floodFill(grid, x-1, y, oldColor, newColor);
        floodFill(grid, x+1, y, oldColor, newColor);
        floodFill(grid, x, y-1, oldColor, newColor);
        floodFill(grid, x, y+1, oldColor, newColor);
    }
}

void PolygonAlgorithms::boundaryFill(GridModel *grid, int x, int y, QColor edgeColor, QColor newColor)
{
    if (isSafe(grid, x, y) && grid->getColor(x, y) != edgeColor)
    {
        grid->setPixel(x, y);
        boundaryFill(grid, x-1, y, edgeColor, newColor);
        boundaryFill(grid, x+1, y, edgeColor, newColor);
        boundaryFill(grid, x, y-1, edgeColor, newColor);
        boundaryFill(grid, x, y+1, edgeColor, newColor);
    }
}

bool PolygonAlgorithms::isSafe(GridModel *grid, int x, int y)
{
    int r = grid->getRows(), c = grid->getCols();
    if (x < -c/2 || x > c/2 || y < -r/2 || y > r/2)
        return false;

    return true;
}


void PolygonAlgorithms::scanLinePolygonFill(GridModel *grid, std::vector<std::pair<int, int>> vertices) {
    // push the first vertex so that consecutive pairs produce
    // the edges of the polygon
    vertices.push_back(vertices[0]);

    // create the edge buckets considering consecutive pairs of vertices
    std::vector<struct EdgeBucket> edgeBuckets;
    for (unsigned int i = 0; i < vertices.size() - 1; ++i) {
        std::pair<int, int> one = vertices[i], two = vertices[i+1];

        // construct the bucket
        struct EdgeBucket e;
        e.yMax = std::max(one.second, two.second);
        e.yMin = std::min(one.second, two.second);
        e.x = (e.yMin == one.second) ? one.first : two.first;
        e.sign = (one.first-two.first)*(one.second-two.second) < 0 ? -1 : 1;
        e.dx = std::abs(one.first - two.first);
        e.dy = std::abs(one.second - two.second);
        e.sum = 0;

        edgeBuckets.push_back(e);
    }

    // sort the edge buckets based on increasing order of lesser y coordinate
    std::sort(edgeBuckets.begin(), edgeBuckets.end(),
              [](struct EdgeBucket a, struct EdgeBucket b) { return a.yMin < b.yMin; });

    // the active list of buckets currently being considered
    std::vector<struct EdgeBucket> active;

    // initialize scan line's y coordinate to minimum y among all buckets
    int scanY = edgeBuckets[0].yMin;

    // initialize scan line's max limit to maximum y among all buckets
    int max = std::max_element(edgeBuckets.begin(), edgeBuckets.end(),
                               [](struct EdgeBucket a, struct EdgeBucket b) { return a.yMax < b.yMax; }
                              )->yMax;

    // the loop for the scan line algorithm
    while (!edgeBuckets.empty() && scanY <= max) {

        // remove a bucket from both the edge bucket list and the active list
        // if its upper y coordinate equals the scan line's y coordinate
        if (!active.empty()) {
            for (unsigned int i = 0; i < active.size(); ) {
                if (active[i].yMax <= scanY) {
                    for (unsigned int j = 0; j < edgeBuckets.size(); ++j) {
                        if (edgeBuckets[j] == active[i]) {
                            edgeBuckets.erase(edgeBuckets.begin() + j);
                            break;
                        }
                    }
                    active.erase(active.begin() + i);
                }
                else {
                    ++i;
                }
            }
        }

        // move bucket into active list if its minimum y coordinate
        // equals the scan line's y coordinate
        for (unsigned int i = 0; i < edgeBuckets.size(); ++i) {
            if (edgeBuckets[i].yMin == scanY)
                active.push_back(edgeBuckets[i]);
        }

        // sort the active list according to increasing x coordinate
        std::sort(active.begin(), active.end(),
                  [](struct EdgeBucket a, struct EdgeBucket b) { return a.x < b.x; });


        // for every alternate pair in active list, draw the line
        // with their x coordinates as end points and
        // y coordinate same as the scan line's y coordinate
        for (unsigned int i = 0; i < active.size()/2; ++i) {
            for (int j = active[2*i].x; j <= active[2*i+1].x; ++j) {
                grid->setPixel(j, scanY);
            }
        }

        // adjust the x coordinates of each bucket in active list
        // based on coherence principle, and using only integer operations
        for (struct EdgeBucket& e : active) {
            if (e.dy != 0) {
                e.sum += e.dx;
                while (e.sum >= e.dy) {
                    e.x += e.sign;
                    e.sum -= e.dy;
                }
            }
        }

        scanY++; // move the scan line up by one unit
    }
}


std::vector<std::tuple<int, int, int, int>> getEdgesFromRectangle(std::tuple<int, int, int, int> rect)
{
    int x1, y1, x2, y2;  // top-left and bottom-right
    std::tie(x1, y1, x2, y2) = rect;

    std::vector<std::tuple<int, int, int, int>> edgeList;

    edgeList.push_back(std::make_tuple(x1, y1, x2, y1));
    edgeList.push_back(std::make_tuple(x2, y1, x2, y2));
    edgeList.push_back(std::make_tuple(x2, y2, x1, y2));
    edgeList.push_back(std::make_tuple(x1, y2, x1, y1));

    return edgeList;
}

std::pair<int, int> ComputeIntersection(std::pair<int, int> prev_point,
                                        std::pair<int, int> current_point,
                                        std::tuple<int, int, int, int> clipEdge)
{
    int x1, y1, x2, y2, cx1, cy1, cx2, cy2;
    double xint, yint;
    std::tie(x1, y1) = prev_point; std::tie(x2, y2) = current_point;
    std::tie(cx1, cy1, cx2, cy2) = clipEdge;

    double m1 = (y2 - y1) / double(x2 - x1), c1 = (y1 - m1 * x1);

    if (cx1 - cx2 == 0) {
        xint = cx1;
        yint = m1 * xint + c1;
    }
    else if (cy1 - cy2 == 0) {
        yint = cy1;
        xint = (yint - c1) / m1;
    }
    else
        throw "not implemented for non axis parallel line";

    return std::make_pair(int(std::round(xint)), int(std::round(yint)));
}

bool inside_test(std::pair<int, int> curr, std::tuple<int, int, int, int> edge)
{
    int x1, y1, x2, y2, x3, y3;
    std::tie(x1, y1, x2, y2) = edge; std::tie(x3, y3) = curr;

    int vx1 = x2 - x1, vy1 = y2 - y1, vx2 = x3 - x1, vy2 = y3 - y1;

    std::cout << ((vx1*vy2 - vx2*vy1)) << "\n";

    return (vx1*vy2 - vx2*vy1) < 0;

    // return true;
}

void PolygonAlgorithms::clipPolygon(GridModel *grid, std::vector<std::pair<int, int> > vertices,
                                    std::tuple<int, int, int, int> rect)
{
    std::vector<std::pair<int, int>> outputList = vertices;
    std::vector<std::tuple<int, int, int, int>> edgeList = getEdgesFromRectangle(rect);

      for (std::tuple<int, int, int, int> clipEdge : edgeList)
      {
         std::cout << "E\n";

         std::vector<std::pair<int, int>> inputList = outputList;
         outputList.clear();

         for(unsigned int i = 0 ; i < inputList.size() ; ++i) {
            std::pair<int, int> current_point = inputList[i];
            std::pair<int, int> prev_point = inputList[(i + inputList.size() - 1) % inputList.size()];
            std::cout << current_point.first << ", " << current_point.second << " ; " << prev_point.first << ", " << prev_point.second << "\n";

            std::pair<int, int> Intersecting_point = ComputeIntersection(prev_point, current_point, clipEdge);

            if (inside_test(current_point, clipEdge)) {
               if (!inside_test(prev_point, clipEdge))
                  outputList.push_back(Intersecting_point);
               outputList.push_back(current_point);
            }
            else if (inside_test(prev_point, clipEdge))
               outputList.push_back(Intersecting_point);

         }
      }

      std::cout << "size oL -> " << outputList.size() << "\n";

      grid->clear();

      // draw rectangle
      int xmin, xmax, ymin, ymax;
      std::tie(xmin, ymax, xmax, ymin) = rect;
      for (int x = xmin; x <= xmax; ++x) {
          grid->setPixel(x, ymin);
          grid->setPixel(x, ymax);
      }
      for (int y = ymin; y <= ymax; ++y) {
          grid->setPixel(xmin, y);
          grid->setPixel(xmax, y);
      }

      for (unsigned int i = 0; i < outputList.size(); ++i)
      {
          int x1, y1, x2, y2;
          std::tie(x1, y1) = outputList[i];
          std::tie(x2, y2) = outputList[(i + outputList.size() - 1) % outputList.size()];
          LineAlgorithms::drawBresenhamLine(grid, x1, y1, x2, y2);
      }
}

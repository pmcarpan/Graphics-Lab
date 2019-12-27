#ifndef POLYGONALGORITHMS_H
#define POLYGONALGORITHMS_H

#include "gridmodel.h"

class PolygonAlgorithms
{
public:
    struct EdgeBucket {
        int yMax, yMin, x, sign, dx, dy, sum;
        // double sum;

        bool operator==(const struct EdgeBucket& other) const {
            if (yMax != other.yMax || yMin != other.yMin || sign != other.sign
                    || dx != other.dx || dy != other.dy)
                return false;
            return true;
        }

        friend std::ostream& operator<<(std::ostream& o, const struct EdgeBucket& e) {
            o << e.yMax << " " << e.yMin << " " << e.x << " " << e.sign << " " << e.dx << " " << e.dy;
            return o;
        }
    };

private:
    PolygonAlgorithms(); // do not instantiate

public:
    static void drawPolygon(GridModel *grid, std::vector<std::pair<int, int>> vertices);

    static void floodFill(GridModel *grid, int x, int y, QColor oldColor, QColor newColor);
    static void boundaryFill(GridModel *grid, int x, int y, QColor edgeColor, QColor newColor);
    static void scanLinePolygonFill(GridModel *grid, std::vector<std::pair<int, int>> vertices);

    static void clipPolygon(GridModel *grid, std::vector<std::pair<int, int>> vertices,
                            std::tuple<int, int, int, int> rect);

private:
    static bool isSafe(GridModel *grid, int x, int y);
};

#endif // POLYGONALGORITHMS_H

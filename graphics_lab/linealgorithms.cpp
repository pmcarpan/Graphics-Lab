#include "linealgorithms.h"

#include <iostream>

LineAlgorithms::LineAlgorithms()
{
    // empty constructor, do not instantiate this class
}

// string to algo-enum mapping
const std::map<const std::string, const LineAlgorithms::Algorithm>
LineAlgorithms::stringAlgoMap =
{
    { "Basic", Algorithm::BASIC },
    { "Bresenham", Algorithm::BRESENHAM },
    { "DDA", Algorithm::DDA }
};

// object for emitting the time taken signal
const DurationEmitter* LineAlgorithms::durationEmitter = new DurationEmitter();

void LineAlgorithms::drawLine(GridModel *grid, int x1, int y1, int x2, int y2, Algorithm algo)
{
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> end;

    // basic checks for vertical and horizontal lines
    if (handleSpecialCases(grid, x1, y1, x2, y2))
    {
        end = std::chrono::system_clock::now();
        long long time = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
        durationEmitter->sendTime(time);
        return;
    }

    // for more accurate start time, placed within switch-case
    // start = std::chrono::system_clock::now();

    switch (algo)
    {
        case Algorithm::BASIC :
            start = std::chrono::system_clock::now();
            drawBasicLine(grid, x1, y1, x2, y2);
            break;
        case Algorithm::DDA :
            start = std::chrono::system_clock::now();
            drawDDALine(grid, x1, y1, x2, y2);
            break;
        case Algorithm::BRESENHAM :
            start = std::chrono::system_clock::now();
            drawBresenhamLine(grid, x1, y1, x2, y2);
            break;
    }

    end = std::chrono::system_clock::now();
    long long time = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    durationEmitter->sendTime(time);
}

void LineAlgorithms::drawBasicLine(GridModel *grid, int x1, int y1, int x2, int y2)
{
    double m, b;
    m = double(y2 - y1) / (x2 - x1);
    b = y1 - m * x1;

    if (std::abs(m) <= 1)
    {
        if (x1 > x2)
        {
            swapPoints(x1, y1, x2, y2);
        }
        for (int currX = x1; currX <= x2; ++currX)
        {
            int currY = int( std::round(m * currX + b) );
            grid->setPixel(currX, currY);
        }
    }
    else
    {
        if (y1 > y2)
        {
            swapPoints(x1, y1, x2, y2);
        }
        for (int currY = y1; currY <= y2; ++currY)
        {
            int currX = int( std::round((currY - b) / m) );
            grid->setPixel(currX, currY);
        }
    }
}

void LineAlgorithms::drawDDALine(GridModel *grid, int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    // total steps = max of |dx| and |dy|
    int steps = std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy);

    // calculate increment for x and y
    double xIncr = dx / double( steps );
    double yIncr = dy / double( steps );

    double currX = x1, currY = y1;
    for (int step = 0; step <= steps; ++step)
    {
        grid->setPixel( int(std::round(currX)), int(std::round(currY)) );
        currX += xIncr;
        currY += yIncr;
    }
}

void LineAlgorithms::drawBresenhamLine(GridModel *grid, int x1, int y1, int x2, int y2)
{
    if (std::abs(x1 - x2) > std::abs(y1 - y2))
        drawBresenhamLineWithXIncr(grid, x1, y1, x2, y2);
    else
        drawBresenhamLineWithYIncr(grid, x1, y1, x2, y2);
}

void LineAlgorithms::drawBresenhamLineWithXIncr(GridModel *grid, int x1, int y1, int x2, int y2)
{
    if (x1 > x2)
        swapPoints(x1, y1, x2, y2);

    int dx, dy, stepY;

    dx = x2 - x1; dy = y2 - y1;

    if (dy < 0) { dy = -dy; stepY = -1; } else { stepY = 1; }

    dx <<= 1; dy <<= 1;

    int fraction = dy - (dx >> 1);
    for (; x1 <= x2; ++x1)
    {
        grid->setPixel(x1, y1);

        // fraction += dy;
        if (fraction >= 0)
        {
            y1 += stepY;
            fraction -= dx;
        }
        fraction += dy;
    }
}

void LineAlgorithms::drawBresenhamLineWithYIncr(GridModel *grid, int x1, int y1, int x2, int y2)
{
    if (y1 > y2)
        swapPoints(x1, y1, x2, y2);

    int dx, dy, stepX;

    dx = x2 - x1; dy = y2 - y1;

    if (dx < 0) { dx = -dx; stepX = -1; } else { stepX = 1; }

    dx <<= 1; dy <<= 1;

    int fraction = dx - (dy >> 1);
    for (; y1 <= y2; ++y1)
    {
        grid->setPixel(x1, y1);

        // fraction += dx;
        if (fraction >= 0)
        {
            x1 += stepX;
            fraction -= dy;
        }
        fraction += dx;
    }
}

bool LineAlgorithms::isVerticalLine(int x1, int x2)
{
    return x1 == x2;
}

bool LineAlgorithms::isHorizontalLine(int y1, int y2)
{
    return y1 == y2;
}

void LineAlgorithms::drawVerticalLine(GridModel *grid, int y1, int y2, int x)
{
    if (y1 > y2)
        std::swap(y1, y2);

    for (; y1 <= y2; ++y1)
        grid->setPixel(x, y1);
}

void LineAlgorithms::drawHorizontalLine(GridModel *grid, int x1, int x2, int y)
{
    if (x1 > x2)
        std::swap(x1, x2);

    for (; x1 <= x2; ++x1)
        grid->setPixel(x1, y);
}

bool LineAlgorithms::handleSpecialCases(GridModel *grid, int x1, int y1, int x2, int y2)
{
    // handle the special cases, return true if handled
    if (isVerticalLine(x1, x2))
    {
        drawVerticalLine(grid, y1, y2, x1);
        return true;
    }
    else if (isHorizontalLine(y1, y2))
    {
        drawHorizontalLine(grid, x1, x2, y1);
        return true;
    }

    // could not handle in a special case
    return false;
}

void LineAlgorithms::swapPoints(int &x1, int &y1, int &x2, int &y2)
{
    std::swap(x1, x2);
    std::swap(y1, y2);
}

int LineAlgorithms::computeCode(int x, int y, std::tuple<int, int, int, int> rect)
{
    int code = INSIDE, xmin, xmax, ymin, ymax;

    std::tie(xmin, ymax, xmax, ymin) = rect;

    if (x < xmin)           // to the left of clip window
        code |= LEFT;
    else if (x > xmax)      // to the right of clip window
        code |= RIGHT;

    if (y < ymin)           // below the clip window
        code |= BOTTOM;
    else if (y > ymax)      // above the clip window
        code |= TOP;

    return code;
}

void LineAlgorithms::clipAndDraw(GridModel *grid, std::tuple<int, int, int, int> line,
                                 std::tuple<int, int, int, int> rect)
{
    int x0, y0, x1, y1, xmin, xmax, ymin, ymax;

    std::tie(x0, y0, x1, y1) = line;
    std::tie(xmin, ymax, xmax, ymin) = rect;

    int outcode0 = computeCode(x0, y0, rect);
    int outcode1 = computeCode(x1, y1, rect);
    bool accept = false;

    std::cout << x0 << " " << y0 << " " << x1 << " " << y1 << "\n";

    while (true) {
        if (!(outcode0 | outcode1)) {
            // bitwise OR is 0: both points inside window; trivially accept and exit loop
            accept = true;
            break;
        } else if (outcode0 & outcode1) {
            // bitwise AND is not 0: both points share an outside zone (LEFT, RIGHT, TOP,
            // or BOTTOM), so both must be outside window; exit loop (accept is false)
            break;
        } else {
            // failed both tests, so calculate the line segment to clip
            // from an outside point to an intersection with clip edge
            double x, y;

            // At least one endpoint is outside the clip rectangle; pick it.
            int outcodeOut = outcode0 ? outcode0 : outcode1;

            // Now find the intersection point;
            // use formulas:
            //   slope = (y1 - y0) / (x1 - x0)
            //   x = x0 + (1 / slope) * (ym - y0), where ym is ymin or ymax
            //   y = y0 + slope * (xm - x0), where xm is xmin or xmax
            // No need to worry about divide-by-zero because, in each case, the
            // outcode bit being tested guarantees the denominator is non-zero
            if (outcodeOut & TOP) {                // point is above the clip window
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            } else if (outcodeOut & BOTTOM) {      // point is below the clip window
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            } else if (outcodeOut & RIGHT) {       // point is to the right of clip window
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            } else /* if (outcodeOut & LEFT)0 */ { // point is to the left of clip window
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            // Now we move outside point to intersection point to clip
            // and get ready for next pass.
            if (outcodeOut == outcode0) {
                x0 = int(std::round(x));
                y0 = int(std::round(y));
                outcode0 = computeCode(x0, y0, rect);
            } else {
                x1 = int(std::round(x));
                y1 = int(std::round(y));
                outcode1 = computeCode(x1, y1, rect);
            }
        }
    }
    if (accept) {
        // DrawRectangle(xmin, ymin, xmax, ymax);
        drawBresenhamLine(grid, x0, y0, x1, y1);
    }
}

void LineAlgorithms::clipLines(GridModel *grid, std::vector<std::tuple<int, int, int, int> > lines,
                               std::tuple<int, int, int, int> rect)
{
    grid->clear();

    // draw the rectangle here
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

    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> end;

    for (std::tuple<int, int, int, int> line : lines)
    {
        clipAndDraw(grid, line, rect);
    }

    end = std::chrono::system_clock::now();
    long long time = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    durationEmitter->sendTime(time);
}

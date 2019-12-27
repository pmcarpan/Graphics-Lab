#include "circlealgorithms.h"

#include <QtMath>

// #include <iostream>

CircleAlgorithms::CircleAlgorithms()
{
    // empty constructor, do not instantiate this class
}

// string to algo-enum mapping
const std::map<const std::string, const CircleAlgorithms::Algorithm>
CircleAlgorithms::stringAlgoMap =
{
    { "Basic", Algorithm::BASIC },
    { "Bresenham", Algorithm::BRESENHAM },
    { "Polar", Algorithm::POLAR }
};

// object for emitting the time taken signal
const DurationEmitter* CircleAlgorithms::durationEmitter = new DurationEmitter();

void CircleAlgorithms::drawCircle(GridModel *grid, int x1, int y1, int r, Algorithm algo)
{
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> end;

    // for more accurate start time, placed within switch-case
    // start = std::chrono::system_clock::now();

    switch (algo)
    {
        case Algorithm::BASIC :
            start = std::chrono::system_clock::now();
            drawBasicCircle(grid, x1, y1, r);
            break;
        case Algorithm::BRESENHAM :
            start = std::chrono::system_clock::now();
            drawBresenhamCircle(grid, x1, y1, r);
            break;
        case Algorithm::POLAR :
            start = std::chrono::system_clock::now();
            drawPolarCircle(grid, x1, y1, r);
            break;
    }

    end = std::chrono::system_clock::now();
    long long time = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    durationEmitter->sendTime(time);
}

void CircleAlgorithms::drawBasicCircle(GridModel *grid, int xc, int yc, int r)
{
    double limit = r / std::sqrt(2);
    for (double x = 0; x <= limit; ++x)
    {
        double y = std::sqrt(r*r - x*x);
        plotAllOctants(grid, int(std::round(x)), int(std::round(y)), xc, yc);
    }
}

void CircleAlgorithms::drawBresenhamCircle(GridModel *grid, int xc, int yc, int r)
{
    int x = 0, y = r, // initial (x, y) is the topmost point
        p = 1 - r;    // decision parameter, approximate initialization

    // we start at the topmost point (90 degrees)
    // and go till the line y = x (45 degrees)
    // remaining points are found by octant symmetry
    while (x <= y)
    {
        plotAllOctants(grid, x, y, xc, yc);

        // need to move bottom-right if decision param > 0
        if (p > 0)
        {
            y--;
            p -= (2 * y);
        }

        // normally move right
        x++;
        p += (2 * x + 1);
    }
}

void CircleAlgorithms::drawPolarCircle(GridModel *grid, int xc, int yc, int r)
{
    double dθ = 1.0 / r, limit = M_PI_4; // limit = π/4
    for (double θ = 0; θ <= limit; θ += dθ)
    {
        double x = r * std::cos(θ),
               y = r * std::sin(θ);
        plotAllOctants(grid, int(std::round(x)), int(std::round(y)), xc, yc);
    }
}

void CircleAlgorithms::plotAllOctants(GridModel *grid, int x, int y, int xc, int yc)
{
    grid->setPixel(xc + x, yc + y); grid->setPixel(xc + y, yc + x);
    grid->setPixel(xc - x, yc + y); grid->setPixel(xc + y, yc - x);
    grid->setPixel(xc + x, yc - y); grid->setPixel(xc - y, yc + x);
    grid->setPixel(xc - x, yc - y); grid->setPixel(xc - y, yc - x);
}

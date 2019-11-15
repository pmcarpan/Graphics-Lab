#include "ellipsealgorithms.h"

#include <QtMath>

// #include <iostream> // TODO: remove after testing

EllipseAlgorithms::EllipseAlgorithms()
{
    // empty constructor, do not instantiate this class
}

// string to algo-enum mapping
const std::map<const std::string, const EllipseAlgorithms::Algorithm>
EllipseAlgorithms::stringAlgoMap =
{
    { "Basic", Algorithm::BASIC },
    { "Bresenham", Algorithm::BRESENHAM },
    { "Polar", Algorithm::POLAR }
};

// object for emitting the time taken signal
const DurationEmitter* EllipseAlgorithms::durationEmitter = new DurationEmitter();

void EllipseAlgorithms::drawEllipse(GridModel *grid, int x1, int y1, int a, int b, Algorithm algo)
{
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    std::chrono::time_point<std::chrono::system_clock> end;

    // for more accurate start time, placed within switch-case
    // start = std::chrono::system_clock::now();

    switch (algo)
    {
        case Algorithm::BASIC :
            start = std::chrono::system_clock::now();
            drawBasicEllipse(grid, x1, y1, a, b);
            break;
        case Algorithm::BRESENHAM :
            start = std::chrono::system_clock::now();
            drawBresenhamEllipse(grid, x1, y1, a, b);
            break;
        case Algorithm::POLAR :
            start = std::chrono::system_clock::now();
            drawPolarEllipse(grid, x1, y1, a, b);
            break;
    }

    end = std::chrono::system_clock::now();
    long long time = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    durationEmitter->sendTime(time);
}

void EllipseAlgorithms::drawBasicEllipse(GridModel *grid, int xc, int yc, int a, int b)
{
    double x = 0, y = b,
           limit = (a*b) / std::sqrt(a*a + b*b) + 1; // point where x = y in quadrant 1
    for (; x <= limit; ++x)
    {
        y = b * std::sqrt(1 - (x*x) / (a*a));
        plotAllQuadrants(grid, int(std::round(x)), int(std::round(y)), xc, yc);
    }
    for (y = std::floor(limit); y >= 0; --y)
    {
        x = a * std::sqrt(1 - (y*y) / (b*b));
        plotAllQuadrants(grid, int(std::round(x)), int(std::round(y)), xc, yc);
    }
}

void EllipseAlgorithms::drawBresenhamEllipse(GridModel *grid, int xc, int yc, int a, int b)
{
    int x, y, p, px, py;
    x = 0; y = b;
    p = int(std::round(b*b - a*a*b + 0.25*a*a));
    px = 0; py = 2*a*a*b;
    while (px < py)
    {
        plotAllQuadrants(grid, x, y, xc, yc);
        if (p >= 0)
        {
            y--;
            py -= 2*a*a;
            p -= py;
        }
        x++;
        px += 2*b*b;
        p += px + b*b;
    }
    p = int(std::round(b*b*(x+0.5)*(x+0.5) + a*a*(y-1)*(y-1) - a*a*b*b));
    while (y >= 0)
    {
        plotAllQuadrants(grid, x, y, xc, yc);
        if (p <= 0)
        {
            x++;
            px += 2*b*b;
            p += px;
        }
        y--;
        py -= 2*a*a;
        p += a*a - py;
    }
}

void EllipseAlgorithms::drawPolarEllipse(GridModel *grid, int xc, int yc, int a, int b)
{
    double dθ = 1.0 / std::max(a, b), limit = M_PI_2; // limit = π/2
    for (double θ = 0; θ <= limit; θ += dθ)
    {
        double x = a * std::cos(θ),
               y = b * std::sin(θ);
        plotAllQuadrants(grid, int(std::round(x)), int(std::round(y)), xc, yc);
    }
}

void EllipseAlgorithms::plotAllQuadrants(GridModel *grid, int x, int y, int xc, int yc)
{
    grid->setPixel(xc + x, yc + y);
    grid->setPixel(xc - x, yc + y);
    grid->setPixel(xc + x, yc - y);
    grid->setPixel(xc - x, yc - y);
}

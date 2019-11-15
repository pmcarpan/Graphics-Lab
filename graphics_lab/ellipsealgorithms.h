#ifndef ELLIPSEALGORITHMS_H
#define ELLIPSEALGORITHMS_H

#include "gridmodel.h"
#include "durationemitter.h"

class EllipseAlgorithms
{
public:
    enum Algorithm { BASIC, BRESENHAM, POLAR };
    static const std::map<const std::string, const Algorithm> stringAlgoMap;
    static const DurationEmitter *durationEmitter;

private:
    EllipseAlgorithms(); // do not instantiate

public:
    static void drawEllipse(GridModel *grid, int x1, int y1, int a, int b,
                           Algorithm algo = Algorithm::BASIC);

    static void drawBasicEllipse(GridModel *grid, int x1, int y1, int a, int b);
    static void drawBresenhamEllipse(GridModel *grid, int x1, int y1, int a, int b);
    static void drawPolarEllipse(GridModel *grid, int x1, int y1, int a, int b);

private:
    static inline void plotAllQuadrants(GridModel *grid, int x, int y, int xc, int yc);
};

#endif // ELLIPSEALGORITHMS_H

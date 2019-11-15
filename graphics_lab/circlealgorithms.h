#ifndef CIRCLEALGORITHMS_H
#define CIRCLEALGORITHMS_H

#include "gridmodel.h"
#include "durationemitter.h"

class CircleAlgorithms
{
public:
    enum Algorithm { BASIC, BRESENHAM, POLAR };
    static const std::map<const std::string, const Algorithm> stringAlgoMap;
    static const DurationEmitter *durationEmitter;

private:
    CircleAlgorithms(); // do not instantiate

public:
    static void drawCircle(GridModel *grid, int x1, int y1, int r,
                           Algorithm algo = Algorithm::BASIC);

    static void drawBasicCircle(GridModel *grid, int x1, int y1, int r);
    static void drawBresenhamCircle(GridModel *grid, int x1, int y1, int r);
    static void drawPolarCircle(GridModel *grid, int x1, int y1, int r);

private:
    static inline void plotAllOctants(GridModel *grid, int x, int y, int xc, int yc);
};

#endif // CIRCLEALGORITHMS_H

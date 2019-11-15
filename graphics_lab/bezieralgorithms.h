#ifndef BEZIERALGORITHMS_H
#define BEZIERALGORITHMS_H

#include "gridmodel.h"

class BezierAlgorithms
{
private:
    BezierAlgorithms(); // do not instantiate

public:
    static void drawBezierFull(GridModel *grid, std::vector<std::pair<int, int>> controlPoints);
    static void drawBezierApprox(GridModel *grid, std::vector<std::pair<int, int>> controlPoints);

private:
    static long comb(int n, int r);
};

#endif // BEZIERALGORITHMS_H

#ifndef LINEALGORITHMS_H
#define LINEALGORITHMS_H

#include "gridmodel.h"
#include "durationemitter.h"

class LineAlgorithms
{
public:
    enum Algorithm { BASIC, BRESENHAM, DDA };
    static const std::map<const std::string, const Algorithm> stringAlgoMap;
    static const DurationEmitter *durationEmitter;

    // for cohen-sutherland line clipping
    static const int INSIDE = 0, // 0000
                     LEFT = 1,   // 0001
                     RIGHT = 2,  // 0010
                     BOTTOM = 4, // 0100
                     TOP = 8;    // 1000

private:
    LineAlgorithms(); // do not instantiate

public:
    static void drawLine(GridModel *grid, int x1, int y1, int x2, int y2,
                         Algorithm algo = Algorithm::BASIC);

    static void drawBasicLine(GridModel *grid, int x1, int y1, int x2, int y2);
    static void drawDDALine(GridModel *grid, int x1, int y1, int x2, int y2);
    static void drawBresenhamLine(GridModel *grid, int x1, int y1, int x2, int y2);

    static int computeCode(int x, int y, std::tuple<int, int, int, int> rect);
    static void clipAndDraw(GridModel *grid, std::tuple<int, int, int, int> line,
                            std::tuple<int, int, int, int> rect);
    static void clipLines(GridModel *grid, std::vector<std::tuple<int, int, int, int>> lines,
                          std::tuple<int, int, int, int> rect);

private:
    static bool isHorizontalLine(int y1, int y2);
    static bool isVerticalLine(int x1, int x2);

    static void drawHorizontalLine(GridModel *grid, int x1, int x2, int y);
    static void drawVerticalLine(GridModel *grid, int y1, int y2, int x);

    static bool handleSpecialCases(GridModel *grid, int x1, int y1, int x2, int y2);

    static void drawBresenhamLineWithXIncr(GridModel *grid, int x1, int y1, int x2, int y2);
    static void drawBresenhamLineWithYIncr(GridModel *grid, int x1, int y1, int x2, int y2);

    static inline void swapPoints(int &x1, int &y1, int &x2, int &y2);
};

#endif // LINEALGORITHMS_H

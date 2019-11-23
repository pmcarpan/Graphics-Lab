#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "gridmodel.h"
#include "gridtableview.h"
#include "menuforlines.h"
#include "linealgorithms.h"
#include "circlealgorithms.h"
#include "ellipsealgorithms.h"
#include "polygonalgorithms.h"
#include "transformationalgorithms.h"
#include "bezieralgorithms.h"

class Widget : public QWidget
{
    Q_OBJECT

    QLayout *globalLayout;
    GridModel *gridModel;
    GridTableView *gridTableView;
    MenuForLines *menuForLines;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void receiveDrawLineSignal(int x1, int y1, int x2, int y2,
                               LineAlgorithms::Algorithm algo = LineAlgorithms::Algorithm::BASIC);
    void receiveDrawCircleSignal(int x1, int y1, int r,
                                 CircleAlgorithms::Algorithm algo = CircleAlgorithms::Algorithm::BASIC);
    void receiveDrawEllipseSignal(int x1, int y1, int a, int b,
                                  EllipseAlgorithms::Algorithm algo = EllipseAlgorithms::Algorithm::BASIC);
    void receiveDrawPolygonSignal(std::vector<std::pair<int, int>> vertices);
    void receiveFloodFillSignal(int x, int y, QColor oldColor, QColor newColor);
    void receiveBoundaryFillSignal(int x, int y, QColor edgeColor, QColor newColor);
    void receiveScanLinePolygonFillSignal(std::vector<std::pair<int, int>> vertices);
    void receiveClipLinesSignal(std::vector<std::tuple<int, int, int, int>> lines,
                                std::tuple<int, int, int, int> rect);
    void receiveClipPolygonSignal(std::vector<std::pair<int, int>> vertices,
                                  std::tuple<int, int, int, int> rect);
    void receiveScaleSignal(double cx, double cy, std::vector<std::pair<int, int>> vertices);
    void receiveShearSignal(double cx, double cy, std::vector<std::pair<int, int>> vertices);
    void receiveRotateSignal(double degrees, std::pair<int, int> about, std::vector<std::pair<int, int>> vertices);
    void receiveTranslateSignal(double dx, double dy, std::vector<std::pair<int, int>> vertices);
    void receiveReflectPointSignal(int x1, int y1, std::vector<std::pair<int, int>> vertices);
    void receiveReflectLineSignal(int x1, int y1, int x2, int y2, std::vector<std::pair<int, int>> vertices);
    void receiveDrawBezierFullSignal(std::vector<std::pair<int, int>> controlPoints);
    void receiveDrawBezierApproxSignal(std::vector<std::pair<int, int>> controlPoints);


    void receivePolygon(std::vector<std::pair<int, int>> vertices);
};

#endif // WIDGET_H

#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Computer Graphics Lab");

    globalLayout = new QHBoxLayout();
    gridModel = new GridModel();
    gridTableView = new GridTableView();

    menuForLines = new MenuForLines();

    gridTableView->setModel(gridModel);

    connect(menuForLines->gridMenu, SIGNAL(sendChangePixelSizeSignal(int)),
            gridTableView, SLOT(receiveChangePixelSizeSignal(int)));
    connect(menuForLines->gridMenu, SIGNAL(sendChangeGridSizeSignal(int)),
            gridModel, SLOT(receiveChangeGridSizeSignal(int)));
    connect(menuForLines->gridMenu, SIGNAL(sendClearGridSignal()),
            gridModel, SLOT(receiveClearGridSignal()));

    connect(gridTableView, SIGNAL(sendHoverIndex(const QModelIndex &)),
            gridModel, SLOT(receiveHoverIndex(const QModelIndex &)));
    connect(gridTableView, SIGNAL(sendClickIndex(const QModelIndex &)),
            gridModel, SLOT(receiveClickIndex(const QModelIndex &)));

    // connections for click and hover coordinates
    connect(gridModel, SIGNAL(sendHoverCoordinates(int, int)),
            menuForLines->lineMenu, SLOT(receiveHoverCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendClickCoordinates(int, int)),
            menuForLines->lineMenu, SLOT(receiveClickCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendHoverCoordinates(int, int)),
            menuForLines->circleMenu, SLOT(receiveHoverCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendClickCoordinates(int, int)),
            menuForLines->circleMenu, SLOT(receiveClickCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendHoverCoordinates(int, int)),
            menuForLines->ellipseMenu, SLOT(receiveHoverCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendClickCoordinates(int, int)),
            menuForLines->ellipseMenu, SLOT(receiveClickCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendHoverCoordinates(int, int)),
            menuForLines->polygonMenu, SLOT(receiveHoverCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendClickCoordinates(int, int)),
            menuForLines->polygonMenu, SLOT(receiveClickCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendHoverCoordinates(int, int)),
            menuForLines->transformationMenu, SLOT(receiveHoverCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendClickCoordinates(int, int)),
            menuForLines->transformationMenu, SLOT(receiveClickCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendHoverCoordinates(int, int)),
            menuForLines->bezierMenu, SLOT(receiveHoverCoordinates(int, int)));
    connect(gridModel, SIGNAL(sendClickCoordinates(int, int)),
            menuForLines->bezierMenu, SLOT(receiveClickCoordinates(int, int)));

    // connections for draw signals
    connect(menuForLines->lineMenu, SIGNAL(sendDrawLineSignal(int, int, int, int, LineAlgorithms::Algorithm)),
            this, SLOT(receiveDrawLineSignal(int, int, int, int, LineAlgorithms::Algorithm)));
    connect(menuForLines->lineMenu,
            SIGNAL(sendClipLinesSignal(std::vector<std::tuple<int, int, int, int>>, std::tuple<int, int, int, int>)),
            this,
            SLOT(receiveClipLinesSignal(std::vector<std::tuple<int, int, int, int>>, std::tuple<int, int, int, int>)));

    connect(menuForLines->circleMenu, SIGNAL(sendDrawCircleSignal(int, int, int, CircleAlgorithms::Algorithm)),
            this, SLOT(receiveDrawCircleSignal(int, int, int, CircleAlgorithms::Algorithm)));
    connect(menuForLines->ellipseMenu, SIGNAL(sendDrawEllipseSignal(int, int, int, int, EllipseAlgorithms::Algorithm)),
            this, SLOT(receiveDrawEllipseSignal(int, int, int, int, EllipseAlgorithms::Algorithm)));
    connect(menuForLines->polygonMenu, SIGNAL(sendDrawPolygonSignal(std::vector<std::pair<int, int>>)),
            this, SLOT(receiveDrawPolygonSignal(std::vector<std::pair<int, int>>)));
    connect(menuForLines->polygonMenu, SIGNAL(sendFloodFillSignal(int, int, QColor, QColor)),
            this, SLOT(receiveFloodFillSignal(int, int, QColor, QColor)));
    connect(menuForLines->polygonMenu, SIGNAL(sendBoundaryFillSignal(int, int, QColor, QColor)),
            this, SLOT(receiveBoundaryFillSignal(int, int, QColor, QColor)));
    connect(menuForLines->polygonMenu, SIGNAL(sendScanLinePolygonFillSignal(std::vector<std::pair<int, int>>)),
            this, SLOT(receiveScanLinePolygonFillSignal(std::vector<std::pair<int, int>>)));
    connect(menuForLines->polygonMenu,
            SIGNAL(sendClipPolygonSignal(std::vector<std::pair<int, int>>, std::tuple<int, int, int, int>)),
            this,
            SLOT(receiveClipPolygonSignal(std::vector<std::pair<int, int>>, std::tuple<int, int, int, int>)));

    connect(menuForLines->transformationMenu, SIGNAL(sendDrawPolygonSignal(std::vector<std::pair<int, int>>)),
            this, SLOT(receiveDrawPolygonSignal(std::vector<std::pair<int, int>>)));
    connect(menuForLines->transformationMenu, SIGNAL(sendScaleSignal(double, double, std::vector<std::pair<int, int>>)),
            this, SLOT(receiveScaleSignal(double, double, std::vector<std::pair<int, int>>)));
    connect(menuForLines->transformationMenu, SIGNAL(sendShearSignal(double, double, std::vector<std::pair<int, int>>)),
            this, SLOT(receiveShearSignal(double, double, std::vector<std::pair<int, int>>)));
    connect(menuForLines->transformationMenu, SIGNAL(sendRotateSignal(double, std::pair<int, int>, std::vector<std::pair<int, int>>)),
            this, SLOT(receiveRotateSignal(double, std::pair<int, int>, std::vector<std::pair<int, int>>)));
    connect(menuForLines->transformationMenu, SIGNAL(sendTranslateSignal(double, double, std::vector<std::pair<int, int>>)),
            this, SLOT(receiveTranslateSignal(double, double, std::vector<std::pair<int, int>>)));
    connect(menuForLines->transformationMenu, SIGNAL(sendReflectPointSignal(int, int, std::vector<std::pair<int, int>>)),
            this, SLOT(receiveReflectPointSignal(int, int, std::vector<std::pair<int, int>>)));
    connect(menuForLines->transformationMenu, SIGNAL(sendReflectLineSignal(int, int, int, int, std::vector<std::pair<int, int>>)),
            this, SLOT(receiveReflectLineSignal(int, int, int, int, std::vector<std::pair<int, int>>)));
    connect(menuForLines->bezierMenu, SIGNAL(sendDrawBezierFullSignal(std::vector<std::pair<int, int>>)),
            this, SLOT(receiveDrawBezierFullSignal(std::vector<std::pair<int, int>>)));
    connect(menuForLines->bezierMenu, SIGNAL(sendDrawBezierApproxSignal(std::vector<std::pair<int, int>>)),
            this, SLOT(receiveDrawBezierApproxSignal(std::vector<std::pair<int, int>>)));

    // connections for time signals
    connect(LineAlgorithms::durationEmitter, SIGNAL(sendTimeSignal(const long long&)),
            menuForLines->lineMenu, SLOT(receiveTimeTaken(const long long&)));
    connect(CircleAlgorithms::durationEmitter, SIGNAL(sendTimeSignal(const long long&)),
            menuForLines->circleMenu, SLOT(receiveTimeTaken(const long long&)));
    connect(EllipseAlgorithms::durationEmitter, SIGNAL(sendTimeSignal(const long long&)),
            menuForLines->ellipseMenu, SLOT(receiveTimeTaken(const long long&)));

    // connection for sending polygon back to menu
    connect(TransformationAlgorithms::polygonEmitter, SIGNAL(sendPolySignal(std::vector<std::pair<int, int>>)),
            this, SLOT(receivePolygon(std::vector<std::pair<int, int>>)));


    globalLayout->addWidget(menuForLines);
    globalLayout->addWidget(gridTableView);

    setLayout(globalLayout);
}

Widget::~Widget()
{
    delete gridModel;
    delete gridTableView;
    delete globalLayout;

    delete menuForLines;
}

void Widget::receiveDrawLineSignal(int x1, int y1, int x2, int y2, LineAlgorithms::Algorithm algo)
{
    LineAlgorithms::drawLine(gridModel, x1, y1, x2, y2, algo);
}

void Widget::receiveDrawCircleSignal(int x1, int y1, int r, CircleAlgorithms::Algorithm algo)
{
    CircleAlgorithms::drawCircle(gridModel, x1, y1, r, algo);
}

void Widget::receiveDrawEllipseSignal(int x1, int y1, int a, int b, EllipseAlgorithms::Algorithm algo)
{
    EllipseAlgorithms::drawEllipse(gridModel, x1, y1, a, b, algo);
}

void Widget::receiveDrawPolygonSignal(std::vector<std::pair<int, int>> vertices)
{
    PolygonAlgorithms::drawPolygon(gridModel, vertices);
}

void Widget::receiveFloodFillSignal(int x, int y, QColor oldColor, QColor newColor)
{
    PolygonAlgorithms::floodFill(gridModel, x, y, oldColor, newColor);
}

void Widget::receiveBoundaryFillSignal(int x, int y, QColor edgeColor, QColor newColor)
{
    PolygonAlgorithms::boundaryFill(gridModel, x, y, edgeColor, newColor);
}

void Widget::receiveScanLinePolygonFillSignal(std::vector<std::pair<int, int>> vertices)
{
    PolygonAlgorithms::scanLinePolygonFill(gridModel, vertices);
}

void Widget::receiveClipLinesSignal(std::vector<std::tuple<int, int, int, int>> lines,
                                    std::tuple<int, int, int, int> rect)
{
    LineAlgorithms::clipLines(gridModel, lines, rect);
}

void Widget::receiveClipPolygonSignal(std::vector<std::pair<int, int>> vertices,
                                      std::tuple<int, int, int, int> rect)
{
    PolygonAlgorithms::clipPolygon(gridModel, vertices, rect);
}

void Widget::receiveScaleSignal(double cx, double cy, std::vector<std::pair<int, int>> vertices)
{
    TransformationAlgorithms::scale(gridModel, cx, cy, vertices);
}

void Widget::receiveShearSignal(double cx, double cy, std::vector<std::pair<int, int>> vertices)
{
    TransformationAlgorithms::shear(gridModel, cx, cy, vertices);
}

void Widget::receiveRotateSignal(double degrees, std::pair<int, int> about, std::vector<std::pair<int, int>> vertices)
{
    TransformationAlgorithms::rotate(gridModel, degrees, about, vertices);
}

void Widget::receiveTranslateSignal(double dx, double dy, std::vector<std::pair<int, int>> vertices)
{
    TransformationAlgorithms::translate(gridModel, dx, dy, vertices);
}

void Widget::receiveReflectPointSignal(int x1, int y1, std::vector<std::pair<int, int>> vertices)
{
    TransformationAlgorithms::reflect(gridModel, x1, y1, vertices);
}

void Widget::receiveReflectLineSignal(int x1, int y1, int x2, int y2, std::vector<std::pair<int, int>> vertices)
{
    TransformationAlgorithms::reflect(gridModel, x1, y1, x2, y2, vertices);
}

void Widget::receiveDrawBezierFullSignal(std::vector<std::pair<int, int>> controlPoints)
{
    BezierAlgorithms::drawBezierFull(gridModel, controlPoints);
}

void Widget::receiveDrawBezierApproxSignal(std::vector<std::pair<int, int>> controlPoints)
{
    BezierAlgorithms::drawBezierApprox(gridModel, controlPoints);
}

void Widget::receivePolygon(std::vector<std::pair<int, int>> v)
{
    menuForLines->transformationMenu->vertices = v;
    menuForLines->transformationMenu->onDrawButtonClicked();
}

#include "polygonmenu.h"

#include <QVBoxLayout>

PolygonMenu::PolygonMenu(QWidget *parent) : QWidget(parent)
{

    drawGroupBox = new QGroupBox("Polygon Drawing Menu");
    drawGroupBoxLayout = new QVBoxLayout();

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();

//    currentPoints = new QTableWidget();
//    currentPoints->setMaximumSize(300, 50);

    pushPointButton = new QPushButton("Push Point");
    clearButton = new QPushButton("Clear");
    drawButton = new QPushButton("Draw Polygon");

    fillGroupBox = new QGroupBox("Polygon Filling Menu");
    fillGroupBoxLayout = new QVBoxLayout();

    floodFillButton = new QPushButton("Flood Fill");
    boundaryFillButton = new QPushButton("Boundary Fill");
    scanLineFillButton = new QPushButton("Scan Line Fill");

    clipGroupBox = new QGroupBox("Clip Polygon");
    clipGroupBoxLayout = new QVBoxLayout();

    clipPointOneLabel = new QLabel();
    setClipPointOneButton = new QPushButton("Set Top Left");
    clipPointOneLabel->setBuddy(setClipPointOneButton);
    clipPointTwoLabel = new QLabel();
    setClipPointTwoButton = new QPushButton("Set Bottom Right");
    clipPointTwoLabel->setBuddy(setClipPointTwoButton);
    clipButton = new QPushButton("Clip");

    timeLabel = new QLabel();

    drawGroupBoxLayout->addWidget(hoverCoordinatesLabel);
    drawGroupBoxLayout->addWidget(clickCoordinatesLabel);
//    drawGroupBoxLayout->addWidget(currentPoints);
    drawGroupBoxLayout->addWidget(pushPointButton);
    drawGroupBoxLayout->addWidget(clearButton);
    drawGroupBoxLayout->addWidget(drawButton);

    fillGroupBoxLayout->addWidget(floodFillButton);
    fillGroupBoxLayout->addWidget(boundaryFillButton);
    fillGroupBoxLayout->addWidget(scanLineFillButton);

    clipGroupBoxLayout->addWidget(clipPointOneLabel);
    clipGroupBoxLayout->addWidget(setClipPointOneButton);
    clipGroupBoxLayout->addWidget(clipPointTwoLabel);
    clipGroupBoxLayout->addWidget(setClipPointTwoButton);
    clipGroupBoxLayout->addWidget(clipButton);

    drawGroupBox->setLayout(drawGroupBoxLayout);
    fillGroupBox->setLayout(fillGroupBoxLayout);
    clipGroupBox->setLayout(clipGroupBoxLayout);

    globalLayout = new QVBoxLayout();
    globalLayout->addWidget(drawGroupBox);
    globalLayout->addWidget(fillGroupBox);
    globalLayout->addWidget(clipGroupBox);
    globalLayout->addWidget(timeLabel);

    setLayout(globalLayout);

    tempX = tempY = x1 = y1 = 0;
    vertices.clear();
    receiveHoverCoordinates(0, 0);
    receiveClickCoordinates(0, 0);
    onSetClipPointOneButtonClicked();
    onSetClipPointTwoButtonClicked();

    connect(pushPointButton, SIGNAL(clicked()), this, SLOT(onPushPointButtonClicked()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(drawButton, SIGNAL(clicked()), this, SLOT(onDrawButtonClicked()));

    connect(floodFillButton, SIGNAL(clicked()), this, SLOT(onFloodFillButtonClicked()));
    connect(boundaryFillButton, SIGNAL(clicked()), this, SLOT(onBoundaryFillButtonClicked()));
    connect(scanLineFillButton, SIGNAL(clicked()), this, SLOT(onScanLineFillButtonClicked()));

    connect(setClipPointOneButton, SIGNAL(clicked()), this, SLOT(onSetClipPointOneButtonClicked()));
    connect(setClipPointTwoButton, SIGNAL(clicked()), this, SLOT(onSetClipPointTwoButtonClicked()));
    connect(clipButton, SIGNAL(clicked()), this, SLOT(onClipButtonClicked()));
}

void PolygonMenu::onDrawButtonClicked()
{
    emit sendDrawPolygonSignal(vertices);
}

void PolygonMenu::receiveHoverCoordinates(int x, int y)
{
    QString text = "Hover Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    hoverCoordinatesLabel->setText(text);
}

void PolygonMenu::receiveClickCoordinates(int x, int y)
{
    tempX = x; tempY = y;

    QString text = "Click Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    clickCoordinatesLabel->setText(text);
}

void PolygonMenu::onPushPointButtonClicked()
{
    vertices.push_back(std::pair<int, int>(tempX, tempY));
}

void PolygonMenu::onClearButtonClicked()
{
    vertices.clear();
}

void PolygonMenu::onFloodFillButtonClicked()
{
    emit sendFloodFillSignal(tempX, tempY, QColor(Qt::red), QColor(Qt::blue));
}

void PolygonMenu::onBoundaryFillButtonClicked()
{
    emit sendBoundaryFillSignal(tempX, tempY, QColor(Qt::blue), QColor(Qt::blue));
}

void PolygonMenu::onScanLineFillButtonClicked()
{
    emit sendScanLinePolygonFillSignal(vertices);
}

void PolygonMenu::onSetClipPointOneButtonClicked()
{
    cx1 = tempX; cy1 = tempY;

    QString text = "Clip Point 1: (" + QString::number(cx1) + ", " + QString::number(cy1) + ")";
    clipPointOneLabel->setText(text);
}

void PolygonMenu::onSetClipPointTwoButtonClicked()
{
    cx2 = tempX; cy2 = tempY;

    QString text = "Clip Point 2: (" + QString::number(cx2) + ", " + QString::number(cy2) + ")";
    clipPointTwoLabel->setText(text);
}

void PolygonMenu::onClipButtonClicked()
{
    std::tuple<int, int, int, int> rect = std::make_tuple(cx1, cy1, cx2, cy2);
    emit sendClipPolygonSignal(vertices, rect);
}

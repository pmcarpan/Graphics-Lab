#include "beziermenu.h"

BezierMenu::BezierMenu(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Bezier");
    groupBoxLayout = new QVBoxLayout();

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();

    pushControlPointButton = new QPushButton("Push Control Point");
    drawBezierFullButton = new QPushButton("Draw Bezier (Full)");
    clearControlPointsButton = new QPushButton("Clear Control Points");

    groupBoxLayout->addWidget(hoverCoordinatesLabel);
    groupBoxLayout->addWidget(clickCoordinatesLabel);
    groupBoxLayout->addWidget(pushControlPointButton);
    groupBoxLayout->addWidget(drawBezierFullButton);
    groupBoxLayout->addWidget(clearControlPointsButton);

    groupBox->setLayout(groupBoxLayout);

    globalLayout = new QVBoxLayout();
    globalLayout->addWidget(groupBox);
    setLayout(globalLayout);

    controlPoints.clear();
    clickX = clickY = 0;
    receiveHoverCoordinates(0, 0); receiveClickCoordinates(0, 0);

    connect(pushControlPointButton, SIGNAL(clicked()), this, SLOT(onPushControlPointButtonClicked()));
    connect(drawBezierFullButton, SIGNAL(clicked()), this, SLOT(onDrawBezierFullButtonClicked()));
    connect(clearControlPointsButton, SIGNAL(clicked()), this, SLOT(onClearControlPointsButtonClicked()));
}

void BezierMenu::receiveHoverCoordinates(int x, int y)
{
    QString text = "Hover Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    hoverCoordinatesLabel->setText(text);
}

void BezierMenu::receiveClickCoordinates(int x, int y)
{
    clickX = x; clickY = y;

    QString text = "Click Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    clickCoordinatesLabel->setText(text);
}

void BezierMenu::onPushControlPointButtonClicked()
{
    controlPoints.push_back(std::make_pair(clickX, clickY));
}

void BezierMenu::onDrawBezierFullButtonClicked()
{
    emit sendDrawBezierFullSignal(controlPoints);
}

void BezierMenu::onClearControlPointsButtonClicked()
{
    controlPoints.clear();
}

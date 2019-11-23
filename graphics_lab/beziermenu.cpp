#include "beziermenu.h"

#include <QMessageBox>

BezierMenu::BezierMenu(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Bezier");
    groupBoxLayout = new QVBoxLayout();

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();

    pushControlPointButton = new QPushButton("Push Control Point");
    drawBezierFullButton = new QPushButton("Draw Bezier (Full)");
    drawBezierApproxButton = new QPushButton("Draw Bezier (Approx)");
    clearControlPointsButton = new QPushButton("Clear Control Points");

    groupBoxLayout->addWidget(hoverCoordinatesLabel);
    groupBoxLayout->addWidget(clickCoordinatesLabel);
    groupBoxLayout->addWidget(pushControlPointButton);
    groupBoxLayout->addWidget(drawBezierFullButton);
    groupBoxLayout->addWidget(drawBezierApproxButton);
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
    connect(drawBezierApproxButton, SIGNAL(clicked()), this, SLOT(onDrawBezierApproxButtonClicked()));
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

void BezierMenu::onDrawBezierApproxButtonClicked()
{
    if (controlPoints.size() < 4 || controlPoints.size() % 3 != 1)
    {
        QMessageBox::warning(this, "Cannot make approx bezier",
                             tr("No. of control points must be <code>3*n + 1 (n > 0)</code>"));
        return;
    }

    emit sendDrawBezierApproxSignal(controlPoints);
}

void BezierMenu::onClearControlPointsButtonClicked()
{
    controlPoints.clear();
}

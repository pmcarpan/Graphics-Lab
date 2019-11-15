#include "ellipsemenu.h"

#include <QVBoxLayout>

EllipseMenu::EllipseMenu(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Ellipse Drawing Menu");

    groupBoxLayout = new QVBoxLayout();
    // groupBoxLayout->setSizeConstraint(QLayout::SetFixedSize);

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();

    centrePointLabel = new QLabel();
    setCentrePointButton = new QPushButton("Set Centre");
    centrePointLabel->setBuddy(setCentrePointButton);

    paramALabel = new QLabel("Parameter [a]: ");
    paramASpinBox = new QSpinBox();
    paramASpinBox->setRange(1, 99);
    paramASpinBox->setValue(5);
    paramALabel->setBuddy(paramASpinBox);

    paramBLabel = new QLabel("Parameter [b]: ");
    paramBSpinBox = new QSpinBox();
    paramBSpinBox->setRange(1, 99);
    paramBSpinBox->setValue(5);
    paramBLabel->setBuddy(paramBSpinBox);

    algoLabel = new QLabel("Algorithm:");
    algoComboBox = new QComboBox();
    for (auto &iterPair : EllipseAlgorithms::stringAlgoMap)
    {
        std::string algoName = iterPair.first;
        algoComboBox->addItem(QString::fromStdString(algoName));
    }
    algoLabel->setBuddy(algoComboBox);

    drawButton = new QPushButton("Draw Ellipse");

    timeLabel = new QLabel();

    groupBoxLayout->addWidget(hoverCoordinatesLabel);
    groupBoxLayout->addWidget(clickCoordinatesLabel);
    groupBoxLayout->addWidget(centrePointLabel);
    groupBoxLayout->addWidget(setCentrePointButton);
    groupBoxLayout->addWidget(paramALabel);
    groupBoxLayout->addWidget(paramASpinBox);
    groupBoxLayout->addWidget(paramBLabel);
    groupBoxLayout->addWidget(paramBSpinBox);
    groupBoxLayout->addWidget(algoLabel);
    groupBoxLayout->addWidget(algoComboBox);
    groupBoxLayout->addWidget(drawButton);
    groupBoxLayout->addWidget(timeLabel);

    groupBox->setLayout(groupBoxLayout);

    globalLayout = new QHBoxLayout();
    globalLayout->addWidget(groupBox);

    setLayout(globalLayout);

    tempX = tempY = x1 = y1 = a = b = 0;
    receiveHoverCoordinates(0, 0);
    receiveClickCoordinates(0, 0);
    onSetCentrePointButtonClicked();
    receiveTimeTaken(0);

    connect(setCentrePointButton, SIGNAL(clicked()), this, SLOT(onSetCentrePointButtonClicked()));
    connect(drawButton, SIGNAL(clicked()), this, SLOT(onDrawButtonClicked()));
}

void EllipseMenu::receiveHoverCoordinates(int x, int y)
{
    QString text = "Hover Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    hoverCoordinatesLabel->setText(text);
}

void EllipseMenu::receiveClickCoordinates(int x, int y)
{
    tempX = x; tempY = y;

    QString text = "Click Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    clickCoordinatesLabel->setText(text);
}

void EllipseMenu::onSetCentrePointButtonClicked()
{
    x1 = tempX; y1 = tempY;

    QString text = "Centre: (" + QString::number(x1) + ", " + QString::number(y1) + ")";
    centrePointLabel->setText(text);
}

void EllipseMenu::onDrawButtonClicked()
{
    a = paramASpinBox->value();
    b = paramBSpinBox->value();

    std::string algoName = algoComboBox->currentText().toStdString();
    EllipseAlgorithms::Algorithm algo = EllipseAlgorithms::stringAlgoMap.at(algoName);

    emit sendDrawEllipseSignal(x1, y1, a, b, algo);
}

void EllipseMenu::receiveTimeTaken(const long long &time)
{
    QString text = "Time taken: " + QString::number(time) + " µs";
    timeLabel->setText(text);
}

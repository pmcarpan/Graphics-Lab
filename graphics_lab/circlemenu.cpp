#include "circlemenu.h"

#include <QVBoxLayout>

CircleMenu::CircleMenu(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Circle Drawing Menu");

    groupBoxLayout = new QVBoxLayout();
    // groupBoxLayout->setSizeConstraint(QLayout::SetFixedSize);

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();
    hoverCoordinatesLabel->setBuddy(clickCoordinatesLabel);

    centrePointLabel = new QLabel();
    clickCoordinatesLabel->setBuddy(centrePointLabel);
    setCentrePointButton = new QPushButton("Set Centre");
    centrePointLabel->setBuddy(setCentrePointButton);

    radiusLabel = new QLabel("Radius: ");
    radiusSpinBox = new QSpinBox();
    radiusSpinBox->setRange(1, 99);
    radiusSpinBox->setValue(5);
    radiusLabel->setBuddy(radiusSpinBox);

    algoLabel = new QLabel("Algorithm:");
    algoComboBox = new QComboBox();
    for (auto &iterPair : CircleAlgorithms::stringAlgoMap)
    {
        std::string algoName = iterPair.first;
        algoComboBox->addItem(QString::fromStdString(algoName));
    }
    algoLabel->setBuddy(algoComboBox);

    drawButton = new QPushButton("Draw Circle");

    timeLabel = new QLabel();

    groupBoxLayout->addWidget(hoverCoordinatesLabel);
    groupBoxLayout->addWidget(clickCoordinatesLabel);
    groupBoxLayout->addWidget(centrePointLabel);
    groupBoxLayout->addWidget(setCentrePointButton);
    groupBoxLayout->addWidget(radiusLabel);
    groupBoxLayout->addWidget(radiusSpinBox);
    groupBoxLayout->addWidget(algoLabel);
    groupBoxLayout->addWidget(algoComboBox);
    groupBoxLayout->addWidget(drawButton);
    groupBoxLayout->addWidget(timeLabel);

    groupBox->setLayout(groupBoxLayout);

    globalLayout = new QHBoxLayout();
    globalLayout->addWidget(groupBox);

    setLayout(globalLayout);

    tempX = tempY = x1 = y1 = r = 0;
    receiveHoverCoordinates(0, 0);
    receiveClickCoordinates(0, 0);
    onSetCentrePointButtonClicked();
    receiveTimeTaken(0);

    connect(setCentrePointButton, SIGNAL(clicked()), this, SLOT(onSetCentrePointButtonClicked()));
    connect(drawButton, SIGNAL(clicked()), this, SLOT(onDrawButtonClicked()));
}

void CircleMenu::receiveHoverCoordinates(int x, int y)
{
    QString text = "Hover Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    hoverCoordinatesLabel->setText(text);
}

void CircleMenu::receiveClickCoordinates(int x, int y)
{
    tempX = x; tempY = y;

    QString text = "Click Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    clickCoordinatesLabel->setText(text);
}

void CircleMenu::onSetCentrePointButtonClicked()
{
    x1 = tempX; y1 = tempY;

    QString text = "Centre: (" + QString::number(x1) + ", " + QString::number(y1) + ")";
    centrePointLabel->setText(text);
}

void CircleMenu::onDrawButtonClicked()
{
    r = radiusSpinBox->value();

    std::string algoName = algoComboBox->currentText().toStdString();
    CircleAlgorithms::Algorithm algo = CircleAlgorithms::stringAlgoMap.at(algoName);

    emit sendDrawCircleSignal(x1, y1, r, algo);
}

void CircleMenu::receiveTimeTaken(const long long &time)
{
    QString text = "Time taken: " + QString::number(time) + " µs";
    timeLabel->setText(text);
}

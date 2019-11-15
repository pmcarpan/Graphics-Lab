#include "linemenu.h"

#include <QVBoxLayout>

LineMenu::LineMenu(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Line Drawing Menu");

    groupBoxLayout = new QVBoxLayout();
    // groupBoxLayout->setSizeConstraint(...);

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();

    pointOneLabel = new QLabel();
    setPointOneButton = new QPushButton("Set Point 1");
    pointOneLabel->setBuddy(setPointOneButton);

    pointTwoLabel = new QLabel();
    setPointTwoButton = new QPushButton("Set Point 2");
    pointTwoLabel->setBuddy(setPointTwoButton);

    algoLabel = new QLabel("Algorithm:");
    algoComboBox = new QComboBox();
    for (auto &iterPair : LineAlgorithms::stringAlgoMap)
    {
        // TODO: capitalize first letter ?
        std::string algoName = iterPair.first;
        algoComboBox->addItem(QString::fromStdString(algoName));
    }
    algoLabel->setBuddy(algoComboBox);

    drawButton = new QPushButton("Draw Line");
    drawAllButton = new QPushButton("Draw All Lines");
    clearButton = new QPushButton("Clear Lines");

    clipPointOneLabel = new QLabel();
    clipPointTwoLabel = new QLabel();

    setClipPointOneButton = new QPushButton("Set Top Left");
    setClipPointTwoButton = new QPushButton("Set Bottom Right");

    clipButton = new QPushButton("Clip");

    timeLabel = new QLabel();

    groupBoxLayout->addWidget(hoverCoordinatesLabel);
    groupBoxLayout->addWidget(clickCoordinatesLabel);
    groupBoxLayout->addWidget(pointOneLabel);
    groupBoxLayout->addWidget(setPointOneButton);
    groupBoxLayout->addWidget(pointTwoLabel);
    groupBoxLayout->addWidget(setPointTwoButton);
    groupBoxLayout->addWidget(algoLabel);
    groupBoxLayout->addWidget(algoComboBox);
    groupBoxLayout->addWidget(drawButton);
    groupBoxLayout->addWidget(drawAllButton);
    groupBoxLayout->addWidget(clearButton);

    groupBoxLayout->addWidget(clipPointOneLabel);
    groupBoxLayout->addWidget(clipPointTwoLabel);
    groupBoxLayout->addWidget(setClipPointOneButton);
    groupBoxLayout->addWidget(setClipPointTwoButton);
    groupBoxLayout->addWidget(clipButton);

    groupBoxLayout->addWidget(timeLabel);

    groupBox->setLayout(groupBoxLayout);

    globalLayout = new QHBoxLayout();
    globalLayout->addWidget(groupBox);

    setLayout(globalLayout);

    tempX = tempY = x1 = y1 = x2 = y2 = cx1 = cy1 = cx2 = cy2 = 0;
    lines.clear();
    receiveHoverCoordinates(0, 0);
    receiveClickCoordinates(0, 0);
    onSetPointOneButtonClicked();
    onSetPointTwoButtonClicked();
    onSetClipPointOneButtonClicked();
    onSetClipPointTwoButtonClicked();
    receiveTimeTaken(0);

    connect(setPointOneButton, SIGNAL(clicked()), this, SLOT(onSetPointOneButtonClicked()));
    connect(setPointTwoButton, SIGNAL(clicked()), this, SLOT(onSetPointTwoButtonClicked()));
    connect(drawButton, SIGNAL(clicked()), this, SLOT(onDrawButtonClicked()));
    connect(drawAllButton, SIGNAL(clicked()), this, SLOT(onDrawAllButtonClicked()));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(setClipPointOneButton, SIGNAL(clicked()), this, SLOT(onSetClipPointOneButtonClicked()));
    connect(setClipPointTwoButton, SIGNAL(clicked()), this, SLOT(onSetClipPointTwoButtonClicked()));
    connect(clipButton, SIGNAL(clicked()), this, SLOT(onClipButtonClicked()));
}

void LineMenu::receiveHoverCoordinates(int x, int y)
{
    QString text = "Hover Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    hoverCoordinatesLabel->setText(text);
}

void LineMenu::receiveClickCoordinates(int x, int y)
{
    tempX = x; tempY = y;

    QString text = "Click Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    clickCoordinatesLabel->setText(text);
}

void LineMenu::onSetPointOneButtonClicked()
{
    x1 = tempX; y1 = tempY;

    QString text = "Point 1: (" + QString::number(x1) + ", " + QString::number(y1) + ")";
    pointOneLabel->setText(text);
}

void LineMenu::onSetPointTwoButtonClicked()
{
    x2 = tempX; y2 = tempY;

    QString text = "Point 2: (" + QString::number(x2) + ", " + QString::number(y2) + ")";
    pointTwoLabel->setText(text);
}

void LineMenu::onDrawButtonClicked()
{
    std::string algoName = algoComboBox->currentText().toStdString();
    LineAlgorithms::Algorithm algo = LineAlgorithms::stringAlgoMap.at(algoName);

    lines.push_back(std::make_tuple(x1, y1, x2, y2));

    emit sendDrawLineSignal(x1, y1, x2, y2, algo);
}

void LineMenu::onDrawAllButtonClicked()
{
    std::string algoName = algoComboBox->currentText().toStdString();
    LineAlgorithms::Algorithm algo = LineAlgorithms::stringAlgoMap.at(algoName);

    for (std::tuple<int, int, int, int> line : lines)
    {
        int x1, y1, x2, y2;
        std::tie(x1, y1, x2, y2) = line;
        emit sendDrawLineSignal(x1, y1, x2, y2, algo);
    }
}

void LineMenu::onClearButtonClicked()
{
    lines.clear();
}

void LineMenu::onClipButtonClicked()
{
    emit sendClipLinesSignal(lines,
                             std::make_tuple(cx1, cy1, cx2, cy2));
}

void LineMenu::receiveTimeTaken(const long long &time)
{
    QString text = "Time taken: " + QString::number(time) + " µs";
    timeLabel->setText(text);
}

void LineMenu::onSetClipPointOneButtonClicked()
{
    cx1 = tempX; cy1 = tempY;

    QString text = "Clip Point 1: (" + QString::number(cx1) + ", " + QString::number(cy1) + ")";
    clipPointOneLabel->setText(text);
}

void LineMenu::onSetClipPointTwoButtonClicked()
{
    cx2 = tempX; cy2 = tempY;

    QString text = "Clip Point 2: (" + QString::number(cx2) + ", " + QString::number(cy2) + ")";
    clipPointTwoLabel->setText(text);
}

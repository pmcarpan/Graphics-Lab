#include "transformationmenu.h"

#include <QGridLayout>
#include <QVBoxLayout>
#include <QTabWidget>

TransformationMenu::TransformationMenu(QWidget *parent) : QWidget(parent)
{
    drawGroupBox = new QGroupBox("Drawing");
    drawLayout = new QVBoxLayout();

    pushPointButton = new QPushButton("Push Point");
    drawPolygonButton = new QPushButton("Draw Polygon");
    clearPolygonPointsButton = new QPushButton("Clear");

    hoverCoordinatesLabel = new QLabel();
    clickCoordinatesLabel = new QLabel();

    pointOneLabel = new QLabel();
    setPointOneButton = new QPushButton("Set Point 1");
    pointTwoLabel = new QLabel();
    setPointTwoButton = new QPushButton("Set Point 2");

    drawLayout->addWidget(pushPointButton);
    drawLayout->addWidget(drawPolygonButton);
    drawLayout->addWidget(clearPolygonPointsButton);
    drawLayout->addWidget(hoverCoordinatesLabel);
    drawLayout->addWidget(clickCoordinatesLabel);
    drawLayout->addWidget(pointOneLabel); drawLayout->addWidget(setPointOneButton);
    drawLayout->addWidget(pointTwoLabel); drawLayout->addWidget(setPointTwoButton);
    drawGroupBox->setLayout(drawLayout);


    scaleGroupBox = new QGroupBox("Scale");
    scaleLayout = new QVBoxLayout();

    scaleXLabel = new QLabel("Scale X");
    scaleXSpinBox = new QDoubleSpinBox();
    scaleXSpinBox->setSingleStep(0.1); scaleXSpinBox->setRange(0, 10); scaleXSpinBox->setDecimals(1);
    scaleYLabel = new QLabel("Scale Y");
    scaleYSpinBox = new QDoubleSpinBox();
    scaleYSpinBox->setSingleStep(0.1); scaleYSpinBox->setRange(0, 10); scaleYSpinBox->setDecimals(1);

    scaleButton = new QPushButton("Scale");

    scaleLayout->addWidget(scaleXLabel); scaleLayout->addWidget(scaleXSpinBox);
    scaleLayout->addWidget(scaleYLabel); scaleLayout->addWidget(scaleYSpinBox);
    scaleGroupBox->setLayout(scaleLayout);
    scaleLayout->addWidget(scaleButton);


    shearGroupBox = new QGroupBox("Shear");
    shearLayout = new QVBoxLayout();

    shearXLabel = new QLabel("Shear X");
    shearXSpinBox = new QDoubleSpinBox();
    shearXSpinBox->setSingleStep(0.1); shearXSpinBox->setRange(0, 10); shearXSpinBox->setDecimals(1);
    shearYLabel = new QLabel("Shear Y");
    shearYSpinBox = new QDoubleSpinBox();
    shearYSpinBox->setSingleStep(0.1); shearYSpinBox->setRange(0, 10); shearYSpinBox->setDecimals(1);

    shearButton = new QPushButton("Shear");

    shearLayout->addWidget(shearXLabel); shearLayout->addWidget(shearXSpinBox);
    shearLayout->addWidget(shearYLabel); shearLayout->addWidget(shearYSpinBox);
    shearLayout->addWidget(shearButton);
    shearGroupBox->setLayout(shearLayout);


    rotateGroupBox = new QGroupBox("Rotate");
    rotateLayout = new QVBoxLayout();

    rotateDegreesLabel = new QLabel("Degrees");
    rotateDegreesSpinBox = new QDoubleSpinBox();
    rotateDegreesSpinBox->setSingleStep(0.1); rotateDegreesSpinBox->setDecimals(1); rotateDegreesSpinBox->setRange(-360, 360);

    rotateButton = new QPushButton("Rotate ACW (about Point 1)");

    rotateLayout->addWidget(rotateDegreesLabel); rotateLayout->addWidget(rotateDegreesSpinBox);
    rotateLayout->addWidget(rotateButton);
    rotateGroupBox->setLayout(rotateLayout);


    translateGroupBox = new QGroupBox("Translate");
    translateLayout = new QVBoxLayout();

    translateDxLabel = new QLabel("dx");
    translateDxSpinBox = new QDoubleSpinBox();
    translateDxSpinBox->setSingleStep(0.1); translateDxSpinBox->setDecimals(1); translateDxSpinBox->setRange(-100, 100);
    translateDyLabel = new QLabel("dy");
    translateDySpinBox = new QDoubleSpinBox();
    translateDySpinBox->setSingleStep(0.1); translateDySpinBox->setDecimals(1); translateDySpinBox->setRange(-100, 100);

    translateButton = new QPushButton("Translate");

    translateLayout->addWidget(translateDxLabel); translateLayout->addWidget(translateDxSpinBox);
    translateLayout->addWidget(translateDyLabel); translateLayout->addWidget(translateDySpinBox);
    translateLayout->addWidget(translateButton);
    translateGroupBox->setLayout(translateLayout);


    reflectGroupBox = new QGroupBox("Reflect");
    reflectLayout = new QVBoxLayout();

    reflectPointButton = new QPushButton("Reflect about P1");
    reflectLineButton = new QPushButton("Reflect about line P1 -> P2");

    reflectLayout->addWidget(reflectPointButton);
    reflectLayout->addWidget(reflectLineButton);
    reflectGroupBox->setLayout(reflectLayout);


QTabWidget *tabWidget = new QTabWidget();
tabWidget->addTab(scaleGroupBox, "Scale");
tabWidget->addTab(shearGroupBox, "Shear");
tabWidget->addTab(rotateGroupBox, "Rotate");
tabWidget->addTab(translateGroupBox, "Translate");
tabWidget->addTab(reflectGroupBox, "Reflect");

    globalLayout = new QVBoxLayout();
    globalLayout->addWidget(drawGroupBox);
//    globalLayout->addWidget(scaleGroupBox);
//    globalLayout->addWidget(shearGroupBox);
    globalLayout->addWidget(tabWidget);
    setLayout(globalLayout);

    vertices.clear();
    clickX = clickY = x1 = y1 = x2 = y2 = 0;
    receiveHoverCoordinates(0, 0); receiveClickCoordinates(0, 0);
    onSetPointOneButtonClicked(); onSetPointTwoButtonClicked();

    connect(pushPointButton, SIGNAL(clicked()), this, SLOT(onPushPointButtonClicked()));
    connect(clearPolygonPointsButton, SIGNAL(clicked()), this, SLOT(onClearButtonClicked()));
    connect(drawPolygonButton, SIGNAL(clicked()), this, SLOT(onDrawButtonClicked()));
    connect(setPointOneButton, SIGNAL(clicked()), this, SLOT(onSetPointOneButtonClicked()));
    connect(setPointTwoButton, SIGNAL(clicked()), this, SLOT(onSetPointTwoButtonClicked()));
    connect(scaleButton, SIGNAL(clicked()), this, SLOT(onScaleButtonClicked()));
    connect(shearButton, SIGNAL(clicked()), this, SLOT(onShearButtonClicked()));
    connect(rotateButton, SIGNAL(clicked()), this, SLOT(onRotateButtonClicked()));
    connect(translateButton, SIGNAL(clicked()), this, SLOT(onTranslateButtonClicked()));
    connect(reflectPointButton, SIGNAL(clicked()), this, SLOT(onReflectPointButtonClicked()));
    connect(reflectLineButton, SIGNAL(clicked()), this, SLOT(onReflectLineButtonClicked()));
}

void TransformationMenu::receiveHoverCoordinates(int x, int y)
{
    QString text = "Hover Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    hoverCoordinatesLabel->setText(text);
}

void TransformationMenu::receiveClickCoordinates(int x, int y)
{
    clickX = x; clickY = y;

    QString text = "Click Point: (" + QString::number(x) + ", " + QString::number(y) + ")";
    clickCoordinatesLabel->setText(text);
}

void TransformationMenu::onPushPointButtonClicked()
{
    vertices.push_back(std::make_pair(clickX, clickY));
}

void TransformationMenu::onClearButtonClicked()
{
    vertices.clear();
}

void TransformationMenu::onDrawButtonClicked()
{
    if (vertices.size() > 0)
        emit sendDrawPolygonSignal(vertices);
}

void TransformationMenu::onSetPointOneButtonClicked()
{
    x1 = clickX; y1 = clickY;

    QString text = "Point 1: (" + QString::number(x1) + ", " + QString::number(y1) + ")";
    pointOneLabel->setText(text);
}

void TransformationMenu::onSetPointTwoButtonClicked()
{
    x2 = clickX; y2 = clickY;

    QString text = "Point 2: (" + QString::number(x2) + ", " + QString::number(y2) + ")";
    pointTwoLabel->setText(text);
}

void TransformationMenu::onScaleButtonClicked()
{
    double cx = scaleXSpinBox->value(),
           cy = scaleYSpinBox->value();
    emit sendScaleSignal(cx, cy, vertices);
}

void TransformationMenu::onShearButtonClicked()
{
    double cx = shearXSpinBox->value(),
           cy = shearYSpinBox->value();
    emit sendShearSignal(cx, cy, vertices);
}

void TransformationMenu::onRotateButtonClicked()
{
    emit sendRotateSignal(rotateDegreesSpinBox->value(), std::make_pair(x1, y1), vertices);
}

void TransformationMenu::onTranslateButtonClicked()
{
    emit sendTranslateSignal(translateDxSpinBox->value(),
                             translateDySpinBox->value(),
                             vertices);
}

void TransformationMenu::onReflectPointButtonClicked()
{
    emit sendReflectPointSignal(x1, y1, vertices);
}

void TransformationMenu::onReflectLineButtonClicked()
{
    emit sendReflectLineSignal(x1, y1, x2, y2, vertices);
}

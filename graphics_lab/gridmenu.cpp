#include "gridmenu.h"

#include <QVBoxLayout>

GridMenu::GridMenu(QWidget *parent) : QWidget(parent)
{
    groupBox = new QGroupBox("Grid Menu");

    groupBoxLayout = new QVBoxLayout();
    // groupBoxLayout->setSizeConstraint(QLayout::SetFixedSize);

    pixelSizeSpinBox = new QSpinBox();
    pixelSizeSpinBox->setMinimum(1);
    pixelSizeSpinBox->setValue(6);

    gridSizeSpinBox = new QSpinBox();
    gridSizeSpinBox->setMinimum(0);
    gridSizeSpinBox->setValue(30);

    setPixelSizeButton = new QPushButton("Set Pixel Size");

    setGridSizeButton = new QPushButton("Set Grid Size");

    clearGridButton = new QPushButton("Clear Grid");

    groupBoxLayout->addWidget(pixelSizeSpinBox);
    groupBoxLayout->addWidget(setPixelSizeButton);

    groupBoxLayout->addWidget(gridSizeSpinBox);
    groupBoxLayout->addWidget(setGridSizeButton);
    groupBoxLayout->addWidget(clearGridButton);

    groupBox->setLayout(groupBoxLayout);

    globalLayout = new QHBoxLayout();
    globalLayout->addWidget(groupBox);

    setLayout(globalLayout);

    connect(setPixelSizeButton, SIGNAL(clicked()), this, SLOT(onPixelSizeButtonClicked()));
    connect(setGridSizeButton, SIGNAL(clicked()), this, SLOT(onGridSizeButtonClicked()));
    connect(clearGridButton, SIGNAL(clicked()), this, SLOT(onClearGridButtonClicked()));
}

void GridMenu::onPixelSizeButtonClicked()
{
    int size = pixelSizeSpinBox->value();

    emit sendChangePixelSizeSignal(size);
}

void GridMenu::onGridSizeButtonClicked()
{
    int size = gridSizeSpinBox->value();

    emit sendChangeGridSizeSignal(size);
}

void GridMenu::onClearGridButtonClicked()
{
    emit sendClearGridSignal();
}

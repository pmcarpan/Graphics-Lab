#include "menuforlines.h"

#include <QVBoxLayout>

MenuForLines::MenuForLines(QWidget *parent) : QWidget(parent)
{
    globalLayout = new QVBoxLayout();
    globalLayout->setAlignment(Qt::AlignTop);

    gridMenu = new GridMenu();

    menuContainer = new QTabWidget();
    menuContainer->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));

    lineMenu = new LineMenu();
    // lineMenu->setVisible(false);
    circleMenu = new CircleMenu();
    // circleMenu->setVisible(false);
    ellipseMenu = new EllipseMenu();
    // ellipseMenu->setVisible(false);
    polygonMenu = new PolygonMenu();
    transformationMenu = new TransformationMenu();
    bezierMenu = new BezierMenu();

    menuContainer->addTab(lineMenu, "Line");
    menuContainer->addTab(circleMenu, "Circle");
    menuContainer->addTab(ellipseMenu, "Ellipse");
    menuContainer->addTab(polygonMenu, "Polygon");
    menuContainer->addTab(transformationMenu, "Transformation");
    menuContainer->addTab(bezierMenu, "Bezier");

    globalLayout->addWidget(gridMenu);
    // globalLayout->addWidget(lineMenu);
    // globalLayout->addWidget(circleMenu);
    // globalLayout->addWidget(ellipseMenu);
    globalLayout->addWidget(menuContainer);

    setLayout(globalLayout);
    setMinimumWidth(MINIMUM_WIDTH);
}

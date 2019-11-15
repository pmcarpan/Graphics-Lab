#ifndef MENUFORLINES_H
#define MENUFORLINES_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include "gridmenu.h"
#include "linemenu.h"
#include "circlemenu.h"
#include "ellipsemenu.h"
#include "polygonmenu.h"
#include "transformationmenu.h"
#include "beziermenu.h"

class MenuForLines : public QWidget
{
    Q_OBJECT

    friend class Widget;

    const int MINIMUM_WIDTH = 180;

    QLayout *globalLayout;
    GridMenu *gridMenu;
    QTabWidget *menuContainer;
    LineMenu *lineMenu;
    CircleMenu *circleMenu;
    EllipseMenu *ellipseMenu;
    PolygonMenu *polygonMenu;
    TransformationMenu *transformationMenu;
    BezierMenu *bezierMenu;

public:
    explicit MenuForLines(QWidget *parent = nullptr);

public slots:

signals:

};

#endif // MENUFORLINES_H

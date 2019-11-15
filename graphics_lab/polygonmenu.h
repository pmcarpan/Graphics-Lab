#ifndef POLYGONMENU_H
#define POLYGONMENU_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>

#include "gridmodel.h"

class PolygonMenu : public QWidget
{
    Q_OBJECT

    friend class Widget;
    friend class GridModel;

    QLayout *globalLayout, *drawGroupBoxLayout, *fillGroupBoxLayout, *clipGroupBoxLayout;
    QGroupBox *drawGroupBox, *fillGroupBox, *clipGroupBox;
    QLabel *hoverCoordinatesLabel, *clickCoordinatesLabel,
           *clipPointOneLabel, *clipPointTwoLabel, *timeLabel;
    QPushButton *drawButton, *pushPointButton, *clearButton,
                *floodFillButton, *boundaryFillButton, *scanLineFillButton,
                *setClipPointOneButton, *setClipPointTwoButton, *clipButton;
    QTableWidget *currentPoints;

    int tempX, tempY, x1, y1, cx1, cy1, cx2, cy2;
    std::vector<std::pair<int, int>> vertices;

public:
    explicit PolygonMenu(QWidget *parent = nullptr);

public slots:
    void receiveHoverCoordinates(int x, int y);
    void receiveClickCoordinates(int x, int y);
    void onPushPointButtonClicked();
    void onClearButtonClicked();
    void onDrawButtonClicked();

    void onFloodFillButtonClicked();
    void onBoundaryFillButtonClicked();
    void onScanLineFillButtonClicked();

    void onSetClipPointOneButtonClicked();
    void onSetClipPointTwoButtonClicked();
    void onClipButtonClicked();

signals:
    void sendDrawPolygonSignal(std::vector<std::pair<int, int>> vertices);

    void sendFloodFillSignal(int x, int y, QColor oldColor, QColor newColor);
    void sendBoundaryFillSignal(int x, int y, QColor edgeColor, QColor newColor);
    void sendScanLinePolygonFillSignal(std::vector<std::pair<int, int>> vertices);

    void sendClipPolygonSignal(std::vector<std::pair<int, int>> vertices,
                               std::tuple<int, int, int, int> rect);
};

#endif // POLYGONMENU_H

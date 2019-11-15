#ifndef LINEMENU_H
#define LINEMENU_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "linealgorithms.h"

class LineMenu : public QWidget
{
    Q_OBJECT

    friend class Widget;

    QLayout *globalLayout, *groupBoxLayout;
    QGroupBox *groupBox;
    QLabel *hoverCoordinatesLabel, *clickCoordinatesLabel, *pointOneLabel, *pointTwoLabel, *algoLabel,
           *clipPointOneLabel, *clipPointTwoLabel, *timeLabel;
    QPushButton *setPointOneButton, *setPointTwoButton, *drawButton, *drawAllButton,
                *setClipPointOneButton, *setClipPointTwoButton, *clearButton, *clipButton;
    QComboBox *algoComboBox;

    int tempX, tempY, x1, y1, x2, y2, cx1, cy1, cx2, cy2;
    std::vector<std::tuple<int, int, int, int>> lines;

public:
    explicit LineMenu(QWidget *parent = nullptr);

public slots:
    void receiveHoverCoordinates(int x, int y);
    void receiveClickCoordinates(int x, int y);
    void onSetPointOneButtonClicked();
    void onSetPointTwoButtonClicked();
    void onDrawButtonClicked();
    void onDrawAllButtonClicked();
    void onClearButtonClicked();
    void onSetClipPointOneButtonClicked();
    void onSetClipPointTwoButtonClicked();
    void onClipButtonClicked();
    void receiveTimeTaken(const long long &time);

signals:
    void sendDrawLineSignal(int x1, int y1, int x2, int y2,
                            LineAlgorithms::Algorithm algo = LineAlgorithms::Algorithm::BASIC);
    void sendClipLinesSignal(std::vector<std::tuple<int, int, int, int>> lines,
                             std::tuple<int, int, int, int> rect);
};

#endif // LINEMENU_H

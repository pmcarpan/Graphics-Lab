#ifndef CIRCLEMENU_H
#define CIRCLEMENU_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>

#include "circlealgorithms.h"

class CircleMenu : public QWidget
{
    Q_OBJECT

    friend class Widget;

    QLayout *globalLayout, *groupBoxLayout;
    QGroupBox *groupBox;
    QLabel *hoverCoordinatesLabel, *clickCoordinatesLabel, *centrePointLabel, *radiusLabel, *algoLabel, *timeLabel;
    QSpinBox *radiusSpinBox;
    QPushButton *setCentrePointButton, *drawButton;
    QComboBox *algoComboBox;

    int tempX, tempY, x1, y1, r;

public:
    explicit CircleMenu(QWidget *parent = nullptr);

public slots:
    void receiveHoverCoordinates(int x, int y);
    void receiveClickCoordinates(int x, int y);
    void onSetCentrePointButtonClicked();
    void onDrawButtonClicked();
    void receiveTimeTaken(const long long &time);

signals:
    void sendDrawCircleSignal(int x1, int y1, int r,
                              CircleAlgorithms::Algorithm algo = CircleAlgorithms::Algorithm::BASIC);
};

#endif // CIRCLEMENU_H

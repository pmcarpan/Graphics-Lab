#ifndef ELLIPSEMENU_H
#define ELLIPSEMENU_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>

#include "ellipsealgorithms.h"

class EllipseMenu : public QWidget
{
    Q_OBJECT

    friend class Widget;

    QLayout *globalLayout, *groupBoxLayout;
    QGroupBox *groupBox;
    QLabel *hoverCoordinatesLabel, *clickCoordinatesLabel, *centrePointLabel,
           *paramALabel, *paramBLabel, *algoLabel, *timeLabel;
    QSpinBox *paramASpinBox, *paramBSpinBox;
    QPushButton *setCentrePointButton, *drawButton;
    QComboBox *algoComboBox;

    int tempX, tempY, x1, y1, a, b;

public:
    explicit EllipseMenu(QWidget *parent = nullptr);

public slots:
    void receiveHoverCoordinates(int x, int y);
    void receiveClickCoordinates(int x, int y);
    void onSetCentrePointButtonClicked();
    void onDrawButtonClicked();
    void receiveTimeTaken(const long long &time);

signals:
    void sendDrawEllipseSignal(int x1, int y1, int a, int b,
                              EllipseAlgorithms::Algorithm algo = EllipseAlgorithms::Algorithm::BASIC);
};

#endif // ELLIPSEMENU_H

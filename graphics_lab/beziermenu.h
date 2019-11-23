#ifndef BEZIERMENU_H
#define BEZIERMENU_H

#include <QWidget>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>

class BezierMenu : public QWidget
{
    Q_OBJECT
    friend class Widget;

    QLayout *globalLayout, *groupBoxLayout;
    QGroupBox *groupBox;
    QLabel *hoverCoordinatesLabel, *clickCoordinatesLabel;
    QPushButton *pushControlPointButton, *drawBezierFullButton, *drawBezierApproxButton,
                *clearControlPointsButton;

    std::vector<std::pair<int, int>> controlPoints;
    int clickX, clickY;

public:
    explicit BezierMenu(QWidget *parent = nullptr);

public slots:
    void receiveHoverCoordinates(int x, int y);
    void receiveClickCoordinates(int x, int y);
    void onPushControlPointButtonClicked();
    void onClearControlPointsButtonClicked();
    void onDrawBezierFullButtonClicked();
    void onDrawBezierApproxButtonClicked();

signals:
    void sendDrawBezierFullSignal(std::vector<std::pair<int, int>> controlPoints);
    void sendDrawBezierApproxSignal(std::vector<std::pair<int, int>> controlPoints);

};

#endif // BEZIERMENU_H

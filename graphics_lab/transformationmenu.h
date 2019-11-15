#ifndef TRANSFORMATIONMENU_H
#define TRANSFORMATIONMENU_H

#include <QWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QDoubleSpinBox>

class TransformationMenu : public QWidget
{
    Q_OBJECT
    friend class Widget;

    QLayout *globalLayout, *drawLayout, *scaleLayout, *shearLayout, *rotateLayout, *translateLayout, *reflectLayout;
    QGroupBox *drawGroupBox, *scaleGroupBox, *shearGroupBox, *rotateGroupBox, *translateGroupBox, *reflectGroupBox;
    QPushButton *pushPointButton, *drawPolygonButton, *clearPolygonPointsButton, *setPointOneButton, *setPointTwoButton,
                *scaleButton,
                *shearButton,
                *rotateButton,
                *translateButton,
                *reflectPointButton, *reflectLineButton;
    QLabel *hoverCoordinatesLabel, *clickCoordinatesLabel, *pointOneLabel, *pointTwoLabel,
           *scaleXLabel, *scaleYLabel,
           *shearXLabel, *shearYLabel,
           *rotateDegreesLabel,
           *translateDxLabel, *translateDyLabel;
    QDoubleSpinBox *scaleXSpinBox, *scaleYSpinBox, *shearXSpinBox, *shearYSpinBox,
                   *rotateDegreesSpinBox,
                   *translateDxSpinBox, *translateDySpinBox;

    int clickX, clickY, x1, y1, x2, y2;
    std::vector<std::pair<int, int>> vertices;

public:
    explicit TransformationMenu(QWidget *parent = nullptr);

public slots:
    void receiveHoverCoordinates(int x, int y);
    void receiveClickCoordinates(int x, int y);
    void onPushPointButtonClicked();
    void onClearButtonClicked();
    void onDrawButtonClicked();
    void onSetPointOneButtonClicked();
    void onSetPointTwoButtonClicked();

    void onScaleButtonClicked();
    void onShearButtonClicked();
    void onRotateButtonClicked();
    void onTranslateButtonClicked();
    void onReflectPointButtonClicked();
    void onReflectLineButtonClicked();

signals:
    void sendDrawPolygonSignal(std::vector<std::pair<int, int>> vertices);

    void sendScaleSignal(double cx, double cy, std::vector<std::pair<int, int>> vertices);
    void sendShearSignal(double cx, double cy, std::vector<std::pair<int, int>> vertices);
    void sendRotateSignal(double degrees, std::pair<int, int> about, std::vector<std::pair<int, int>> vertices);
    void sendTranslateSignal(double dx, double dy, std::vector<std::pair<int, int>> vertices);
    void sendReflectPointSignal(int x1, int y1, std::vector<std::pair<int, int>> vertices);
    void sendReflectLineSignal(int x1, int y1, int x2, int y2, std::vector<std::pair<int, int>> vertices);
};

#endif // TRANSFORMATIONMENU_H

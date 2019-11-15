#ifndef GRIDMENU_H
#define GRIDMENU_H

#include <QWidget>
#include <QGroupBox>
#include <QSpinBox>
#include <QPushButton>

class GridMenu : public QWidget
{
    Q_OBJECT

    friend class Widget;

    QLayout *globalLayout, *groupBoxLayout;
    QGroupBox *groupBox;
    QSpinBox *pixelSizeSpinBox, *gridSizeSpinBox;
    QPushButton *setPixelSizeButton, *setGridSizeButton, *clearGridButton;

public:
    explicit GridMenu(QWidget *parent = nullptr);

public slots:
    void onPixelSizeButtonClicked();
    void onGridSizeButtonClicked();
    void onClearGridButtonClicked();

signals:
    void sendChangePixelSizeSignal(int size);
    void sendChangeGridSizeSignal(int size);
    void sendClearGridSignal();

};

#endif // GRIDMENU_H

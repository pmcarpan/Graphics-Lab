#ifndef GRIDTABLEVIEW_H
#define GRIDTABLEVIEW_H

#include <QTableView>
#include <QMouseEvent>
#include <QHeaderView>

class GridTableView : public QTableView
{
    Q_OBJECT

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

public:
    GridTableView(QWidget *parent = nullptr);
    void setPixelSize(const int size);

public slots:
    void receiveChangePixelSizeSignal(int size);
    void receiveClickIndex(const QModelIndex& index);

signals:
    void sendHoverIndex(const QModelIndex &index);
    void sendClickIndex(const QModelIndex &index);
};

#endif // GRIDTABLEVIEW_H

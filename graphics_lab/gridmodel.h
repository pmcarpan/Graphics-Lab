#ifndef GRIDMODEL_H
#define GRIDMODEL_H

#include <QAbstractTableModel>
#include <QColor>
#include <QMouseEvent>

class GridModel : public QAbstractTableModel
{
    Q_OBJECT

    friend class Widget;

    int rows, cols;
    const QColor ***cellColors;

    const QColor DEFAULT_CELL_COLOR = QColor(Qt::red),
                 DRAWN_CELL_COLOR = QColor(Qt::blue),
                 AXIS_CELL_COLOR = QColor(Qt::gray);

private:
    void setDefaultColors();
    void allocateMemoryForCells();

public:
    GridModel(QObject *parent = nullptr);
    GridModel(int numRows, int numColumns, QObject *parent = nullptr);
    ~GridModel() override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QColor getColor(int x, int y);
    int getRows();
    int getCols();

    void recreate(const int numRows, const int numColumns);
    void setPixel(const int x, const int y);
    void clear();

public slots:
    void receiveHoverIndex(const QModelIndex &index);
    void receiveClickIndex(const QModelIndex &index);

    void receiveChangeGridSizeSignal(int size);

    void receiveClearGridSignal();

    void receiveSetPixelSignal(const int &x, const int &y);

signals:
    void sendHoverCoordinates(int x, int y);
    void sendClickCoordinates(int x, int y);
};

#endif // GRIDMODEL_H

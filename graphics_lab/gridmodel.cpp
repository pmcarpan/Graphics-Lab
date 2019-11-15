#include "gridmodel.h"

GridModel::GridModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    rows = cols = 21;
    cellColors = nullptr;

    allocateMemoryForCells();
    setDefaultColors();

}

GridModel::GridModel(int numRows, int numColumns, QObject *parent) :
    QAbstractTableModel(parent)
{
    rows = numRows;
    cols = numColumns;
    cellColors = nullptr;

    allocateMemoryForCells();
    setDefaultColors();
}

GridModel::~GridModel()
{
    delete cellColors;
}

void GridModel::allocateMemoryForCells()
{
    unsigned int rows_, cols_;
    rows_ = cols_ = unsigned(rows);

    delete cellColors; // delete old object if it exists
    cellColors = new const QColor**[rows_];

    for (int i = 0; i < rows; i++)
        cellColors[i] = new const QColor*[cols_];
}

void GridModel::setDefaultColors()
{
    unsigned int rows_, cols_;
    rows_ = cols_ = unsigned(rows);

    unsigned int axRowIdx, axColIdx;
    axRowIdx = axColIdx = rows_ / 2;

    for (unsigned int i = 0; i < rows_; i++)
    {
        for (unsigned int j = 0; j < cols_; j++)
        {
            if (i == axRowIdx || j == axColIdx)
                cellColors[i][j] = &AXIS_CELL_COLOR;
            else
                cellColors[i][j] = &DEFAULT_CELL_COLOR;
        }
    }
}

void GridModel::clear()
{
    setDefaultColors();
    emit dataChanged(index(0, 0), index(rows, cols), QVector<int>({Qt::BackgroundRole}));
}

int GridModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return rows;
}

int GridModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return cols;
}

QVariant GridModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::BackgroundRole)
        return *cellColors[index.row()][index.column()];

    return QVariant();
}

void GridModel::setPixel(const int x, const int y)
{
    // cartesian to actual co-ordinates
    int x_ = x + cols/2, y_ = -y + rows/2;

    if (x_ < 0 || x_ >= cols || y_ < 0 || y_ >= rows) return;

    cellColors[y_][x_] = &DRAWN_CELL_COLOR;
    emit dataChanged(index(y_, x_), index(y_, x_), QVector<int>({Qt::BackgroundRole}));
}

void GridModel::recreate(const int numRows, const int numColumns)
{
    if (numRows < 1 || numColumns < 1)
        return;

    beginResetModel();

    rows = numRows;
    cols = numColumns;

    allocateMemoryForCells();
    setDefaultColors();

    endResetModel();
}

void GridModel::receiveHoverIndex(const QModelIndex &index)
{
    int x = 0, y = 0;
    x = index.column() - cols/2;
    y = -index.row() + rows/2;

    emit sendHoverCoordinates(x, y);
}

void GridModel::receiveClickIndex(const QModelIndex &index)
{
    int x = 0, y = 0;
    x = index.column() - cols/2;
    y = -index.row() + rows/2;
    // setPixel(x, y);

    emit sendClickCoordinates(x, y);
}

void GridModel::receiveChangeGridSizeSignal(int size)
{
    // size is max x (and y) co-ordinate
    int num = size * 2 + 1; // numbers of rows (= number of columns)

    recreate(num, num);
}

void GridModel::receiveClearGridSignal()
{
    clear();
}

void GridModel::receiveSetPixelSignal(const int &x, const int &y)
{
    setPixel(x, y);
}

QColor GridModel::getColor(int x, int y)
{
    x = x + cols/2;
    y = -y + rows/2;
    return QColor(*cellColors[y][x]);
}

int GridModel::getRows()
{
    return rows;
}

int GridModel::getCols()
{
    return cols;
}

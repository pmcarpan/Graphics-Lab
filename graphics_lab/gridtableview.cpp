#include "gridtableview.h"

#include <iostream>

GridTableView::GridTableView(QWidget *parent) :
    QTableView(parent)
{
    setMouseTracking(true);

    // allow headers to shrink as much as possible
    horizontalHeader()->setMinimumSectionSize(1);
    verticalHeader()->setMinimumSectionSize(1);

    horizontalHeader()->hide();
    verticalHeader()->hide();

    setPixelSize(8);

    // connect(this, SIGNAL(clicked(const QModelIndex &)), this, SLOT(receiveClickIndex(const QModelIndex &)));
}

void GridTableView::mouseMoveEvent(QMouseEvent *event)
{
    QModelIndex index = indexAt(event->pos());

    // send index positions only when valid
    if (!index.isValid())
        return;

    emit sendHoverIndex(index);
}

void GridTableView::mousePressEvent(QMouseEvent *event)
{
    QModelIndex index = indexAt(event->pos());

    // send index positions only when valid
    if (!index.isValid())
        return;

    if (event->button() == Qt::LeftButton)
         receiveClickIndex(index);
}

void GridTableView::setPixelSize(const int size)
{
    if (size < 1)
        return;

    horizontalHeader()->setDefaultSectionSize(size);
    verticalHeader()->setDefaultSectionSize(size);
}

void GridTableView::receiveChangePixelSizeSignal(int size)
{
    setPixelSize(size);
}

void GridTableView::receiveClickIndex(const QModelIndex &index)
{
    if (!index.isValid())
        return;

    emit sendClickIndex(index);
}

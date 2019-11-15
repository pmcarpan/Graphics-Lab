#include "drawsignalemitter.h"

DrawSignalEmitter::DrawSignalEmitter(QObject *parent) : QObject(parent)
{

}

void DrawSignalEmitter::sendDraw(const int &x, const int &y) const
{
    emit sendDrawSignal(x, y);
}

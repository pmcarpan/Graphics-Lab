#include "polygonemitter.h"

PolygonEmitter::PolygonEmitter(QObject *parent) : QObject(parent)
{

}

void PolygonEmitter::sendPoly(std::vector<std::pair<int, int>> vertices)
{
    emit sendPolySignal(vertices);
}

#include "durationemitter.h"

DurationEmitter::DurationEmitter(QObject *parent) : QObject(parent)
{

}

void DurationEmitter::sendTime(const long long &time) const
{
    emit sendTimeSignal(time);
}

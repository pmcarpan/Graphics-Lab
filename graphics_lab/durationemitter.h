#ifndef DURATIONEMITTER_H
#define DURATIONEMITTER_H

#include <QObject>

class DurationEmitter : public QObject
{
    Q_OBJECT
public:
    explicit DurationEmitter(QObject *parent = nullptr);
    void sendTime(const long long &time) const;

public slots:

signals:
    double sendTimeSignal(const long long &time) const;
};

#endif // DURATIONEMITTER_H

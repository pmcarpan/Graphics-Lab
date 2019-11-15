#ifndef DRAWSIGNALEMITTER_H
#define DRAWSIGNALEMITTER_H

#include <QObject>

class DrawSignalEmitter : public QObject
{
    Q_OBJECT
public:
    explicit DrawSignalEmitter(QObject *parent = nullptr);
    void sendDraw(const int &x, const int &y) const;

public slots:

signals:
    void sendDrawSignal(const int &x, const int &y) const;
};

#endif // DRAWSIGNALEMITTER_H

#ifndef POLYGONEMITTER_H
#define POLYGONEMITTER_H

#include <QObject>

class PolygonEmitter : public QObject
{
    Q_OBJECT
public:
    explicit PolygonEmitter(QObject *parent = nullptr);
    void sendPoly(std::vector<std::pair<int, int>> vertices);

signals:
    void sendPolySignal(const std::vector<std::pair<int, int>> vertices);

public slots:
};

#endif // POLYGONEMITTER_H

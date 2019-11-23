#ifndef TRANSFORMATIONALGORITHMS_H
#define TRANSFORMATIONALGORITHMS_H

#include "gridmodel.h"
#include "polygonemitter.h"

class TransformationAlgorithms
{
public:
    static constexpr double PRECISION = 1E-6;

    static PolygonEmitter *polygonEmitter;

private:
    TransformationAlgorithms();
public:
    static void scale(GridModel *grid, double cx, double cy,
                      std::vector<std::pair<int, int>> vertices);
    static void shear(GridModel *grid, double cx, double cy,
                      std::vector<std::pair<int, int>> vertices);
    static void rotate(GridModel *grid, double degrees, std::pair<int, int> about,
                       std::vector<std::pair<int, int>> vertices);
    static void reflect(GridModel *grid, int x1, int y1,
                        std::vector<std::pair<int, int>> vertices);
    static void reflect(GridModel *grid, int x1, int y1, int x2, int y2,
                        std::vector<std::pair<int, int>> vertices);
    static void translate(GridModel *grid, double dx, double dy,
                          std::vector<std::pair<int, int>> vertices);

private:
    static std::array<double, 3> convVertexToArray(std::pair<int, int> vertex);
    static std::array<std::array<double, 3>, 3> getScaleMatrix(double cx, double cy);
    static std::array<std::array<double, 3>, 3> getShearMatrix(double cx, double cy);
    static std::array<std::array<double, 3>, 3> getRotateMatrix(double degrees, std::pair<int, int> about);
    static std::array<std::array<double, 3>, 3> getTranslationMatrix(double dx, double dy);

    static std::array<std::array<double, 3>, 3> multiplyMatrices(
            std::array<std::array<double, 3>, 3> A,
            std::array<std::array<double, 3>, 3> B);
    static std::array<double, 3> multiplyMatrixWithVector(
            std::array<std::array<double, 3>, 3> A,
            std::array<double, 3> v);
};

#endif // TRANSFORMATIONALGORITHMS_H

#include "transformationalgorithms.h"

#include <array>
#include <iostream>
#include <QtMath>

#include "polygonalgorithms.h"
#include "linealgorithms.h"

PolygonEmitter* TransformationAlgorithms::polygonEmitter = new PolygonEmitter();

TransformationAlgorithms::TransformationAlgorithms()
{
    // empty constructor, do not instantiate this class
}


void TransformationAlgorithms::scale(GridModel *grid, double cx, double cy,
                  std::vector<std::pair<int, int>> vertices)
{
    std::vector<std::pair<int, int>> final;
    std::array<std::array<double, 3>, 3> S = getScaleMatrix(cx, cy);
    for (std::pair<int, int> vertex : vertices) {
        std::array<double, 3> v = convVertexToArray(vertex);
        std::array<double, 3> transformed = multiplyMatrixWithVector(S, v);

        assert(std::fabs(transformed[2] - 1) < PRECISION);

        final.push_back(
          std::make_pair(int(std::round(transformed[0])), int(std::round(transformed[1])))
        );
    }

    grid->clear();
    PolygonAlgorithms::drawPolygon(grid, final);
    polygonEmitter->sendPoly(final);
}

void TransformationAlgorithms::shear(GridModel *grid, double cx, double cy,
                  std::vector<std::pair<int, int>> vertices)
{
    std::vector<std::pair<int, int>> final;
    std::array<std::array<double, 3>, 3> S = getShearMatrix(cx, cy);
    for (std::pair<int, int> vertex : vertices) {
        std::array<double, 3> v = convVertexToArray(vertex);
        std::array<double, 3> transformed = multiplyMatrixWithVector(S, v);

        assert(std::fabs(transformed[2] - 1) < PRECISION);

        final.push_back(
          std::make_pair(int(std::round(transformed[0])), int(std::round(transformed[1])))
        );
    }

    grid->clear();
    PolygonAlgorithms::drawPolygon(grid, final);
    polygonEmitter->sendPoly(final);
}

void TransformationAlgorithms::rotate(GridModel *grid, double degrees, std::pair<int, int> about,
                   std::vector<std::pair<int, int>> vertices)
{
    std::vector<std::pair<int, int>> final;
    std::array<std::array<double, 3>, 3> S = getRotateMatrix(degrees, about);
    for (std::pair<int, int> vertex : vertices) {
        std::array<double, 3> v = convVertexToArray(vertex);
        std::array<double, 3> transformed = multiplyMatrixWithVector(S, v);

        assert(std::fabs(transformed[2] - 1) < PRECISION);

        final.push_back(
          std::make_pair(int(std::round(transformed[0])), int(std::round(transformed[1])))
        );
    }

    grid->clear();
    PolygonAlgorithms::drawPolygon(grid, final);
    polygonEmitter->sendPoly(final);
}

void TransformationAlgorithms::reflect(GridModel *grid, int x1, int y1, std::vector<std::pair<int, int> > vertices)
{
    std::vector<std::pair<int, int>> final;
    std::array<std::array<double, 3>, 3>
            T = getTranslationMatrix(-x1, -y1), T_dash = getTranslationMatrix(x1, y1);

    for (std::pair<int, int> vertex : vertices) {
        std::array<double, 3> v = convVertexToArray(vertex);
        std::array<double, 3> transformed = multiplyMatrixWithVector(T, v);
        transformed[0] = -transformed[0];
        transformed[1] = -transformed[1];
        transformed = multiplyMatrixWithVector(T_dash, transformed);

        assert(std::fabs(transformed[2] - 1) < PRECISION);

        // std::cout << transformed[0] << " " << transformed[1] << "\n";

        final.push_back(
          std::make_pair(int(std::round(transformed[0])), int(std::round(transformed[1])))
        );
    }

    grid->clear();
    PolygonAlgorithms::drawPolygon(grid, final);
    grid->setPixel(x1, y1);
    polygonEmitter->sendPoly(final);
}

void TransformationAlgorithms::reflect(GridModel *grid, int x1, int y1, int x2, int y2,
                    std::vector<std::pair<int, int>> vertices)
{
    if (x1 == x2 && y1 == y2) // decomposes to reflect about point
    {
        reflect(grid, x1, y1, vertices);
        return;
    }

    std::vector<std::pair<int, int>> final;

    double m = (y2 - y1)/(x2 - x1), c = y1 - m * x1, x_intercept = -c / m;
    double degrees = std::atan(m) * 180 / M_PI;
    if (x2 < x1) degrees += 180; // correction for mistakes when delta x < 0

    // std::cout << "deg " << degrees << " m " << m << " c " << c << " X_int " << x_intercept << "\n";

    std::pair<int, int> origin = std::make_pair(0, 0);
    std::array<std::array<double, 3>, 3>
            T = getTranslationMatrix(-x_intercept, 0), T_dash = getTranslationMatrix(x_intercept, 0),
            R = getRotateMatrix(-degrees, origin), R_dash = getRotateMatrix(degrees, origin),
            M = multiplyMatrices(R, T), M_dash = multiplyMatrices(T_dash, R_dash);

    for (std::pair<int, int> vertex : vertices) {
        std::array<double, 3> v = convVertexToArray(vertex);
        std::array<double, 3> transformed = multiplyMatrixWithVector(M, v);
        transformed[1] = -transformed[1];
        transformed = multiplyMatrixWithVector(M_dash, transformed);

        assert(std::fabs(transformed[2] - 1) < PRECISION);

        // std::cout << transformed[0] << " " << transformed[1] << "\n";

        final.push_back(
          std::make_pair(int(std::round(transformed[0])), int(std::round(transformed[1])))
        );
    }

    grid->clear();
    LineAlgorithms::drawLine(grid, x1, y1, x2, y2);
    PolygonAlgorithms::drawPolygon(grid, final);
    polygonEmitter->sendPoly(final);
}


void TransformationAlgorithms::translate(GridModel *grid, double dx, double dy,
                                         std::vector<std::pair<int, int> > vertices)
{
    std::vector<std::pair<int, int>> final;
    std::array<std::array<double, 3>, 3> T = getTranslationMatrix(dx, dy);
    for (std::pair<int, int> vertex : vertices) {
        std::array<double, 3> v = convVertexToArray(vertex);
        std::array<double, 3> transformed = multiplyMatrixWithVector(T, v);

        assert(std::fabs(transformed[2] - 1) < PRECISION);

        final.push_back(
          std::make_pair(int(std::round(transformed[0])), int(std::round(transformed[1])))
        );
    }

    grid->clear();
    PolygonAlgorithms::drawPolygon(grid, final);
    polygonEmitter->sendPoly(final);
}


std::array<double, 3> TransformationAlgorithms::convVertexToArray(std::pair<int, int> vertex)
{
    std::array<double, 3> v;
    v[0] = vertex.first; v[1] = vertex.second; v[2] = 1;
    return v;
}

std::array<std::array<double, 3>, 3> TransformationAlgorithms::getScaleMatrix(double cx, double cy)
{
    std::array<std::array<double, 3>, 3> M{{ {{cx, 0, 0}}, {{0, cy, 0}}, {{0, 0, 1}} }};
    return M;
}

std::array<std::array<double, 3>, 3> TransformationAlgorithms::getShearMatrix(double cx, double cy)
{
    std::array<std::array<double, 3>, 3> M{{ {{1, cx, 0}}, {{cy, 1, 0}}, {{0, 0, 1}} }};
    return M;
}

std::array<std::array<double, 3>, 3> TransformationAlgorithms::getRotateMatrix(double degrees, std::pair<int, int> about)
{
    double rad = degrees * M_PI / 180, s = std::sin(rad), c = std::cos(rad);

    std::array<std::array<double, 3>, 3>
            T = getTranslationMatrix(-about.first, -about.second),
            R = {{ {{c, -s, 0}}, {{s, c, 0}}, {{0, 0, 1}} }},
            T_dash = getTranslationMatrix(about.first, about.second),
            M = multiplyMatrices(T_dash, multiplyMatrices(R, T));
    return M;
}

std::array<std::array<double, 3>, 3> TransformationAlgorithms::getTranslationMatrix(double dx, double dy)
{
    std::array<std::array<double, 3>, 3> M{{ {{1, 0, dx}}, {{0, 1, dy}}, {{0, 0, 1}} }};
    return M;
}

std::array<std::array<double, 3>, 3> TransformationAlgorithms::multiplyMatrices(
        std::array<std::array<double, 3>, 3> A,
        std::array<std::array<double, 3>, 3> B)
{
    std::array<std::array<double, 3>, 3> C;
    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (unsigned int k = 0; k < 3; k++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

std::array<double, 3> TransformationAlgorithms::multiplyMatrixWithVector(
        std::array<std::array<double, 3>, 3> A,
        std::array<double, 3> v)
{
    std::array<double, 3> u;
    for (unsigned int i = 0; i < 3; i++) {
        u[i] = 0;
        for (unsigned int j = 0; j < 3; j++) {
            u[i] += (A[i][j] * v[j]);
        }
    }
    return  u;
}

#include "bezieralgorithms.h"



BezierAlgorithms::BezierAlgorithms()
{
    // empty constructor, do not instantiate this class
}

template <typename T1, typename T2>
std::pair<T2, T2> operator *(T1 x, const std::pair<T2, T2>& y)
{
    return std::make_pair(x * y.first, x * y.second);
}

template <typename T1, typename T2>
std::pair<T2, T2> operator +(const std::pair<T1, T1>& x, const std::pair<T2, T2>& y)
{
    return std::make_pair(x.first + y.first, x.second + y.second);
}

void BezierAlgorithms::drawBezierFull(GridModel *grid, std::vector<std::pair<int, int> > controlPoints)
{
    grid->clear();
    for (std::pair<int, int> pt : controlPoints)
        grid->setPixel(pt.first, pt.second);

    int n = int(controlPoints.size()) - 1;

    std::vector<int> combs;
    int curr = 1;
    for (int i = 0; i <= n; i++)
    {
        combs.push_back(curr);
        curr = curr * (n - i) / (i + 1);
    }

    double increment = 0.01;
    for (double u = 0; u <= 1; u += increment)
    {
        std::pair<double, double> p = std::make_pair(0, 0);
        double non_comb_part = std::pow(1-u, n);
        for (unsigned int i = 0; i <= unsigned(n); i++)
        {
            p = p + (combs[i] * non_comb_part) *
                        std::make_pair(double(controlPoints[i].first), double(controlPoints[i].second));
            non_comb_part = non_comb_part * u / (1-u);
        }

        grid->setPixel(int(std::round(p.first)), int(std::round(p.second)));
    }
}

void BezierAlgorithms::drawBezierApprox(GridModel *grid, std::vector<std::pair<int, int> > controlPoints)
{
    assert(controlPoints.size() >= 4);     // atleast 4 control pts
    assert(controlPoints.size() % 3 == 1); // must allow cubic approximation

    grid->clear();
    for (std::pair<int, int> pt : controlPoints)
        grid->setPixel(pt.first, pt.second);

    for (auto it = controlPoints.begin(); it != controlPoints.end() - 1; it += 3)
    {
//        std::cout << "1\n";

        drawBezierFull(grid, std::vector<std::pair<int, int>>(it, it + 4));
    }
}


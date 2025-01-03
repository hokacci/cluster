#pragma once

#include <vector>
#include <cmath>


// 2次元の点を表す構造体
struct Point2D
{
    double x = 0;
    double y = 0;
};

// 2点間の距離を計算する
double distance(Point2D a, Point2D b);

// 重心を計算する
Point2D center(std::vector<Point2D> points);

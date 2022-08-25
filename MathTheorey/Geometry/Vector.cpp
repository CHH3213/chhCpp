//
// Created by CHH3213 on 2022/8/25.
//
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
/*
 * 向量的相关运算
 */
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(x / a, y / a); }

    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};


typedef Point Vector;
//叉积
double cross(Vector a, Vector b) {
    return a.x*b.y - a.y*b.x;
}
//内积
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

//向量的模
double vector_norm(Vector a)
{
    return sqrt(dot(a,a));
}

//计算两向量夹角
double theta(Vector a,Vector b)
{
    return acos(dot(a,b) / vector_norm(a) / vector_norm(b));
}

//计算两向量构成的平行四边形有向面积
double area(Vector a,Vector b)
{
    return cross(a,b);
}
//求向量A顺时针旋转角度 θ 后的向量
Vector rotate(Vector a,double theta)
{
    return Vector(a.x * cos(theta) + a.y * sin(theta) , -a.x * sin(theta) + a.y * cos(theta));
}



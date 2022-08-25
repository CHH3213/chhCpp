//
// Created by CHH3213 on 2022/8/25.
//
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
/*
 * 点与线的相关计算
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





//判断点是否在直线上,是返回true
bool on_line(Point p,Point a,Point b)
{
    Vector v = b - a,u = p - a;
    if(cross(v,u) == 0)
        return true;
    else
        return false;
}

//判断点是否在线段上
bool on_segment(Point p,Point a,Point b)
{
    Vector v = b - a,u = p - a,w = p - b;
    return (cross(v,u) == 0 && dot(u,w) <= 0);
}

//点到直线的距离
double distance_line(Point p,Point a,Point b)
{
    //平行四边形面积/底
    Vector v1 = b - a,v2 = p - a;
    return fabs(cross(v1,v2) / vector_norm(v1));
}

//点到线段的距离
double distance_segment(Point p,Point a,Point b)
{
    if(a == b)
        return vector_norm(p-a);
    Vector v1 = b - a,v2 = p - a,v3 = p - b;
    if(dot(v1,v2) < 0)//点在线段左端点左侧区域
        return vector_norm(v2);
    if(dot(v1,v3) > 0)//点在线段右端点右侧区域
        return vector_norm(v3);
    return  fabs(cross(v1,v2) / vector_norm(v1));//点在线段左右端点之间区域
}

//点在直线上的投影
Point projection(Point p,Point a,Point b)
{
    Vector v = b - a,u = p - a;
    return a + v * (dot(v,u) / dot(v,v));
}

//判断线段是否相交
bool segment_intersection(Point a1,Point a2,Point b1,Point b2)
{
    double c1 = cross(a2 - a1,b1 - a1), c2 = cross(a2 - a1,b2 - a1);
    double c3 = cross(b2 - b1,a2 - b1), c4 = cross(b2 - b1,a1 - b1);
    return (c1 * c2 <= 0 && c3 * c4 <= 0);
}

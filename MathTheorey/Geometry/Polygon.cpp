//
// Created by CHH3213 on 2022/8/25.
//
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
/*
 * 多边形的计算
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

//三角形的面积
//求三角形面积分为两种情况，若给的是顶点坐标，就用叉积法来求，若给的是三边长，就用海伦公式来求。
double triangle_area(Point a,Point b,Point c){
    Vector v = b-a;
    Vector w=c-a;
    return cross(v,w)/2;
}
double triangle_area(double a,double b,double c){
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

//求多边形面积的方法有很多，这里给两个方法
//方法一：枚举每个点，这里取原点o作为定点方便计算
double polygon_area(Point p[],int n)
{
    double s = 0;
    for(int i = 1;i < n;i++)
        s += cross(p[i],p[i-1]);	//cross是计算叉积
    s += cross(p[n-1],p[0]);
    return s / 2;
}

////方法二：枚举多边形的每条边
//double polygon_area(Point p[],int n)
//{
//    double s = 0;
//    for(int i = 1;i < n-1;i++)
//        s += cross(p[i] - p[0],p[i+1] - p[i]);
//    return s / 2;
//}


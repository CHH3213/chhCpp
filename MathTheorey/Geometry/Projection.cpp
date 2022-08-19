//
// Created by CHH3213 on 2022/8/12.
//
#include <iostream>
using namespace std;
#include <math.h>

#define EPS 1e-9
#define equals(a, b) (fabs((a) - (b)) < EPS)
class Point {//Point类，点
public:
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

    Point operator + (Point p) { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) { return Point(x - p.x, y - p.y); }
    Point operator * (double a) { return Point(a * x, a * y); }
    Point operator / (double a) { return Point(x / a, y / a); }

    double abs() { return sqrt(norm()); }
    double norm() { return sqrt(x * x + y * y); }

    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

typedef Point Vector;//Vector类，向量

struct Segment{//Segment 线段
    Point p1, p2;
};
double dot(Vector a, Vector b) {//内积
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {//外积
    return a.x*b.y - a.y*b.x;
}


Point project(Segment s, Point p) {//投影 对于给定的三个点p1、p2、p，从点p向通过
//p1、p2的直线引一条垂线，求垂足x的坐标。（点p在直线p1p2上的投影）
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r/base.norm();
}

int main(){
    Point p1, p2, p;
    cin>>p1.x>>p1.y>>p2.x>>p2.y;

    Segment s;
    s.p1 = p1;
    s.p2 = p2;

    int q;
    cin>>q;

    while(q--){
        cin>>p.x>>p.y;
        p = project(s, p);
        printf("%.10f %.10f\n", p.x, p.y);
    }
}

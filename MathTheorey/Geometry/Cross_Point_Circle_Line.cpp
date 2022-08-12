//
// Created by CHH3213 on 2022/8/12.
//
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<assert.h>
using namespace std;

#define EPS (1e-10)
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
    double norm() { return x * x + y * y; }

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

typedef Segment Line;

class Circle {//Circle 圆
public:
    Point c;
    double r;
    Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
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
    return s.p1 + base * r;
}

double getDistanceLP(Line l, Point p) {//直线l和点p的距离
    return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs() );
}

bool intersect(Circle c, Line l) {
    if(getDistanceLP(l, c.c) > c.r) {
        return false;
    } else {
        return true;
    }
}
Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

pair<Point, Point> getCrossPoints(Circle c, Line l) {
    assert(intersect(c, l));
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();
    double base = sqrt(c.r * c.r - (pr - c.c).norm() );
    return make_pair(pr + e * base, pr - e * base);
}

int main(){
    Circle c;
    cin>>c.c.x>>c.c.y>>c.r;

    int q;
    cin>>q;

    Line l;
    pair<Point, Point> p;

    while(q--){
        cin>>l.p1.x>>l.p1.y>>l.p2.x>>l.p2.y;
        p = getCrossPoints(c, l);
        if(p.first.x < p.second.x || (p.first.x == p.second.x && p.first.y <= p.second.y) ) {
            printf("%.6f %.6f %.6f %.6f\n", p.first.x, p.first.y, p.second.x, p.second.y);
        } else {
            printf("%.6f %.6f %.6f %.6f\n", p.second.x, p.second.y, p.first.x, p.first.y);
        }
    }
}

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

typedef Segment Line;//Line 直线

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

double getDistanceLP(Line l, Point p) {//直线l和点p的距离
    return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs() );
}

double getDistanceSP(Segment s, Point p) {//线段s与点p的距离
    if( dot(s.p2 - s.p1, p - s.p1) < 0.0 ) return (p - s.p1).abs();
    if( dot(s.p1 - s.p2, p - s.p2) < 0.0 ) return (p - s.p2).abs();
    return getDistanceLP(s, p);
}

bool intersect(Circle c1, Circle c2) {//判断圆c1和圆c2是否相交
    if((c1.c - c2.c).abs() <= c1.r + c2.r) {
        return true;
    } else {
        return false;
    }
}

double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    assert(intersect(c1, c2));
    double d = (c1.c - c2.c).abs();
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

int main(){
    Circle c1, c2;
    cin>>c1.c.x>>c1.c.y>>c1.r>>c2.c.x>>c2.c.y>>c2.r;

    pair<Point, Point> p;

    p = getCrossPoints(c1, c2);

    if(p.first.x < p.second.x || (p.first.x == p.second.x && p.first.y <= p.second.y) ) {
        printf("%.7f %.7f %.7f %.7f\n", p.first.x, p.first.y, p.second.x, p.second.y);
    } else {
        printf("%.7f %.7f %.7f %.7f\n", p.second.x, p.second.y, p.first.x, p.first.y);
    }
}

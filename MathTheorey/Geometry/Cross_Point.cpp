//
// Created by CHH3213 on 2022/8/12.
//
#include<stdio.h>
#include<iostream>
#include<cmath>
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
double dot(Vector a, Vector b) {//内积
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {//外积
    return a.x*b.y - a.y*b.x;
}

Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = abs(cross(base, s1.p1 - s2.p1));
    double d2 = abs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}

int main(){
    int q;
    cin>>q;

    Segment s1, s2;
    Point p;

    while(q--){
        cin>>s1.p1.x>>s1.p1.y>>s1.p2.x>>s1.p2.y>>s2.p1.x>>s2.p1.y>>s2.p2.x>>s2.p2.y;
        p = getCrossPoint(s1, s2);
        printf("%.10f %.10f\n", p.x, p.y);
    }
}

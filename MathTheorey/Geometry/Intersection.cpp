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
Point project(Segment s, Point p) {//投影 对于给定的三个点p1、p2、p，从点p向通过
//p1、p2的直线引一条垂线，求垂足x的坐标。（点p在直线p1p2上的投影）
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

Point reflect(Segment s, Point p) {//映像 以线段s为对称轴与点p成先对称的点
//对于三个点p1、p2、p，设以通过p1、p2的直线为对称轴与点p成线对称的点为x，
//求点x的坐标（点p对于直线p1p2的映像）
    return p + (project(s, p) - p) * 2.0;
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if( cross(a, b) > EPS ) return COUNTER_CLOCKWISE;
    if( cross(a, b) < -EPS ) return CLOCKWISE;
    if( dot(a, b) < -EPS ) return ONLINE_BACK;
    if( a.norm() < b.norm() ) return ONLINE_FRONT;

    return ON_SEGMENT;
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
             ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool intersect(Segment s1, Segment s2) {
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

int main(){
    int q;
    cin>>q;

    Segment s1, s2;

    while(q--){
        cin>>s1.p1.x>>s1.p1.y>>s1.p2.x>>s1.p2.y>>s2.p1.x>>s2.p1.y>>s2.p2.x>>s2.p2.y;
        cout<<intersect(s1, s2)<<endl;
    }
}

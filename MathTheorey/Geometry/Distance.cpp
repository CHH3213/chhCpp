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

typedef Segment Line;//Line 直线

double dot(Vector a, Vector b) {//内积
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {//外积
    return a.x*b.y - a.y*b.x;
}

double getDistance(Point a, Point b) {//点a和点b的距离
    return (a - b).abs();
}

double getDistanceLP(Line l, Point p) {//直线l和点p的距离
    return abs(cross(l.p2 - l.p1, p - l.p1) / (l.p2 - l.p1).abs() );
}

double getDistanceSP(Segment s, Point p) {//线段s与点p的距离
    if( dot(s.p2 - s.p1, p - s.p1) < 0.0 ) return (p - s.p1).abs();
    if( dot(s.p1 - s.p2, p - s.p2) < 0.0 ) return (p - s.p2).abs();
    return getDistanceLP(s, p);
}

/*ccw模块*/
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

bool intersect(Point p1, Point p2, Point p3, Point p4) {//判断线段p1p2和线段p3p4是否相交
    return ( ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
             ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0 );
}

bool intersect(Segment s1, Segment s2) {//判断线段s1和线段s2是否相交
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

double getDistance(Segment s1, Segment s2) {//线段与线段的距离
    if(intersect(s1, s2) ) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}

int main(){
    int q;
    cin>>q;

    Segment s1, s2;

    while(q--){
        cin>>s1.p1.x>>s1.p1.y>>s1.p2.x>>s1.p2.y>>s2.p1.x>>s2.p1.y>>s2.p2.x>>s2.p2.y;
        printf("%.10f\n", getDistance(s1, s2) );
    }
}

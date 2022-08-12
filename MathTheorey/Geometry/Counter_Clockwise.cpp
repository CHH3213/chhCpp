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

int main(){
    Point p0, p1, p2;
    cin>>p0.x>>p0.y>>p1.x>>p1.y;

    int q;
    cin>>q;

    while(q--){
        cin>>p2.x>>p2.y;
        switch(ccw(p0, p1, p2)){
            case 1: cout<<"COUNTER_CLOCKWISE"<<endl; break;
            case -1: cout<<"CLOCKWISE"<<endl; break;
            case 2: cout<<"ONLINE_BACK"<<endl; break;
            case -2: cout<<"ONLINE_FRONT"<<endl; break;
            case 0: cout<<"SEGMENT"<<endl; break;
        }

    }
}

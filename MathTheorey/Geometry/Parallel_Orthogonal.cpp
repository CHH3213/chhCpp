//
// Created by CHH3213 on 2022/8/12.
//
#include<iostream>
#include<cmath>
using namespace std;

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

struct Segment{
    Point p1, p2;
};
double dot(Vector a, Vector b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
    return a.x*b.y - a.y*b.x;
}

bool isOrthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0.0);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2){
    return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1, Segment s2){
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Vector a, Vector b){
    return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2){
    return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1, Segment s2){
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

int main(){
    int q;
    cin>>q;

    Point p0, p1, p2, p3;

    while(q--){
        cin>>p0.x>>p0.y>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
        if(isOrthogonal(p0, p1, p2, p3) ){
            cout<<1<<endl;
        } else if(isParallel(p0, p1, p2, p3) ){
            cout<<2<<endl;
        } else {
            cout<<0<<endl;
        }
    }
}

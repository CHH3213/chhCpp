//
// Created by CHH3213 on 2022/8/24.
//
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
/*
 * 计算几何 之 判断两直线是否相交并求两直线交点
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
typedef Point Vector;//Vector类，向量

double cross(Point a,Point b)
{
    //计算叉积大小
    return a.x * b.y - b.x * a.y;
}

Point intersection(Point p0,Vector v,Point q0,Vector w)
{
//    直线用点向式表示，即 p = p_0 + tv，p0是直线上的一定点，v是直线的一个向量，我们的每一个t都对应直线上的一个点。在计算几何中，直线最常用的就是点向式表示法。
    if(cross(v,w)==0){
        //说明无交点
        return NULL;
    }
    Vector u = p0 - q0;
    double t = cross(w,u) / cross(v,w);
    return {p0.x+t*v.x , p0.y+t*v.y};	//p + t*v
}

int main(){
    Point p0, q0;
    cin>>p0.x>>p0.y>>q0.x>>q0.y;
    Vector v,w;
    cin>>v.x>>v.y>>w.x>>w.y;
    Point inter = intersection(p0,v,q0,w);
    if(inter==NULL){
        cout<<"No intersection"<<endl;
        return 0;
    }
    cout<<inter.x<<' '<<inter.y<<endl;
    return 0;
}

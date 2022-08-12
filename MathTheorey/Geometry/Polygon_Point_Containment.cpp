//
// Created by CHH3213 on 2022/8/12.
//

#include<iostream>
#include<cmath>
#include<vector>
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

typedef vector<Point> Polygon;

double dot(Vector a, Vector b) {//内积
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {//外积
    return a.x*b.y - a.y*b.x;
}

/*
	IN 2
	ON 1
	OUT 0
*/
int contains(Polygon g, Point p) {
    int n = g.size();
    bool x = false;
    for(int i = 0; i < n; i++) {
        Point a = g[i] - p, b = g[(i+1) % n] - p;
        if( abs(cross(a, b) ) < EPS && dot(a, b) < EPS ) return 1;
        if( a.y > b.y ) swap(a, b);
        if( a.y < EPS && EPS < b.y && cross(a, b) > EPS ) x = !x;
    }
    return (x ? 2 : 0);
}

int main(){
    int n;
    cin>>n;

    Polygon g;
    Point temp;

    while(n--){
        cin>>temp.x>>temp.y;
        g.push_back(temp);
    }

    cin>>n;

    while(n--){
        cin>>temp.x>>temp.y;
        cout<<contains(g, temp)<<endl;
    }
}

//
// Created by CHH3213 on 2022/8/12.
//
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
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

typedef vector<Point> Polygon;//Polygon 多边形

double dot(Vector a, Vector b) {//内积
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {//外积
    return a.x*b.y - a.y*b.x;
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

Polygon andrewScan(Polygon s) {
    Polygon u, l;
    if(s.size() < 3) return s;
    sort(s.begin(), s.end());//以x、y为基准升序排序
    //将x最小的2个点添加至u
    u.push_back(s[0]);
    u.push_back(s[1]);
    //将x最大的2个点添加至l
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);

    //构建凸包上部
    for(int i = 2; i < s.size(); i++) {
        for(int n = u.size(); n >= 2 && ccw(u[n-2], u[n-1], s[i]) != CLOCKWISE; n--) {
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    //构建凸包下部
    for( int i = s.size() - 3; i >= 0; i--) {
        for(int n = l.size(); n >= 2 && ccw(l[n-2], l[n-1], s[i]) != CLOCKWISE; n--) {
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    //按顺时针方向生成凸包的点的序列
    reverse(l.begin(), l.end());
    for(int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);

    return l;
}

int main(){
    int n;
    cin>>n;

    Polygon s;
    Point p;

    while(n--){
        cin>>p.x>>p.y;
        s.push_back(p);
    }
    cout<<s.size()<<endl;
    s = andrewScan(s);

    cout<<s.size()<<endl;
    for(int i = 0; i < s.size(); i++){
        cout<<s[i].x<<" "<<s[i].y<<endl;
    }
}

//
// Created by CHH3213 on 2022/8/12.
//
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
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

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint {
public:
    Point p;
    int seg, st;//输入线段的ID，端点的种类
    EndPoint() {}
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st) {}

    bool operator < (const EndPoint &ep) const {
        //按y坐标升序排序
        if(p.y == ep.p.y) {
            return st < ep.st;//y相同时，按照下端点、左端点、右端点、上端点的顺序排列
        } else return p.y < ep.p.y;
    }
};

EndPoint EP[2 * 100000];//端点列表

//线段相交问题：曼哈顿几何
int manhattanIntersection(vector<Segment> S) {
    int n = S.size();

    for(int i = 0, k = 0; i < n; i++) {
        //调整端点p1、p2，保证左小右大
        if(S[i].p1.y == S[i].p2.y) {
            if(S[i].p1.x > S[i].p2.x) swap(S[i].p1, S[i].p2);
        } else if (S[i].p1.y > S[i].p2.y) swap(S[i].p1, S[i].p2);

        if(S[i].p1.y == S[i].p2.y) {
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        } else {
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }

    sort(EP, EP + (2 * n));//按端点的y坐标升序排列

    set<int> BT;//二叉搜索树
    BT.insert(1000000001);//设置标记
    int cnt = 0;

    for(int i = 0; i < 2 * n; i++) {
        if(EP[i].st == TOP) {
            BT.erase(EP[i].p.x);//删除上端点
        } else if(EP[i].st == BOTTOM) {
            BT.insert(EP[i].p.x);//添加下端点
        } else if(EP[i].st == LEFT) {
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);//O(log n)
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);//O(log n)
            cnt += distance(b, e);//加上b和e的距离（点数） O(k)
        }
    }

    return cnt;
}

int main(){
    int n;
    cin>>n;

    vector<Segment> S;
    Segment s;

    while(n--){
        cin>>s.p1.x>>s.p1.y>>s.p2.x>>s.p2.y;
        S.push_back(s);
    }

    cout<<manhattanIntersection(S)<<endl;
}

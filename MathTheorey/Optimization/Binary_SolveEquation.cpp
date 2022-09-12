//
// Created by CHH3213 on 2022/9/12.
//
#include <valarray>
#include<iostream>
using namespace std;
#define EPS 1e-6
/*
 * 使用二分法求解方程的根：np.log(x)+x^2=0
 */
double func(double x){
    /**
     * 构造函数
     * x:自变量
     * return：函数值
     */
    return log(x)+x*x;
}

double bisection(double a, double b){
    /**
     * 二分法求根
     * [a,b]:  含有根的区间
     */
    if(a>b)swap(a,b);//确保a < b
    double y_a = func(a),y_b =func(b);
    if(y_a==0){// 已经是根
        b=a;
        return a;
    }
    if(y_b==0){// 已经是根
        a=b;
        return b;
    }
    while(b-a>EPS){
        double x = a+(b-a)/2;
        double y = func(x);
        if(y==0){
            a=x,b=x;
            break;
        }else if(y*y_a>=0){ // 根在右半边
            a=x;
        }else{//根在左半边
            b=x;
        }
    }
    return a;
}
int main(){
    cout<<"answer: "<<bisection(0.0,2.0)<<"----prove: "<<func(bisection(0.0,2.0)) <<endl;
    return 0;
};
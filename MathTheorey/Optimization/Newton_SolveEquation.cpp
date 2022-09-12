//
// Created by CHH3213 on 2022/9/12.
//
#include<iostream>
#include <valarray>

using namespace std;

#define DELTA 1e-4
#define EPS 1e-6
/*
 * 使用牛顿法求解方程的根：np.log(x)+x^2=0
 */
double func(double x){
    /**
     * 构造函数
     * x:自变量
     * return：函数值
     */
    return log(x)+x*x;
}

double func_prime(double x){
    /**
     * 计算函数导数,以导数定义的方式求解
     */
    return (func(x+DELTA)-func(x-DELTA))/(2*DELTA);
}
double Newton(double x0){
    double x = x0;
    double x_last=0.1;
    while(abs(x-x_last)>EPS){
        x_last=x;
        x=x_last-func(x_last)/ func_prime(x_last);
    }
    return x;
}

int main(){
    cout<<"answer: "<<Newton(0.5)<<"----prove: "<<func(Newton(0.5)) <<endl;
    return 0;
}
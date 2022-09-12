//
// Created by CHH3213 on 2022/9/12.
//
#include<iostream>
#include <valarray>
/*
 * 使用梯度下降法求解函数极值
 */
using namespace std;

#define DELTA 1e-4
#define EPS 1e-6

double func(double x){
    /**
     * 函数
     */
    return x*x-4*x;
}


double func_prime(double x){
    /**
     * 函数导数
     */
    return (func(x+DELTA)-func(x-DELTA))/(2*DELTA);
}



double GradientDescent(double x0,double learning_rate ){
    /**
     * 梯度下降算法
     * x0为迭代初值
     * learning_rate为学习率
     */
    double x = x0;
    double x_last = 0.5;
    while(abs(x-x_last)>EPS){
        x_last=x;
        x = x_last-learning_rate* func_prime(x_last);
    }
    return x;
}
int main(){

    double x1= GradientDescent(0,0.01);
    cout<<x1<<endl;
}

//
// Created by CHH3213 on 2022/9/12.
//
#include<iostream>
#include <valarray>
#include <vector>
/*
 * 使用梯度下降法求解多元函数极值：f(x)=4(x1-1)^2+(x2-2)^4
 */
using namespace std;

#define DELTA 1e-4
#define EPS 1e-9

double func(double x1, double x2){
    /**
     * 函数
     */
    return 4*pow(x1-1,2)+pow(x2-2,4);
}


vector<double> func_prime(double x1,double x2){
    /**
     * 函数导数
     */
     double nabla_x1 = (func(x1+DELTA,x2)-func(x1-DELTA,x2))/(2*DELTA);//对x1的偏导数
     double nabla_x2 = (func(x1,x2+DELTA)-func(x1,x2-DELTA))/(2*DELTA);//对x2的偏导数
    return {nabla_x1,nabla_x2};
}



vector<double> GradientDescent(vector<double> x0,double learning_rate ){
    /**
     * 梯度下降算法
     * x0为迭代初值
     * learning_rate为学习率
     */
    vector<double> x = x0;
    vector<double> x_last = {0.5,0.5};
    while(abs(x[0]-x_last[0])>EPS||abs(x[1]-x_last[1])>EPS){
        x_last=x;
        vector<double>prime = func_prime(x_last[0],x_last[1]);
        x[0] = x_last[0]-learning_rate*prime[0] ;
        x[1] = x_last[1]-learning_rate*prime[1] ;
//        cout<<x[0]<<' '<<x[1]<<endl;
    }
    return x;
}
int main(){

    vector<double> x= GradientDescent({0,0},0.01);
    cout<<x[0]<<' '<<x[1]<<endl;
}

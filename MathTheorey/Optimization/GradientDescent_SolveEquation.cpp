//
// Created by CHH3213 on 2022/8/18.
//
#include<iostream>
#include <valarray>
/*
 * 使用梯度下降法求解二次方程的根
 * 步骤：原函数->构造损失函数->对损失函数求导->进行梯度下降
 */
using namespace std;

#define DELTA 1e-4
#define EPS 1e-6
//y=ax^2+bx+c
double func(double a,double b,double c,double x){
    return a*pow(x,2)+b*x+c;
}

//构造损失函数
double loss_func(double a,double b,double c,double x){
    return pow(func(a,b,c,x)-0,2);
}

//构造损失函数导数
double loss_func_prime(double a,double b,double c,double x){
    return (loss_func(a,b,c,x+DELTA)-loss_func(a,b,c,x))/DELTA;
}

double GradientDescent(double a,double b,double c,double x0,double learning_rate ){
    /**
     * 梯度下降算法
     * a,b,c为二次函数的系数
     * x0为迭代初值
     * learning_rate为学习率
     */
    double x = x0;
    while(abs(loss_func(a,b,c,x))>EPS){
        x = x-learning_rate* loss_func_prime(a,b,c,x);
    }
    return x;
}
int main(){
    double a = 1.0,b=2.0,c=-3.0;
    double x0=-b/(2*a)-1;//通过设置不同初值找出来
    double x1= GradientDescent(a,b,c,x0,0.01);
    x0=-b/(2*a)+1;
    double x2= GradientDescent(a,b,c,x0,0.01);
    cout<<x1<<" "<<x2<<endl;
}

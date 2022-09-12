//
// Created by CHH3213 on 2022/9/12.
//
#include<iostream>
#include <valarray>

using namespace std;

#define DELTA 1e-4
#define EPS 1e-6
/*
 * 使用模拟退火求函数极值点
 */
double func(double x){
    /**
     * 构造函数
     * x:自变量
     * return：函数值
     */
    return x*x-4*x;
}


double rnd(double low,double high){
    /**
     * 返回指定范围内的随机浮点数
     */
    double rd=rand()/((double)RAND_MAX+1.0);
    return low+rd*(high-low);
}

double Annealing(double T0, double T_min, double x0,double gamma){
    /**
     * T0:初始温度
     * T_min:温度的下限，若温度T达到T_min，则停止搜索
     * x0:初始迭代值
     * gamma:T_{k+1} = gamma * T_k, 0<gamma<1
     * return:极值点
     */
     double T=T0;
     double x = x0;
     double x_ = 2;
     double delta_y=1.0;
     while(abs(delta_y)>EPS){//如果函数值满足精度，停止搜索
//     while(T>T_min){//温度T达到T_min，则停止搜索

         double x_ = x+rnd(-1,1);
         cout<<x_<<endl;
         delta_y = func(x_)-func(x);
         if(delta_y<=0){
             x = x_;
         }else{
             if(exp(-delta_y/T)>rnd(0,1)){
                 x=x_;
             }
         }
         T=gamma*T;
         cout<<x<<endl;
     }
    return x;
}

int main(){
    double T0=200,T_min = 1,x0=2,gamma=0.9;
    cout<<"extreme  value: "<<Annealing(T0,T_min,x0,gamma)<<endl;
    return 0;
}
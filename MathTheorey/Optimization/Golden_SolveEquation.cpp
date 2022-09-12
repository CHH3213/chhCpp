//
// Created by CHH3213 on 2022/9/12.
//
#include <valarray>
#include<iostream>
#include <vector>

using namespace std;
#define EPS 1e-6
/*
 * 使用黄金搜索法求解迭代n次后的含最小值区间，：f(x)=x^2-5
 */
double func(double x){
    /**
     * 构造函数,单谷函数
     * x:自变量
     * return：函数值
     */
    return x*x-5;
}
//double func(double x){
//    /**
//     * 求根
//     */
//    return pow(x*x-5,2);
//}

vector<double> golden_section_search(double a, double b,int n){
    /**
     *  含最小值的区间[a,b]
     * n: 迭代次数
     */
    double rho = (sqrt(5)-1)/2.0;//0.618黄金分割比
    double c=rho*a+(1-rho)*b;//(a, b)中靠近a的黄金分割点
    double d = rho*b+(1-rho)*a;//(a,b)中靠近b的黄金分割点
    while(n--){
        if(func(c)>func(d)){
            //这时(c, b)是含最小值区间, d是(c, b)的中靠近c的黄金分割点, 仍用a, b表示含最小值区间，c表示靠近a的黄金分割点
            a=c;
            c=d;
            d= rho*b+(1-rho)*a;//(a,b)中靠近b的黄金分割点
        }else{
            //这时(a, d)是含最小值区间,c是区间(a,d)的靠近d的黄金分割点,仍用a, b表示含最小值区间，d表示靠近b的黄金分割点
            b=d;
            d=c;
            c=rho*a+(1-rho)*b;
        }
    }
    return {a,b};
}

int main(){
    vector<double> res = golden_section_search(-3,3,20);
    cout<<res[0]<<' '<<res[1]<<endl;

    return 0;
}
//
// Created by CHH3213 on 2022/9/12.
//
#include<iostream>
#include <valarray>
/*
 * 使用抛物线法求解 x*x-5的最小值点
 */
using namespace std;

#define DELTA 1e-4
#define EPS 1e-6
double func(double x){
    /**
     * 构造函数
     * x:自变量
     * return：函数值
     */
//    return pow(x*x-5,2);
    return x*x-5;
}

double quadratic_fit_search(double a,double b,double c,int n){
    /**
     * 抛物线法；
     * 区间(a,b)；
     * a<c<b
     * n: 迭代次数
     */
    while(n--){
        double beta_1 = 1/(b-a)*((func(b)-func(c))/(b-c)-(func(c)- func(a))/(c-a));
        double beta_2 = (func(c)-func(a))/(c-a)-beta_2*(c+a);
         double x = -beta_1/(2*beta_2);
         if(x<c){
             b=c;
             c=x;
         }else{
             a=c;
             c=x;
         }
     }
     return c;
}

double quadratic_fit_search_2(double a,double b,double c,int n){
    /**
     * 抛物线法；
     * 区间(a,c)；
     * a<b<c
     * n: 迭代次数
     * return: 最小值点
     */
    while(n--){
        double y_a=func(a),y_b=func(b),y_c=func(c);
        double x = 0.5*(y_a*(b*b-c*c)+y_b*(c*c-a*a)+y_c*(a*a-b*b))/(y_a*(b-c)+y_b*(c-a)+y_c*(a-b));
        double y_x = func(x);
        if(x>b){
             if(y_x>y_b){   //用 a < b < x 作为新的起点
                 c=x;
             }else{     //用 b < x < c作为新的起点
                 a=b;
                 b=x;
             }
        }else if(x<b){
             if(y_x>y_b){   //用 x < b < c作为新的起点
                 a=x;
             }else{     //用 a < x < b作为新的起点
                 c=b;
                 b=x;
             }
        }

     }
    return b;

}

int main(){
    cout<<quadratic_fit_search_2(-2,2,3,50)<<endl;
    return 0;
}
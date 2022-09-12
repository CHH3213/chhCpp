//
// Created by CHH3213 on 2022/9/12.
//
#include <iostream>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;


double Lagrange(vector<vector<double>> points,double x_p){
    /**
     * points: 插值节点的坐标(x_i,z_i)集合
     * x_p: 为需计算的插值函数值的横坐标
     * return: 插值函数值
     */
     double  res=0;
    int items = points.size();//插值点个数
    for(int i=0;i<items;i++){
        double nume=1;//分子
        double deno=1;//分母
        for(int k=0;k<items;k++){
            if(k!=i){
                nume*=(x_p-points[k][0]);
                deno*=(points[i][0]-points[k][0]);
            }

        }
        res+=nume/deno*points[i][1];
    }

    return res;
}

int main(){
    vector<vector<double>> points={{1.1,3.887},{2.3,4.276},{3.9,4.651},{5.1,2.117}};
    cout<<"2.101: "<< Lagrange(points,2.101)<<endl;
    cout<<"4.234: "<< Lagrange(points,4.234)<<endl;
    return 0;
}


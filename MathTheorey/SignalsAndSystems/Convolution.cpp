//
// Created by CHH3213 on 2022/9/14.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> conv(vector<int> u, vector<int>v){
    /**
     * 定义conv函数
     */
    int m = u.size(),n=v.size();
    int len = m + n -1;	//计算卷积结果的长度
    vector<int>result(len,0);
    for(int k = 0; k < len; k++)
    {
        for(int i = 0; i < n; i++){
            if(k-i<n&&k-i>=0&&i<m)result[k] += u[i]*v[k-i];
            else{
                continue;
            }
        }

    }
    return result;
}

int main(){
    vector<int>x={1,2,3};
    vector<int>h={4,5,6,7};
    vector<int>res = conv(x,h);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<' ';
    }

    return 0;
}
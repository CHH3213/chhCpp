////
//// Created by CHH3213 on 2022/9/8.
////
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int det(vector<vector<int>>matrix){
    int n = matrix.size();
    int res=0;
    // 一阶二阶直接计算
    if(n==1)res=matrix[0][0];
    if(n==2)res=matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
    for(int k=0;k<n;k++){
        vector<vector<int>>M(n-1,vector<int>(n-1));//代数余子式
        // 为代数余子式赋值
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-1;j++)
                M[i][j]=matrix[i+1][j<k?j:j+1];
        // 按第一行展开，递归计算行列式，注意元素0则不展开可以加快计算速度
        if(matrix[0][k])
            res+=matrix[0][k]*det(M)*(((2+k)%2)?-1:1);
    }
    return res;
}
int main(){
    vector<vector<int>>matrix={{2,1,-1},{2,1,0},{1,-1,1}};
    int res = det(matrix);
    cout<<res<<endl;
    return 0;
}


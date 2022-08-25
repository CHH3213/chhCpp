//
// Created by CHH3213 on 2022/8/13.
//
#include<iostream>
#include<vector>
#include <stack>
#include<string>
using namespace std;

int count = 0;
void dfs(){
    count++;
}
int main(){

    int m,n;
    cin>>m>>n;
    vector<vector<int>>map(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }



    return 0;
}
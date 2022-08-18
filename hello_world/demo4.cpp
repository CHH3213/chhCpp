#include<iostream>
#include<vector>
#include<string>
#include <queue>

using namespace std;

//
//邻接表构建
//分别将路径上的点保存在两个数组中
//比较两个数组是否由相等的元素
int main(){
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    vector<vector<int>>near_table(2*n);
    for(vector<int>v:vec){
        near_table[v[0]].push_back(v[1]);
    }
    int c1,c2;
    cin>>c1>>c2;
    queue<int>que;
    vector<int>v1;
    vector<int>v2;
    que.push(c1);
    while(!que.empty()){
        int c = que.front();
        que.pop();
        v1.push_back(c);
        for(int city:near_table[c]){
            que.push(city);
        }
    }
    que.push(c2);
    while(!que.empty()){
        int c = que.front();
        que.pop();
        v2.push_back(c);
        for(int city:near_table[c]){
            que.push(city);
        }
    }
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                cout<<v1[i]<<endl;
                return 0;
            }
        }
    }

}

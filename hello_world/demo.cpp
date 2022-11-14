#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){


    int N;
    cin>>N;
    int res = 0;
    vector<vector<int>>grids(N,vector<int>(2,0));
    for(int i=0;i<grids.size();i++){
        cin>>grids[i][0]>>grids[i][1];
    }

    cout<<res<<endl;

    return 0;

}

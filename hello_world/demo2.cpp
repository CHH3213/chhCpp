#include<iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

//第三题

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int res = 0 ;
    for(int i=0;i<n;i++){
        if(i>0&&vec[i]<=vec[i-1]+i-1)continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1&&vec[j]<=vec[j-1]+j-1)continue;
            res=max(res,vec[j]+vec[i]-(j-i));
        }
    }
    cout<<res<<endl;



    return 0;
}
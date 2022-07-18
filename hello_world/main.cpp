#include <iostream>
#include<string>
#include<vector>
using namespace std;
string longest(string&s1,string&s2){
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int res=INT16_MIN;
    int index = 0;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
            if(dp[i][j]>res){
                res = dp[i][j];
                index = i;
            }
        }
    }
    //截取字符串并返回
    return res == 0 ? "-1" : s1.substr((index - res),(index));
}


int main() {
    string s1;
    string  s2 ;
    while(true){
        cout<<"====="<<endl;
        cin>>s1;
        cout<<"---"<<endl;
        cin>>s2;
        cout<<"===="<<endl;
        string length = longest(s1,s2);
        cout<<length<<endl;
    }

    return 0;
}



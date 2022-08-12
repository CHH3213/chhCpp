#include<iostream>
#include <vector>
#include <climits>

using namespace std;
int maxReward(string s,string t){
    int m = s.size();
    int n = t.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j]);
                dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
        }
    }
    return dp[m][n]*2;
}
int main(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int res = maxReward(s1,s2);
    cout<<res<<endl;
    return 0;
}
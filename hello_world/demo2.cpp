
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com



#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<algorithm>
using namespace std;

static bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first==b.first){
        return a.second<b.second;
    }else{
        return a.first>b.first;
    }
}
int main() {
    int m;
    cin>>m;
    vector<int>money(m);
    for(int i=0;i<m;i++){
        cin>>money[i];
    }
    int n;
    cin>>n;

    int rest;
    int last_rest;
    vector<pair<int,int>>result(n);
    sort(money.begin(),money.end());
    for(int i=m-1;i>=0;i--){
        int cnt = 1;
        rest=n;
        int equal = money[i];
        for(int j=i-1;j>=0;j--){
            last_rest=rest;
            rest -=(equal-money[j]);
            if(rest>0)cnt++;
            else {
                break;
            }


        }
        result.push_back(pair<int,int>{cnt,last_rest});

    }

    sort(result.begin(),result.end(),cmp);
    cout<<result[0].first<<' '<<result[0].second<<endl;

}
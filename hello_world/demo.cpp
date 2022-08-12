
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com



#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>>st;
        string res="";
        int num = 0;
        string cur = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9')
            {
                num = 10*num + s[i] - '0';
            }else if(s[i]=='['){
                st.push(pair<string,int>{cur,num});
                num=0;
                cur.clear();
            }else if(s[i]>='a'&&s[i]<='z'){
                cout<<cur<<endl;
                cur+=s[i];
            }else if(s[i]==']'){
                pair<string,int> tmp = st.top();
                cur+=copys(tmp.first,tmp.second);
                st.pop();

            }
        }
        res+=cur;
        return res;
    }
    string copys(string& s,int k){
        string res;
        while(k--){
            res+=s;
        }
        return res;
    }
};


int main() {


    string s="3[a]2[bc]";
    Solution().decodeString(s);
    return 0;
}
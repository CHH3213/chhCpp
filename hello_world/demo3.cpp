//
// Created by CHH3213 on 2022/8/13.
//
#include<iostream>
#include<vector>
#include <stack>
#include<string>
using namespace std;


int main(){
    int M;
    cin>>M;
    vector<string>datas(M);
    stack<string>st;
    for(int i=0;i<M;i++){

        getline(cin,datas[i]);
//        scanf("%[^\n]",st);
//        cin>>datas[i];
    }
    vector<string>vecs;
    for(int k=0;k<datas.size();k++){
        string s = datas[k];
        cout<<s<<endl;
        string res="";
        for(int i=0;i<s.size();i++) {
            if (s[i] == '#') {
                if (s[i + 1] == 'R' || s[i + 1] == 'G' || s[i + 1] == 'B' || s[i + 1] == 'K' || s[i + 1] == 'Y' ||
                    s[i + 1] == 'W' || s[i + 1] == 'P') {
                    st.push(s.substr(i, 2));
                    i++;
                } else if (s[i + 1] == 'C') {
                    int j = i + 2;
                    while (s[j] >= '0' && s[j] <= '9' || s[j] >= 'A' && s[j] <= 'F')j++;
                    if (j - 1 == 6)st.push(s.substr(i + 2, 6));
                    i+=6;
                } else if (s[i + 1] == 'n'||i==s.size()-1) {
                    string color = st.top();
                    st.pop();
                    cout<<color<<endl;
                    if (color.size() > 2) {
                        res += ' ';
                        res += color;
                    } else {
                        res += ' ';
                        if (color == "#R")res += "FF0000";
                        else if (color == "#G")res += "00C932";
                        else if (color == "#B")res += "0000FF";
                        else if (color == "#K")res += "000000";
                        else if (color == "#Y")res += "FFFF00";
                        else if (color == "#W")res += "FFFFFF";
                        else if (color == "#P")res += "FF88FF";
                        res+=' ';
                    }
                    i++;
                } else {
                    res += s[i];
                }
            }else{
                res+=s[i];
            }
        }
        vecs.push_back(res);
        cout<<res<<endl;

    }


}
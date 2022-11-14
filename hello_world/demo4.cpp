#include<bits/stdc++.h>
using namespace std;
void toLower(string&s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=s[i]-'A'+'a';
        }
    }
}

int main(){

    string s;
    cin>>s;
    toLower(s);
    string res="";
    vector<int>cnts(255,0);//a-z
    vector<int>nums(10,0);//0-9
    for(char c:s){
        cnts[c]++;
    }
    //0
    while(cnts['z']){
        cnts['z']--;
        cnts['e']--;
        cnts['r']--;
        cnts['0']--;
    }

    //2
    while(cnts['w']){
        cnts['t']--;
        cnts['w']--;
        cnts['o']--;
        nums[2]++;
    }
    //8
    while(cnts['g']){
        cnts['e']--;
        cnts['i']--;
        cnts['g']--;
        cnts['h']--;
        cnts['t']--;
        nums[8]++;
    }
    //6
    while(cnts['x']){
        if(cnts['s']&&cnts['i']){
            cnts['s']--;
            cnts['i']--;
            cnts['x']--;
            nums[6]++;
        }

    }
    //7
    while(cnts['s']){
        if(cnts['v']&&cnts['n']&&(cnts['e']>1)){
            cnts['s']--;
            cnts['e']--;
            cnts['v']--;
            cnts['e']--;
            cnts['n']--;
            nums[7]++;
        }

    }
    //3
    while(cnts['h']){
        if(cnts['t']&&cnts['r']&&(cnts['e']>1)){
            cnts['t']--;
            cnts['h']--;
            cnts['r']--;
            cnts['e']--;
            cnts['e']--;
            nums[3]++;
        }

    }
    //4-5
    while(cnts['f']){
        if(cnts['f']&&cnts['o']&&cnts['u']&&cnts['r']) {
            cnts['f']--;
            cnts['o']--;
            cnts['u']--;
            cnts['r']--;
            nums[4]++;
        }else if(cnts['f']&&cnts['i']&&cnts['v']&&cnts['e']){
            cnts['f']--;
            cnts['i']--;
            cnts['v']--;
            cnts['e']--;
            nums[5]++;
        }else break;
    }
    //1
    while(cnts['o']){
        if(cnts['n']&&cnts['e']){
            cnts['o']--;
            cnts['n']--;
            cnts['e']--;
            nums[1]++;
        }


    }
    //9
    while(cnts['i']){
        cnts['i']--;
        nums[9]++;
    }
    for(int i=0;i<10;i++){
        while(nums[i]--){
            cout<<i;
        }
    }
    cout<<endl;
    return 0;

};
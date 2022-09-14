#include<iostream>
#include <vector>

#include<algorithm>
using namespace std;


int main(){
    int n,m;
    cin>>n;
    vector<int>data1;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        data1.push_back(tmp);
    }
    cin>>m;
    vector<int>data2;
    for(int i=0;i<m;i++){
        cin>>tmp;
        data2.push_back(tmp);

    }
    int cnt_1 = n;
    int cnt_2 = m;
    while(n<m){
        data1.push_back(0);
        n++;
    }
    while(n>m){
        data2.push_back(0);
        m++;
    }
    int len = cnt_1+cnt_2-1;
    vector<int>conv_y(len,0);
    for(int i=0;i<=cnt_1;i++){
        for(int k=0;k<=i;k++){
            conv_y[i]+=data1[k]*data2[i-k];
        }
    }


    cout<< len<<',';
    for(int i=0;i<len;i++){
        cout<<conv_y[i]<<' ';
    }
    cout<<endl;

    vector<int>r_y(len+1,0);
    for(int i=0;i<=cnt_1;i++){
        for(int k=0;k+i<cnt_2;k++){
            r_y[i]+=data1[k]*data2[i+k];
        }
    }


    cout<< len+1<<',';
    for(int i=0;i<=len;i++){
        cout<<r_y[i]<<' ';
    }
    cout<<endl;



    return 0;
}
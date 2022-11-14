//
// Created by CHH3213 on 2022/8/13.
//
#include<iostream>
#include <vector>

using  namespace std;



int main(){

    long N,K;
    cin>>N>>K;
    vector<long>nums(N);
    for(long i=0;i<N;i++){
        cin>>nums[i];
    }
    while(true){
        for(long i=0;i<N;i++){
            if(nums[i]>0){
                nums[i]--;
                K--;
                if(K==0){
                    cout<<i+1<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
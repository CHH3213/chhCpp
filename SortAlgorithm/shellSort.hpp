//
// Created by CHH3213 on 2022/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int>&arr){
    for(int step=arr.size()/2;step>0;step/=2){
        for(int i=step;i<arr.size();i++){
            int tmp=arr[i];
            int j=i-step;
            for(;j>=0&&arr[j-1]>tmp;j-=step){
                arr[j+step]=arr[j];
            }
            arr[j+step]=tmp;
        }
    }
}
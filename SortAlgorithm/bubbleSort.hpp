//
// Created by CHH3213 on 2022/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>&arr){
    for(int i=0;i<arr.size()-1;i++){
        bool flag=false;
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){{
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                flag=true;
            }}
        }
        if(!flag)break;
    }
}
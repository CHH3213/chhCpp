//
// Created by CHH3213 on 2022/8/3.
//

#include <iostream>
#include <vector>

using namespace std;
void directSort(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int tmp=arr[i];
        int j=i;
        for(;j>0&&arr[j-1]>tmp;j--){
            arr[j]=arr[j-1];
        }
        if(j!=i)arr[j]=tmp;
    }
}
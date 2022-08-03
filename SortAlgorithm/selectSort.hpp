//
// Created by CHH3213 on 2022/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

void selectSort(vector<int>&arr){
    for (int i = 0; i < arr.size()-1; i++) {//进行n-1趟排序
        int min = i;
        for (int j = i+1; j < arr.size(); j++) {
            if(arr[min]>arr[j])min=j; // 记录目前能找到的最小值元素的下标
        }
        // 找到最小值后，再将找到的最小值和i位置所在的值进行交换
        if(i!=min) {
            int temp =arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        };
    }
}
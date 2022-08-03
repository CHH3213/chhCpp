//
// Created by CHH3213 on 2022/8/3.
//
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>&arr,int low,int high){
    int base = arr[low]; //暂存基准元素到base
    while (low<high) {//从表的两端交替的向中间扫描
        while(low<high && arr[high]>=base)high--;//右端扫描
        if(low<high) {
            arr[low]=arr[high];//把比基准小的元素放到基准前面
            low++;
        }
        while(low<high && arr[low]< base)low++;//左端扫描
        if(low<high) {
            arr[high]=arr[low];//把比基准大的元素放到基准后面
            high--;
        }
    }
    arr[low] = base;//把基准元素放到最终位置

    return low;//返回基准元素所在的位置
}

void quickSort(vector<int>&arr,int start,int end){
    if(start<end) {
        int index = partition(arr, start, end); //将表一分为2
        quickSort(arr, start, index-1); // 对左子序列进行快速排序
        quickSort(arr, index+1, end); //对右子序列进行快速排序
    }
}
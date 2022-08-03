#include <iostream>
#include <vector>

using namespace std;
#include "directSort.hpp"
#include "shellSort.hpp"
#include "bubbleSort.hpp"
#include "quickSort.hpp"
#include "selectSort.hpp"
int main(){
    vector<int>arr={9, -16, 310, 23, -30, -49, 25, 21, 30};
//    directSort(arr);
//    shellSort(arr);
//    bubbleSort(arr);
//    quickSort(arr,0,arr.size()-1);
    selectSort(arr);
    for(int a:arr){
        cout<<a<<' ';
    }
    return 0;
}
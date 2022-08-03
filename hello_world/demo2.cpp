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
int main(){
    vector<int>arr={9, -16, 310, 23, -30, -49, 25, 21, 30};
    directSort(arr);
    for(int a:arr){
        cout<<a<<' ';
    }
    return 0;
}
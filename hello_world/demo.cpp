#include<iostream>
#include<vector>
#include <valarray>

using namespace std;


int main(){
    int n;
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int d1,d2,d3;
    cin>>d1>>d2>>d3;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(abs(i-x1)+abs(j-y1)==d1&&abs(i-x2)+abs(j-y2)==d2&&abs(i-x3)+abs(j-y3)==d3){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    return 0;

}

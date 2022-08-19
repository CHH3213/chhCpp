#include<iostream>
#include<vector>
#include<string>
#include <queue>
#include <complex>

using namespace std;


int main(){
    vector<double>A{1,2};
    vector<double>B{3,1};
    vector<double>C{0,0};
    vector<double>segment = {B[0]-A[0],B[1]-A[1]};
    vector<double>delta = {C[0]-A[0],C[1]-A[1]};
    double nor = sqrt(pow(segment[0],2)+pow(segment[1],2));
    double r = (delta[0]*segment[0]+delta[1]*segment[1])/nor;
    vector<double>D={A[0]+segment[0]*r/nor,A[1]+segment[1]*r/nor};
    cout<<D[0]<<" "<<D[1]<<endl;
   return 0;
}

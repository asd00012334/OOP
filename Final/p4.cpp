#include<iostream>
#include<cmath>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool even(int const& a){
    if(a%2==0) return true;
    return false;
}

bool cmp(int const& l, int const& r){
    if(even(l)&&!even(r)) return true;
    if(!even(l)&&even(r)) return false;
    return l>r;
}

void sort(vector<int> &arr){
    sort(arr.begin(),arr.end(),cmp);
}

int main(){
    int i,j;
    vector<int> num;
    while(cin>>j)
        num.push_back(j);

    sort(num);
    std::cout<<"Sorted result: ";
    for(i=0;i<num.size();i++){
        std::cout<<num[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

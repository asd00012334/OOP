#include <bits/stdc++.h>

const int size=10;

bool cmp(int a, int b){
    if(a%2==0&&b%2==1) return true;
    else if(a%2==1&&b%2==0) return false;
    else if(a>b) return true;
    return false;
}

void sort(int arr[]){
	//add here
	std::sort(arr,arr+size,cmp);
}

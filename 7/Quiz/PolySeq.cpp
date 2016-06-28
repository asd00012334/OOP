#include <bits/stdc++.h>
#include "PolySeq.hpp"
using namespace std;

void PolySeq::Print(){
    for(int cnt=0;cnt<term;cnt++)
        cout<<ptr[cnt]<<" ";
    cout<<endl;
}

PolySeq::~PolySeq(){
    delete [] ptr;
}

PolySeq::PolySeq(PolySeq const& ini):term(ini.term){
    ptr= new int[term];
    for(int cnt=0;cnt<term;cnt++)
        ptr[cnt]=ini.ptr[cnt];
}

PolySeq::PolySeq(int term, int* coef):term(term){
    ptr=new int[term];
    for(int cnt=0;cnt<term;cnt++)
        ptr[cnt]=coef[cnt];
}

PolySeq::PolySeq():term(1){
    ptr=new int[1];
    ptr=0;
}

PolySeq::PolySeq(int n):term(n){
    ptr=new int[n];
    for(int cnt=0;cnt<n;cnt++)
        ptr[cnt]=1;
}

PolySeq PolySeq::Add(const PolySeq& r){
    int tranSiz=max(r.term,term);
    vector<int> tranState(tranSiz,0);
    for(int cnt=0;cnt<tranSiz;cnt++)
        tranState[cnt]=0;
    for(int cnt=0;cnt<term;cnt++)
        tranState[tranSiz-cnt-1]=ptr[term-cnt-1];
    for(int cnt=0;cnt<r.term;cnt++)
        tranState[tranSiz-cnt-1]+=r.ptr[r.term-cnt-1];
    int start;
    for(start=0;start<tranSiz&&tranState[start]==0;start++);
    int siz=tranSiz-start;
    PolySeq output(siz);
    for(int cnt=0;cnt<siz;cnt++)
        output.ptr[cnt]=0;
    for(int cnt=start;cnt<tranSiz;cnt++)
        output.ptr[cnt-start]=tranState[cnt];
    return output;
}

PolySeq PolySeq::Multiply(const PolySeq& r){
    int tranSiz=r.term+term-1;
    vector<int> tranState(tranSiz,0);
    for(int leftDeg=0;leftDeg<term;leftDeg++)
    for(int rightDeg=0;rightDeg<r.term;rightDeg++){
        tranState[tranState.size()-rightDeg-leftDeg-1]+=
        ptr[term-leftDeg-1]*r.ptr[r.term-rightDeg-1];
    }
    int start;
    for(start=0;start<tranSiz&&tranState[start]==0;start++);
    int siz=tranSiz-start;
    PolySeq output(siz);
    for(int cnt=0;cnt<siz;cnt++)
        output.ptr[cnt]=0;
    for(int cnt=start;cnt<tranSiz;cnt++)
        output.ptr[cnt-start]=tranState[cnt];
    return output;
}

PolySeq PolySeq::Derivative(){
    if(term==1) return PolySeq();
    PolySeq output(term-1);
    for(int cnt=0;cnt<output.term;cnt++)
        output.ptr[cnt]=0;
    for(int oDeg=1;oDeg<term;oDeg++){
        output.ptr[output.term-(oDeg-1)-1]=
        ptr[term-oDeg-1]*oDeg;
    }
    return output;
}

double PolySeq::Integral(int lower,int upper){
    if(lower==upper) return 0;
    else if(lower>upper) swap(lower,upper);
    double output=0;
    for(int oDeg=0;oDeg<term;oDeg++){
        output+=
        (((double)ptr[term-oDeg-1])/(oDeg+1))*pow(upper,oDeg+1)-
        (((double)ptr[term-oDeg-1])/(oDeg+1))*pow(lower,oDeg+1);
    }
    return output;
}

/**
#ifndef POLYSEQ
#define POLYSEQ
#include<iostream>
int tranSiz=max(r.term,term);
    vector<int> tranState(tranSiz,0);
    for(int cnt=0;cnt<term;cnt++)
        tranState=ptr[cnt];
    for(int cnt=0;cnt<r.term;cnt++)
        tranState+=r.ptr[cnt];
    int start;
    for(start=0;start<tranSiz&&tranState[start]==0;start++);
    int siz=tranSiz-start;
    PolySeq output(siz);
    for(int cnt=start;cnt<tranSiz;cnt++)
        output[cnt-start]=tranState[cnt];
    return output;
using namespace std;
class PolySeq{
private:
	int term;
	int *ptr;
public :
	PolySeq();
	PolySeq(int n);
	PolySeq( int n, int arr[]);
        ~PolySeq();
        PolySeq Add(const PolySeq &);
        PolySeq Multiply(const PolySeq &);
        PolySeq Derivative();
        double  Integral(int form ,int end);
	void Print();

};

#endif

*/

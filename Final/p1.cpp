#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> a,b;
    string l;
    getline(cin,l);
    stringstream ss(l+"\n");
    while(1){
        int temp;
        ss>>temp;
        if(ss.eof()) break;
        a.push_back(temp);
    }
    getline(cin,l);
    ss.str(l+"\n");
    ss.clear();
    while(1){
        int temp;
        ss>>temp;
        if(ss.eof()) break;
        b.push_back(temp);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> ans;
    int ai,bi;
    ai=bi=0;
    while(ai<a.size()&&bi<b.size()){
        if(a[ai]==b[bi]){
            ans.push_back(a[ai]);
            ai++;
            bi++;
        }
        else if(a[ai]<b[bi])
            ai++;
        else
            bi++;
    }
    for(int cnt=0;cnt<ans.size();cnt++){
        if(cnt) printf(" ");
        printf("%d",ans[cnt]);
    }
    printf("\n");
    return 0;
}

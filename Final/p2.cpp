#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> ans;
    while(1){
        int temp;
        temp=getchar();
        if(temp=='['||temp==']'||temp==' ') continue;
        if(temp=='\n'||temp==EOF) break;
        ungetc(temp,stdin);
        scanf("%d",&temp);
        ans.push_back(temp);
    }
    for(int cnt=0;cnt<ans.size();cnt++){
        if(cnt) printf(" ");
        printf("%d",ans[cnt]);
    }
    printf("\n");
    return 0;
}

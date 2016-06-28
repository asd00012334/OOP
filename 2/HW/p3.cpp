#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    map <string, int> menu;
    for(;m;m--){
        string foodName;
        int foodPrice;
        cin>>foodName>>foodPrice;
        menu[foodName]=foodPrice;
    }
    for(;n;n--){
        int cost=0;
        while(1){
            string ordering;
            cin>>ordering;
            if(ordering==".")
                break;
            else if(menu.count(ordering)==1)
                cost+=menu[ordering];
            else
                /**Do Exactly Nothing, just like our government lol**/;
        }
        cout<<cost<<endl;
    }
    return 0;
}

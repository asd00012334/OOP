#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

string digit="0123456789abcde";

int main(){
    bool eof=false;

    while(!eof){
        long long int input=0;
        bool positivity=true;
        cin.clear();
        /*
        bool nummeric=true;
        bool validity=false;
        for(int cnt=1;;cnt++){
            char temp=getchar();
            if(temp=='-'&&cnt==1)
                positivity=false;
            else if(isdigit(temp)){
                input*=10;
                if(positivity)
                    input+=temp-'0';
                else
                    input-=temp-'0';
            }
            else if(temp=='\n'){
                if(cnt>1)
                    validity=true;
                break;
            }
            else if(temp==EOF){
                eof=true;
                break;
            }
            else
                nummeric=false;
        }
        */
        int temp=getchar();
        if(temp==EOF)
            break;
        else if(temp=='-')
            positivity=false;
        else
            ungetc(temp,stdin);
        cin>>input;
        if(cin.eof())
            break;
        if(!cin.good()){
            puts("not a number!");
            while(getchar()!='\n');
            continue;
        }
        else{
            int temp2=getchar();
            if(temp2!='\n'){
                puts("not a number!");
                while(getchar()!='\n');
                continue;
            }
            ungetc(temp2,stdin);
            while(getchar()!='\n');
        }
        /*
        if(!validity)
            continue;
        if(!nummeric){
            puts("not a number!");
            continue;
        }
        input>=0?0:input=-input;
        */
        if(!positivity&&input!=0)
            putc('-',stdout);
        cout<<hex<<input<<' ';
        if(!positivity&&input!=0)
            putc('-',stdout);
        cout<<oct<<input<<endl;
        cout<<dec;
    }
    return 0;
}

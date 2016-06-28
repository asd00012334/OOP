#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> literal;
    while(1){
        char index;
        index=getchar();
        if(index=='i'){
            int temp;
            scanf("%d",&temp);
            literal.push(temp);
        }
        else if(index=='+'){
            int right;
            int left;
            left=literal.top();
            literal.pop();
            right=literal.top();
            literal.pop();
            literal.push(right+left);
        }
        else if(index=='-'){
            int right;
            int left;
            left=literal.top();
            literal.pop();
            right=literal.top();
            literal.pop();
            literal.push(right-left);
        }
        else if(index=='*'){
            int right;
            int left;
            left=literal.top();
            literal.pop();
            right=literal.top();
            literal.pop();
            literal.push(right*left);
        }
        else if(index=='/'){
            int right;
            int left;
            left=literal.top();
            literal.pop();
            right=literal.top();
            literal.pop();
            literal.push(right/left);
        }
        else if(index==' '){
            /*****************************
            * this do absolutely nothing *
            ******************************/
        }
        else if(index=='\n'){
            break;
        }
    }
    printf("%d",literal.top());
    return 0;
}

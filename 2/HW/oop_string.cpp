#include"oop_string.h"
#include<algorithm>
#include<functional>


namespace oop{
    void reverse( std::string &str){
        std::string temp=str;
        int num=str.size();
        for(int cnt=0;cnt<num;cnt++)
            str[cnt]=temp[num-1-cnt];
        return;
    }

    void toUpperCase( std::string &str){
        for(int cnt=0;cnt<str.size();cnt++)
            if(str[cnt]>='a'&&str[cnt]<='z')
                str[cnt]+='A'-'a';
        return;
    }

    void trim( std::string &str){
        std::string temp=str;
        int left,right;
        for(left=0;temp[left]==' ';left++);
        for(right=temp.size()-1;temp[right]==' ';right--);
        str.resize(0);
        for(int cnt=left;cnt<=right;cnt++){
            str.insert(cnt-left,1,temp[cnt]);
        }
        return;
    }
};

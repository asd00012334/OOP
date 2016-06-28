#ifndef _LEXICAL_CAST_
#define _LEXICAL_CAST_
#include <bits/stdc++.h>
struct bad_lexical_cast: std::bad_cast{
};

bool ischar(int input){
    if('a'<=input&&input<='z') return true;
    if('A'<=input&&input<='Z') return true;
    return false;
}



template<typename To, typename From>
To lexical_cast(const From& val){
    To output;
    bool except=false;
    std::stringstream ss,ss_c;
    std::stringstream checker_before, checker_after;
    ss<<val;
    ss>>output;
    checker_before<<val;
    checker_after<<output;
    if(checker_before.str().empty()) except=true;
    if(checker_after.str().empty()) except=true;
    if(checker_before.str().size()>1){
        if(ischar(checker_before.str().back()))
            except=true;
        if(checker_before.str().back()==' ')
            except=true;
    }
    if(checker_before.str().size()>0){
        if(checker_before.str()[0]==' ')
            except=true;
    }
    if(ss.bad()) except=true;
    {
        long long int a,b;
        checker_after>>a;
        checker_before>>b;
        if(a!=b) except=true;
    }

    if(except) throw bad_lexical_cast();
    return output;
}
#endif // _LEXICAL_CAST_

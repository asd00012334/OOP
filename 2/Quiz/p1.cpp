#include<iostream>
#include<stack>
#include<string>
int main()
{
	std::string s;
	std::stack<char> p;
	while(std::cin>>s)
	{
	     //fill you code
		 int siz=s.size();
		 for(int cnt=0;cnt<siz;cnt++){
            if(cnt==(siz/2)&&siz%2==1)
                ;
            else if(p.size()==0)
                p.push(s[cnt]);
            else if(p.top()==s[cnt])
                p.pop();
            else if(p.top()!=s[cnt])
                p.push(s[cnt]);
		 }
		 if(p.size()>0)
		 //if the string is a palindrome
		 std::cout<<"The string is not a Palindrome"<<std::endl;
		 else
		 //if the string is not a palindrome
		 std::cout<<"The string is a Palindrome"<<std::endl;

	}


	return 0;
}

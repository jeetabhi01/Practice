#include<iostream>
#include<stack>

using namespace std;

void reversestack(std::stack<int> &s1, std::stack<int> &s2);


int main(){
std::stack<int> s1, s2;
for(int i = 0 ; i < 5 ; i++)
{
s1.push(i);
std::cout<<s1.top()<<std::endl;
}

reversestack(s1, s2);
int i = 5;
while(s2.size()!= 0)
// {std::cout<<'['<<i<<']'<<s2.top()<<std::endl;
{s1.push(s2.top());
 std::cout<<"[top]"<<s1.top()<<std::endl;
i--;
s2.pop();}
return 0;

}

void reversestack(std::stack<int> &s1, std::stack<int> &s2){
    if(s1.size()==1){
    s2.push(s1.top());
    s1.pop();
    }
    else{
        int top  = s1.top();
        s1.pop();
    reversestack(s1, s2);
    s2.push(top);
    }
}
#include<iostream>
using namespace std;


class node{
    private: int info;
            node * next;
    public: friend class stack;
        node(int &x){
            this->info = x;
            next = NULL;
        }
};

class stack {
private:
	node * top;
    int size;
public:
    stack(){
        top = NULL;
        size = 0;
    }
   bool isempty();
   void push(int &x);
   int pop();
   int stacksize();
   int peek();
};

bool stack::isempty(){
    return(size==0);
}

void stack::push(int &x){
    auto new_node = new node(x); 
    new_node->next = top;
    top = new_node;
    size++;
}
int stack::pop(){
    int x = -1;
    if(isempty())
    return x;
    else{
        x = top->info;
        node * temp;
        temp = top ;
        top = top->next;
        temp ->next = NULL;
        delete temp;
        
        size--;
    }
    return x;
}
int stack::stacksize(){
    return size;
}
int stack::peek(){
    if(isempty()){
    std::cout<<"The stack is empty cannot access the top element\n";
    return -1;}
    else{
        return top->info;
    }
}

signed main(){
    class stack st;
    int x;
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    for(int i = 0; i < 10; i++){
       std::cout<<"Enter the element to be pushed\n";
        std::cin>>x;
        st.push(x);
        
        
            //  cerr<<st.pop()<<endl;
    }

    for(int i = 9; i>0 ; i++){
        if(st.isempty()){
        std::cout<<"stack  underflow\n"<<std::endl;
        break;
        }
        std::cout<<"ELement Popped  "<<st.pop()<<std::endl;
        std::cout<<"The element at the top is "<<st.peek()<<std::endl;
        }
    return 0;
}

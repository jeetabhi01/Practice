#include<iostream>
using namespace std;
 
class node{
    private: 
        int info;
       node * next;
    friend class queue;
    node(int x){
        this->info = x;
        this->next = NULL;

    }
};

class queue{
    private:
    int Size;
    node * Front, * rear;
    public:
    
    queue();
    bool empty();
    void enqueue(int &x);
    void dequeue();
    int front();
    int back();
    int size();
    
};

int main(){
    queue a;
    int x = 8;
    std::cout<<a.front()<<endl;std::cout<<a.back()<<endl;
    std::cout<<"The size of the queue is "<<a.size()<<endl;
    a.enqueue(x);
   std::cout<<"The front of the queue is "<<a.front()<<endl;
   std::cout<<"The back of the queue is "<<a.back()<<endl;
    x= 9;
    a.enqueue(x);std::cout<<"The front of the queue is "<<a.front()<<endl;;
   std::cout<<"The back of the queue is "<<a.back()<<endl;
    x= 14;
    a.enqueue(x);std::cout<<"The front of the queue is "<<a.front()<<endl;;
   std::cout<<"The back of the queue is "<<a.back()<<endl;
    a.dequeue();std::cout<<"The front of the queue is "<<a.front()<<endl;;
   std::cout<<"The back of the queue is "<<a.back()<<endl;
    a.dequeue();std::cout<<"The front of the queue is "<<a.front()<<endl;;
   std::cout<<"The back of the queue is "<<a.back()<<endl;
    a.dequeue();
    a.dequeue();
    return 0;
    

}




queue::queue(){
        
        Front = NULL ;
        rear  = NULL ;
        Size  = 0;
    } 
bool queue::empty(){
    return(Size==0);
}

void queue::enqueue(int &x){
    
    node * temp  = new node(x);
    if(Front == NULL && rear == NULL)
    Front = rear = temp;

    else {
        //node * ptr  = Front;
        //while(ptr->next!=NULL)
        //ptr = ptr->next;
        node * temp = new node(x);
        rear->next = temp;
        rear       = temp;
        }
    Size++;
}

void queue::dequeue(){
    if(empty())
    std::cout<<"The queue is empty\n";
    else{
    node * temp = Front;
    Front = Front->next;
    temp->next = NULL;
    delete temp;
    Size--;
    }
}

int queue::front(){
    if(empty()){
    std::cout<<"The queue is empty\n";
    return -1;}
    else{
        return(Front->info);
    }
}

int queue::back(){
    if(empty()){
    std::cout<<"The queue is empty\n";
    return -1;
    }
    else{
        return(rear->info);
    }
}

int queue::size(){
    return Size;
}


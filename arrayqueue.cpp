#include<iostream>

using namespace std;

#define MAX 3

class queue{

    private:
        int  * Front, * rear;
        int Size, * arrqueue;
    public:
     queue(){
        arrqueue = new int[MAX];
        Size=0;
        Front  = rear = arrqueue;
     }
     bool empty();
     void enqueue(int x);
     void dequeue();
     int front();
     int back();
     int size();
};
 int main(){
     class queue q;
     int x;
     q.enqueue(4);std::cout<<"Size"<<q.size()<<endl;
     q.enqueue(5);std::cout<<"Size"<<q.size()<<endl;
     q.enqueue(8);std::cout<<"Size"<<q.size()<<endl;
     q.dequeue();std::cout<<"Size"<<q.size()<<endl;
     q.dequeue();std::cout<<"Size"<<q.size()<<endl;
     q.dequeue();std::cout<<"Size"<<q.size()<<endl;
     q.dequeue();std::cout<<"Size"<<q.size()<<endl;
     q.enqueue(4);std::cout<<"Size"<<q.size()<<endl;
 return 0;
 }


bool queue::empty(){
    return (Size==0);
}

void queue::enqueue(int x){
    if(rear == &arrqueue[MAX])
    std::cout<<"The queue is full\n";
    else
    {
        //if(Front== arrqueue )
            *rear = x;
            std::cout<<*rear<<endl;
             rear = rear + 1;
             Size++;
    }
    return;
}

void queue::dequeue(){
    if((Front == rear)){
    std::cout<<"The queue is empty ::UNDERFLOW\n";
    return ;
    }
    else{
        cout<<"The element at the front is "<<*Front<<endl;
        Front = Front + 1;  
        cout<<*Front<<endl;  
        Size--;
        return;  
    }
}
    

int queue::front(){
    if(empty()){
    std::cout<<"The queue is empty\n";
    return -1;
    }
    else{
        return(*Front);
    }
}
int queue::back(){
    if(empty()){
    std::cout<<"The queue is empty\n";
    return -1;
    }
    else
    return(*rear);
}

int queue::size(){
    return Size;
    }
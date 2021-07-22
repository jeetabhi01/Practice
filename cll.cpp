//Circular Linked Lists
//Libraries
#include<bits/stdc++.h>
#include<cstdio>

//namespaces
using namespace std;


//Global Variable Declarations

struct node{
    int data;
    node * next;
};

struct node * start = NULL;

//Function prototypes

struct node * create_cll(node *);
void display_cll(node *);

//main function

signed main(){
start = create_cll(start);
display_cll(start);

return 0;
}

struct node * create_cll(node *){
        node * new_node, *ptr;
        
    cout<<"Enter the data in the new node"<<endl;
    cout<<"Enter -404 to terminate the allocation of data"<<endl;
    
    while(true){
      new_node=new struct node;
      cin>>new_node->data;
       if (new_node->data==-404)
       break; //Breaks while Loop;
       
      // new_node->next= new_node;
        if (start==NULL){
           new_node->next= new_node;
            start=new_node;
            }
       else{
        ptr=start;
        while(ptr->next!=start)
        ptr=ptr->next;
           
        ptr->next=new_node;
        new_node->next=start;
    
        }
    
    }
    return start;
    
}

void display_cll(node *) {
    node * ptr;
    ptr=start;
    while(true){
        cout<<ptr->data;
        
        if(ptr->next==start)
        break;
        ptr=ptr->next;
    }
return;
}

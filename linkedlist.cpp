#include<bits/stdc++.h>

using namespace std;

//#define ll linkedlist;

struct node
	{
	   int data;
	   struct node* next;
	};

struct node * start=NULL;
struct node * create_ll(node*);
void display_ll(node*);

signed main ()
{
 start=create_ll(start);
 display_ll(start);
 return 0;

}
//THE FOLLOWING FUNCTION CREATES LINKED LIST
struct node* create_ll(node*)
{
  node *ptr; node *new_node;
  
  cout<<"enter -404 to end"<<endl;
  while(true)
  { new_node = new struct node;
     if (new_node==NULL)
     cout<<"memory allocation failed"<<endl;  
  else
  { cout<<"Enter the data:  "<<endl;
    cin>>new_node->data;
    if (new_node->data == -404)
    break;
    new_node->next=NULL;
  
    	 if(start == NULL)
    	    start = new_node;
   	  else
   	    {
   	 	ptr= start;
   		while(ptr->next != NULL)
   	 	ptr=ptr->next;
   	  	ptr->next= new_node;
   	    } 
     
    }
   }
    return start; 
}


//THE FOLLOWING FUNCTION DISPLAYS THE LINKEDLIST
void display_ll(node*)
{
  node *ptr;
  ptr=start;
  while(ptr->next!=NULL)
    { 
    cout<<ptr->data<<endl;
      ptr=ptr->next;
    }
 //   return start;
 }


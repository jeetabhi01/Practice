//Libraries
#include<bits/stdc++.h>
#include<cstdio>
//Define
#define nl "\n"

//Namespaces
using namespace std;



//global variables
struct node
	{
	 int data;
	 node * next;
	 };

struct node * start = NULL;     


//Function declarations
 node * create_ll(struct node*);
void   display_ll(struct node*);
node * insert_beg(struct node*);
node * insert_end(struct node*);
void   delete_ll(struct node *);
node * delete_node(struct node*);
node * insert_after(struct node*);
node * insert_before(struct node*);

//Main function
signed main()
{
  start = create_ll(start);
  display_ll(start);
  
  start = insert_beg(start);
  display_ll(start); 
  
  start = insert_end(start);
  cout<<"\n";
  display_ll(start);

   start = insert_after(start);
   
   cout<<"\n";
   display_ll(start);

   start= insert_before(start);
   cout<<"\n";
   display_ll(start);
   
   start= delete_node(start);
   cout<<endl;
   display_ll(start);
   delete_ll(start);
   if (start==NULL)
   cout<<"no error";
return 0;
}




//Function Definition
node * create_ll(node * )
{ 
  node * ptr;
  
  node * new_node;
 
   cout<<"Enter the data: \n";
 while(true)
     {
       new_node = new node;
 
 if (new_node==NULL)
  cout<<"Memory allocation failed nl"<<endl;
  else         
           cin>>new_node->data;
           new_node->next=NULL;
    if      (new_node->data==-404)    
           break;
    else
        if (start==NULL)
       { //cin>>new_node-> data; 
        //new_node->next= NULL;
       start=new_node;}
       else
       {  ptr =start;
          while(ptr->next!=NULL)
          ptr= ptr->next;
           ptr->next=new_node;
           }
         }
return start;
}




 void display_ll(node *)
 {
   node * ptr;
   ptr= start;
   while(ptr!=NULL)
 {  cout<<ptr->data<<endl;  
  // if(ptr->data==100)
   //break;    
   ptr=ptr->next;
  }    
  }
  



 node * insert_beg(node *)
{
	node * ptr, *new_node;
	cout<<"Enter the data in the new node to be inserted\n";
	new_node= new node;
	if (new_node == NULL)
	cout<<"Memory allocation failed"<<endl;
	else
	{
	 cin>>new_node->data;
	 ptr=start;
	 new_node->next=ptr;
	start=new_node;
	 }
  return start;
}





node * insert_end(node *)
{
  node * ptr,* new_node;
  cout<<"Enter the data in the new node to be inserted at the end\n";
  new_node = new node;
  if (new_node == NULL)
	cout<<"Memory allocation failed"<<endl;
	else
	{
	 cin>>new_node->data;
	 new_node->next = NULL;
	 ptr=start;
	 while(ptr->next!=NULL)
	 ptr=ptr->next;
	 ptr->next= new_node;
	 }
return start;
}

node * insert_after(node *)
{
 cout<<endl<<"enter the value after which node is to be inserted"<<endl;
 
 int value;
 cin>>value;
 node * ptr, *new_node;
 ptr = start;
 while(ptr->data!=value)
 ptr=ptr->next;
 new_node=new node;
 cout<<"Enter the data in the node"<<endl;
 cin>>new_node->data;
 new_node->next=ptr->next;
 ptr->next=new_node;
 
 return start;
 }

void delete_ll(node *)
{
node * ptr,*temp;
ptr = start;
while(ptr!=NULL)
{ temp = ptr->next;
   free(ptr);
   ptr=temp;
}
//free(temp);
return;
}

node * insert_before(node *)
{ int value;
  node * ptr, * new_node;
  ptr = start;
  
  cout<<"Enter the value before which node is to be inserted"<<endl;
  cin>>value;
  
  while (ptr->next->data!=value)
  ptr=ptr->next;
  
  new_node= new node;
  cout<<"Enter the data in the new node:\n";
  cin>>new_node->data;
  new_node->next=ptr->next;
  ptr->next=new_node;
  
  return start;
  
  }
 
 node * delete_node(node *)
 {
   int value;
   node * ptr,*preptr;
     cout<<"Enter the value to be deleted"<<endl;
   cin>>value;
   ptr=start;
   while(ptr->data!=value)
   ptr=ptr->next;
   preptr->next=ptr->next;
   free(ptr);
   return start;
   }

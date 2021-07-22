#include<iosream>
#include<string>
using namespace std;

struct driver
	{
	string name;
	int id;
	}
	
struct linkedtaxi
	{
	int taxiid;
	driver *drv;
	linkedtaxi *next;
	}
struct queue
	{
	 linkedtaxi *front;
	 linkedtaxi *end;
	 int numtaxi;
	 }
int main()
{
Queue q; 

q.front=NULL;
q.end =NULL;
q.numtaxi= 0;
 
 while (true)
 {
 cout<<"Enter the  

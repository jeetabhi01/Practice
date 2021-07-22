#include<iostream>
using namespace std;

#define MAX 3
class stack {
private:
	int top;
	int *arr;
public:
	stack() {
		arr = new int[MAX];
		top = -1;
	}
	bool isempty();
	bool isfull();
	void push(int &x);
	int pop();
	int peek();
};

bool stack::isempty() {
	return(top<0);
}

bool stack::isfull() {
	return(top>MAX-1);
}

void stack::push(int &x) {
	if(isfull())
		cout<<"Stack  overflow\n";
	else {
		arr[++top]=x;
		//cout<<arr[top]<<endl;
	}
	return;
}

int stack::pop() {
	if(isempty())
	{
		cout<<"Stack underflow\n";
		return -1;
	}
	else
		cerr<<"top = "<<top<<" \t";
	return(arr[top--]);
}

int stack::peek() {
	if(isempty()) {
		cout<<"The stack is empty\n";
		return -1;
	}
	else
		return (arr[top]);
}

int main() {
	class stack st;
	int x;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#endif

	for(int i= 0; i<5; i++) {
		cin>>x;
		st.push(x);
		if(st.isfull()) {
			cout<<"Stack overflow\n";
			break;
		}
	}
	for(int i = MAX-1; i>-5; i--) {
		cout<<st.pop()<<endl;
		if(st.isempty())
		{
			cout<<"Stack underflow\n";
			break;
		}
	}
	return 0;
}

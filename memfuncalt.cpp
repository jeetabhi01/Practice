#include<bits/stdc++.h>
using namespace std;
//Object 1

struct V3{
	double x,y,z;
	V3 scale(double const factor){
	V3 v;
	v.x=x*factor;
	v.y=y*factor;
	v.z=z*factor;
	return v;
	}
	V3 add(V3 const &b){
	V3 v;
	v.x=x+b.x;
	v.y=y+b.y;
	v.z=z+b.z;
	return v;
	}
	double length(){
	return (sqrt(x*x+y*y+z*z));
	}
	void print(){
		cout<<" x = "<<x<<" y= "<<y<<" z= "<<z<<endl;
		return;
	}
};

//Object 2
struct motionsim{
	V3 init_pos,curr_pos,acc,init_vel,curr_vel;
	double delta_t;
	void initialisesim(){
	curr_pos=init_pos;
	curr_vel=init_vel;
	return;
	}
	void simstep(){
		curr_pos=curr_pos.add(curr_vel.scale(delta_t));	
		curr_vel=curr_vel.add(acc.scale(delta_t));
		return;
	}
	void printpos(){
	curr_pos.print();
	return;
	}
};


//Main function
signed main(){
	double total_t, delta_t,t=0.0;
	motionsim msim;
	cout<<"Give the components of initial position\n";
	cin>>(msim.init_pos).x>>(msim.init_pos).y>>(msim.init_pos).z;
	
	cout<<"Give the components of initial velocity\n";
	cin>>(msim.init_vel).x>>(msim.init_vel).y>>(msim.init_vel).z; 
	
	cout<<"Give the components of acceleration\n";
	cin>>(msim.acc).x>>(msim.acc).y>>(msim.acc).z;
	
	cout<<"Give the total time \n";
	cin>>total_t;
	
	cout<<"Give the time granualarity\n";
	cin>>delta_t;
	
	if((total_t<0)||(delta_t<0)){
		cout<<"Invalid input \n";
		return -1;
		}
	else {
	msim.delta_t=delta_t;
	msim.initialisesim();
	while(t<=total_t){
		msim.simstep();
		cout<<"time= "<<t<<" ";
		msim.printpos();
		t=t+delta_t;
		}
	}
return 0;
}
	
	

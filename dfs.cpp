#include<iostream>
#include<vector>

using namespace std;

void dfs(std::vector<std::vector<int>> &);
void dfsHelper(int in, std::vector<std::vector<int>> &, bool *);


int main(){
	
	int n ;
	cout<<"Enter the number of nodes\n";
	cin>>n;

	std::vector<std::vector<int>> v(n);
//	int * visited = new int[n];

	cout<<"Enter the number of edges\n";
	int e;
	cin>>e;
	for(int i = 0 ; i < e; i++){
		int sv , ev;
		cin>>sv>>ev;
		v[sv].push_back(ev);
		v[ev].push_back(sv);
	}
		
	dfs(v);
	return 0;
}

void dfs(std::vector<std::vector<int>> &v){
	bool * visited = new bool[v.size()];
	for(int i = 0; i < v.size(); i++)
	{
		if(!visited[i])
		dfsHelper(i,v,visited);
	}


}

void dfsHelper( int in ,std::vector<std::vector<int>> &v  , bool * visited ){
	visited[in] = true;
	cout<<in<<" ";
	for(auto element : v[in]){
		if(visited[element])
		continue;
//                cout<<element<<" ";		
		dfsHelper(element,v,visited);
	}
	return;
}
			

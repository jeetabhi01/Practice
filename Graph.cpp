/* ------------------------------------------------------------|
|                Author: Abhijeet Khopkar                      |
|               Central University of Haryana                  |
|--------------------------------------------------------------*/




class Edge{
    public:
    int startingV;
    int endingV;
    int cost;
    Edge(int sv, int ev,int cost){
        this->startingV = sv;
        this->endingV   = ev;
        this->cost      = cost;
    }
    Edge(){
        startingV = 0 ;
        endingV = 0 ;
        cost = 0;
    }

   void Setedges(int &a , int &b,int &c){
        this->startingV = a;
        this->endingV = b;
        this->cost = c;
        return;
    }
    
    ~Edge(){
        
    }
   
};
 bool compareEdge(const Edge &b, const Edge &a){
        return b.cost < a.cost;
    }

#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;

            #define ff          first
            #define ss          second
            #define eb          emplace_back
            #define mp          make_pair
            #define MOD         (long long)(10e9+7LL)
            #define ll          long long
            #define ld          long double

void printDFS(int **edges , bool *visited, int sv, int &n );
void printBFS(int ** edges, bool *visited, int sv , int &n);
void dfs(int ** edges, int &n);
void bfs(int ** edges, int &n);
Edge * kruskal(Edge * edges, int &n,int &e);
Edge * kruskalHelper(Edge * edges, bool * visited, int &n, int* parent);
int findParent(int , int* );
int main(){
   cout<<"Enter the number of nodes and edges\n";
   int n, e;
   cin>>n>>e;
   Edge * edges = new Edge[e];
   cout<<MOD<<std::endl;
   cout<<"Give the edges with their cost\n";
   for(int i = 0 ; i < e ; i++){
       int sv ,ev,cost;
       cin>>sv>>ev>>cost;
        edges[i].Setedges(sv,ev,cost);
        cout<<"\n---------------\n";
        cout<<edges[i].startingV<<" "<<edges[i].endingV<<" "<<edges[i].cost<<"\n";
   }
    auto output = kruskal(edges,n,e);
    for(int i = 0 ; i < n-1 ; i++){
        cout<<output[i].startingV<<" "<<output[i].endingV<<"\n";
    }
    return 0;
}

void dfs(int ** edges, int &n){
    bool * visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }

    for(int i = 0 ; i < n; i++){
        if(!visited[i]){
            printDFS(edges,visited,i, n);
        }
    }
    delete visited;
    return;
}

void bfs(int ** edges ,int &n){
    bool * visited = new bool[n];
    for(int i = 0 ;i  <n ; i++){
        visited[i] = false;
    }
    for(int i = 0 ; i < n;  i++){
        if(!visited[i])
        printBFS(edges,visited,i, n);
    }
    delete visited;
    return;
}

void printDFS(int ** edges, bool * visited, int sv ,int &n){
    cout<<sv<<endl;
    visited[sv] = true;

    for(int i = 0 ; i < n; i++){
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
        printDFS(edges,visited,i, n);
        }
    }
    return;
}

void printBFS(int ** edges, bool * visited, int sv, int &n){
    std::queue<int> pendingVertices;
    pendingVertices.push(sv);
    while(!pendingVertices.empty()){
        auto currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        visited[currentVertex] = true;
        for(int i = 0 ; i < n; i++){
            if(edges[currentVertex][i] == 1 && !visited[i]){
            pendingVertices.push(i);
            visited[i] = true;
            }
        }
    }
    return;
}

int findParent(int point , int * parent){
    if(parent[point] == point)
    return point;
    else
    return findParent(parent[point],parent);
    
}
Edge * kruskalHelper(Edge * edges, int &n, int* parent, int &e){
    std::sort(edges,edges+e, compareEdge);
    for(int i =0 ; i < e; i++){
        cout<<edges[i].cost<<" ";
    }
    Edge * minspantree = new Edge[n-1];

    int count = 0 ;
    
    for(int i = 0 ; i < e; i++){
        auto currentEdge = edges[i];;
        int startV = findParent(currentEdge.startingV,parent);
        int endV   = findParent(currentEdge.endingV,parent);
        if(startV == endV)    
            continue;
        else{
        minspantree[count] = edges[i];
        parent[startV] =  endV;
        count++;
        }
    }
    return minspantree;
}
Edge * kruskal(Edge * edges, int &n,int &e){
   
    int * parent = new int[n];
    for(int i = 0 ; i < n; i++){
        parent[i] = i;
    }
    auto output = kruskalHelper(edges,n,parent,e);
   
    delete parent;
    return output;
}


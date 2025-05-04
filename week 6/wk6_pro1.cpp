#include<bits/stdc++.h>
using namespace std;
/*
Find if path exists between two nodes of a undirected graph
*/

void addEdge(vector<vector<int> > &adj,int u,int v){
  adj[u][v]=1;
  adj[v][u]=1;
}

bool DFS(vector<vector<int> >&adj,int src,int dest,int vis[]){
	int n=adj.size();
  	if(src==dest)
        return true;
    vis[src]=1;
    for(int i=0;i<n;i++ ){
        if(!vis[i] && adj[src][i]==1){
            if(DFS(adj,i,dest,vis))
                return true;
        }
    }
    return false;
}

int main(){
  int n,e;
  cout<<"Enter no.of vertices and edges: ";
  cin>>n>>e;
  vector<vector<int> >adj(n,vector<int>(n,0));
  cout<<"Enter edges (u,v): ";
  int u,v,src,dest;
  for(int i=0;i<e;i++){
    cin>>u>>v;
    addEdge(adj,u,v);
  }
  cout<<"Enter source and destination node:" ;
  cin>>src>>dest;
  int vis[n]={0};
  if(DFS(adj,src,dest,vis)){
  	cout<<"Yes Path Exists.";
  }
  else{
  	cout<<"No Such Path Exists";
  }
  return 0;
}

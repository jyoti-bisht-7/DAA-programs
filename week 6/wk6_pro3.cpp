#include<bits/stdc++.h>
using namespace std;
/*
Find if cycle exists in a directed graph (DFS)
*/

bool DFS(int node,vector<vector<int> > &adj, int vis[],int pathVis[] ) {
    vis[node]=1;
    pathVis[node]=1;
    for(int it: adj[node]){
    	if(!vis[it]){
    		//not visited check for cycle
    		if(DFS(it,adj,vis,pathVis)){
    			return true;
			}
		}
		//visited and path visited also
		else if(pathVis[it]){
			return true;
		}
	}
	pathVis[node]=0;
	return false;
}

int main(){
  	int n, e;
    cout << "Enter no.of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int> > adj(n);
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
  	int vis[n]={0};
  	int pathVis[n]={0};
  	for(int i=0;i<n;i++){
  		if(!vis[i]){
  			if(DFS(i,adj,vis,pathVis)){
  				cout<<"Yes Cycle exists.";
  				return 0;
			}
		}
  	}
  	cout<<"No cycle exists.";
  	return 0;
}

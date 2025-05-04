#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>> &adj,int u,int v,int w){
  adj[u][v]=w;
}

void Dijkistra(vector<vector<int>>&adj,int s){
  int n=adj.size();
 
  //initialize distance array
  vector<int>dist(n,1e9);
  dist[s]=0;
  //initialize predecessor array
  vector<int>pii(n,-1);
 
  //create priority queue
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  pq.push({s,0});//push source node in queue
 
  while(!pq.empty()){
    //extract the node with minimum distance from queue
    auto it=pq.top();
    int u=it.first;
    int d=it.second;
    pq.pop();
    //check for adjacent nodes
    for(int i=0;i<n;i++){
      if(adj[u][i]){
        //Relax the edges
        if(dist[i]>d+adj[u][i]){
          dist[i]=d+adj[u][i];
          pii[i]=u;
          pq.push({i,dist[i]});
        }
      }
    }
  }
  cout<<"The distances and paths form akshay's house to friends' house are: \n:";
  for(int i=0;i<n;i++){
    if(i!=s){
      cout<<i<<endl;
      int j=i;
      cout<<j;
      while(j!=s){
        cout<<"<-"<<pii[j];
        j=pii[j];
      }
      cout<<"Distance: " <<dist[i]<<endl;
    }
   
  }
}

int main(){
  int n,e;
  cout<<"Enter no.of vertices and edges: ";
  cin>>n>>e;
  vector<vector<int>>adj(n,vector<int>(n,0));
  cout<<"Enter edges and weights (u,v,w): ";
  int u,v,s,w;
  for(int i=0;i<e;i++){
    cin>>u>>v>>w;
    addEdge(adj,u,v,w);
  }
  cout<<"Enter source node:" ;
  cin>>s;
  Dijkistra(adj,s);
}

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {

public:
  unordered_map<int,list<int>> adj;


 void addEdge(int u,int v, bool direction) {
    // direction = 0 -> undirected
    // direction = 1 -> directed

 // create edge
   adj[u].push_back(v);

   if (direction == 0)
   {
     adj[v].push_back(u);

   }
 }

 void printFns () {
 
    for(auto i:adj){
        cout << i.first << " -> ";
        for(auto j:i.second){
            cout << j << " , ";
        }
        cout << endl;
    }
 }
};

int main () {

 int n;
 cout << "Enter the number of nodes" << endl;
 cin >> n;

 int m;
 cout << "Enter the number of Edges" << endl;
 cin>> m;

 Graph g;
 for (int i = 0; i < m; i++)
 {
    int u,v;
    cin >> u >> v ;

    // create an undirected graph
    g.addEdge(u,v,0);
 }

 g.printFns();

 cout << sizeof(long  long int) << endl;
 
}
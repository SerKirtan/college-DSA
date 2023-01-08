#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
template <typename T>
class graph
{
public:
  unordered_map<T, list<T>> adj;

  void addEdge(T u, T v, bool direction)
  {
    // Direction = 0 means undirected graph and direction = 1 means directed graph

    adj[u].push_back(v);
    if (direction == 0)
      adj[v].push_back(u);
  }

  void adjPrintList()
  {
    for (auto i : adj)
    {
      cout << i.first << "-> ";
      for (auto j : i.second)
        cout << j << ", ";
      cout << endl;
    }
  }
};

int main()
{   
  int edges, nodes;
  cout << "Enter the number of nodes and edges : ";
  cin >> nodes >> edges;
  graph<int> g;
  cout << "Enter all edges : ";

  for( int i = 0 ; i < edges ; i++)
  {
    int u , v;
    cin >> u >> v;
    //creating an undirected graph
    g.addEdge( u , v , 0);
  }

  //printing graph
  g.adjPrintList();

  return 0;
}

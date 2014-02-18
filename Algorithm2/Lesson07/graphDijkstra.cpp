#include<iostream>
#include<string>
#include<list>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdio.h>

using namespace std;

class Adjacent; 

class Vertex {
	
  int  name;
  list<Adjacent> adj_list;
	
  bool flag;
  double value;
  Vertex* prev;
	
  Vertex( int n ) : name(n), flag(false), value(0.0), prev(NULL) { };
	
  void AddAdjacent( Vertex* v, double w );
  void PrintAdjList( );
	
  friend class Adjacent;
  friend class Graph;
};

class Adjacent {
  Vertex*  vertex;
  double   weight;
	
public:
  Adjacent( Vertex* v, double w ) : vertex(v), weight(w) { }; 
  Adjacent( ) : vertex(NULL), weight(0.0) { }; 
		
  bool operator > (const Adjacent & x ) const 
  {  
    if(vertex -> value > x.vertex -> value) return true;
    return false; 
  }
	
  friend class Vertex;
  friend class Graph;
};


void Vertex::AddAdjacent( Vertex* v, double w )
{ 
  adj_list.push_back( Adjacent( v, w ) ); 
}

void Vertex::PrintAdjList( )
{
  cout << name << ":";
  list<Adjacent>::iterator itr;
  for(itr = adj_list.begin(); itr != adj_list.end(); itr++){
    cout << itr -> vertex -> name << "(" << itr -> weight << ")" << " ";
  }
  cout << endl;
}

class Graph {
	
  map  < int, Vertex* > vmap;
  int   n_vertex;
  int   n_edge;
	
public:
  Graph ( ) : n_vertex(0), n_edge(0) { };
  void AddEdge( int v1, int v2, double weight );
  void AddUndirectedEdge( int v1, int v2, double weitht);
  void PrintAdjList( );
  void Dijkstra( int start );
	
};


void Graph::Dijkstra( int start )
{
  if( vmap.find( start ) == vmap.end() ){
    cout << "There is no starting node" << endl;
    return;
  }

  Vertex* v = vmap[start];
	
  priority_queue< Adjacent, vector<Adjacent>, greater<Adjacent> > pq; 
 	
  int n = 0;
  v -> value = 0;
	
  while( true )
    {		
      v -> flag = true;
      n++;
		
      if( n == n_vertex)
	break;

      list<Adjacent>::iterator itr;
      for (itr = v -> adj_list.begin(); itr != v -> adj_list.end(); itr++)
	{
	  Vertex* w = itr -> vertex;
			
	  if( !w -> flag ){ 
	    if( w -> value == 0 || v -> value + itr -> weight < w -> value){
	      w -> value = v -> value + itr -> weight;
	      w -> prev = v;
	      pq.push(*itr);
	    }
	  }
	}

      while( true )
	{
	  if( pq.empty() ){
	    cout << "There is no path from start to end node" << endl;
	    return;
	  }
	  v = pq.top().vertex; 
	  pq.pop();
			
	  if( !v -> flag ){
	    //cout << "break" << endl;
	    break;
	  }
	}
    }
}


void Graph::AddUndirectedEdge(int v1name, int v2name, double weight)
{
	
  AddEdge(v1name, v2name, weight);
  AddEdge(v2name, v1name, weight);
	
}


void Graph::AddEdge( int v1name, int v2name, double weight )
{   
  if ( vmap.find(v1name) == vmap.end() ) {
    vmap[ v1name ] = new Vertex( v1name );
    n_vertex++;
  }
  if ( vmap.find(v2name) == vmap.end() ) {
    vmap[ v2name ] = new Vertex( v2name );
    n_vertex++;
  }
  vmap[ v1name ] ->AddAdjacent( vmap[ v2name ], weight );
  n_edge++;
}

void Graph::PrintAdjList()
{
  cout <<"Min Length: "<< vmap[n_vertex-1] -> value << endl;
}


int main()
{
  Graph g;
	
  int nodeNum;
	
  scanf("%d¥n", &nodeNum);
  int start;
  int end;
  double weight;
	
  while(cin >> start >> end >> weight){
    g.AddEdge(start, end, weight);
  }
  cout << "Node number: " << nodeNum << endl;
	
  g.Dijkstra(0);
  g.PrintAdjList();
	
  return 0;
} 

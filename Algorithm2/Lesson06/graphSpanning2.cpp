#include<iostream>
#include<string>
#include<list>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

class Vertex;

class Adjacent {
  Vertex*  vertex;
  double   weight;
	
public:
  Adjacent( Vertex* v, double w ) : vertex(v), weight(w) { }; 
  Adjacent( ) : vertex(NULL), weight(0.0) { }; 
		
  friend class Vertex;
  friend class Graph;
};

class Vertex {
	
  string           name;
  list<Adjacent>   adj_list;
	
  bool flag;
  double value;
  Vertex* prev;
	
  Vertex( string n ) : name(n), flag(false), value(0.0), prev(NULL) { };
	
  void AddAdjacent( Vertex* v, double w )
  { adj_list.push_back( Adjacent( v, w ) ); };
  void PrintAdjList( );
	
  friend class Graph;
};


void Vertex::PrintAdjList( )
{
  if(prev == NULL) return;
  cout << prev -> name <<"-("<< value <<")-"<< name << endl;
}

class Graph {
	
  map  < string, Vertex* > vmap;
  int   n_vertex;
  int   n_edge;
	
public:
  Graph ( ) : n_vertex(0), n_edge(0) { };
  void AddEdge( string v1, string v2, double weight );
  void AddUndirectedEdge( string v1, string v2, double weitht);
  void PrintAdjList( );
  void Prim( string start);
	
};


void Graph::Prim( string start )
{
  if( vmap.find( start ) == vmap.end() )
    return;
	
  Vertex* v = vmap[start];
	
  vector< Adjacent> edge_set;
 	
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
	    if ( w -> value == 0 || w -> value > itr -> weight ) { 
	      edge_set.push_back(*itr);
	    }
	  }
	}

      while( true )
	{
	  if( edge_set.empty() ){
	    cout << "There is no spanning tree" << endl;
	    return;
	  }

	  vector<Adjacent>::iterator itrv = edge_set.begin();
	  itrv++;
	  for(; itrv != edge_set.end(); itrv++){
	    Adjacent tmp = *itrv;
	    vector<Adjacent>::iterator right = itrv;
	    vector<Adjacent>::iterator left = --itrv;
	    itrv++;
	    if(left -> weight > tmp.weight){
	      do{
		*right = *left;
		right--;
		left--;
	      }while(right != edge_set.begin() && left -> weight > tmp.weight);
	      *right = tmp;
	    }
	  }

	  map<string,Vertex*>::iterator itrm;
	  list<Adjacent>::iterator itrl;
	  bool fin = false;
	  while(true){
	    for(itrm = vmap.begin(); itrm != vmap.end(); itrm++){
	      if(!itrm -> second -> flag) continue;
	      for(itrl = itrm -> second -> adj_list.begin(); itrl != itrm -> second -> adj_list.end(); itrl++){
		if(itrl -> weight != edge_set.begin() -> weight || itrl -> vertex == vmap[start]) continue;
		if(itrm -> second -> prev != NULL && itrm -> second -> prev == itrl -> vertex) continue;
		if(itrl -> vertex -> prev != NULL) continue;
		itrl -> vertex -> value = itrl -> weight;
		itrl -> vertex -> prev = itrm -> second;
		v = itrl -> vertex;
		vector<Adjacent>::iterator iter = edge_set.begin();
		edge_set.erase(iter);
		fin = true;
		break;
	      }
	      if(fin) break;
	    }
	    if(fin) break;
	    vector<Adjacent>::iterator iter = edge_set.begin();
	    edge_set.erase(iter);
	  }

	  if( !v -> flag ){
	    break;
	  }
	}
    }	
}



void Graph::AddUndirectedEdge(string v1name, string v2name, double weight)
{
	
  AddEdge(v1name, v2name, weight);
  AddEdge(v2name, v1name, weight);
	
}


void Graph::AddEdge( string v1name, string v2name, double weight )
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
  map<string,Vertex*>::iterator itr;
  for(itr = vmap.begin(); itr != vmap.end(); itr++){
    itr -> second -> PrintAdjList();
  }

}


int main()
{
  Graph g;
	
  g.AddUndirectedEdge( "A", "B", 2.0 );
  g.AddUndirectedEdge( "C", "A", 4.0 );
  g.AddUndirectedEdge( "A", "D", 1.0 );
  g.AddUndirectedEdge( "B", "D", 3.0 );
  g.AddUndirectedEdge( "B", "E", 10.0 );
  g.AddUndirectedEdge( "C", "F", 5.0 );
  g.AddUndirectedEdge( "D", "C", 2.0 );
  g.AddUndirectedEdge( "D", "E", 2.0 );
  g.AddUndirectedEdge( "D", "F", 8.0 );
  g.AddUndirectedEdge( "D", "G", 4.0 );
  g.AddUndirectedEdge( "E", "G", 6.0 );
  g.AddUndirectedEdge( "G", "F", 1.0 );
	
  g.Prim("A");
  g.PrintAdjList();
  cout << endl;
	
  return 0;
}

#include<iostream>
#include<string>
#include<list>
#include<map>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Vertex;

class Adjacent {
    Vertex*  vertex;
    double   weight;
	
public:
    Adjacent( Vertex* v, double w ) : vertex(v), weight(w) { }; 
    Adjacent( ) : vertex(NULL), weight(0.0) { }; 
	
    bool operator > (const Adjacent & x ) const 
	{  return (weight > x.weight ); }
	
    //  const を付け忘れるとコンパイルできない。
	
	friend class Vertex;
	friend class Graph;
};

class Vertex {
    
    int name;
    int x;
    int y;
    list<Adjacent>   adj_list;
	
	bool flag;
	double value;
	Vertex* prev;
	
    Vertex( int px, int py, int n ) : name(n), flag(false), value(0.0), prev(NULL), x(px), y(py) { };
	
    void AddAdjacent( Vertex* v, double w )
	{ adj_list.push_back( Adjacent( v, w ) ); };
    void PrintAdjList( );
	
	friend class Graph;
};


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
	void Prim( int start);
    void SetVertex(int x,int y);
	
};


void Graph::Prim( int start )
{
	if( vmap.find( start ) == vmap.end() )
		return;
	

	Vertex* v = vmap[start];
	
	priority_queue< Adjacent, vector<Adjacent>, greater<Adjacent> > pq; 
 	
	int n = 0;
	v -> value = 0;
    int sum = 0;
	
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
					w -> prev = v;
					w -> value = itr -> weight;
					pq.push(*itr);
				}
			}
		}

		while( true )
		{
			
			if( pq.empty() ){
				cout << "There is no spanning tree" << endl;
				return;
			}
			v = pq.top().vertex; 
			pq.pop();
			if( !v -> flag ){
				break;
			}
		}
        sum += v -> value;

	}
    cout <<"Total Length:"<< sum << endl;
	
}


void Graph::AddUndirectedEdge(int v1name, int v2name, double weight)
{
	
	AddEdge(v1name, v2name, weight);
	AddEdge(v2name, v1name, weight);
	
}


void Graph::AddEdge( int v1name, int v2name, double weight )
{   
    vmap[ v1name ] -> AddAdjacent( vmap[ v2name ], weight );
    n_edge++;
}

void Graph::PrintAdjList()
{
	map<int, Vertex*>::iterator itr;
	for( itr = vmap.begin(); itr != vmap.end(); itr++ ){
		itr -> second -> PrintAdjList();
	}
}

void Graph::SetVertex(int x,int y)
{
    if(vmap.find(10 * x + y) != vmap.end())
        return;
    
    vmap[10 * x + y] = new Vertex(x,y,10 * x + y);
    n_vertex++;
    map<int,Vertex*>::iterator itr;
    for(itr = vmap.begin(); itr != vmap.end(); itr++){
        if(itr -> second -> name == 10 * x + y)
            continue;
        int px = x - itr -> second -> x;
        int py = y - itr -> second -> y;
        AddUndirectedEdge(10 * x + y, itr -> second -> name, sqrt( px * px + py * py));
    }
}


int main()
{
	Graph g;
	int x,y;
    
    cin >> x;
    while(cin >> x >> y){
        g.SetVertex(x,y);
    }
	
	g.Prim(0);
	g.PrintAdjList();
	cout << endl;
	
	return 0;
} 


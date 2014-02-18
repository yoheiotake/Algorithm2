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
    int down;
    int amount;
    list<Adjacent> adj_list;
	
    bool flag;
    double value;
    Vertex* prev;
	
    Vertex( int n,int p_down ) : name(n), down(p_down),flag(false), value(0.0), prev(NULL),amount(0) { };
	
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
    if(prev != NULL) prev -> PrintAdjList();
    cout << name <<" -> ";
}

class Graph {
	
    map  < int, Vertex* > vmap;
    int   n_vertex;
    int   n_edge;
	
public:
    Graph ( ) : n_vertex(0), n_edge(0) { };
    void AddEdge( int v1, int v2, double weight );
    void AddUndirectedEdge( int v1, int v2, double weight);
    void PrintAdjList( );
    void Dijkstra( int start ,int init_data);
    void SetVertex(int name,int down);
	
};


void Graph::Dijkstra( int start,int init_data )
{
    if( vmap.find( start ) == vmap.end() ){
        cout << "There is no starting node" << endl;
        return;
    }
    
    Vertex* v = vmap[start];
	
    priority_queue< Adjacent, vector<Adjacent>, greater<Adjacent> > pq;
 	
    int n = 0;
    v -> amount = init_data;
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
                if( w -> value == 0 || v -> value + itr -> weight * v -> amount + 100 < w -> value){
                    w -> value = v -> value + itr -> weight * v -> amount + 100;
                    w -> amount = v -> amount - w -> down;
                    if(w -> amount < 0) w -> amount = 0;
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
    vmap[ v1name ] ->AddAdjacent( vmap[ v2name ], weight );
    n_edge++;
}

void Graph::PrintAdjList()
{
    cout <<"Min Length: "<< vmap[n_vertex-1] -> value << endl;
    cout <<"Min path: "<< endl;
    vmap[n_vertex-1] -> prev -> PrintAdjList();
    cout << vmap[n_vertex-1] -> name << endl;
}

void Graph::SetVertex(int name,int down){
    if(vmap.find(name) != vmap.end())
        return;
    vmap[name] = new Vertex(name,down);
    n_vertex++;
}


int main()
{
    Graph g;
	
    int num,amount;
    cin >> num >> amount;
    
    int start;
    int end;
    cin >> start >> end;
    
    int v,d;
    for(int i = 0; i < num ; i++){
        cin >> v >> d;
        g.SetVertex(v,d);
    }
	
    int s,e,dist;
    while(cin >> s >> e >> dist){
        g.AddEdge(s, e, dist);
    }
    cout << "Node number: " << num << endl;
	
    g.Dijkstra(0,amount);
    g.PrintAdjList();
	
    return 0;
} 

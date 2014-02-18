#include<iostream>
#include<string>
#include<list>
#include<map>
#include<queue>
#include<algorithm>
#include<stdio.h>
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
	
    int           name;
    list<Adjacent>   adj_list;
	int indNum;
	
    Vertex( int n ) : name(n) { };
	
    void AddAdjacent( Vertex* v, double w )
	{ adj_list.push_back( Adjacent( v, w ) ); };
   	
	friend class Graph;
};


class Graph {
	
    map  < int, Vertex* > vmap;
    int   n_vertex;
    int   n_edge;
	
public:
    Graph ( ) : n_vertex(0), n_edge(0) { };
    void AddEdge( int v1, int v2, double weight );
	void CompIndegree( );
	void CompTopSort( );
};


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

void Graph::CompIndegree()
{
    map<int,Vertex*>::iterator itr;
    list<Adjacent>::iterator itrl;
    for(itr = vmap.begin(); itr != vmap.end(); itr++){
        for(itrl = itr -> second -> adj_list.begin(); itrl != itr -> second -> adj_list.end(); itrl++)
            itrl -> vertex -> indNum++;
    }
}

void Graph::CompTopSort(){
    map<int,Vertex*>::iterator itr;
    list<Adjacent>::iterator itrl;
    queue<Vertex*> q;
    for(itr = vmap.begin(); itr != vmap.end(); itr++)
        if(itr -> second -> indNum == 0)
            q.push(itr -> second);
    
    while(!q.empty()){
        cout << q.front() -> name;
        for(itrl = q.front() -> adj_list.begin(); itrl != q.front() -> adj_list.end(); itrl++)
            if(--itrl -> vertex -> indNum == 0)
                q.push(itrl -> vertex);
        q.pop();
        if(q.empty() || cout <<"->");
    }
}


int main()
{
	Graph g;
	
    int p1,p2,p3;
    cin >> p1;
    
    while(cin >> p1 >> p2 >> p3){
        g.AddEdge(p1,p2,p3);
    }
	
	g.CompIndegree();
    g.CompTopSort();
	
	cout << endl;
	
	return 0;
}

// 実行方法: cat sample.txt | ./a.out

#include <iostream>
#include <new>
#include <cassert>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class PriorityQueue {
	
  class Cell {
		
  public:
    int  data;
    Cell* next;
		
    Cell( int x, Cell* p ) : data(x), next(p) {} ;
  };
	
  Cell* top;
	
public:
  PriorityQueue();  
  ~PriorityQueue();  
  void Enqueue(int x); 
  void DequeueMin();   
  void Dump();
  int Min() const;
  bool IsEmpty() const;
};


PriorityQueue::PriorityQueue() 
{
  top = NULL;
}

PriorityQueue::~PriorityQueue() 
{
  while ( ! IsEmpty() )
    DequeueMin( );
}

void PriorityQueue::Enqueue( int x ) 
{
  // データは値の小さい順に並べておく。
  if ( top == NULL || top->data >= x ) {
    top = new Cell( x, top );
  }
  else {
    Cell* p = top;
    // データを挿入すべき場所を探す。
    while ( p->next != NULL && p->next->data < x ) {
      p = p->next;
    }
    p->next = new Cell( x, p->next );
  }
}

void PriorityQueue::DequeueMin(  ) 
{
  assert ( top != NULL ); //異常判定 要素が無い場合
  Cell* oldtop = top;
  top = top->next;
  delete oldtop;
}

void PriorityQueue::Dump( )
{
  for ( Cell* p = top; p != NULL; p = p->next )
    cout << p->data << endl;
  return;
}

int PriorityQueue::Min( ) const {
	
  return top->data;
}

bool PriorityQueue::IsEmpty( ) const
{
  return ( top == NULL  );
}

int main()
{
	
  try{
    int data, num;
    scanf("num:%d\n", &num);
				
    PriorityQueue q;
		
    while(scanf("%d\n", &data) != EOF){
      q.Enqueue(data);
    }
		
    while ( ! q.IsEmpty() )  {
      cout << q.Min() << endl;
      q.DequeueMin();
    }
		
  }catch(const char* str ){
    cout << str << endl;
  }
	
  return 0;
	
}


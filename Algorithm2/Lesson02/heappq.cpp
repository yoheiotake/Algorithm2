#include <iostream>
#include <new>
#include <vector>
#include <stdio.h>
using namespace std;


void swap(int& x, int& y);

class PriorityQueue {
	
  int* array;
  int  size;
  int  ndata;
	
public:
  PriorityQueue( int queue_size );
  ~PriorityQueue( );
  void Enqueue(int data);
  void DequeueMin();   
  int  Min() const;
  bool IsEmpty() const;
  void Show() const;
	
};


PriorityQueue::PriorityQueue( int queue_size ) 
{
  array = new int [ queue_size ];
  size = queue_size;
  ndata = 0;
}

PriorityQueue::~PriorityQueue( ) 
{
  delete [] array;
}

void PriorityQueue::Enqueue( int data ) 
{
  if ( ndata >= size ) 
    throw " Queue overflow ";
	
  int parent;
  int i = ndata;
	
  while ( i > 0 ) {
    parent = (int) (i-1)/2;
    if ( array[ parent ] > data ) {
      array[ i ] = array[ parent ];
      i = parent; 
    }
    else
      break;
  }
  array[i] = data; 
  ndata++;
}

void PriorityQueue::DequeueMin( ) 
{
  if(ndata <= 0) return;

  int tmp = array[ndata-1];
  int parent = 0;
  int x = (int)(ndata-1)/2;

  while(x > parent){
    int child = parent*2+1;

    if(array[child] > array[child+1]) child++;
    if(array[child] > tmp) break;

    array[parent] = array[child];
    parent = child;
  }
  array[parent] = tmp;
  ndata--;
}



int PriorityQueue::Min( ) const
{
  return array[0];
}

bool PriorityQueue::IsEmpty( ) const
{
  return ( ndata <= 0 );
}


void PriorityQueue::Show() const
{
	
  for(int i = 0; i < ndata; i++){
    cout << array[i] << ". ";
  }
  cout << endl;
}

void swap(int &x, int &y){
	
  int temp = x;
  x = y;
  y = temp;
	
}


int main()
{
	
  try{
    int data, num;
    scanf("num:%d\n", &num);
		
    cout << "num is " << num << endl;
		
    PriorityQueue q(num);
		

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

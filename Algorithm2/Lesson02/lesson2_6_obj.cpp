#include <iostream>
#include <new>
#include <vector>
#include <stdio.h>
using namespace std;


void swap(int& x, int& y);

class NSObject{
private:
  int data;
  string name;
public:
  NSObject();
  ~NSObject();
  int get_data(){ return data; };
  void insert_data(int i){ data = i; };
};

NSObject::NSObject(){
  data = 0;
}

NSObject::~NSObject(){

}

class PriorityQueue {
	
  NSObject* array;
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
  array = new NSObject [ queue_size ];
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
    if ( array[ parent ].get_data() > data ) {
      array[i].insert_data(array[parent].get_data());
      i = parent; 
    }
    else
      break;
  }
  array[i].insert_data(data);
  ndata++;
}

void PriorityQueue::DequeueMin( ) 
{
  if(ndata <= 0) throw "Queue UnderFlow";

  int tmp = array[ndata-1].get_data();
  int parent = 0;
  int x = (int)(ndata-1)/2;

  while(parent < x){
    int child = 2*parent + 1;
    if(array[child].get_data() > array[child+1].get_data()) child++;
    if(array[child].get_data() > tmp) break;

    array[parent].insert_data(array[child].get_data());
    parent = child;
  }
  array[parent].insert_data(tmp);
  ndata--;
}



int PriorityQueue::Min( ) const
{
  return array[0].get_data();
}

bool PriorityQueue::IsEmpty( ) const
{
  return ( ndata <= 0 );
}


void PriorityQueue::Show() const
{
	
  for(int i = 0; i < ndata; i++){
    cout << array[i].get_data() << ". ";
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

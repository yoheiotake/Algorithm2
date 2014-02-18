#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct box{
  int num;
  string name;
};

class PriorityQueue {
	
  struct box* array;
  int  size;
  int  ndata;
	
public:
  PriorityQueue( struct box* p,int array_size);
  ~PriorityQueue( );
  void Enqueue(string name,int data);
  void DequeueMin();   
  string Min() const;
  bool IsEmpty() const;
  void Show() const;
	
};

PriorityQueue::PriorityQueue( struct box* p,int array_size)
{
  array = p;
  size = array_size;
  ndata = 0;
}

PriorityQueue::~PriorityQueue( ) 
{
  delete [] array;
}

void PriorityQueue::Enqueue( string name,int data ) 
{
  
  if ( ndata >= size )
    throw " Queue overflow ";
	
  int parent;
  int i = ndata;
	
  while ( i > 0 ) {
    parent = (int) (i-1)/2;
    if ( array[ parent ].num > data ) {
      array[ i ].num = array[ parent ].num;
      array[ i ].name = array[ parent ].name;
      i = parent; 
    }
    else if(array[parent].num == data && array[parent].name > name ){
      array[i].name = array[parent].name;
      i = parent;
    }
    else{
      break;
    }
  }
  array[i].num = data;
  array[i].name = name;
  ndata++;
}

void PriorityQueue::Show() const
{
	
  for(int i = 0; i < ndata; i++){
    cout << array[i].name << ". ";
  }
  cout << endl;

  for(int i = 0; i < ndata; i++){
    cout << array[i].num << ". ";
  }
  cout << endl;
}

string PriorityQueue::Min( ) const
{
  return array[0].name;
}

void PriorityQueue::DequeueMin( ) 
{
  if(ndata <= 0)
    throw "Queue underflow";

  int tmp = array[ndata-1].num;
  string tmp_name = array[ndata-1].name;
  int parent = 0;
  int x = (int)(ndata-1)/2;

  while(x > parent){
    int child = parent*2+1;

    if(array[child].num > array[child+1].num || (array[child].num == array[child+1].num && array[child].name > array[child+1].name)) child++;
    if(array[child].num > tmp || (array[child].num == tmp && array[child].name > tmp_name)) break;
    
    array[parent].num = array[child].num;
    array[parent].name = array[child].name;
    parent = child;
  }
  array[parent].num = tmp;
  array[parent].name = tmp_name;
  ndata--;

}

bool PriorityQueue::IsEmpty( ) const
{
  return ( ndata <= 0 );
}

int main(){

  try{
    int size = 10;
    char buf[10];
    int  num[10];

    //struct box array[size];
    struct box *p = new box[size];

    //PriorityQueue q(array,size);
    PriorityQueue q(p,size);
  
    while( scanf("%s\n",buf) != EOF){
      scanf("%d\n",num);
      q.Enqueue(buf,*num);
    }

    q.Show();

    while ( ! q.IsEmpty() )  {
      cout << q.Min() << endl;
      q.DequeueMin();
    }
    
  }catch(const char* str){
    cout << str << endl;
  }

  return 0;
}

#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<stdio.h>
#include<ctime>
using namespace std;

class HashSeparate
{
  list<int>* table;
  int  table_size;
  int  ndata;
	
public:
  HashSeparate( int size );
  ~HashSeparate( );
  bool Insert( int key );
  bool Find( int key ) const;
  void Show() const;
	
private:
  int hash( int key ) const { return key % table_size; };
};

HashSeparate::HashSeparate( int size )
{
  table = new list<int>[size];
  table_size = size;
  ndata = 0;
}

HashSeparate::~HashSeparate( )
{
  delete [] table;
}

bool HashSeparate::Insert( int key )
{
  if(Find(key)) return false;
  table[hash(key)].push_front(key);

  ndata++;
  return true;
}

bool HashSeparate::Find( int key ) const
{
  list<int>::iterator itr;
  itr = find(table[hash(key)].begin(),table[hash(key)].end(),key);
  if(itr == table[hash(key)].end()) return false;
  return true;
}


void HashSeparate::Show() const
{
  for(int i = 0 ; i < table_size; i++)
    {
      list<int> l = table[i];
      if( !l.empty() ){
	list<int>::iterator itr;
	for(itr = l.begin(); itr != l.end(); itr++){
	  cout << (*itr) << ". ";
			
	}
	cout << endl;
      }
    }
}

int main()
{
  int size,data;
  scanf("num:%d\n",&size);
  HashSeparate score(size);
  while(scanf("%d\n",&data) != EOF){
    score.Insert(data);
    }
		
  int times = 100;
  int target;
  srand(time(NULL));

  clock_t begin = clock();
  for(int i = 0;i < times; i++){
    target = rand()%(size*5);
    cout << target <<" : "<< score.Find(target) << endl;
  }
  clock_t end = clock();
  cout <<"Time is "<< (double)(end - begin)/CLOCKS_PER_SEC << endl;
  return 0;
}

#include<iostream>
#include<string>
#include<list>
#include<algorithm>

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
  else table[hash(key)].push_front(key);

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
  HashSeparate score(100);
  score.Insert(100);	
  score.Insert(120);
  score.Insert(4501);
  score.Insert(200);
		
  cout << score.Find(200) << endl;
  cout << score.Find(10) << endl;
  cout << score.Find(0) << endl;
  cout << score.Find( 100) << endl;
  cout << score.Find(4501) << endl;
  cout << score.Find(4500) << endl;
	
  return 0;
}

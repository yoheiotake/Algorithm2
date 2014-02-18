#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

class HashSeparate
{
  map<int, int>* table;
  int  table_size;
  int  ndata;
	
public:
  HashSeparate( int size );
  ~HashSeparate( );
  bool Insert( int key, int value );
  bool Find( int key, int & value ) const;
  void Show() const;
	
private:
  int hash( int key ) const { return key % table_size; };
};

HashSeparate::HashSeparate( int size )
{
  table = new map<int, int>[size];
  table_size = size;
  ndata = 0;
}

HashSeparate::~HashSeparate( )
{
  delete [] table;
}

bool HashSeparate::Insert( int key, int value )
{
  if(Find(key,value)) return false;
  table[hash(key)][key] = value;
  ndata++;
  return true;
}

bool HashSeparate::Find( int key, int & value ) const
{
  map<int,int>::iterator itr;
  itr = table[hash(key)].find(key);
  if(itr == table[hash(key)].end()) return false;
  return true;
}

void HashSeparate::Show() const
{
  for(int i = 0 ; i < table_size; i++)
    {
      map<int, int> m = table[i];
      if( !m.empty() ){
	map<int, int>::iterator itr;
	for(itr = m.begin(); itr != m.end(); itr++){
			
	  cout << itr -> first << ", " << itr -> second << ".";
			
	}
	cout << endl;
      }
    }
}

int main()
{
  HashSeparate score(10);
	
  score.Insert(100,100);
  score.Insert(23,23);
  score.Insert(33,33);
  score.Insert(0,0);
  score.Insert(3,3);
	
  int i;
	
  cout << score.Find(33,i) << endl;
  cout << score.Find(10,i) << endl;
  cout << score.Find(3,i) << endl;

		
  return 0;
}

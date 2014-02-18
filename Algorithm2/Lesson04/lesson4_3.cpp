#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

template<class KT,class VT>
class HashSeparate
{
  map<KT, VT>* table;
  int  table_size;
  int  ndata;
	
public:
  HashSeparate( int size );
  ~HashSeparate( );
  bool Insert( KT key, VT value );
  bool Find( KT key, VT & value ) const;
  void Show() const;
	
private:
  KT hash( KT key ) const { return key % table_size; };
};

template<class KT,class VT>
HashSeparate<KT,VT>::HashSeparate( int size )
{
  table = new map<KT, VT>[size];
  table_size = size;
  ndata = 0;
}

template<class KT,class VT>
HashSeparate<KT,VT>::~HashSeparate( )
{
  delete [] table;
}

template<class KT,class VT>
bool HashSeparate<KT,VT>::Insert( KT key, VT value )
{
  if(Find(key,value)) return false;
  table[hash(key)][key] = value;
  ndata++;
  return true;
}

template<class KT,class VT>
bool HashSeparate<KT,VT>::Find( KT key, VT & value ) const
{
  typename map<KT,VT>::iterator itr;
  itr = table[hash(key)].find(key);
  if(itr == table[hash(key)].end()) return false;
  return true;
}

template<class KT,class VT>
void HashSeparate<KT,VT>::Show() const
{
  for(int i = 0 ; i < table_size; i++)
    {
      map<KT, VT> m = table[i];
      if( !m.empty() ){
	typename map<KT, VT>::iterator itr;
	for(itr = m.begin(); itr != m.end(); itr++){
			
	  cout << itr -> first << ", " << itr -> second << ".";
			
	}
	cout << endl;
      }
    }
}

int main()
{
  HashSeparate<int,int> score(10);
	
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

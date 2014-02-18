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
  int hash( KT key ) const;
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

template<class KT,class VT>
int HashSeparate<KT,VT>::hash( KT key ) const{
  unsigned int x = 0;
  for(int i = 0; i < (int)key.length();i++)
    x = (x*128 + key[i]) % table_size;
  return x;
}

int main()
{
  HashSeparate<string,int> staff(10);
	
  staff.Insert("mino",10);
  staff.Insert("yoshi",20);
  staff.Insert("nabe",30);
  staff.Insert("masaki",40);

  int dummy;

  cout << staff.Find("mino",dummy) << endl;
  cout << staff.Find("yama",dummy) << endl;
		
  return 0;
}

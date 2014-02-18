#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<stdio.h>
#include<ctime>
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
  int size = 10000000;
  HashSeparate<string,int> staff(size);
	
  string key;
  int data;

  clock_t begin1 = clock();
  while(cin >> key >> data){
    staff.Insert(key,data);
  }
  clock_t end1 = clock();

  //int times = 100000;
  int dummy;

  clock_t begin2 = clock();
  for(int i = 0; i < size; i++){
    staff.Find("mino",dummy);
  }
  clock_t end2 = clock();

  cout <<"サイズ : "<< size << endl;
  cout <<"挿入時間 : "<< (double)(end1 - begin1)/CLOCKS_PER_SEC << endl;
  cout <<"検索時間 : "<< (double)(end2 - begin2)/CLOCKS_PER_SEC << endl;
  return 0;
}

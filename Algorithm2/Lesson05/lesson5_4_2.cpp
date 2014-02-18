#include <iostream>
#include <string>
#include <new>
using namespace std;

template< class KT, class VT >
class HashTable
{
  enum EntryType { ACTIVE, EMPTY, ERASED };
	
  class HashEntry
  {
    KT key;
    VT value;
    EntryType status;
		
  public:
    HashEntry(  ){ status = EMPTY; };
		
    friend class HashTable;
  };
	
  HashEntry* table;
	
  int table_size;
  int nempty;
  int collision;
	
public:
  HashTable( int n );
  ~HashTable( );
  bool Insert( KT key, VT value );
  bool Find( KT key, VT & value ) const; 
  bool Erase( KT key );
	
private:
  unsigned int hash( int i ) const { return i % table_size; };
  unsigned int hash( const string & s ) const ; 
  unsigned int nexthash ( unsigned int h ) const 
  { return (h+1) % table_size; };
  unsigned int hash2(const string & key) const;
  unsigned int hash3(const string & key) const;
	
};

template< class KT, class VT >
HashTable<KT,VT>::HashTable( int size )
{ 
  table_size = size;
  table  =  new HashEntry[table_size];
  nempty = table_size;
}

// 文字列用のハッシュ関数（一例） 
// (ASCII文字コードの文字列変換によく用いられるもの)
template< class KT, class VT >
unsigned int HashTable<KT,VT>::hash( const string & key ) const 
{
  unsigned int x = 0; // ハッシュ値は非負整数 (0以上の整数) である
  // ASCII文字は 1バイト (=8ビット=2^8 = 128) で表される
  // ASCIIコード表により，各文字 (半角英数字を含む) がどの数字に
  // 対応するか決められている．
  for( int i = 0; i < (int)key.length(); i++ ){
    // key[i]: keyのi番目の文字コード (ASCIIコード表に定められた数字が入る)
    x = ( x * 128 + key[i] ) % table_size;
  }
  return x;    
}

template< class KT, class VT >
HashTable<KT,VT>::~HashTable( )
{
  delete [] table;
}

template< class KT, class VT >
bool HashTable<KT,VT>::Insert( KT k, VT v )
{
	
  if ( Find( k, v ) ) return false;
	
  if ( nempty <= 1 )
    throw " Hash table is full ";
	
	
  int h = hash3(k);
  collision = 0;
  while ( table[h].status == ACTIVE ){
    h = nexthash( h );
    collision++;
  }
   cout <<"Collision = "<< collision << endl;
	
  table[h].key = k;
  table[h].value = v;
	
  if ( table[h].status == EMPTY ) 
    nempty--;
	
  table[h].status = ACTIVE;
	
  return true;
}


template< class KT, class VT >
bool HashTable<KT,VT>::Find( KT key, VT & value) const
{
  for(int h=hash3(key),n=0; table[h].status != EMPTY && n < table_size; h=nexthash(h),n++){
    if(table[h].key == key && table[h].status != ERASED){
      value = table[h].value;
      return true;
    }
  }
  return false;
}

template< class KT, class VT >
bool HashTable<KT,VT>::Erase( KT key )
{
  for(int h=hash3(key),n=0; table[h].status != EMPTY && n < table_size; h=nexthash(h),n++){
    if(table[h].key == key){
      table[h].status = ERASED;
      return true;
    }
  }
  return false;
}


template< class KT, class VT >
unsigned int HashTable<KT,VT>::hash2( const string & key ) const
{
  unsigned int x = 0; // ハッシュ値は非負整数 (0以上の整数) である
  for( int i = 0; i < (int)key.length(); i++ ){
    x += key[i];
  }

  x = x % table_size;
  return x;    
}

template< class KT, class VT >
unsigned int HashTable<KT,VT>::hash3( const string & key ) const
{
  unsigned int x = 0;
  for(int i = 0; i < (int)key.length(); i++){
    x += key[i];
    x += (x << 10);
    x ^= (x >> 6);
  }
  x += (x << 3);
  x ^= (x >> 11);
  x += (x << 15);
  x = x % table_size;
  return x;   
}

int main()
{

  try {
		
    HashTable<string, int> score(100);

    string key;
    int value;

    while(cin >> key >> value){
      score.Insert(key,value);
    }
		
    int i;
		
    if ( score.Find( "mino", i ) )
      cout <<   i  <<  endl;
    else
      cout <<"Not Found"<< endl;
		
  }
  catch ( bad_alloc ba ) {
    // new演算子によるメモリ確保に失敗したときにスローされる
    cout << " memory allocation error." << endl;
  }
  catch ( const char* msg ) {
    // nemptyが1以下のとき要素を追加しようとしたときスローされる
    cout << msg << endl;
  }
	
  return 0;
	
}

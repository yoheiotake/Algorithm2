#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<stdio.h>
#include<ctime>
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
  int size,num,data;
  size = 1000000;

  HashSeparate score(size);
  
  scanf("num:%d\n",&num);
  while(cin >> data){
    score.Insert(data,data);
  }
  
	
  int times = 1000000;
  int target;
  int dummy;
  srand(time(NULL));

  clock_t begin = clock();
  for(int i=0;i < times; i++){
    target = rand()%size;
    score.Find(target,dummy);
  }
  clock_t end = clock();
  cout <<"サイズ : "<< size << endl;
  cout <<"要素数 : "<< num << endl;
  cout <<"占有率 : "<< (double)num/size << endl;
  cout <<"検索時間 : "<< (double)(end - begin)/CLOCKS_PER_SEC <<endl;


  return 0;
}

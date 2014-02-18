#include<iostream>
#include<map>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
  map<string, int> m;
	
  m["May"] = 3; // データの格納
  m["July"] = 7;
  m["April"] = 4;
	
	
  map<string, int>::iterator itr; //イテレータ
	
  //データの検索
  itr = m.find("April");
  if( itr != m.end() )
    cout << itr->first << " " << itr->second << endl;
  else {
    cout << "not found" << endl;
  }
	 
  //データの検索
  itr = m.find("June");
  if( itr != m.end() )
    cout << itr->first << " " << itr->second << endl;
  else {
    cout << "not found" << endl;
  }
	
  //データの走査
  for(itr = m.begin(); itr != m.end(); itr++)
    {
      cout << itr->first << " " << itr->second << endl;
    }
	
  //データの削除
  itr = m.find("July");
  if( itr != m.end() )
    m.erase( itr );
  cout << endl;
	
  //データの走査
  for( itr = m.begin(); itr != m.end(); itr++){
    cout << itr -> first << " " << itr -> second << endl;
  }
	

  return 0;

}

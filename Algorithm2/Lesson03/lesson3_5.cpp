#include<iostream>
#include<map>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
  map<string, int> m;
	
  int value;
  string key;

  while(cin >> key >> value){
    m[key] = value;
  }
	
  map<string, int>::iterator itr;	

  for( itr = m.begin(); itr != m.end(); itr++){
    cout << itr -> first << " " << itr -> second << endl;
  }

  return 0;
}

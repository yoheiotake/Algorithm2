#include<map>     // ベクターを使うために必要。
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	
  map<string, int> m;  // <文字列型，int型>のマップを宣言。

  /* データの読み込みとmapへの格納 */
  int value; //バリュー
  string key; //キー
	
  vector<string> v; //検索用のベクター (キーをすべて保存しておく)


  //"value " "<int key>の形式を取る標準入力の読み込み
  while(cin >> key >> value)
    {
      m[key] = value; //データの格納
      v.push_back(key); //キーの保存 (検索に用いる)
    }

  /* データの検索 (全要素の検索時間)*/
	
  clock_t t1begin = clock();	//計測時間 (開始)
	
  vector<string>::iterator itr;
  for(itr = v.begin(); itr != v.end(); itr++){
		
    map<string, int>::iterator mitr = m.find(*itr);
    if( mitr == m.end())
      cout << "error";
		
		
		
		
  }
	
  clock_t t1end = clock();   //計測時間 (終了)	
	
  //データの格納時間
  cout << "Exec time (find) [sec]: " << (double)(t1end - t1begin) / CLOCKS_PER_SEC << endl;
	
  return 0;
}

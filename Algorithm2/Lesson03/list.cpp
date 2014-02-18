//#include<vector>     // ベクターを使うために必要
#include<algorithm>  // STLコンテナの関数を利用するために必要
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<list>

using namespace std;

int main()
{
	
  int times = 100; //検索 & 削除の回数
  list<int> v;  // 整数型のベクターを宣言
	
  /* データの読み込みと追加 */
  int data, num;
  scanf("num:%d\n", &num);

  //データ容量
  //v.reserve(num);

  clock_t t1begin = clock();	
  while(scanf("%d\n", &data) != EOF){
    v.push_back(data); //データの追加
  }
  clock_t t1end = clock();
	
  //vectorの実要素数と追加可能な配列サイズ
  cout << "v_size: " << v.size() << ". v_capacity: " /* << v.capacity() */ << endl;
	
  //データの追加時間
  cout << "データの追加 (msec): " << (double)(t1end - t1begin) / CLOCKS_PER_SEC << endl;
	
  /* 全データの走査 */
  clock_t t2begin = clock(); 
  list<int>::const_iterator itr; // イテレータもつかえる。	
  for( itr = v.begin(); itr != v.end(); itr++ ){} //イテレータをすべてなめるだけ
  clock_t t2end = clock();	
	
  //データの追加時間
  cout << "データの走査 (msec): " << (double)(t2end - t2begin) / CLOCKS_PER_SEC << endl;

  /* データの検索 (times回) */
	
  int target; //検索対象の要素
	
  srand(time(NULL));
	
  for(int i = 0; i < times; i++)
    {
      //検索対象の要素 (ランダムに取得する)
      target = rand() % num;
      list<int>::iterator itr = find(v.begin(), v.end(), target);
      if(itr != v.end()){
	//要素があった
      }
      else {
	//要素がなかった
      }
    }
	
  /* データの検索 & 削除 (times回) */
  for(int i = 0; i < times; i++){
    //検索対象の要素 (ランダムに取得する)
    target = rand() % num;
    list<int>::iterator itr = find(v.begin(), v.end(), target);
    if(itr != v.end()){
      //要素があった (削除)
      v.erase(itr);
    }
    else {
      //要素がなかった
    }
  }
	
	
  return 0;
}

/****************************************
<実行方法>
> g++ list.cpp
> g++ -Wall rand.cpp -o rand
> ./rand 100 | ./a.out


v_size: 100. v_capacity: 
データの追加 (msec): 0
データの走査 (msec): 0

v_size: 1000. v_capacity: 
データの追加 (msec): 0
データの走査 (msec): 0

v_size: 10000. v_capacity: 
データの追加 (msec): 0
データの走査 (msec): 0

v_size: 100000. v_capacity: 
データの追加 (msec): 0.04
データの走査 (msec): 0

v_size: 1000000. v_capacity: 
データの追加 (msec): 0.48
データの走査 (msec): 0.01

v_size: 10000000. v_capacity: 
データの追加 (msec): 3.84
データの走査 (msec): 0.12

v_size: 100000000. v_capacity: 
データの追加 (msec): 43.68
データの走査 (msec): 1.13

***************************************/

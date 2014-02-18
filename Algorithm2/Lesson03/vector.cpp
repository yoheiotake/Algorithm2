#include<vector>     // ベクターを使うために必要
#include<algorithm>  // STLコンテナの関数を利用するために必要
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	
  int times = 100; //検索 & 削除の回数
  vector<int> v;  // 整数型のベクターを宣言
	
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
  cout << "v_size: " << v.size() << ". v_capacity: " << v.capacity() << endl;
	
  //データの追加時間
  cout << "データの追加 (msec): " << (double)(t1end - t1begin) / CLOCKS_PER_SEC << endl;
	
  /* 全データの走査 */
  clock_t t2begin = clock(); 
  vector<int>::const_iterator itr; // イテレータもつかえる。	
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
      vector<int>::iterator itr = find(v.begin(), v.end(), target);
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
    vector<int>::iterator itr = find(v.begin(), v.end(), target);
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
> g++ vector.cpp
> g++ -Wall rand.cpp -o rand
> ./rand 100 | ./a.out


v_size: 100. v_capacity: 128
データの追加 (msec): 0
データの走査 (msec): 0

v_size: 1000. v_capacity: 1024
データの追加 (msec): 0
データの走査 (msec): 0

v_size: 10000. v_capacity: 16384
データの追加 (msec): 0
データの走査 (msec): 0

v_size: 100000. v_capacity: 131072
データの追加 (msec): 0.04
データの走査 (msec): 0.01

v_size: 1000000. v_capacity: 1048576
データの追加 (msec): 0.49
データの走査 (msec): 0.02

v_size: 10000000. v_capacity: 16777216
データの追加 (msec): 4.89
データの走査 (msec): 0.16

v_size: 100000000. v_capacity: 134217728
データの追加 (msec): 47.37
データの走査 (msec): 1.58

***************************************/

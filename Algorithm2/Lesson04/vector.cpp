#include<vector>     // ベクターを使うために必要。
#include<iostream>
#include<stdio.h>
#include<ctime>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{
	
  int times = 100; //検索 & 削除の回数
  vector<int> v;  // 整数型のベクターを宣言。
	
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
	
  clock_t t3begin = clock(); 
  for(int i = 0; i < times; i++)
    {
      //検索対象の要素 (ランダムに取得する)
      target = rand() % num;
      vector<int>::iterator itr = find(v.begin(), v.end(), target);
      if(itr != v.end()){
	//要素があった
	//cout << "there is " << target << endl;
      }
      else {
	//要素がなかった
	//cout << "there is not " << target << endl;
      }
    }
  clock_t t3end = clock();		
  //データの検索時間
  cout << "データの検索 (msec): " << (double)(t3end - t3begin) / CLOCKS_PER_SEC << endl;
	
	
  /* データの検索 & 削除 (times回) */
  clock_t t4begin = clock(); 
  for(int i = 0; i < times; i++){
    //検索対象の要素 (ランダムに取得する)
    target = rand() % num;
    vector<int>::iterator itr = find(v.begin(), v.end(), target);
    if(itr != v.end()){
      //要素があった (削除)
      //cout << "there is " << target << endl;
      v.erase(itr);
    }
    else {
      //要素がなかった
      //cout << "there is not " << target << endl;
    }
  }
  clock_t t4end = clock();		
  //データの検索時間
  cout << "データの検索 & 削除 (msec): " << (double)(t4end - t4begin) / CLOCKS_PER_SEC << endl;
	
	
  return 0;
}

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
	
  //乱数の数
  int num = atoi(argv[1]);
	
  //乱数の種の設定
  srand(time(NULL));
  int value;
  char key[6]; 
	
  //キーに含まれる要素集合
  char material[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	
  for(int i = 0; i < num; i++){
		
    //バリューの作成
    value = rand() % num; 
    //キーの作成
    for(int j = 0; j < 5; j++){
      key[j] = material[rand() % (sizeof(material)-1)];
    }
		
    cout << key << " "<< value << endl;
		
  }
	
  return 0;
	
}

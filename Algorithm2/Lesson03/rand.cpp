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

  cout << "num:" << num << endl;
	
  for(int i = 0; i < num; i++){
		
    cout << rand() % num << endl;
		
  }
	
  return 0;
	
}

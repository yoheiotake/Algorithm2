#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
	
  int num = atoi(argv[1]);
	
  srand(time(NULL));

  cout << "num:" << num << endl;
	
  for(int i = 0; i < num; i++){
		
    cout << rand() % num << endl;
		
  }
	
  return 0;
	
}

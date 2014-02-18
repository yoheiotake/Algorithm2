#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
  int data;
  scanf("num:%d",&data);

  cout <<"num is "<< data << endl;
  cout <<"出力 : "<< data%3 << endl;
}

/*************************
<実行方法>
./a.out < input.txt
./rand 10 | ./a.out

*************************/

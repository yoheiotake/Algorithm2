#include<iostream>

#include<stdio.h>


using namespace std;


int main(){


int data;


cout << "数字を入力せよ" << endl;


//入力ストリームをint型データに変換して，それを変数dataに格納する

scanf("%d", &data); //第2引数は 格納する変数のポインタ (アドレス)


cout << "数字は" << data << "です" << endl;


}

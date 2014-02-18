#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

int makeChange(vector<int> dcoins, int coin);

int main()
{
  int coin;
  int denomi;
  vector<int> dcoins;
	
  scanf("coin:%d¥n", &coin);
  while(cin >> denomi){
    dcoins.push_back(denomi);
  }

  clock_t begin = clock();
  cout << "The minimum coin num: " << makeChange(dcoins, coin) << endl;
  clock_t end = clock();

  cout <<"CPU Time: "<< (double)(end - begin)/CLOCKS_PER_SEC << endl;
	
  return 0;
}

int makeChange(vector<int> dcoins, int value){
    
  int minCoins = value;
  vector<int>::iterator itr = find(dcoins.begin(),dcoins.end(),minCoins);
  if(itr != dcoins.end())
    return 1;
    
  for(itr = dcoins.begin(); itr != dcoins.end(); itr++){
    if(*itr > value) continue;
    int curCoins = makeChange(dcoins,value - *itr) + 1;
    if(curCoins < minCoins)
      minCoins = curCoins;
  }
    
  return minCoins;
}

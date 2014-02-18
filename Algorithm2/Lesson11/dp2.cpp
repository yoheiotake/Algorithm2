#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>
#include <map>
#include <ctime>
using namespace std;


int makeChange(vector<int> dcoins, int coin);

class Select{
private:
  int min;
  int coin;
public:
  Select();
  bool operator > (const Select & x ) const;
  void Set_Min(int m,int c);
  int Get_Min(){return min;};
  int Get_Coin(){return coin;};
};

Select::Select(){
  min = 0;
  coin = 0;
}

void Select::Set_Min(int m,int c){
  min = m;
  coin = c;
}

bool Select::operator > (const Select & x ) const{
  if(min > x.min) return true;
  return false;
}



class DP{
private:
  int min;
  vector<int> v;
public:
  DP();
  void Set_Min(int p_min,int coin);
  vector<int> Get_List();
  int Get_Min();
};

DP::DP(){
  min = 0;
}

void DP::Set_Min(int p_min,int coin){
  min = p_min;
  v.push_back(coin);
}

vector<int> DP::Get_List(){
  return v;
}

int DP::Get_Min(){
  return min;
}


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
    
  DP array[value + 1];
  for(int i = 1; i < sizeof(array) / sizeof(array[0]); i++){
    priority_queue<Select,vector<Select>,greater<Select> > pq;
    vector<int>::iterator itr = dcoins.begin();
    Select c;
    for(; itr != dcoins.end(); itr++){
      if(*itr <= i){
	c.Set_Min(array[ i - *itr ].Get_Min() + 1,*itr);
	pq.push(c);
      }
    }
    c = pq.top();
    for(int val = c.Get_Min(); !pq.empty() && val == c.Get_Min(); pq.pop(),c = pq.top())
      array[i].Set_Min(c.Get_Min(),c.Get_Coin());
  }
    
  cout <<"Combination: {";
  for(int i = value; i != 0 ; ){
    cout << array[i].Get_List().front();
    i = i - array[i].Get_List().front();
    if(i != 0) cout <<",";
  }
  cout <<"}"<< endl;
    
  return array[value].Get_Min();
}

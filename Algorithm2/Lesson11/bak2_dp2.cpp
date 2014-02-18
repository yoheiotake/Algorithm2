#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>
#include <map>
using namespace std;


int makeChange(vector<int> dcoins, int coin);

class DP{
private:
    int min;
    vector<int> v;
public:
    DP();
    void Set_Min(map<int,int> table,int value);
    vector<int> Get_List();
    int Get_Min();
};

DP::DP(){
    min = 0;
}

void DP::Set_Min(map<int,int> table,int value){
    min = value;
    map<int,int>::iterator itr = table.begin();
    for(; itr != table.end(); itr++)
        if( itr -> second == min)
            v.push_back(itr -> first);
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
	
	cout << "The minimum coin num: " << makeChange(dcoins, coin) << endl;
	
	return 0;
}

int makeChange(vector<int> dcoins, int value){
    
    DP array[value + 1];
    for(int i = 1; i < sizeof(array) / sizeof(array[0]); i++){
        priority_queue<int,vector<int>,greater<int> > pq;
        vector<int>::iterator itr = dcoins.begin();
        map<int,int> table;
        for(; itr != dcoins.end(); itr++){
            if(*itr <= i){
                table[*itr] = array[ i - *itr ].Get_Min() + 1;
                pq.push(table[*itr]);
            }
        }
        array[i].Set_Min(table,pq.top());
    }
    
    cout <<"Combination: {";
    for(int i = value; i != 0 ; ){
        vector<int> v_list = array[i].Get_List();
        cout << v_list[0];
        i = i - v_list[0];
        if(i != 0)
            cout <<",";
    }
    cout <<"}"<< endl;
    
    return array[value].Get_Min();
}
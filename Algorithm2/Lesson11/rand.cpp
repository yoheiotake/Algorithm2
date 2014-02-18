#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	
	if(argc != 4 ){
		cout << "Usage ./rand [Max Coins Num] [Max Coin Value] [Max Target Value]" << endl;
	}
	

	int num = atoi(argv[1]);
	int maxValue = atoi(argv[2]);
	int maxTarget = atoi(argv[3]);
	

	srand(time(NULL));

	int value = rand() % maxTarget;
	
	cout << "coin:" << value << endl;;
	
	cout << "1" << endl;
	
	
	vector<int> v;
	
	int i = 0;
	while(i < num){
		
		int coin = rand() % maxValue;
		//cout << "::" << coin << endl;

		if( coin != 0 && find(v.begin(), v.end(), coin) == v.end()){	
			v.push_back(coin);
			cout << coin << endl;
			i++;
		}
	}
	
	return 0;
	
}

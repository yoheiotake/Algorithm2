#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

class Edge {

public:
	int start;
	int end;
	int weight;

public:
	Edge(int start, int end) : start(start), end(end), weight(0) { }; // コンストラクタ
	// 比較演算子 ">" を定義する
	bool operator == (const Edge & x) const
	{ return ( start == x.start && end == x.end ); }
	
};

void swap(int & x, int & y)
{	
	int temp = x;
	x = y;
	y = temp;
}

int main(int argc, char* argv[])
{
	
	if(argc != 4){
		cout << "usage: ./randGraph nodeNum edgeNum maxWeight" << endl;
		return 0; 
	}
	
	// 乱数の数
	int nodeNum = atoi(argv[1]); // 頂点数
	int edgeNum = atoi(argv[2]); // 辺数
	int maxWeight = atoi(argv[3]); // 最初の積載荷物の量
		
	if( nodeNum <= 0 || edgeNum > (nodeNum * (nodeNum - 1)) / 2 || maxWeight <= 0)
	{
		cout << "usage: ./randGraph nodeNum edgeNum maxWeight" << endl;
		return 0; 
	}
	
	cout << nodeNum << " " << maxWeight << endl; // 第1行目 
	cout << "0" << " " << nodeNum - 1 << endl; // 第2行目 (デフォルトで始点は0，終点はnodeNum-1)
	
	// 乱数の種の設定
	srand(time(NULL));

	// 第3行目以降
	for(int i = 0; i < nodeNum; i++){
		int cityWeight = rand() % maxWeight;
		cout << i << " " << cityWeight << endl;
	}
		
	// 辺数分の2頂点間の組を求める
	int num = 0;
	
	vector<Edge> v;
	v.reserve(edgeNum); // 確保すべき辺数分だけ
	
	while(true){
		
		if(num == edgeNum)
			break; // 辺数分の要素を確保
		
		int start = rand() % nodeNum;
		int end = rand() % nodeNum;
		
		if( start > end )
			swap(start, end); 
			// 無向辺を想定しているため，start <= end となるように揃えておく
		if( start != end){ // ループは避ける
			Edge* newEdge = new Edge(start, end);
	
			vector<Edge>::iterator itr = find(v.begin(), v.end(), *newEdge);
			if( itr == v.end() ){
				// 同じ辺は存在しない
				newEdge -> weight = rand() % maxWeight;
				v.push_back(*newEdge);
				num++;
			}
		} 
		
	}
	// 標準出力
	vector<Edge>::iterator itr;
	for(itr = v.begin(); itr != v.end(); itr++){
		cout << itr -> start << " " << itr -> end << " " << itr -> weight << endl; 
	}
	
	
	return 0;
	
}

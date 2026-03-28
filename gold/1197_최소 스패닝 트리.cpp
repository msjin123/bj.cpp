#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int x,vector<int>&parents){
	if (x!=parents[x]){
		parents[x] = find(parents[x],parents);
	}
	return parents[x];
}



bool union1(int a1,int b1,vector<int>&parents){
	a1=find(a1,parents);
	b1=find(b1,parents);

	if (a1==b1){ // root node 같음 -> cycle 있음 -> 버림
		return false;
	}
	else if (a1<b1){
		parents[b1]=a1;
	}
	else if (a1>b1){
		parents[a1]=b1;
	}
	return true;
}

struct ar21{
	int u,v,w; // 시작점,끝점,가중치
};


int main(){
	
	int v,e;
	cin >> v >> e; // 정점의 갯수, 간선의 갯수
	// vector<vector<int>>ar2(e,vector<int>(3));
	vector<ar21>ar2(e);
	for (int i=0; i<e; i++){
		int a,b,c;
		cin >> a >> b >> c;
		// ar2[i]={a,b,c};
		ar2[i].u=a;
		ar2[i].v=b;
		ar2[i].w=c;

	}
	sort(ar2.begin(),ar2.end(), [](const ar21 &a, const ar21 &b){
		return a.w<b.w;
	});


	vector<int> parents(v+1);
	for (int i=1; i<=v; i++){
		parents[i]=i;
	}

	int sum_weight=0;
	for (int i=0; i<e; i++){
		int node1=ar2[i].u;
		int node2=ar2[i].v;
		int weight=ar2[i].w;

		if (union1(node1,node2,parents)) sum_weight+=weight;
		// 차피 스패닝트리 완성된 이후는 다 cycle이라 전부 버려짐 따로 처리 안해도 될듯?

	}
	cout << sum_weight;

}
	

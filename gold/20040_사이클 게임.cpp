#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edges{
	int u,v;
};

int find(int x,vector<int>&parents){
	if (x!=parents[x]){
		parents[x] = find(parents[x],parents);
	}
	return parents[x];
	
}


bool union1(int a1,int b1, vector<int> &parents){
	a1=find(a1,parents);
	b1=find(b1,parents); // 각각의 루트노드 반환

	if (a1==b1){
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





int main(){
	int n,m;
	cin >> n >> m;
	vector<edges>ar2(m);

	for (int i=0; i<m; i++){
		int a,b;
		cin >> a >> b;
		ar2[i].u=a;
		ar2[i].v=b;
	}
	vector<int>parents(n);
	for (int node=0; node<n; node++){
		parents[node]=node;
	}

	int ans=1;
	for (int i=0; i<m; i++){
		int node1=ar2[i].u;
		int node2=ar2[i].v;
		if (union1(node1,node2,parents)==true) ans++;
		else break;
	}
	if (ans==m+1) cout << 0; // cycle 없음 
	else cout << ans;

	return 0;
}
	

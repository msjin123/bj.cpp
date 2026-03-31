#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int find(int x,vector<int>&parents){
	if (x!=parents[x]){
		parents[x] = find(parents[x],parents);
	}
	return parents[x];
}




bool union1(int a, int b, vector<int>&parents){
	a=find(a,parents);
	b=find(b,parents);
	if (a==b) return false;
	
	else if (a<b){
		parents[b]=a;
	}
	else if (a>b){
		parents[a]=b;
	}
	return true;
}







struct connect
{
	int a,b,c;
};


int main(){
	int n,m;
	cin >> n;
	cin >> m;
	vector<connect>ar(m);
	for (int i=0; i<m; i++){
		cin >> ar[i].a;
		cin >> ar[i].b;
		cin >> ar[i].c;
	}
	sort(ar.begin(),ar.end(),[](connect x,connect y){
		return x.c<y.c;
	});

	vector<int>parents(n+1);
	for (int i=1; i<=n; i++){
		parents[i]=i;
	}

	int ans=0;
	for (int i=0; i<m; i++){
		int node1=ar[i].a;
		int node2=ar[i].b;
		int cost=ar[i].c;
		if (union1(node1,node2,parents)==true) ans+=cost;
	}

	cout << ans;
	return 0;


}

	

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	cin >> n >> k;
	// 0 ~ 100000
	vector<int> dist1(100001,100000007);

	deque<pair<int,int>>dq;
	dq.push_front({0,n}); // {dist,node}
	dist1[n]=0;
	while (!dq.empty()){
		int dist=dq.front().first;
		int node=dq.front().second;
		dq.pop_front();

		if (dist>dist1[node]) continue;

		if (node-1>=0 and dist1[node-1]>dist+1){
			dq.push_back({dist+1,node-1});
			dist1[node-1]=dist+1;
		}
		if (node+1<=100000 and dist1[node+1]>dist+1){
			dq.push_back({dist+1,node+1});
			dist1[node+1]=dist+1;
		}
		if (2*node<=100000 and dist1[2*node]>dist){
			dq.push_front({dist,2*node});
			dist1[2*node]=dist;
		}

	}
	cout << dist1[k];

	return 0;

}

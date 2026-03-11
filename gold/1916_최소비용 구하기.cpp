#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m; // 각각 줄바꿈 입력
	//vector<vector<vector<int>>>li(n+1);
	vector<vector<pair<int,int>>>li(n+1);
	for (int i=0; i<m; i++){
		int start,arrive,cost;
		cin >> start >> arrive >> cost;
		li[start].push_back(make_pair(arrive,cost));
	}

	int start_num,arrive_num;
	cin >> start_num >> arrive_num;

	vector<int>dist(n+1,1e9-1);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	dist[start_num]=0;
	pq.push({dist[start_num],start_num});
	
	while(!pq.empty()){
		int dist1=pq.top().first;
		int node1=pq.top().second;
		pq.pop();

		// cout << dist1 << " " << node1 << '\n';

		if (dist1>dist[node1]) continue; // 최적화

		for (int a=0; a<li[node1].size(); a++){
			int node2=li[node1][a].first;
			int cost2=li[node1][a].second;
			
			if (dist[node2]<=dist1+cost2) continue;
			
			dist[node2]=dist1+cost2;
			pq.push({dist[node2],node2});

		}
	}

	// for (int b=0; b<n; b++){
	// 	cout << dist[b] << " ";
	// }

	cout << dist[arrive_num];


	return 0;
}

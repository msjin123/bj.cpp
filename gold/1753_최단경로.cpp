#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int v1,e; // 정점,간선
	cin >> v1 >> e;
	int k; // 시작위치
	cin >> k;
	// vector<vector<int>>graph1(v1+1,vector<int>(2,0));
	vector<vector<pair<int,int>>>graph1(v1+1); // 이거 2차원이 아니라 3차원 벡터임 // .first .second 로 접근

	for (int i=0; i<e; i++){
		int u,v,w; // 시작정점,끝정점,간선의 가중치
		cin >> u >> v >> w;
		
		graph1[u].push_back({v,w});
		// graph1[u]={v,w}
	}

	// 정점 번호 = 1~v1 각각 하나씩
	vector<int>dist(v1+1,100000001);

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // 최소 출력
	pq.push({0,k}); // 거리 작은거 우선 출력 : {거리,정점}
	dist[k]=0;
	while(!pq.empty()){
		int dist1=pq.top().first;
		int node=pq.top().second;
		pq.pop(); // 최소 거리부터 출력
		
		if (dist1>dist[node]) continue; // 꼭 필요 X

		for (auto b : graph1[node]){
			int v2=b.first;
			int d=b.second;
			if (dist[v2]>dist1+d){ // 이미 더 짧은 거리가 방문해서 차지하고 있으면 추가안함
				pq.push({dist1+d,v2});
				dist[v2]=dist1+d;
			}

		}

	}

	for (int i=1; i<=v1; i++){
		if (dist[i]==100000001){
			cout << "INF" << '\n';
		}
		else{
			cout << dist[i] << '\n';
		}
	}
	
	return 0;
	
}

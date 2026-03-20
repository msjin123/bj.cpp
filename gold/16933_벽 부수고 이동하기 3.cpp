#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<char>>li(n+1,vector<char>(m+1));
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			cin >> li[i][j];
		}
	}
	int ans=0;
	vector<int>dy={-1,1,0,0};
	vector<int>dx={0,0,-1,1};
	vector<vector<vector<int>>>visited(n+1,vector<vector<int>>(m+1,vector<int>(k+2,false)));
	queue<tuple<int,int,int,int,int,int>>q; //<y,x,dist,부순벽 개수,낮/밤,dist+2 인 거 추가되었을때 한번 쉬는 용>
	// 낮=3 밤=4
	// rest=0 정상 rest=1 한텀(한바퀴) 쉬기 rest>=2 도 가능
	q.push({1,1,1,0,3,0});
	visited[0][0][0]=true;
	while(!q.empty()){
		auto [y,x,dist,bwall,daynight,rest] = q.front();
		// cout << y << " " << x << '\n';
		q.pop();
		if (bwall>k) continue;
		if (rest==1){ // rest=1 일떄
			q.push({y,x,dist,bwall,daynight,0}); // daynight=4
			visited[y][x][bwall]=true; // 한턴 쉬고 다음턴에 rest=0 되어서 꺼낼 수 있을때 visited 처리
			continue;				   // (원래도 queue에 ny nx.. 추가할떄 visited 처리 하니까)
		}
		if (y==n and x==m){
			ans=dist;
			break;
		}


		for (int a=0; a<=3; a++){
			int ny=y+dy[a];
			int nx=x+dx[a];
			if (ny<1 or nx<1 or ny>n or nx>m) continue;
			
  			if (li[ny][nx]=='0'){ // 벽 아니면 낮밤 상관없음
				if (visited[ny][nx][bwall]==false){
					visited[ny][nx][bwall]=true;
					if (daynight==3) q.push({ny,nx,dist+1,bwall,4,0});
					else q.push({ny,nx,dist+1,bwall,3,0});
				} 
			}
			else if (li[ny][nx]=='1'){ // 낮에만 벽 부술 수 있음
				if (visited[ny][nx][bwall+1]==false and daynight==3){
					visited[ny][nx][bwall+1]=true;
					q.push({ny,nx,dist+1,bwall+1,4,0});
				}
				// 여기서 추가로 1가지 더 고려해야되네
				else if (visited[ny][nx][bwall+1]==false and daynight==4){
					q.push({ny,nx,dist+2,bwall+1,4,1}); 
					// visited[ny][nx][bwall+1]=true;  // 이걸 안해볼까 
				}
			}

			
		}
	}

	if (ans==0) cout << -1;
	else cout << ans;
	return 0;

}

	

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int r,c;
int ans=0;
vector<char> alps;
vector<int> dx={-1,1,0,0};
vector<int> dy={0,0,-1,1};
vector<vector<int>>vis; // 전부 0 초기화
int tt=0;
void dfs1(const vector<vector<char>>&li,int x,int y,int size1){ // x=바깥인덱스(세로) y=안쪽인덱스(가로)
	// 종료 조건부터
	// cout << x << " " << y << '\n';
	
	if (x!=1 or y!=1){
		// int s=0; // 말이 걸어온 길이
		// for (int i=0; i<alps.size(); i++){
		// 	s++;
		// }
		
		char alp2=li[x][y];
		for (int i=0; i<size1; i++){
			if (alp2==alps[i]){
				tt=1;
				ans=max(ans,size1);  // li[x][y] 이전 알파벳까지 = s
				return;
			}
		}
	}
	alps.push_back(li[x][y]);
	vis[x][y]=1;
	// (위 아래 왼쪽 오른쪽 순서)
	for (int i=0; i<=3; i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if (nx<1 or ny<1 or nx>r or ny>c){
			continue;
		}
		// cout << nx << " " << ny << '\n';
		if (vis[nx][ny]==0){
			// alps.push_back(li[nx][ny]);
			
			dfs1(li,nx,ny,size1+1);
			// alps.pop_back();
			
		}
	}
	alps.pop_back();
	vis[x][y]=0;


	ans=max(ans,size1); // 중복 하나도 없는 경우도 해야됨
}

int main(){
	
	cin >> r >> c;
	
	vector<vector<char>>li(r+1,vector<char>(c+1));
	for (int i=1; i<=r; i++){
		for (int j=1; j<=c; j++){
			cin >> li[i][j];
		}
	}
	vis.resize(r+1,vector<int>(c+1,0));
	
	
	
	dfs1(li,1,1,0);
	if (tt==0){
		cout << r * c;
	}
	else{
		cout << ans;
	}
}

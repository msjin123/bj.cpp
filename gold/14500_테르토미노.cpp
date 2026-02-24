#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;
int answer_max = 0;
vector<vector<int>>vis;
int stamp = 0;
vector<int> dy = { -1,1,0,0 };
vector<int> dx = { 0,0,-1,1 };
void dfs_4(const vector<vector<int>>&li, int i, int j,int n,int m) {
	// global : answer_max , vector<vector<int>>vis , stamp
	int sum_4 = 0;
	int cnt = 0;

	stack<pair<int,int>>s;
	stamp += 1;
	s.push(make_pair(i,j));
	while (!s.empty()) {
		int y = s.top().first;
		int x = s.top().second;
        // cout << y << ' ' << x << '\n';
		/*s.pop();*/
		if (vis[y][x] == stamp) {
			s.pop();
			sum_4 -= li[y][x];
			cnt--;
            vis[y][x]=0;
			continue;
		}

		vis[y][x] = stamp;
		sum_4 += li[y][x];
		cnt++;
		if (cnt == 4) {
			answer_max = max(sum_4, answer_max);
			s.pop();
			cnt--;
			sum_4 -= li[y][x];
            vis[y][x]=0;
			continue;
		}

		
		for (int h = 0; h <= 3; h++) {
			int ny = y + dy[h];
			int nx = x + dx[h];
            
            if (ny<i or nx<0 or ny>n - 1 or nx>m - 1) { // 위는 탐색 x 시간줄이기
				continue;
			}
			if (vis[ny][nx] != stamp) {
				s.push(make_pair(ny, nx));
			}
		}

	}
    // 뚱땡이 모양만 따로 추가 (이건 dfs로안됨)
    vector<int> ar;
    for (int g = 0; g <= 3; g++) {
        int ni = i + dy[g];
        int nj = j + dx[g];
        if (ni<0 or nj<0 or ni>n - 1 or nj>m - 1) {
            continue;
        }
        ar.push_back(li[ni][nj]);
    
    // ar.size()=2 일떄는 갱신x 뚱떙이 모양 안나옴
    int siz=ar.size();
    int sz=accumulate(ar.begin(),ar.end(),0);
    if (siz==3){
        answer_max = max(sz+li[i][j], answer_max);
    }
    else if (siz==4){ // ar.size()=4
        answer_max=max(sz-*min_element(ar.begin(),ar.end())+li[i][j],answer_max);
        
    }
	
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;  // 세로,가로
	cin >> n >> m;
	vector<vector<int>>li(n, vector<int>(m, 0));
	vis.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> li[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs_4(li, i, j,n,m);
		}
	}
    // dfs_4(li,0,0,m,n);
	cout << answer_max;
}

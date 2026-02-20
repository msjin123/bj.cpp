#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct state{
    int x,y,dist;
};

// 2차원 벡터 , 가로길이 , 세로길이
int bfs(vector <vector <int>> li, int m, int n){
    int answer=0;
    // 위 아래 좌 우
    
    vector <int> dx={-1,1,0,0};
    vector <int> dy={0,0,-1,1};

    vector <vector <int>> visited(n,vector <int>(m,0));
    queue <state> q3;
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (li[i][j]==1){
                
                q3.push({i,j,0}); // 각각 x,y,dist 에 대응
                visited[i][j]=1;  // 1이 하나만 있다는 고정관념은 버리기
            }
        }
    }

    
    while (!q3.empty()){
        state arr=q3.front();
        answer=arr.dist; // 계속 갱신하다가 마지막 answer 가 총 거친 날짜
        q3.pop();
        for (int i=0; i<4; i++){
            int ny=arr.x+dx[i];
            int nx=arr.y+dy[i];
            if (nx<0 or ny<0 or nx>m-1 or ny>n-1){
                continue;
            }
            else{
                if (li[ny][nx]==0 and visited[ny][nx]==0){
                    visited[ny][nx]=1;
                    li[ny][nx]=1;
                    q3.push({ny,nx,arr.dist+1});
                }
            }
        }
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (li[i][j]==0){ // li[m][n] x
                return -1;
            }
        }
    }

    return answer;

}


int main(){
    int m,n;
    cin >> m >> n;
    vector <vector <int>> li;
    for (int i=0; i<n; i++){
        vector <int> li2; // li2 매번 초기화 해줘야됨 --> 여기에 넣어야됨
        for (int j=0; j<m; j++){
            int a;
            cin >> a;
            li2.push_back(a);
        }
        li.push_back(li2);
    }

    int answer=bfs(li,m,n);
    cout << answer;





    return 0;
}

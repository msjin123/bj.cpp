#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<char>>li(n+1,vector<char>(n+1));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> li[i][j];
        }
    }

    int ans=2501;
    queue<tuple<int,int,int>>q; // y,x,부순벽개수
    vector<vector<int>>visited(n+1,vector<int>(n+1,2501));
    vector<int> dy = {-1,1,0,0};
    vector<int> dx = {0,0,-1,1};
    q.push({1,1,0});
    visited[1][1]=0;
    while (!q.empty()){
        auto [y,x,bwall] = q.front();
        if (y==n && x==n){
            if (bwall<ans){
                ans=bwall;
            }
        }
        q.pop();
        for (int a=0; a<=3; a++){
            int ny = y+dy[a];
            int nx = x+dx[a];
            if (ny<1 || nx<1 || ny>n || nx>n) continue;
            if (li[ny][nx]=='1' && visited[ny][nx]>bwall){
                visited[ny][nx]=bwall;
                q.push({ny,nx,bwall});
            }
            else if (li[ny][nx]=='0' and visited[ny][nx]>bwall+1){
                visited[ny][nx]=bwall+1;
                q.push({ny,nx,bwall+1});
            }
        }

    }
    cout << ans << '\n';
    // for (int b=0; b<=n; b++){
    //     for (int c=0; c<=n; c++){
    //         cout << visited[b][c] << " ";
    //     }
    //     cout << '\n';
    // }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int m,n;
    cin >> m >> n; // m이 세로 n이 가로
    // 1 동쪽 2 서쪽 3 남쪽 4 북쪽
    vector<vector<int>>li(m+1,vector<int>(n+1));
    vector<vector<vector<bool>>>visited(m+1,vector<vector<bool>>(n+1,vector<bool>(5,false))); 
    // visited[][] 안에 [1][2][3][4] 각각 동서남북
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin >> li[i][j];
        }
    }
    int startx,starty,startsee,endx,endy,endsee;
    // 행과 열의 번호 , 방향 입력
    cin >> starty >> startx >> startsee;
    cin >> endy >> endx >> endsee;
    int ans;
    queue<tuple<int,int,int,int>>q;
    q.push({starty,startx,startsee,0});
    visited[starty][startx][startsee]=true;
    vector<int> dy = {-123, 0,0,1,-1};
    vector<int> dx = {-123, 1,-1,0,0};
    
    // seedir=1 li[y][x+1], seedir=2 li[y][x-1], seedir=3 li[y+1][x], seedir=4 li[y-1][x]
    while (!q.empty()){
        auto [y,x,seedir,number] = q.front();
        // cout << y <<  " " << x << " " << seedir << " " << number << '\n';
        if (y==endy and x==endx and seedir==endsee){
            ans=number;
            break;
        }
        q.pop();

        // no turn , seedir에 따라 달라지는 ny,nx  1칸부터 3칸까지
        for (int i=1; i<=3; i++){
            int ny = y + dy[seedir]*i;
            int nx = x + dx[seedir]*i;
            if (ny<1 or nx<1 or ny>m or nx>n) break;
            
            if (li[ny][nx]==1) break;
            if (li[ny][nx]==0 and visited[ny][nx][seedir]==true) continue;
            q.push({ny,nx,seedir,number+1});
            visited[ny][nx][seedir]=true;
        }
        // turn left
        int seedirl;
        if (seedir==1) seedirl=4;
        else if (seedir==2) seedirl=3;
        else if (seedir==3) seedirl=1;
        else if (seedir==4) seedirl=2;
        if (visited[y][x][seedirl]==false){
            q.push({y,x,seedirl,number+1});
            visited[y][x][seedirl]=true;
        }
        
        // turn right
        int seedirr;
        if (seedir==1) seedirr=3;
        else if (seedir==2) seedirr=4;
        else if (seedir==3) seedirr=2;
        else if (seedir==4) seedirr=1;
        if (visited[y][x][seedirr]==false){
            q.push({y,x,seedirr,number+1});
            visited[y][x][seedirr]=true;
        }
    }
    

    cout << ans;
    return 0;
}
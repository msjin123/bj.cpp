#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> dy={0,0,-1,1};
vector<int> dx={-1,1,0,0};
bool bfs1(vector<vector<int>>&li,int n, int m, int i, int j,vector<vector<int>>&visited,int stamp){
    
    queue<pair<int,int>>q;
    q.push({i,j});
    visited[i][j]=stamp;
    bool ret=true;
    while (!q.empty()){
        // auto [a,b]=q.front();
        int a=q.front().first;
        int b=q.front().second;
        // 종료조건 : 고립된 공기가 아님
        if ((a==1) || (b==1) || (a==n) || (b==m)){
            ret=false;
        }
        q.pop();
        for (int z=0; z<=3; z++){
            int ny=a+dy[z];
            int nx=b+dx[z];
            
            if (ny<1 || nx<1 || ny>n || nx>m) continue;
            if (visited[ny][nx]==0 && li[ny][nx]==0){
                q.push({ny,nx});
                visited[ny][nx]=stamp;
            }
        }
    }
    
    // cout << ret << '\n';
    // 고립된 공기가 아니면 전부 0으로 그대로 둠
    // 고립된 공기들이라면 모두 2로 바꾸기 (0 = 고립안된 공기 , 2 = 고립된 공기)
    if (ret==false) return false;
    
    return true;
}
void checkcheese(vector<vector<int>>&li,int n, int m, int i, int j){
    int c=0;
    for (int a=0; a<=3; a++){
        int ny = i+dy[a];
        int nx = j+dx[a];
        // cout << ny << " " << nx << '\n';
        if ((ny<1) || (nx<1) || (ny>n) || (nx>m)) continue;
        
        
        if (li[ny][nx]==0) c++;
    }
    // cout << "c : " << c << '\n';
    if (c>=2){
        li[i][j]=3; 
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<int>>li(n+1,vector<int>(m+1,0)); // 크기,초깃값
    // li 입력
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> li[i][j];
        }
    }
    // 처음 치즈갯수 구하기
    int cheeses=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (li[i][j]==1) cheeses++;
        }
    }
    
    
    int ans=0;
    
    while (1){
        
        // 모든 치즈가 다 녹았는지 검사하고 다 녹았으면 종료
        if (cheeses==0) break;
        ans++;

        vector<vector<int>>visited(n+1,vector<int>(m+1,0)); 
        int stamp=0;
        // 공기 중 내부공간 공기 검사하고 2로 바꾸기
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (li[i][j]==0 && visited[i][j]==0){
                    stamp+=1;
                    // cout << "d " << i << " " << j << '\n';
                    if (bfs1(li,n,m,i,j,visited,stamp)==true){
                        for (int a=1; a<=n; a++){
                            for (int b=1; b<=m; b++){
                                if (visited[a][b]==stamp && li[a][b]==0){
                                    li[a][b]=2;
                                }
                            }
                        }
                       
                }
            }
        }
    }
        // cout << "li \n";
        
        // for (int i=1; i<=n; i++){
        //     for (int j=1; j<=m; j++){
        //         cout << li[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << "visited \n";
        // for (int i=1; i<=n; i++){
        //     for (int j=1; j<=m; j++){
        //         cout << visited[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        
        
        // 고립 = 2 , 고립 x = 0
        // 녹을 치즈를 전부 3으로 바꾸기
        
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (li[i][j]==1){ // 상하좌우중 2개이상 0이면 녹음
                    checkcheese(li,n,m,i,j); // 녹을 치즈는 3으로 변경
                }
            }
        }
        
        // for (int i=1; i<=n; i++){
        //     for (int j=1; j<=m; j++){
        //         cout << li[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // 치즈 녹이기
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (li[i][j]==3){ 
                    li[i][j]=0;
                    cheeses--;
                }
            }
        }
        // 2를 전부 0으로 초기화
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (li[i][j]==2){ 
                    li[i][j]=0;
                }
            }
        }
        

        
    }
    
    cout << ans;
    return 0;
}

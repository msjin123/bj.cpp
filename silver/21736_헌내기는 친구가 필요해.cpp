#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>>stamp;
// const, & 붙이면 li(main 안의 li)전체를 복사하는게 아니라 li를 읽기만 해서 메모리 절약 가능
int find_people(const vector<vector<char>>&li,int n,int m){

    int people=0;
    vector<int>dy={-1,1,0,0};
    vector<int>dx={0,0,-1,1};

    int a,b;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (li[i][j]=='I'){
                a=i;
                b=j;
            }
        }
    }
    // li[a][b]="I"
    queue<pair<int,int>>q;
    q.push(make_pair(a,b));
    stamp[a][b]+=1;
    while (!q.empty()){
        int y=q.front().first;
        int x=q.front().second;
        // 큐에서 지울때 확인 해도됨(이런 유형은 지울때 확인하는게 더 직관적일지도?)
        if (li[y][x]=='P'){
            people++;
        }

        q.pop();
        for (int i=0; i<4; i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (nx<0 or ny<0 or nx>m-1 or ny>n-1){
                continue;
            }
            if (li[ny][nx]!='X' and stamp[ny][nx]==0){
                stamp[ny][nx]+=1;
                q.push(make_pair(ny,nx));
            }

        }

    }
    
    return people;

}




int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<char>>li;
    // vector<vector<int>>stamp(n,vector<int>(m,0));
    for (int i=0; i<n; i++){
        vector<int> st;
        for (int j=0; j<m; j++){
            st.push_back(0);
        }
        stamp.push_back(st);
    }
    // ---------------------------
    for (int i=0; i<n; i++){
        vector<char>ar;
        for (int j=0; j<m; j++){
            char a;
            cin >> a;
            ar.push_back(a);
            }
        li.push_back(ar);

}

    

    int answer=find_people(li,n,m);
    if (answer==0){
        cout << "TT";
    }
    else{
    cout << answer;
    }
    return 0;
}

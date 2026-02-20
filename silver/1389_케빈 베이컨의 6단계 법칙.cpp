#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int cumdist;
vector<int>vis;
int stamp;
int find_sumdist(const vector<vector<int>>&comp,int user,int n){
    // vector <int>visited(n+1,0);
    vector <int>dist(n+1,0);
    stamp+=1;
    queue<int>q;
    int far=0;
    q.push(user);
    vis[user]=stamp;
    // dist[user]=0;
    far+=dist[user];

    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int i:comp[u]){
            if (vis[i]!=stamp){
                vis[i]=stamp;
                q.push(i);
                dist[i]=dist[u]+1;
                far+=dist[i];
            }
        }
        if (far>cumdist){
            return 10000001;
        }   


    }
    int sum_dist=0;
    for (int i=1; i<=n; i++){
        sum_dist+=dist[i];
    }
    
    return sum_dist;

}




int main(){
    int n,m;
    cin >> n >> m; // 유저수,친구 관계 수(중복 가능)
    vector<vector<int>>comp(n+1); // 인접리스트
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        comp[a].push_back(b);
        comp[b].push_back(a);
    }

    cumdist=101*1000;
    int cumans;
    // vector<int>vis(n+1,0);

    // for (int i=0; i<=n+1; i++){
    //     vis.push_back(0);
    // }
    vis.assign(n+1,0);
    stamp=0;

    for (int user=n; user>=1; user--){
        int tmpdist=find_sumdist(comp,user,n);
        if (tmpdist<=cumdist){
            cumdist=tmpdist;
            cumans=user;
        }
        
        
    }
    
    cout << cumans;
    


}
    

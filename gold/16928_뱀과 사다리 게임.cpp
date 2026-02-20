#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int find_dist(vector<vector<int>>li , vector<int>li2){
    vector<int> visited(101,false);
    queue <pair<int,int>>q;
    q.push(make_pair(1,0));
    visited[1]=true;
    int ans=10000001;
    while(!q.empty()){
        int num=q.front().first;
        int dist=q.front().second;
        if (num==100){
            return dist;
        }
        q.pop();
        for (int n : li[num]){  // 일반
            if (li2[n]!=-1){
                int pn=li2[n];
                if (visited[pn]==false){
                    visited[pn]=true;
                    q.push(make_pair(pn,dist+1));
                }
            }
            else if (visited[n]==false){
                visited[n]=true;
                q.push(make_pair(n,dist+1));
                
            }
        }
        
    }

    
}
int main(){
    int n,m;
    cin >> n >> m; // 사다리,뱀
    vector<vector<int>>li(101); //li[1] ~ li[100]
    for (int i=1; i<=94; i++){
        for (int j=1; j<=6; j++){
            li[i].push_back(i+j);
        }
    }
    for (int i=95; i<=100; i++){
        for (int j=1; j<=(100-i); j++){
            li[i].push_back(i+j);
        }
    }

    vector<int>li2(101,-1);
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        li2[x]=y;
    }
    for (int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        li2[u]=v;
    }


    int answer=find_dist(li,li2);
    cout << answer;

    return 0;
}
//

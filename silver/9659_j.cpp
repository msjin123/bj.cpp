#include <iostream>
#include <vector>
using namespace std;
int ans1,ans2,ans3,ans4=0;
int dist3=0;
int dist4=0;
void recur(vector<vector<int>> &child, int id){

    for (auto nxt : child[id]){
        ans2++;
        dist3++;
        recur(child,nxt);
        dist3--;
    }
    ans3 = max(ans3,dist3);



    // for (int i=1; i<=n; i++){
    //     if (parents[i]==id){ // i = id의 자식노드 = cid
    //         ans2++;
    //         dist3++;
    //         recur(parents,i,n);
    //         dist3--;
    //     }
    // }
    // ans3=max(ans3,dist3);
}
void recur2(vector<vector<int>> &graph, int id, int parent){
    for (auto nxt : graph[id]){
        if (nxt==parent) continue;
        dist4++;
        recur2(graph,nxt,id);
        dist4--;
    }
    ans4 = max(ans4,dist4);
    
}


int main(){
    int n;
    cin >> n;
    vector<int> parents(n+1);
    vector<vector<int>> child(n+1);
    vector<vector<int>> graph(n+1); // 양방향 그래프
    // node n, edge n-1
    for (int _=0; _<n-1; _++){
        int cid,pid;
        cin >> cid >> pid;
        parents[cid] = pid;
        child[pid].push_back(cid);
        graph[cid].push_back(pid);
        graph[pid].push_back(cid);
    }
    // node x
    int x;
    cin >> x;
    
    // 1
    int id = x;
    while (id!=1){
        id=parents[id];
        ans1++;
    }
    // 2,3
    id = x;
    ans2=1;
    recur(child,id);
    // 4
    id = x;
    
    recur2(graph,id,0); 
    
    // cout
    cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n' << ans4 << endl;
    return 0;


}
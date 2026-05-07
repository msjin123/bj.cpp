#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>ar(101,-1);
    for (int i=0; i<n; i++){ // 사다리
        int x,y;
        cin >> x >> y;
        ar[x]=y;
    }

    for (int i=0; i<m; i++){ // 뱀
        int u,v;
        cin >> u >> v;
        ar[u]=v;
    }

    vector<int> dist1(101,-1);
    queue<int> q;
    q.push(1);
    dist1[1]=0;
    while (!q.empty()){
        int num=q.front();
        if (num==100){
            break;
        }
        q.pop();
        for (int b=num+1; b<=num+6; b++){
            if (b>100){
                continue;
            }
            int nb=-1;
            if (ar[b]!=-1){ // 뱀or사다리
                nb=ar[b];
            }
            else if (ar[b]==-1){
                nb=b;
            }
            if (dist1[nb]==-1){
                q.push(nb);
                dist1[nb]=dist1[num]+1;
            }
        }


    }
    cout << dist1[100];
}   



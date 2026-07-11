#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000001
using namespace std;
int main(){
    int n,p,c; // 학생 수, 장소 수, (두) 장소를 잇는 경로의 수
    cin >> n >> p >> c;

    vector<vector<pair<int,int>>> linked(p+1,vector<pair<int,int>>());
    for (int _=0; _<c; _++){
        int i,j,cost;
        cin >> i >> j >> cost;
        linked[i].push_back({j,cost});
        linked[j].push_back({i,cost});

    }
    vector<int> student_place(n+1); // 1번 학생은 몇번 장소에 있고 2번 학생은 몇번 장소에 있고...
    for (int t=1; t<=n; t++){
        cin >> student_place[t];    // student_place[1]=5 1번 학생은 5번 장소에 있다
    }

    vector<long long> dist_sum(p+1,0);      // 이 중에서 최솟값이 정답 각 장소별로 모든 학생들이 그 장소로 오는 최단경로를 구할거임
    //                                         // dist_sum[i] = 모든 학생들이 i번 장소로 오는 최단경로의 합
    for (int t=1; t<=n; t++){
        int place = student_place[t];
        vector<long long> dist(p+1,INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,place});
        
        while (!pq.empty()){
            int d = pq.top().first;
            int p = pq.top().second;
            pq.pop();

            if (dist[p]<d) continue;

            for (auto a : linked[p]){
                int p1 = a.first;
                int d1 = a.second;
                if (dist[p1]>d+d1){
                    pq.push({d+d1,p1});
                    dist[p1] = d+d1;
                }
            }
        }
        for (int t1=1; t1<=p; t1++){
            if (t1==place) continue;
            dist_sum[t1]+=dist[t1];
        }
        // for (int t1=1; t1<=p; t1++){
        //     cout << dist[t1] << " ";
        // }
        // cout << '\n';

    }
    
    // for (int t1=1; t1<=p; t1++){
    //     cout << dist_sum[t1] << " ";
    // }
    // cout << '\n';

    cout << *min_element(dist_sum.begin()+1,dist_sum.end());
    return 0;


}
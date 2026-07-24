#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
// c=용량

bool possible(int c, vector<tuple<int,int,int>> &ar, int n, int k){
    vector<int> visited(n+2);
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0]=true;
    while (!q.empty()){
        int num = q.front().first; // num = 급유지번호
        int moved = q.front().second; // moved = 이동한 횟수
        q.pop();
        // k+1번동안 도착점 도달 x 일떄
        if (moved>k+1) return false;
        // 도착점 도달 완료 일때
        if (num==n+1){
            // if (moved<=k+1) return true;
            // else return false;
            return true;
        }

        for (int i=0; i<n+2; i++){
            if (visited[i]==false){
                long x1 = get<1>(ar[num]);
                long y1 = get<2>(ar[num]);
                long x2 = get<1>(ar[i]);
                long y2 = get<2>(ar[i]);
                double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
                int need = (int)ceil(dist/10.0); // ceil = 소숫점이 있을때만 올림
                if (need <= c){
                    q.push({i,moved+1});
                    visited[i]=true;
                }
                // long limit = (c*10)*(c*10L);
                // long dist2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                // if (dist2<=limit){
                //     q.push({i,moved+1});
                //     visited[i]=true;
                // }

            }
        }
    }
    // 도착지점까지 도달 못하는 경우
    return false;
}



int main(){
    int n,k;
    cin >> n >> k;

    vector<tuple<int,int,int>> ar(n+2);
    ar[0] = {0,0,0}; // 출발점 S의 좌표
    for (int t=1; t<=n; t++){
        // 급유지 좌표(n개) 입력 (x,y)
        int x,y;
        cin >> x >> y;
        ar[t] = {t,x,y};
    }
    ar[n+1] = {n+1,10000,10000}; // 목적지 T의 좌표

    // mid = 우리가 구하는 비행기 연료통 용량 ans
    // 매개변수 ans를 이분탐색을 통하여 ans가 가능한 최소 (연료통)용량을 찾기
    int l,r;
    l=0;
    r=1500;
    while (l<=r){
        int mid = (l+r)/2;
        if (possible(mid,ar,n,k)){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout << l << endl;
    return 0;
}



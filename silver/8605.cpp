#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main(){
    long long n,s; // 거울의 수,현재위치
    cin >> n >> s;
    deque<long long> dq; // 거울의 위치 (왼쪽부터 순서대로 주어짐)
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        dq.push_back(a);
    }

    int mirror=n; // 남은 거울의 갯수
    while (!dq.empty()){
        if (mirror%2!=0){
            s = 2*dq.back()-s; // 가장 오른쪽으로 대칭이동
            dq.pop_back();
        }
        else if (mirror%2==0){
            s = 2*dq.front()-s; // 가장 왼쪽으로 대칭이동
            dq.pop_front();
        }
        mirror--;
    }
    cout << s;

}
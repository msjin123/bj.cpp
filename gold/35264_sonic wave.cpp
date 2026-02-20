#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long int> y(n + 1);
    for (int i = 1; i <= n; i++) {
        long long int ynum;
        cin >> ynum;
        y[i] = ynum;
    }

	vector<long long int>store(4, 0); // i%4=0,1,2,3 위치에 설치된 스피커의 세기의 누적 합 저장하는 벡터
    vector<long long int>answer(n + 1, 0);

    int x; // i%4=x 를 만족하는 x
    int m = 0;
    for (int i = 1; i <= n; i++) {
        x = i % 4;
        long long int num = y[i] - store[x]; // 현재 수 - 누적 합 (= 현재 수에서 이전까지의 누적 합만큼 격차 좁히기)
        if (num != 0) {
            m++;           // 0이면 스피커 설치 안해도 됨 0 아닐때만
            answer[i] = num;
            // store[x] 갱신
            
            store[x] = store[x] + num;
            store[(x + 2) % 4] = store[(x + 2) % 4] - num;
        }
    }
    
    cout << m << '\n';
    for (int i = 1; i <= n; i++) {
        if (answer[i] != 0) {
            
            long long int x, v, q; // 위치,세기,위상
            x = i;
            v = abs(answer[i]);
            if (answer[i] > 0) {
                q = 3;
            }
            else if (answer[i] < 0) {
                q = 1;
            }
            cout << x << " " << v << " " << q << '\n';
        }
    }
    
    

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    unsigned int n;
    cin >> n;
    unsigned int ans=0;
    for (int t=0; t<4; t++){
        int byte1 = n&0xFF;  // 우측 1바이트(8비트) 추출
        n=n>>8;              // 우측 1바이트 이동 (나누기 256하고 같음 하지만 이건 비트연산으로 더 직관적인듯)
        ans+=byte1<<24-8*t;        // 추출한 우측 1바이트를 가장 좌측 1바이트 자리부터 차례대로 옮김
    }

    cout << ans;
    return 0;

}
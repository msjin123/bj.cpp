#include <iostream>
#include <cstdint>
#include <cstring>
#include <bitset>
using namespace std;
int main(){

    // 231
    // 11100111
    // 0.231      
    // 1.848*10^(-3)
    // 1.110110*10^(-3)

    float n;
    cin >> n;
    

    // n에 저장된 메모리를 32비트 정수를 담는 bits의 메모리에 복사
    // 단순히 bits를 출력하면 10진수가 출력됨. 하지만 이렇게 int type의 bits로 바꾸면 비트 연산이 가능해짐
    uint32_t bits;
    // uint32_t bits1 = n;
    // int32_t bits2 = n;
    // cout << bits1 << '\n';
    // cout << bits2 << '\n';

    memcpy(&bits,&n,sizeof(bits));
    
    int S = (bits>>31)&1;
    int E = (bits>>23)&0xFF;
    int M = bits&0x7FFFFF;

    cout << bitset<1>(S) << ' ' << bitset<8>(E) << ' ' << bitset<23>(M) << endl;
    return 0;

}
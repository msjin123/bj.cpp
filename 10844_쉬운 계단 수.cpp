#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <long long int>dp1(101); // 1~100
    dp1[1]=9;

    const int MOD=1000000000;
    vector <vector<int>>dp2(101,vector<int>(10));
    dp2[1][0]=0;
    for (int i=1; i<=9; i++){
        dp2[1][i]=1;
    }
    
    for (int i=2; i<=100; i++){
        dp2[i][0]=dp2[i-1][1];
        dp2[i][9]=dp2[i-1][8];
        for (int j=1; j<=8; j++){
            dp2[i][j]=(dp2[i-1][j-1]+dp2[i-1][j+1])%MOD;
        }
        
    }
    // dp2를 이용해서 dp1 만들기
    for (int i=2; i<=100; i++){
        dp1[i]=((dp1[i-1]*2)-(dp2[i-1][0]+dp2[i-1][9])%MOD+MOD)%MOD;
    }

    cout << dp1[n];
    



}

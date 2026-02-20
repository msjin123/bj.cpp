#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    // n*m 직사각형
    vector<vector<char>>li(n,vector<char>(m,'0'));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            char a; // 숫자 하나
            cin >> a;
            li[i][j]=a;
        }
    }
    int lev=1; // 2*2부터 시작
    int ans=1; // 1*1 정사각형은 전부 양 끝이 같은 정사각형
    
    int o=min(n,m);
    while (lev+1<=o){
    
        for (int i=0; i<n-lev; i++){
            for (int j=0; j<m-lev; j++){
                if (li[i][j]==li[i+lev][j] && li[i][j]==li[i+lev][j+lev] && li[i][j]==li[i][j+lev]){
                    
                    ans=lev+1;
                }
                
            }
        }
        lev++;
    }
    
    cout << ans*ans;
}

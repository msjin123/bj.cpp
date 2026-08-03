#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i=0; i<n; i++){
        cin >> ar[i];
    }

    // ar[i+1],ar[i] 의 차이 = gap[i][0]
    // gap[i] 값이 큰 순서대로 k-1개를 뽑아내야 한다  그래야 k개의 성냥을 피울 수 있음 성냥 적게 피운다고 더 좋은 경우는 x
    vector<vector<int>> gap(n-1,vector<int>(2));
    for (int i=0; i<n-1; i++){
        gap[i][0] = ar[i+1]-ar[i];
        gap[i][1] = i; // index 저장용
    }  

    // gap이 큰 순서대로 sort
    sort(gap.begin(),gap.end(),[](vector<int> a, vector<int> b){
        return a[0]>b[0];
    });
    vector<int> save_index;
    save_index.reserve(k-1);
    if (k>n) k=n;
    for (int t=1; t<=k-1; t++){
        save_index.push_back(gap[t-1][1]);
    }
    sort(save_index.begin(),save_index.end());
    
    // save_index 는 0~k-2
    int ans=0;
    int sidx;
    if (k==1) sidx=123;
    else sidx=0;
    int psave=0;
    for (int i=0; i<n-1; i++){
        if (sidx<=k-1 && i==save_index[sidx]){
            ans=ans+(psave+1);
            sidx++;
            psave=0;
        }
        else{
            psave+=ar[i+1]-ar[i];
        }

    }
    // i=n-1 일때는 psave+=ar[i+1]-ar[i]; 대신 아래코드를 함 (총 k번 나눠서 더함)
    ans=ans+(psave+1); 

    cout << ans << endl;
    return 0;
}
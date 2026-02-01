#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,b;
    cin >> n >> m >> b;
    vector <vector<int>> li;
    for (int i=0; i<n; i++){
        vector<int> ar;
        for (int j=0; j<m; j++){
            int height;
            cin >> height;
            ar.push_back(height);
        }
        li.push_back(ar);
    }
    
    int sum=0;
    int average;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            sum+=li[i][j];
        }
    }
    sum+=b; // 인벤토리에 있는 블록의 개수까지
    average=sum/(n*m); // 내림으로 계산

    if (average>256){
        average=256;
    }

    int ans=100000001;
    int height;
    for (int h=0; h<=average; h++){
        int time=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (li[i][j]<=h){
                    time+=(h-li[i][j]); // 블록 넣기
                }
                else if (li[i][j]>h){
                    time+=2*(li[i][j]-h); // 블록 제거
                }
                
            }
            
        }
        // 최소시간 갱신 -> 시간,높이 저장
        if (time<=ans){
            ans=time;
            height=h;
        }
        

    }

    // cout << sum << "," << average << endl;
    cout << ans << " " << height;

    return 0;
}

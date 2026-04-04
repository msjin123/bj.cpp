#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    
    
    while (1){
        long long n;
        cin >> n;
        if (n==0) break;
        vector<long long>height(n+1);
        for (int i=0; i<n; i++){
            cin >> height[i];
        }
        height[n]=0;
        long long ans=0; // 최대 넓이
        // if (n==1){
        //     ans = 1 * height[0];
        // }
        stack<pair<long long,long long>>s; // (시작좌표,높이)
        
        s.push({0,height[0]});
        int x=1;

        while (x<=n){
            
            int x2=x;
            while (!s.empty()){
                long long past_x=s.top().first;
                long long past_h=s.top().second;
                
                if (height[x]<past_h){ // 현재 높이보다 더 큰 과거 높이들
                    ans=max(ans,(x-past_x)*past_h);
                    s.pop();
                    x2=past_x;
                    
                }
                else if (height[x]>past_h){
                    break;
                }
                else if (height[x]==past_h){
                    x2=past_x;
                    break;
                }
            }
            s.push({x2,height[x]});
            
            x++;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    int n,k1,k2;
    cin >> n >> k1 >> k2;

    vector<tuple<int,int,int>> ar(n);
    for (int i=0; i<n; i++){
        cin >> get<0>(ar[i]) >> get<1>(ar[i]);
        get<2>(ar[i])=i;
    }

    sort(ar.begin(),ar.end(),[](tuple<int,int,int> a, tuple<int,int,int> b){
        return get<0>(a)<get<0>(b); // 0번쨰 인덱스 원소 기준 정렬 (집 위치 기준 정렬)
    });

    vector<int> ans(n,0);
    // two pointer three times
    int l,r;
    l=0;
    r=0;
    for (int i=0; i<n; i++){
        while (1){
            if (get<0>(ar[i])-get<0>(ar[l])>k2){
                l++;
            }
            else{
                break;
            }
        }
        while (r<n-1){
            if (get<0>(ar[r+1])-get<0>(ar[i])<=k2){
                r++;
            }
            else{
                break;
            }
        }
        // l,r 정해짐
        int friends = r-l;
        ans[get<2>(ar[i])] += friends; 
    }
    // re sort
    // 문제 2!  이거는 학교순 정렬만 했고 같은 학교에서 집위치는 정렬 안되있었다!
    // 따라서 학교가 같을떄 집위치 기준 정렬을 한번 더 해줘야한다
    sort(ar.begin(),ar.end(),[](tuple<int,int,int> a, tuple<int,int,int> b){
        if (get<1>(a)!=get<1>(b)) return get<1>(a)<get<1>(b); // 1번쨰 인덱스 원소 기준 정렬 (같은 학교끼리 모아놓기)
        return get<0>(a)<get<0>(b);
        
    });
    
    // int school_len = get<1>(ar[n-1]);
    // 문제 이해 부족 : school 번호가 순서대로라는 말은 없음 번호 = 1~n 이라고 해서 n개의 학교가 있는것도 아니고..
    set<int> school;
    for (int i=0; i<n; i++){
        school.insert(get<1>(ar[i]));
    }
    // 2nd
    l=0;
    r=0;
    int idx=0;
    for (auto z : school){
        l=idx;
        r=idx;
        // 같은 school 끼리 투포인터
        while (idx<=n-1 && get<1>(ar[idx])==z){
            while (1){
                if (get<0>(ar[idx])-get<0>(ar[l])>k2){
                    l++;
                }
                else{
                    break;
                }
            }
            while (r<n-1 && get<1>(ar[r+1])==z){ // school = z 범위에서만
                if (get<0>(ar[r+1])-get<0>(ar[idx])<=k2){
                    r++;
                }
                else{
                    break;
                }
            }
            // l,r 정해짐
            int friends = r-l;
            ans[get<2>(ar[idx])] -= friends; 
            idx++;
        }
    }
    // 3rd
    l=0;
    r=0;
    idx=0;
    for (auto z : school){
        l=idx;
        r=idx;
        while (idx<=n-1 && get<1>(ar[idx])==z){
            while (1){
                if (get<0>(ar[idx])-get<0>(ar[l])>k1){
                    l++;
                }
                else{
                    break;
                }
            }
            while (r<n-1 && get<1>(ar[r+1])==z){ // school = z 범위에서만
                if (get<0>(ar[r+1])-get<0>(ar[idx])<=k1){
                    r++;
                }
                else{
                    break;
                }
            }
            // l,r 정해짐
            int friends = r-l;
            ans[get<2>(ar[idx])] += friends; 
            idx++;
        }
    }


    for (int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
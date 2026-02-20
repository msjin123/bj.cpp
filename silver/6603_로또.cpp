#include <iostream>
#include <vector>
using namespace std;
void lotto(vector<int> n, vector<int> n2,int k,int start){ // (기존 벡터, 6개 채워주는 백터, 기존벡터의 길이, 시작 인덱스)
                       // n2 길이 = 6 (n의 길이 = k)
    if (n2.size()==6){ // 꽉 찼을때 (넘칠 때)
        for (int a=0; a<6; a++){
            cout << n2[a] << " ";
        }
        cout << endl;
        
        
    }
    else{
        for (int i=start; i<k; i++){
            n2.push_back(n[i]);
            start++;
            lotto(n,n2,k,start);
            n2.pop_back(); // 백트래킹
            
            // start를 인수로 받는 나의 재귀함수 특성상, start--를 하면 안된다. 
            // 현재 재귀는 상관없지만, 다음 재귀 start에 영향을 준다.
            
        }

    }

    
}
int main(){
    
    while (1){
        vector<int> nums;
        int k;
        cin >> k; // 7~12
        if (k==0){
            break;
        }
        for (int i=0; i<k; i++){
            int num;
            cin >> num;
            nums.push_back(num);

        }
        // nums[0] ~ nums[k-1]
        vector<int> n2;
        lotto(nums,n2,k,0);
        cout << '\n';
    }

    return 0;
}

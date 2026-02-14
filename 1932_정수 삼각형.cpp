#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <vector<int>>triangle;
    for (int i=1; i<=n; i++){
        vector<int> nums;
        for (int j=1; j<=i; j++){
            int num;
            cin >> num;
            nums.push_back(num);
        }
        triangle.push_back(nums);
    }
    
    // 그낭 n*n 으로 만들기 , 인덱스기준으로 순회
    vector <vector<int>> sumtriangle(n,vector<int>(n,-1));
    sumtriangle[0][0]=triangle[0][0]; // i=0
    for (int i=1; i<=n-1; i++){
        
        sumtriangle[i][0]=sumtriangle[i-1][0]+triangle[i][0]; // j=0
        for (int j=1; j<=i-1; j++){                           // j=1 ~ j=i-1
            if (sumtriangle[i-1][j-1]+triangle[i][j]>sumtriangle[i-1][j]+triangle[i][j]){
                sumtriangle[i][j]=sumtriangle[i-1][j-1]+triangle[i][j];
            }
            else{
                sumtriangle[i][j]=sumtriangle[i-1][j]+triangle[i][j];
            }
        }
        sumtriangle[i][i]=sumtriangle[i-1][i-1]+triangle[i][i]; // j=i
    }

    int ans=-1;
    for (int a=0; a<=n-1; a++){
        if (sumtriangle[n-1][a]>ans){
            ans=sumtriangle[n-1][a];
        }
    }

    cout << ans;

    return 0;

}


#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int n,q;
vector<long long> arr;
vector<long long> tree;

long long init(int node, int start, int end){
    if (start==end){
        return tree[node] = arr[start];
    }
    int mid = (start+end)/2;

    long long leftsum = init(node*2,start,mid);
    long long rightsum = init(node*2+1,mid+1,end);

    return tree[node] = leftsum + rightsum;
}

// 우리가 구하고 싶은 구간 : left ~ right
// tree[node] 의 관리? 범위 : start ~ end
long long query(int node, int start, int end, int left, int right){
    // 아예 안겹침
    if (start>right || end<left){
        return 0;
    }
    // 다 겹침
    else if (start>=left && end<=right){
        return tree[node];
    }

    int mid = (start+end) / 2;

    long long leftsum = query(node*2,start,mid,left,right);
    long long rightsum = query(node*2+1,mid+1,end,left,right);

    return leftsum + rightsum;

}

// arr[index] = value 로 바꾸기
void update(int node, int start, int end, int index, int value){
    if (index>end || index<start){
        return;
    }
    if (start==end){
        arr[index]=value;
        tree[node]=value;
        return;
    }
    int mid = (start+end) / 2;

    update(node*2,start,mid,index,value);
    update(node*2+1,mid+1,end,index,value);

    tree[node] = tree[node*2] + tree[node*2+1];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    
    cin >> n >> q;

    arr.resize(n+1);
    tree.resize(4*n+1);

    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }
    cin.ignore();
    init(1,1,n);
    
    for (int i=1; i<=q; i++){
        string s;
        getline(cin,s);
        istringstream iss(s);
        if (s[0]=='1'){
            int type,l,r;
            iss >> type >> l >> r;
            long long ans;
            ans = query(1,1,n,l,r);
            cout << ans << '\n';
        }
        else if (s[0]=='2'){
            int type,x,v;
            iss >> type >> x >> v;
            update(1,1,n,x,v);
        }

    }
    return 0;
}
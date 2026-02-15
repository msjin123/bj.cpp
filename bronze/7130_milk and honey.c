#include <stdio.h>
int main(){
    int m,h;
    scanf("%d %d",&m,&h);
    int n;
    scanf("%d",&n);

    int ans=0;
    for (int i=0; i<n; i++){
        int c,b;
        scanf("%d %d",&c,&b);
        int h1,h2;
        h1=c*m;
        h2=b*h;
        if (h1>h2){
            ans+=h1;
        }
        else{
            ans+=h2;
        }
    }

    printf("%d",ans);


}

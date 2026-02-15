#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++){
        int c;
        scanf("%d",&c);
        int q,d,n,p;
        q=c/25;
        c=c%25;
        d=c/10;
        c=c%10;
        n=c/5;
        c=c%5;
        p=c/1;
        c=c%1;
        // c=0

        printf("%d %d %d %d\n",q,d,n,p);
        

    }
    return 0;
}

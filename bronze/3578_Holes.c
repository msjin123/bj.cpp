#include <stdio.h>
int main(){
    int h;
    scanf("%d",&h);
    if (h==0){
        printf("%d",1);
    }
    else if (h==1){
        printf("%d",0);
    }
    else if (h%2!=0){
        int rep=h/2;
        printf("%d",4);
        for (int i=0; i<rep; i++){
            printf("%d",8);
        }
        
    }
    else if (h%2==0){
        int rep=h/2;
        for (int i=0; i<rep; i++){
            printf("%d",8);
        }
    }
    return 0;
}

# include <iostream>
int len1(char c[]){
    int ans=0;
    while (*c!='\0'){
        c++;
        ans++;
    }
    return ans;
}


int main(){
    char a[51];
    char b[51];
    scanf("%s",a);
    scanf("%s",b);
    int lena,lenb;
    lena=len1(a);
    lenb=len1(b);
    
    int mindiff=51;
    for (int i=0; i<=lenb-lena; i++){
        int temp=0;
        for (int j=0; j<lena; j++){
            if (b[j+i]!=a[j]){
                temp++;
            }
        }
        if (temp<mindiff){
            mindiff=temp;
        }
    }

    printf("%d",mindiff);
}

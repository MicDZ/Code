#include<bits/stdc++.h>
using namespace std;
char a[101010]={0},b[1010110],c[101010]={0};

int main()
{
    scanf("%s",a+1);
    strcpy(a,b);
    for(int i=1;i<=strlen(a);i++){
        a[i]=b[strlen(a)-i+1];
    }
    for(int i=1;i<=strlen(a);i++)cout<<a[i];
    for(int i=1;i<=3;i++){
            int x=0,s;
        for(int i=1;i<=strlen(a);i++){
            if(i==1)s=1;
            else s=0;
            a[i]=a[i]+s+x;
            x=a[i]/10;
            a[i]%=10;
        }
        //printf("%s",a+1);
    }
}

#include<bits/stdc++.h>
using namespace std;
char word[10010];
int a[10010];
long long ans;
int main(){
	int s=1;
    for(int i=1;i<=6;i++){
        scanf("%s",word);
        if(!strcmp(word,"one")||!strcmp(word,"a")||!strcmp(word,"another")||!strcmp(word,"first")){
            a[s]=1;
            s++;
            continue;
        }
        if(!strcmp(word,"two")||!strcmp(word,"both")||!strcmp(word,"second")){
            a[s]=4;
            s++;
            continue;
        }
        if(!strcmp(word,"three")||!strcmp(word,"third")){
            a[s]=9;
            s++;
            continue;
        }
        if(!strcmp(word,"four")){
            a[s]=16;
            s++;
            continue;
        }
        if(!strcmp(word,"five")){
            a[s]=25;
            s++;
            continue;
        }
        if(!strcmp(word,"six")){
            a[s]=36;
            s++;
            continue;
        }
        if(!strcmp(word,"seven")){
            a[s]=49;
            s++;
            continue;
        }
        if(!strcmp(word,"eight")){
            a[s]=64;
            s++;
            continue;
        }
        if(!strcmp(word,"nine")){
            a[s]=81;
            s++;
            continue;
        }
        if(!strcmp(word,"ten")){
            a[s]=0;
            s++;
            continue;
        }
        if(!strcmp(word,"eleven")){
            a[s]=21;
            s++;
            continue;
        }
        if(!strcmp(word,"twelve")){
            a[s]=44;
            s++;
            continue;
        }
        if(!strcmp(word,"thirteen")){
            a[s]=69;
            s++;
            continue;
        }
        if(!strcmp(word,"fourteen")){
            a[s]=96;
            s++;
            continue;
        }
        if(!strcmp(word,"fifteen")){
            a[s]=25;
            s++;
            continue;
        }
        if(!strcmp(word,"sixteen")){
            a[s]=56;
            s++;
            continue;
        }
        if(!strcmp(word,"seventeen")){
            a[s]=89;
            s++;
            continue;
        }
        if(!strcmp(word,"eighteen")){
            a[s]=24;
            s++;
            continue;
        }
        if(!strcmp(word,"ninteen")){
            a[s]=61;
            s++;
            continue;
        }
        if(!strcmp(word,"twenty")){
            a[s]=0;
            s++;
            continue;
        }
    }
    scanf("%s",word);
    sort(a+1,a+s+1);
    for(int i=1;i<=s;i++)ans=ans*100+a[i];
    printf("%lld",ans);
    return 0;
}

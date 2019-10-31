#include<bits/stdc++.h>
using namespace std;

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define REP(i,e,s) for(register int i=e; i<=s; i++)

#define MAXN (100000+10)

int s[MAXN];

int main () {
    int n=read();
    REP(i,1,n) s[i]=read();
    int t=read(),ans=0; 

    REP(i,1,t) {
        int q=read();
        int left=1,right=n,mid;
        while(left<right) {
            if(s[n]==q) {
                ans++;
                break;
            }
            mid=(left+right)/2;
            if(s[mid]==q) {
                ans++;
                break;   
            }
            if(s[mid]>q) right=mid;
            if(s[mid]<q) left=mid+1;
        }
        if(s[mid]==q) cout<<q<<" ";
    }
    puts("");
    printf("%d\n",ans);
}


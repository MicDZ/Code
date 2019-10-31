#include<bits/stdc++.h>

using namespace std;
#define MAXN 10000+10
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[MAXN],V;
bool have[MAXN];
bool dfs(int m,int l){
    if(m==0&&l==0) return 1;
    if(l==0)  l=V;
    int s=1;
    if(l!=V){
        s=lastnum+1;
    }
    for(int i=s;i<=n;i++){
        if(!have[i-1]&&i>1&&a[i]==a[i-1]) continue;
        if(!have[i]&&a[i]<=l){ 
            have[i]=1;
            lastnum=i;
            if(dfs(m-1,l-a[i])) return 1;
            else{
                have[i]=0;
                if(V==l||a[i]==l) return 0; 
            }
        }
    }
    return 0;
}

bool cmp(int a,int b) {
    return a>b;
}

int main() {
    int n;
    while(cin>>n&&n!=0) {
        memset(a,0,sizeof(a));
        int sum=0;
        for(int i=1; i<=n; i++) a[i]=read(),sum+=a[i];
        sort(a+1,a+n+1,cmp);
        for(int i=a[n]; i<=sum/2; i++) {
            if(sum%i!=0) continue;
            V=i;
            memset(have,0,sizeof(have));
            if(dfs(n,i)) {
                cout<<i<<endl;
                break;
            }
        } 
        if(i>sum/2) cout<<sum<<endl;
    }
}
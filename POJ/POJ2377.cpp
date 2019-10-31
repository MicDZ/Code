#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 200000+10
#define INF 0x3f3f3f
int f[MAXN],cnt;
struct point{
    int u,v,s;
}a[MAXN];
int read(){
    int f=1,x=0,ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int find(int x){
    if(f[x]==x)return f[x];
    return f[x]=find(f[x]);
}
int link(int x,int y){
    f[find(x)]=find(y);
}
bool cmp(point a,point b){
    return a.s<b.s;
}
int main(){
    int n=read();
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cnt++;
            a[cnt].u=i;
            a[cnt].v=j;
            a[cnt].s=read();
        }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)f[i]=i;
    int ans=0,s=0;
    for(int i=1;i<=cnt;i++){
        if(find(a[i].u)!=find(a[i].v)){
            link(a[i].u,a[i].v),ans+=a[i].s;
            s++;
            if(s==n-1){
                cout<<ans<<endl;
                return 0;
            }
        }
    }
    return 0;
} 

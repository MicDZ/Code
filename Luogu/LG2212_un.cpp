#include<bits/stdc++.h>
using namespace std;
#define MAXN 5000+10
#define MAXM 5000000+10
#define INF 0x3f3f3f
int f[MAXN],hd[MAXN],x[MAXN],y[MAXN],cnt,maxx=-INF;
double ben[MAXN];
struct point{
    int u,v;
    double s;
}a[MAXM];
int read(){
    int f=1,x=0;
    char ch=getchar();
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
double dist(int x1,int x2,int y1,int y2){
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
int main(){
    int n=read(),c=read();
    for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
        	if(dist(x[i],x[j],y[i],y[j])<c){
        		cnt++;
            	a[cnt].u=i;
            	a[cnt].v=j;
            	a[cnt].s=dist(x[i],x[j],y[i],y[j]);
        	}
            
        }
       int s=0;
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=MAXN;i++)f[i]=i;
    double ans=0;int st=0;
    for(int i=1;i<=cnt;i++){
		if(find(a[i].u)!=find(a[i].v)){
			link(a[i].u,a[i].v),ans+=a[i].s;
			s++;
			if(s==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
    cout<<0;
    return 0;
} 
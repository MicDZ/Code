#include<stdio.h>
#define MAXN 2000+1
#define MAXM (MAXN*MAXN)
#define INF 0x3f3f3f
#define file(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout)
//#define ONLINE_JUDGE
int read() {
     int x=0,f=1;
	 char ch=getchar();
	 while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	 while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	 return x*f;
}

int g[MAXN][MAXN],head[MAXM],have[MAXM],match[MAXM],to[MAXM*2],next[MAXM*2],cnt,n,m,k;

void addedge(int x,int y){
    cnt++;
	to[cnt]=y;
    next[cnt]=head[x];
    head[x]=cnt;
}

int dfs(int x){
    for(int i=head[x]; i; i=next[i]){
        int u=to[i];
		if(!have[u]){
            have[u]=1;
            if(!match[u]||dfs(match[u])){
                match[u]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    n=read(),m=read(),k=read();
    for(int i=1; i<=k; i++){
        int x,y;
		x=read(),y=read();
        g[x][y]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(((i+j)%2==1)||g[i][j])continue;
			int u=(i-1)*m+j;
            if(!g[i-1][j]&&i-1>=1) 
				addedge(u,(i-2)*m+j);
            if(!g[i+1][j]&&i+1<=n)
				addedge(u,i*m+j);
            if(!g[i][j-1]&&j-1>=1)
				addedge(u,(i-1)*m+j-1);
            if(!g[i][j+1]&&j+1<=m)
				addedge(u,(i-1)*m+j+1);
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if((i+j&1)||g[i][j])continue;
            for(int k=1; k<=n*m+10; k++) have[k]=0;
		//	memset(match,0,sizeof(match));
            if(dfs((i-1)*m+j)) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

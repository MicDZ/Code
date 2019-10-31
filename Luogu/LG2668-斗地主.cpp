#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100+10;

int a[MAXN],ans,dp[30][15][12][10][5];

void init() {
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0][0][0] = 0;
  	REP(l,0,5) REP(k,0,7) REP(j,0,11) REP(i,0,23) REP(w,0,2) 
		if(w + i + j * 2 + k * 3 + l * 4 <= 23) {
			if(w == 2) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j][k][l][w-2]+1); 
			if(w) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j][k][l][w-1]+1); 
			if(l) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j][k][l-1][w]+1); 
			if(i) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i-1][j][k][l][w]+1); 
			if(j) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j-1][k][l][w]+1); 
			if(k) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j][k-1][l][w]+1); 
			if(k&&i) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i-1][j][k-1][l][w]+1); 
			if(k&&w) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j][k-1][l][w-1]+1); 
			if(k&&j) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j-1][k-1][l][w]+1); 
			if(l&&i>=2) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i-2][j][k][l-1][w]+1);
			if(l&&i&&w) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i-1][j][k][l-1][w-1]+ 1);
			if(l&&j>=2) dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j-2][k][l-1][w]+1);
			if(l) {
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i+4][j][k][l-1][w]); 
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i+2][j+1][k][l-1][w]);
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i][j+2][k][l-1][w]);
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i+1][j][k+1][l-1][w]); 
			}
			if(k) {
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i+3][j][k-1][l][w]);
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i+1][j+1][k-1][l][w]); 
			}
			if(j)
				dp[i][j][k][l][w]=min(dp[i][j][k][l][w],dp[i+2][j-1][k][l][w]); 
		}
}
int	num[]={0,5,3,2};

bool check() {
	REP(i,1,14) if(a[i]) return 0;
	return 1;
}

void dfs(int k) {
	if(check()) {ans=min(ans,k);return ;}
	if(k>ans) return ;
	int num[5],gui=0;
	REP(i,0,4) num[i]=0;
	REP(i,1,13) num[a[i]]++;
	gui=a[14];
	ans=min(ans,k+dp[num[1]][num[2]][num[3]][num[4]][gui]);

	
	for(int tmp=5,i=1;i<=3;i++,tmp-=4-i) {
        for(int tot = 0, j = 1; j <= 12; j++, tot = 0) {
            REP(t,j,12)
                if(a[t] >= i) {
                    tot++;
                    if(tot >= tmp) {
						DREP(l,t,t-tot+1) a[l] -= i; 
                        dfs(k + 1);
                        DREP(l,t,t-tot+1) a[l] += i; 
                    }
                }
                else tot = 0; 
        }
    }


}

int main() {
	int t=read(),n=read();
	init();
	while(t--) {
		memset(a,0,sizeof(a));
		REP(i,1,n) {
			int x;
			scanf("%d",&x);
			if(x!=0) {
				if(x<3) x+=11;
				else x-=2;
				a[x]++; 
			}
			else a[14]++;
			read();
		}
		ans=n;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}

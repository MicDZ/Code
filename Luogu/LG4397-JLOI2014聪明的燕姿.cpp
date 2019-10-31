#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
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

const int MAXN=10000000+10;

bool is_prime(int a) {
	if(a==2) return 1;
	if(a<=1) return 0;
	for(int i=2; i*i<=a; i++)
		if(a%i==0) return 0;
	return 1;
}

int prime[MAXN],vis[MAXN],cnt;

bool ola_seieve() {
	REP(i,2,MAXN) {
        if(!vis[i]) prime[++cnt]=i;
        for(int j=1; j<=cnt&&i*prime[j]<=MAXN; j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int ans[MAXN<<1],num;

void dfs(int k,int left,int x) {
	//DE("%lld\n",x);
	if(x<=0) return ;
	if(left==1) {
		ans[++num]=x;
		return ;
	}
	
	if(left-1>prime[k]&&is_prime(left-1))
		ans[++num]=x*(left-1);
	
	for(int i=k+1; prime[i]*prime[i]<=left; i++) {
		int prod=1,temp=1;
		for(int j=1; ; j++) {
			prod*=prime[i];
			temp+=prod;
			if(temp>left) break;
			if(left%temp==0) dfs(i,left/temp,x*prod);
		}
		
	}
}

signed main() {
	int s;
	ola_seieve();
	while(~scanf("%lld",&s)) {
		num=0;
		dfs(0,s,1);
		sort(ans+1,ans+1+num);
		printf("%lld\n",num);
		REP(i,1,num) printf("%lld%c",ans[i]," \n"[i==num]);
	}
	return 0;
}

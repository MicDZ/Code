#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=1000+10;
char c[MAXN][MAXN];
int a[MAXN],cnt[6];
int main() {
	int n=read(),m=read();
	REP(i,1,n) scanf("%s",c[i]+1);
	REP(i,1,m) a[i]=read();
	int ans=0;
	REP(i,1,m) {
		memset(cnt,0,sizeof(cnt));
		REP(j,1,n) cnt[c[j][i]-'A'+1]++;
		REP(j,1,5) cnt[0]=max(cnt[0],cnt[j]);
		ans+=cnt[0]*a[i];
	}

	printf("%d\n",ans);
	return 0;
}


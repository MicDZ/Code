#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=5000000+10;

int cnt[1048576],a[1048576+10][5],num;

char s[MAXN];

int ans;

void insert(char *w) {
	int len=strlen(w);
	int p=0;
	REP(i,0,len-1) {
		if(!a[p][(int)w[i]]) a[p][(int)w[i]]=++num;
		p=a[p][(int)w[i]];
		
	}
ans=max(ans,cnt[p]++);
}
char x[12];

char* substr(char *w,int be,int len) {
	REP(i,be,be+len-1) x[i-be]=w[i];
	return x;
}

int main() {
	file("a");
	scanf("%s",s);
	int len=strlen(s),k=read();
	REP(i,0,len-1) {
		if(s[i]=='A') s[i]=1;
		else if(s[i]=='G') s[i]=2;
		else if(s[i]=='C') s[i]=3;
		else if(s[i]=='T') s[i]=4;
	}

	REP(i,0,len-k) {
		insert(substr(s,i,k));
//		DE("%s\n",substr(s,i,k));
	}

	printf("%d\n",ans+1);
	return 0;
}

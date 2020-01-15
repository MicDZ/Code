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
#define int ll
const int MAXN=100000+10;

int a[MAXN],pos[MAXN];

struct edge {
	int l,r,id;
} s[MAXN];

bool cmp(edge a,edge b) {
	if(pos[a.l]==pos[b.l]) return a.r<b.r;
	return a.l<b.l;
}

int cnt[MAXN];

struct ans {
	int a,b;
} ans[MAXN],now;

void add(int x) {
	cnt[x]++;
	if(cnt[x]>1) now.a=now.a+cnt[x]*(cnt[x]-1)-(cnt[x]-1)*(cnt[x]-2);
}

void del(int x) {
	cnt[x]--;
	if(cnt[x]>0) now.a=now.a+cnt[x]*(cnt[x]-1)-(cnt[x]+1)*cnt[x];
}

signed main() {
	file("data");
	int n=read(),q=read(),m=sqrt(n);
	REP(i,1,n) a[i]=read(),pos[i]=(i-1)/m+1;
	REP(i,1,q) s[i].l=read(),s[i].r=read(),s[i].id=i;
	sort(s+1,s+1+q,cmp);
	int l=s[1].l,r=s[1].r;
	REP(i,l,r)  add(a[i]);
	now.b=(r-l+1)*(r-l);
	int gcd=__gcd(now.a,now.b);	
	ans[s[1].id].a=now.a/gcd;
	ans[s[1].id].b=now.b/gcd;

	REP(i,2,q) {
		if(s[i].l==s[i].r) {ans[s[i].id].a=0,ans[s[i].id].b=1;continue;}
		while(l<s[i].l) del(a[l++]);
		while(l>s[i].l) add(a[--l]);
		while(r<s[i].r) add(a[++r]);
		while(r>s[i].r) del(a[r--]);
		
		now.b=(s[i].r-s[i].l+1)*(s[i].r-s[i].l);
		int gcd=__gcd(now.a,now.b);	
		ans[s[i].id].a=now.a/gcd;
		ans[s[i].id].b=now.b/gcd;
	}
	REP(i,1,q) printf("%lld/%lld\n",ans[i].a,ans[i].b);
	return 0;
}


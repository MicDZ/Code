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

const int MAXN=200000+10;

int n,m,gap,a[MAXN],temp[MAXN],chge[MAXN][3];

struct query {
	int l,r,id,t;
} q[MAXN];

bool cmp(query a,query b) {
	if(a.l/gap==b.l/gap) {
		if(a.r/gap==b.r/gap) return a.id<b.id;
		return a.r<b.r;
	}
	return a.l<b.l;
}

int tot[1000005],ans;

void add(int a) {
	if(!tot[a]) ans++;
	tot[a]++;
}

void del(int a) {
	tot[a]--;
	if(!tot[a]) ans--;
}

int _ans[MAXN];

int main() {
file("带修莫队");
	n=read(),m=read(),gap=pow(n,1.9/3);
	REP(i,1,n) temp[i]=a[i]=read();
	int cnt1=0,cnt2=0;
	REP(i,1,m) {
		char op[3];
		scanf("%s",op+1);
		if(op[1]=='Q') {
			int l=read(),r=read();
			q[cnt1].l=l,q[cnt1].r=r,q[cnt1].id=cnt1,q[cnt1].t=cnt2;
			cnt1++;
		}
		else {
			int p=read(),c=read();
			chge[cnt2][0]=p;chge[cnt2][1]=temp[p];chge[cnt2][2]=temp[p]=c;
			cnt2++;
		}
	}
	sort(q,q+cnt1,cmp);
	add(a[1]);
	int l=1,r=1,lst=0;
	REP(i,0,cnt1-1) {
		while(lst<q[i].t) {
			if(l<=chge[lst][0]&&chge[lst][0]<=r) del(chge[lst][1]),add(chge[lst][2]);
			a[chge[lst][0]]=chge[lst][2];
			lst++;
		}
		while(lst>q[i].t) {
			if(l<=chge[lst-1][0]&&chge[lst-1][0]<=r) del(chge[lst-1][2]),add(chge[lst-1][1]);
			a[chge[lst-1][0]]=chge[lst-1][1];
			lst--;
		}
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(r>q[i].r) del(a[r--]);
		_ans[q[i].id]=ans;
	}

		REP(i,0,cnt1-1) printf("%d\n",_ans[i]);
	return 0;
}


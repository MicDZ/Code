#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+10;

int a[MAXN],num[MAXN],ans[MAXN];

set<int> s[MAXN];

bool cmp(int a,int b) {
	return num[a]<num[b];
}

int main() {
	int n=read(),m=read(),sum=1;
	REP(i,1,n) num[i]=1,s[1].insert(i);
	REP(i,1,m) {
		int t=read();
		REP(j,1,t) a[j]=read();
		sort(a+1,a+1+t,cmp);
		int l=1,r=1;
		for(; l<=t; l=r+1) {
			r=l;
			while(num[a[r+1]]==num[a[l]]&&r<t) r++;
			if((int)s[num[a[l]]].size()==r-l+1) {l=r;continue;}
			int tmp=num[a[l]];sum++;
			REP(j,l,r) s[tmp].erase(a[j]),num[a[j]]=sum,s[sum].insert(a[j]);
			if(s[tmp].size()==1&&!ans[*s[tmp].begin()]) ans[*s[tmp].begin()]=i;
			if(s[sum].size()==1&&!ans[*s[sum].begin()]) ans[*s[sum].begin()]=i;
		}
	}

	REP(i,1,n) printf("%d ",ans[i]);
	return 0;
}


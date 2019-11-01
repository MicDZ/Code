#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
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

const int MAXN=100000+10;

int s[MAXN],p[MAXN],c[MAXN],dp[MAXN];

int x(int i) {return s[i]*c[i];}
int y(int i) {return dp[i-1]+s[i]*c[i]*c[i]-2*s[i]*c[i];}

double calc1(int i,int j) {
	return 1.0*(y(i)-y(j))/(x(i)-x(j));
}

int calc2(int i,int j) {
    return dp[j-1]+s[i]*(c[i]-c[j]+1)*(c[i]-c[j]+1);
}

vector<int> stack[MAXN];

struct stack {
	int top=0;
	int size() {return top;}
	
} stack[MAXN];

signed main() {
	int n=read();
	REP(i,1,n) s[i]=read(),c[i]=c[p[s[i]]]+1,p[s[i]]=i;
	REP(i,1,n) {
		while (stack[s[i]].size()>=2&&calc1(stack[s[i]][stack[s[i]].size()-2],i)>=calc1(stack[s[i]][stack[s[i]].size()-2],stack[s[i]][stack[s[i]].size()-1])) stack[s[i]].pop_back();
        stack[s[i]].push_back(i);
        while (stack[s[i]].size()>=2&&calc2(i,stack[s[i]][stack[s[i]].size()-1])<=calc2(i,stack[s[i]][stack[s[i]].size()-2])) stack[s[i]].pop_back();
        dp[i]=calc2(i,stack[s[i]].back());	
	}//上凸包
	printf("%lld\n",dp[n]);
	return 0;
}

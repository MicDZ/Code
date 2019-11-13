#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>

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

const int MAXN=1000+10,INF=0x3f3f3f3f;

struct edge {
	char first;int second,third;
};
edge make_pair(char a,int b,int third) {return (edge){a,b,third};}
struct stack {
	edge s[MAXN];
	int tp;
	stack() {tp=0;s[0].first=0,s[0].second=0,s[0].third=0;}
	void push(edge x) {s[++tp]=x;}
	edge top() {return s[tp];}
	void pop() {tp--;}
	int size() {return tp;}
} ;

map<char,int> mp;

int main() {
	file("LG3952-时间复杂度");
	int t=read();
	while(t--) {
		stack sta;
		char op[2],du[9+10];
		int L=read(),ori=0;
		scanf("O(%s",du+1);
		int len=strlen(du+1);
		if(len==2) ori=0;
		else REP(i,3,len-1) ori=ori*10+du[i]-'0';
		int ans=0;bool flag=0;
		
		REP(l,1,L) {
			scanf("%s",op+1);
			ans=max(ans,sta.top().second);
			
			if(op[1]=='F') {
				char var[3],e[30],s[30];
				scanf("%s%s%s",var+1,e+1,s+1);
				if(mp[var[1]]) {
					flag=1;
				}
				mp[var[1]]=1;
				
				int oe=0,os=0;
				if(e[1]=='n') oe=1;
				if(s[1]=='n') os=1;
				
				int nume=0,nums=0;
				
				if(!oe) REP(i,1,strlen(e+1)) nume=nume*10+e[i]-'0'; else nume=INF;
				if(!os) REP(i,1,strlen(s+1)) nums=nums*10+s[i]-'0'; else nums=INF;
				if((!oe&&os)&&(sta.top().third||(!sta.size()))) sta.push(make_pair(var[1],sta.top().second+1,1));
				else if((!oe&&!os)&&(nume<nums)&&(sta.top().third||(!sta.size()))) sta.push(make_pair(var[1],sta.top().second,1));
				else if(nums<nume) sta.push(make_pair(var[1],sta.top().second,0));
				else sta.push(make_pair(var[1],sta.top().second,sta.top().third));
			}
			if(op[1]=='E') {
				char var=sta.top().first;
				mp[var]=0;
				if(!sta.size()) {
					flag=1;
				}
				sta.pop();
			}

		}

		DE("%d %d\n",ori,ans);
		if(flag) {puts("ERR");continue;}
		if(sta.size()) puts("ERR");
		else if(ans==ori) puts("Yes");
		else puts("No");
		mp.clear();
	}
	return 0;
}

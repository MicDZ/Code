#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=60+10;

int w[MAXN],v[MAXN],q[MAXN],dp[MAXN][32000+10];
vector<int> enclo[MAXN];

int main() {
	int N=read(),m=read();
	REP(i,1,m) {
		w[i]=read();
		v[i]=read();
		q[i]=read();	
		if(q[i]) enclo[q[i]].push_back(i);
	}
	
	REP(t,1,m) 
		if(enclo[t].size()) 
			REP(i,0,enclo[t].size()-1) 
				DREP(j,N,w[enclo[t][i]]) 
					dp[t][j]=max(dp[t][j-w[enclo[t][i]]]+v[enclo[t][i]],dp[t][j]);
	

	
	return 0;
}

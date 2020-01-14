#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

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
const int MAXN=30000+10;
int a[MAXN],u[MAXN];

priority_queue<int> q1,q2;

int main() {
    int m=read(),n=read();
	
	REP(i,1,m) a[i]=read();
	REP(i,1,n) u[i]=read()+1;
    
    int j=1;
    REP(i,1,m) {
        q2.push(-a[i]);
        if(!q1.empty() && q1.top()>-q2.top()) {
            int temp1=q1.top();q1.pop();
            int temp2=-q2.top();q2.pop();
            q1.push(temp2);
            q2.push(-temp1);
        }
        while (j<=n&&u[j]==i+1) {
            printf("%d\n",-q2.top());
			
			q1.push(-q2.top());
            q2.pop();
            j++;
        }
    }
	return 0;
}


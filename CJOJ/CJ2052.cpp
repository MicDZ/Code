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

vector<int> v;

int main() {
	int n=read(),m=read();
	int now=1;
	REP(i,1,n) v.push_back(i);
	while(v.size()) {
		if(now+m-1>n) now=(now+m-1)%v.size();
		else now+=m-1;
		printf("%d ",now);
		v.erase(v.begin()+now);
	}
}

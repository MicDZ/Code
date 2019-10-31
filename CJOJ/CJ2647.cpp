#include<bits/stdc++.h>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
using namespace std;
const int MAXN=1000+10,MAXM=10000+10;
int read(){
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct point{
	double x,y,z;
}a[MAXN];

double dist(point a,point b){
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}

bool have[MAXM],arr;
long long n,h,r;

int s=0;
void dfs(long long x){
	if(arr||x>n)return;
	//cout<<"in:"<<x<<endl;
	if(a[x].z+r>=h){arr=1;return;}
	REP(i,1,n){
		if(have[i]||dist(a[i],a[x])>2*r)continue;
		have[i]=1;
		dfs(i);
		//have[i]=0;
	}
}
int main(){
	int T=read();
	while(T--){
		arr=0;
		s=0;

		n=read(),h=read(),r=read();
		memset(have,0,sizeof have);

		REP(i,1,n) {
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
		}
		REP(i,1,n) 
			if(abs(a[i].z)<=r) {
				have[i]=1;
				dfs(i);
				memset(have,0,sizeof have);
			}

		if(arr) puts("Yes");
		else puts("No");
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=100+10;
int dis[MAXN][MAXN][MAXN],max_t[4],t;

struct edge{
	int oil_rest[4],step;
};
queue<edge> q;
void bfs() {
	while(!q.empty()) {
			
		edge u=q.front();q.pop();
		//cout<<u.oil_rest[1]<<" "<<u.oil_rest[2]<<" "<<u.oil_rest[3]<<" "<<u.step<<endl;
		REP(i,1,3)
				if(u.oil_rest[i]==t) {
					printf("%d\n",u.step);
					exit(0);
				}

		REP(i,1,3) REP(j,1,3) {
			if(i==j) continue;
			int rest[4];
			if(u.oil_rest[i]>max_t[j]-u.oil_rest[j]) {
				rest[i]=u.oil_rest[i]-(max_t[j]-u.oil_rest[j]);
				rest[j]=max_t[j];
			}
			else if(u.oil_rest[i]<=max_t[j]-u.oil_rest[j]) {
				rest[i]=0;
				rest[j]=u.oil_rest[j]+u.oil_rest[i];
			}
			edge now;
			rest[6-i-j]=u.oil_rest[6-i-j];
			REP(i,1,3) 
				now.oil_rest[i]=rest[i];
			now.step=u.step+1;			
			if(dis[rest[1]][rest[2]][rest[3]]<=now.step) continue;	
			dis[rest[1]][rest[2]][rest[3]]=now.step;	
			q.push(now);
		}	


		
		REP(i,1,3) {
			int rest[4];
			if(u.oil_rest[i]<=0) continue;
			rest[i]=0;
			int j=(6-i-1)/2,k=6-i-j;
			rest[j]=u.oil_rest[j];
			rest[k]=u.oil_rest[k];
			edge now;
			REP(i,1,3) now.oil_rest[i]=rest[i]; 
			now.step=u.step+1;
			if(dis[rest[1]][rest[2]][rest[3]]<=now.step) continue;
			dis[rest[1]][rest[2]][rest[3]]=now.step;
			q.push(now);
		}

	}
}

int main() {
	max_t[1]=read(),max_t[2]=read(),max_t[3]=read(),t=read();
	//dis[x][1]=0;
	q.push((edge){{0,max_t[1],0,0},0});
	memset(dis,1,sizeof(dis));
	dis[max_t[1]][0][0]=0;
	
	//REP(i,1,100) REP(i,1,100)
	//if(max_t[1]==t) {
	//	puts("0");
	//	return 0;
	//}
	bfs();

	puts("NO ANSWER!");
	return 0;
}


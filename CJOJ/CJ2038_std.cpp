#include<cstdio>
#define R register
#define I inline
using namespace std;
const int S=510,N=6010;
int v[S],w[S],c[S],f[N],q[N];
I int max(int x,int y) {
	return x>y?x:y;
}
I int cal(int i,int j,int k) {
	return f[j+k*v[i]]-k*w[i];
}
I int read() {
	R int f=0;
	R char c=getchar();
	while(c<48||c>57) c=getchar();
	while(c>47&&c<58) f=(f<<3)+(f<<1)+(c^48),c=getchar();
	return f;
}
int main() {
	R int n=read(),m=read(),i,j,k,p,l,r,d,o,ans=0;
	for(i=1; i<=n; ++i) {
		v[i]=read(),w[i]=read(),c[i]=read();
		for(j=0; j<v[i]; ++j) {
			l=1,r=0,d=(m-j)/v[i],o=max(d-c[i],0);
			for(k=d-1; k>=o; --k) {
				while(l<=r&&cal(i,j,q[r])<=cal(i,j,k)) --r;
				q[++r]=k;
			}
			for(p=d; p>=0; --p) {
				while(l<=r&&q[l]>p-1) ++l;
				if(l<=r) f[j+p*v[i]]=max(f[j+p*v[i]],cal(i,j,q[l])+p*w[i]);
				if(p-c[i]>=1) {
					while(l<=r&&cal(i,j,q[r])<=cal(i,j,p-c[i]-1)) --r;
					q[++r]=p-c[i]-1;
				}
			}
		}
	}
	for(i=1; i<=m; ++i) ans=max(ans,f[i]);
	printf("%d",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e5+10
#define INF 0x3f3f3f3f
int x[MAXN],y[MAXN];
double dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
inline double my_max(double a,double b){
	if(a>b)return a;
	else return b;
}
int main(){
	double n,maxx=-INF;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(double i=1;i<=n;i++){
		for(double j=i+1;j<=n;j++)
			maxx=my_max(maxx,dis(i,j));
	}
	printf("%.6lf",maxx);
}
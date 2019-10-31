#include<bits/stdc++.h>
using namespace std;
double a[1010100];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		double l,r;
		cin>>l>>r;
		a[i]=l/r;
	}
	sort(a+1,a+n+1);
	printf("%.8lf",a[1]*m);
}

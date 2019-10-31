#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	long long a=0,b=0;
	for(long long i=n,j=m;i>=1&&j>=0;i--)
	{
		a=a+i*j;
		j--;
	}
	cout<<a;
	long long u=0,v=0;
	for(long long i=n;i>=1;i--)
		u=u+i;
	for(long long i=m;i>=1;i--)
		v=v+i;
	cout<<" "<<u*v-a;
} 

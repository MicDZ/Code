#include<bits/stdc++.h>
using namespace std;
int a[10101]={0};
int b[10101]={0};
int main()
{
	int n,maxx=-10231233;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=abs(a[i]-a[i+1]);
		if(a[i]>maxx)maxx=a[i];
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	cout<<"end"<<endl;
	sort(b+1,b+n+1);
	if(b[sizeof(b)]>=maxx)cout<<"Jolly";
	else cout<<"Not jolly";
} 

#include<bits/stdc++.h>
using namespace std;
int a[1010110];
int main()
{
	int n;
	cin>>n;
	int a1=0,a2=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)a1++;
		if(a[i]==2)a2++;
	}
	int ans;
	ans=min(a1,a2);
	if(a1>=a2)ans+=(a1-a2)/3;
	cout<<ans;
}

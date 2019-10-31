#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int s,n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[s]++;
	}
	sort(a+1,a+1+3);
	cout<<n-a[1]-a[2];
}

#include<bits/stdc++.h>
using namespace std;
string a[10101];
int main()
{
	int n;
	cin>>n;
	if(n==1){
		cin>>a[1];
		cout<<a[1];
		return 0;
	}
	string x,y;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			x=a[i+1];
			y=a[i];
			break;
		}
	}
	int sx=0,sy=0;
	for(int i=1;i<=n;i++){
		if(a[i]==x)sx++;
		if(a[i]==y)sy++;
	}
	if(sx>=sy)cout<<x;
	if(sx<sy)cout<<y;
} 

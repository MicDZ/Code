#include<bits/stdc++.h>
using namespace std;
bool pd(int a){
	if(a<2)return 0;
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)return 0;
	return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++)
			if(pd(j))cout<<j<<endl;
		cout<<endl;
	}
}

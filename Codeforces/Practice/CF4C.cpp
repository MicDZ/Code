#include<bits/stdc++.h>
using namespace std;
//1 3 5 9
//0x3f3f3f3f
int main()
{
    int a[5];
    for(int i=1;i<=4;i++)
    	cin>>a[i];
    sort(a+1,a+1+4);
    bool b=0;
	for(int x=1;x<=4;x++){
		int k,i,j;
		if(x==1)i=1,j=2,k=3;
		if(x==2)i=1,j=2,k=4;
		if(x==3)i=1,j=3,k=4;
		if(x==4)i=2,j=3,k=4;
		if(a[i]+a[j]>a[k]){
			cout<<"TRIANGLE";
				return 0;
			}
		else if(a[i]+a[j]>=a[k]){
			b=1;
		}
	}
	if(b==0)cout<<"IMPOSSIBLE";
	if(b==1)cout<<"SEGMENT";
				
}

#include<bits/stdc++.h>
using namespace std;
char a[105];
int js[1005];
bool pd(int a)
{
	if(a==1)return 0;
	for(int i=2;i<=sqrt(a);i++)
		if(a%i==0)return 0;
	return 1;
}
int main()
{
	scanf("%s",a);
	for(int i=0;i<strlen(a);i++)
		js[a[i]]++;
	int max=-1023456,min=1023456;
	for(int i=97;i<122;i++){
		if(js[i]==0)continue;
		if(js[i]>max)max=js[i];
		if(js[i]<min)min=js[i];
	}
	if(!pd(max-min))
		cout<<"No Answer\n0";
	else cout<<"Lucky Word\n"<<max-min;	
}

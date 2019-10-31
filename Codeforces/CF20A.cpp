#include<bits/stdc++.h>
using namespace std;
char a[101011];
int main()
{
	gets(a);
	int s=0;
	for(int i=1;i<=strlen(a);i++)
		if(!(a[i]==a[i-1]&&a[i]=='/')){
			s++;
			cout<<a[i-1];
		}
	if(a[strlen(a)-1]!='/'||s==0)cout<<a[strlen(a)-1];
}

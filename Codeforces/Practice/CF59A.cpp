#include<bits/stdc++.h>
using namespace std;
string a;
int main()
{
	cin>>a;
	int s=0,l=0;
	for(int i=0;i<sizeof(a);i++){
		if('a'<=a[i]&&a[i]<='z')s++;
		if('A'<=a[i]&&a[i]<='Z')l++;
	}
	//printf("%d %d",'a','A');
	if(s>=l){
		for(int i=0;i<sizeof(a);i++){
			if('A'<=a[i]&&a[i]<='Z')printf("%c",a[i]-32);
			else cout<<a[i];
		}
	} 
	else if(s<l){
		for(int i=0;i<sizeof(a);i++){
			if('a'<=a[i]&&a[i]<='z')printf("%c",a[i]+32);
			else cout<<a[i];
		}
	}
}

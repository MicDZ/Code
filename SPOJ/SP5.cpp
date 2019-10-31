#include<bits/stdc++.h>
using namespace std;
int tt[1010];
char a[1010100];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		bool book=1;
		scanf("%s",a+1);
		for(int i=1;i<=strlen(a)/2&&book;i++){
			if(a[i]!=a[strlen(a)/2-1]){
				book=0;
			}
		}
	}
	
}

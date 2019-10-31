#include<bits/stdc++.h>
using namespace std;
struct people{
	string name; 
	int year;
	int month;
	int day; 
}a[101010];
bool cmp(const people&a,const people&b) 
{
  	if(a.year<b.year) return 1;
  	if(a.year>b.year) return 0;
  	if(a.month<b.month) return 1;
  	if(a.month>b.month) return 0;
  	if(a.day<b.day) return 1;
  	if(a.day>b.day) return 0;
  	if(a.name<b.name) return 0;
  	else return 1;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i].name<<endl;
} 

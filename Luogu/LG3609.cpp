#include<bits/stdc++.h>
using namespace std;
int a[40010],b[40010],ans;
void msort(int l,int r) {
	int mid=(l+r)/2;
	if(l==r) return ;
	msort(l,mid);
	msort(mid+1,r);
	int p=l,q=mid+1,k=l;
	while(p <= mid && q <= r) {
		if(a[p] > a[q])b[k++]=a[q++],ans+=mid-p+1;
		else b[k++]=a[p++];
	}
	while(p <= mid) b[k++]=a[p++];
	while(q <= r) b[k++]=a[q++];
	for(int i=l; i<=r; i++)a[i]=b[i];
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	msort(1,n);
	printf("%d",ans);
}

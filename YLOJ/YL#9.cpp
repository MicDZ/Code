#include<bits/stdc++.h>
#define MAXN 10+10
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
} 

int a[MAXN],b[MAXN];

bool pd(int x,int k) {
	if(k==3) 
		if(x>999||x<100) return 0;
	if(k==4)
		if(x>9999||x<1000) return 0;
	for(int i=1; x; i++) {
		if(!a[x%10]) return 0;
		x/=10;
	}
	return 1;
}

int main() {
	//freopen("1.out","w",stdout);
	
	int n=read();
	for(int i=1; i<=n; i++) {
		int q=read();
		a[q]=1;
		b[i]=q;
	}

	int sum=0;
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++)
				for(int x=1; x<=n; x++)
					for(int y=1; y<=n; y++) {
						int s1=b[i]*100+b[j]*10+b[k];
						//cout<<s1<<endl;
						int ans1=s1*b[y],ans2=s1*b[x],ans=ans1+ans2*10;
						if(pd(ans1,3)&&pd(ans2,3)&&pd(ans,4)) {
							//cout<<b[i]<<" "<<b[j]<<" "<<b[k]<<endl<<"  "<<b[x]<<" "<<b[y]<<endl;
							sum++;
						}
					}
	cout<<sum<<endl;
}

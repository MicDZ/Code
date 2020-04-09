#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000+10
#define INF 0x3f3f3f3f

int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char a[MAXN],b1,b2;
int have[MAXN],sum[MAXN][27];
int main() {
    int n=read();
    scanf("%s",a+1);
    for(int i=1; i<=n; i++) {
        sum[i][a[i]-'a']=sum[i-1][a[i]-'a']+1;
        for(int j='a'; j<='z'; j++) {
            if(j==a[i]) continue;
            sum[i][j-'a']=sum[i-1][j-'a'];
        }
    }
    //cout<<sum[0][0]<<endl;
    for(int i=1; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            bool flag=1;
            for(int k='a'; k<='z'&&flag; k++) {
                if(sum[j][k-'a']-sum[i-1][k-'a']>=ceil(n*1.0/2)) {flag=0;continue;}
            }
            if(flag) {
                cout<<"YES"<<endl;
                for(int i=1; i<=j; i++) cout<<a[i];
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
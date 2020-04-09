#include<bits/stdc++.h>
#define INF 0x3f3f3f
#define MAXN 1000+10 
using namespace std;
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char a[MAXN][MAXN];
int s[MAXN][MAXN];
int main(){
    int n=read(),m=read();
    //getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            a[i][j]=getchar();
        getchar();
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<a[i][j];
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                s[i+1][j]++;
                s[i-1][j]++;
                s[i][j+1]++;
                s[i][j-1]++;
                s[i+1][j+1]++;
                s[i-1][j+1]++;
                s[i+1][j-1]++;
                s[i-1][j-1]++;
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i][j]!='*'&&a[i][j]!='.'){
                if(a[i][j]-'0'!=s[i][j]){
                    cout<<"NO\n";
                    return 0;
                }
            }
            if(a[i][j]=='.'){
                if(
                    a[i+1][j]=='*'||
                    a[i-1][j]=='*'||
                    a[i][j+1]=='*'||
                    a[i][j-1]=='*'||
                    a[i+1][j+1]=='*'||
                    a[i-1][j+1]=='*'||
                    a[i+1][j-1]=='*'||
                    a[i-1][j-1]=='*'
                    ){
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
        cout<<"YES\n";
        return 0;
}
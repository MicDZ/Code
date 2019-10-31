#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e2+5
#define INF 0x3f3f3f
#define ll long long 
string s[MAXN];
bool have[MAXN][MAXN];
const int a[]={0,-1,-1,-1,0,1,1,1},b[]={1,1,0,-1,-1,-1,0,1};
int x,y,n;
bool book;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>s[i];
    for(int i=1;i<=n;i++)
   		for(int j=1;j<=n;j++)
   			have[i][j]=0;
    for(int i=1;i<=n;i++)
    	for(int j=0;j<=n-1;j++)
    		if(s[i][j]=='y') {
        		for(int k=0;k<=7;k++){
        			x=i;y=j;
            		book=1;
            		for(int t=1;t<=6;t++){
                		x+=a[k];y+=b[k];
                		if(x<1||x>n||y<0||y>n-1) book=0;
                		if(book==0)break;
                		if(t==1&&s[x][y]!='i')book=0;
                		if(t==2&&s[x][y]!='z')book=0;
                		if(t==3&&s[x][y]!='h')book=0;
                		if(t==4&&s[x][y]!='o')book=0;
                		if(t==5&&s[x][y]!='n')book=0;
                		if(t==6&&s[x][y]!='g')book=0;
            		} 
            		x=i;y=j;
            		if(book)
            			for(int t=0;t<=6;t++)
            				have[i][j]=1,x+=a[k],y+=b[k];
        	}
    	}
    	for(int i=1;i<=n;i++)
    		for(int j=0;j<=n-1; j++)
    			if(have[i][j]==0)have[i][j]=1;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(have[i][j])cout<<s[i][j];
    	}
    	cout<<endl;
    }
    	
    return 0;
}
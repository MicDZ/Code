#include<bits/stdc++.h>
#define INF 10234567
using namespace std;

char a[1010][1010];
bool book[101010101];
int xx[10]={0,-1,1,0,0},yy[10]={0,0,0,1,-1},ans=INF;
int bh()
{
    int id=0,cs=1;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++){
            if(a[i][j]=='B')id+=cs*1;
            if(a[i][j]=='W')id+=cs*2;
            cs++;
        }
    return id;
}
bool pd()
{
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[3][3]==a[4][4]||a[1][4]==a[2][3]&&a[2][3]==a[3][2]&&a[3][2]==a[4][1])return 1;
    for(int i=1;i<=4;i++)
        if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]&&a[i][3]==a[i][4]||a[1][i]==a[2][i]&&a[2][i]==a[3][i]&&a[3][i]==a[4][i])return 1;
    return 0;
}
void dfs(int s,char now)
{
    //cout<<"PD is:"<<pd()<<endl;
    if(s>ans)return;
    if(pd()){
       ans=min(ans,s);
       return;
    }
    //cout<<"start"<<s<<endl;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++){
            if(a[i][j]!='O')continue;
            for(int k=1;k<=4;k++){
                if(a[i+xx[k]][j+yy[k]]!=now){
                    swap(a[i][j],a[i+xx[k]][j+yy[k]]);
                    if(!book[bh()]){
                        book[bh()]=1;
                        dfs(s+1,a[i][j]);
                        book[bh()]=0;
                    }
                    swap(a[i][j],a[i+xx[k]][j+yy[k]]);
                }
            }
        }
}
int main()
{

    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            cin>>a[i][j];
    if(pd()){
        cout<<"1";
        return 0;
    }
    //cout<<bh();
    //book[bh()]=1;
    dfs(0,'Q');
    cout<<ans;
    return 0;
}

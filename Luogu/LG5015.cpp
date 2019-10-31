#include<bits/stdc++.h>
using namespace std;
int main() {
    char ch=getchar();
    int ans=0;
    while(ch!='\n') {
        if(ch!=' ') ans++;
        ch=getchar();
    }
    printf("%d\n",ans);
}
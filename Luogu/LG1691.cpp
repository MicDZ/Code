#include<bits/stdc++.h>
using namespace std;
char c[1010];
int main()
{
    int n,x=0;
    scanf("%d%s",&n,c);
    while(next_permutation(c,c+n));
    puts(c);
    x++;
    for(int i=1;next_permutation(c,c+n);i++)
    {
        puts(c);
        x++;
    }
    printf("%d",x);
}

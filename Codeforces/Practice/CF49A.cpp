#include<bits/stdc++.h>
using namespace std;
string str;
bool pd(char a)
{
	if(str[len]=='A'||str[len]=='E'||str[len]=='I'||str[len]=='O'||str[len]=='U'||str[len]=='Y'||str[len]=='a'||str[len]=='e'||str[len]=='i'||str[len]=='o'||str[len]=='u'||str[len]=='y')return 1;
}
int main(){
    getline(cin, str);
    int len=str.length()-1;
    while(!isalpha(str[len]))len--;
    
    else printf("NO");
    return 0;
}

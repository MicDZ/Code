#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e3+5
#define INF 0x3f3f3f
#define ll long long 
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
map<string,int> cnt;
vector<string> words;
string repr(const string& s){
	string ans=s;
	for(int i=0;i<ans.length();i++)ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}
int main() {
	int n = 0;
	string s;
	while(cin>>s){
		if(s[0]=='#') break;
		words.push_back(s);
		string r=repr(s);
		if(!cnt.count(r))cnt[r] = 0;
		cnt[r]++;
	}
	vector<string>ans;
	for(int i=0;i<words.size();i++)
		if(cnt[repr(words[i])]==1)ans.push_back(words[i]);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size(); i++)
		cout<<ans[i]<<"\n";
	return 0;
}//开始基础数据结构复习
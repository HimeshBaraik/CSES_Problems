#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	
	
	int n;
	cin>>n;
	int m=n;
	int ans1=0;
	int ans2=0;
	int ans=0;
	while(n>0)
	{
	    ans1+=n/2;
	    n=n/2;
	}
	while(m>0)
	{
	    ans2+=m/5;
	    m=m/5;
	}
	ans=min(ans1,ans2);
	cout<<ans<<endl;

}

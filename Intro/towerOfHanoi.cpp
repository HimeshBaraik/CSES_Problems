#include <bits/stdc++.h>
using namespace std;


int towerOfHanoi(int n,int source,int des,int middle,vector<pair<int,int>> & v)
{
    if(n==0)
    return 0;
    
    //move n-1 disk from s1 to s2 and move biggest disk s1 to s3
    int move=towerOfHanoi(n-1,source,middle,des,v);
    //move n th to source to desnitation
    // 
    v.push_back({source,des});
    //now we need to move n-1 disks from middle to des
    int move1=towerOfHanoi(n-1,middle,des,source,v);
    
    return 1+move+move1;
    
    
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<pair<int,int>>v;
	int ans=towerOfHanoi(n,1,3,2,v);
	cout<<ans<<endl;
	for(auto p:v)
	{
	    cout<<p.first<<" "<<p.second<<endl;
	}
	
	

}

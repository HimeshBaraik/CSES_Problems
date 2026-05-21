#include <bits/stdc++.h>
using namespace std;

// Checks whether (i, j) is inside the board
bool isValid(int i,int j,int n)
{
    // valid indices: 0 to n-1
    if(i<0 || j<0 || i>=n || j>=n)
        return false;
    
    return true;
}

int main() {
	int n;
	cin>>n;
	
	// All 8 possible knight moves
	vector<pair<int,int>> dir={
	    {1,2},{-1,2},{2,1},{-2,1},
	    {1,-2},{-1,-2},{2,-1},{-2,-1}
	};

	// ans[i][j] = minimum moves to reach (i,j) from (0,0)
	// initialized with large value (infinity)
	vector<vector<int>>ans(n,vector<int>(n,1e9));

	// starting point
	ans[0][0]=0;

	// iterate over grid (trying DP-style relaxation)
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        // -------------------------------
	        // First loop: try to update current cell (i,j)
	        // using its neighbors (reverse relaxation)
	        // -------------------------------
	        for(auto &p:dir)
	        {
	            int x=p.first+i;
	            int y=p.second+j;

	            // if neighbor is valid
	            if(isValid(x,y,n))
	            {
	                // "if I can come from (x,y) to (i,j)"
	                // then distance = 1 + distance[x][y]
	                ans[i][j]=min(ans[i][j],1+ans[x][y]);
	            }
	        }
	        
	        // -------------------------------
	        // Second loop: try to update neighbors
	        // using current cell (forward relaxation)
	        // -------------------------------
	        for(auto &p:dir){
	            
	            int x=p.first+i;
	            int y=p.second+j;

	            if(isValid(x,y,n))
	            {
	                // "from (i,j) I can go to (x,y)"
	                // so update neighbor distance
	                ans[x][y]=min(ans[x][y],1+ans[i][j]);
	            }
	        }
	        
	        // NOTE:
	        // You are doing BOTH forward and backward relaxation
	        // but only in ONE pass over the grid.
	        // This does NOT guarantee shortest paths in graphs.
	    }
	}
	
	// print result grid
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cout<<ans[i][j]<<" ";
	    }
	    cout<<endl;
	}
}

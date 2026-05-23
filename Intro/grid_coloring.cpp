#include <bits/stdc++.h>
using namespace std;

char place(char ch1,char ch2,char ch3)
{
    for(int i=0;i<4;i++)
    {
        char ch=i+'A';
        if(ch!=ch1 && ch!=ch2 && ch!=ch3)
        {
            return ch;
        }
    }
    return ' ';
}

int main() {
 
     int n,m;
     cin>>n>>m;
     vector<string>v;
     for(int i=0;i<n;i++)
     {   string s;
         for(int j=0;j<m;j++)
         {
             char ch;
             cin>>ch;
             s.push_back(ch);
         }
         
         v.push_back(s);
     }
     vector<string>ans;
     for(int i=0;i<n;i++)
     {  
         string s;
         for(int j=0;j<m;j++)
         {
             char ch1=v[i][j];
             char ch2=' ';
             char ch3=' ';
             if(i>0){
                 ch2=ans[i-1][j];
             }
             if(j>0)
             {
                 ch3=s[j-1];
             }
              
             char ch=place(ch1,ch2,ch3);
             
             
             s.push_back(ch);
             
         }
         ans.push_back(s);
     }
     
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             cout<<ans[i][j];
         }
         cout<<endl;
     }

}

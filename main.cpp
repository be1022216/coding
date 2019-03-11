#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char ch[170][170];
int  vis[170][170];
int a1[]={0,-1,0,1};
 int a2[]={-1,0,1,0};
int h,w;
void dfs(int i,int j,int p)
{
    for(int k=0;k<4;k++)
    {
        int i1=i+a1[k];
        int j1=j+a2[k];
        if(i1>=0&&j1>=0&&i1<h&&j1<w)
        {
            if(vis[i1][j1]>=p)
            {

                vis[i1][j1]=p;
                dfs(i1,j1,p+1);

            }
        }
    }
}
int main()
{


    int tt;
    cin>>tt;
    while(tt--)
    {
       cin>>h>>w;
       for(int i=0;i<h;i++)
       {
           for(int j=0;j<w;j++)
           {
               cin>>ch[i][j];
               vis[i][j]=10000;
           }
       }
       for(int i=0;i<h;i++)
       {
           for(int j=0;j<w;j++)
           {
               if(ch[i][j]=='1')
               {
                   vis[i][j]=0;
                   //cout<<"chale"<<endl;
                  // cout<<"H"<<h<<"W"<<w<<endl;
                   dfs(i,j,1);
               }
           }
       }
       for(int i=0;i<h;i++)
       {
           for(int j=0;j<w;j++)
           {
               cout<<vis[i][j]<<" ";
           }
           cout<<endl;
       }


    }
    return 0;
}

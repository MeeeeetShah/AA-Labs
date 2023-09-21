#include <bits/stdc++.h>
#include <iostream>
#include<array>

using namespace std;
const int n=6;
void RandApproxMVC(int G[n][n],int n)
{
    int E[n][2];
    int i,j;
    for(i=0;i<(n/2);i++)
    {
        for(j=0;j<n;j++)
        {
            if (G[i][j]==1)
            {

            }
        }
    }
    
}
int main()
{
    int G[6][6]=
    { 
        {0,1,0,1,0,0},
        {1,0,1,1,0,0},
        {0,1,0,0,1,1},
        {1,1,0,0,1,0},
        {0,0,1,1,0,0},
        {0,0,1,0,0,0}

    };
    RandApproxMVC(G,6);
    return 0;
}
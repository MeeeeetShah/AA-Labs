/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
 
	// Build table K[][] in bottom up manner
	for (i = 0; i <= n; i++) {
    	for (w = 0; w <= W; w++) {
        	if (i == 0 || w == 0)
            	K[i][w] = 0;
        	else if (wt[i - 1] <= w)
            	K[i][w] = max(val[i - 1]
                              	+ K[i - 1][w - wt[i - 1]],
                          	K[i - 1][w]);
        	else
            	K[i][w] = K[i - 1][w];
    	}
	}
	return K[n][W];
}
 
 bool resducesSOS (int Sum,int S[],int n)
 {
     int W=Sum;
     int wt[n];
     
     int val[n];
     for(int i=0;i<n;i++)
     {
         wt[i]=S[i];
         val[i]=S[i];
     }
     int V=Sum;
     int Sol=knapSack(W, wt, val, n);
     if (Sol>=V)
     {
         return true;
     }
     else
     {
         return false;
     }
 }
int main()
{
	int S[] ={2,4,6,8};
    int Sum=9;
	int n = sizeof(S) / sizeof(S[0]);
	if(resducesSOS(Sum,S,n))
	{
	    cout<<"Sum Of Subset  "<<Sum<<" is  possible..from S"<<endl;
	}
	else
	{
	    cout<<"Sum Of Subset "<<Sum<<" is not possible..from S"<<endl;
	}
 
	return 0;
}


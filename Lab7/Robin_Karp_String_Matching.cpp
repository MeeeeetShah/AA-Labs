/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

void Robin_Karp_String_Matcher(char T[],char P[],int d,int q)
{
    int M = strlen(P);
    int N = strlen(T);
    int i, s,j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) 
    {
        p = (d * p + P[i]-'0') % q;
        t = (d * t + T[i]-'0') % q;
    }
    
    for(s=0;s<N-M+1;s++)
    {
         if (p == t) 
         {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) 
            {
                if (T[s + j] != P[j])
                {
                    break;
                }
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
 
            if (j == M)
                cout << "Pattern found at index " << s
                     << endl;
        }
        
        if(s<N-M)
        {
            t = (d * (t - (T[s] -'0')* h) + T[s + M]-'0') % q;
 
            // We might get negative value of t, converting
            // it to positive
            if (t < 0)
                t = (t + q);
        }
        
    }
}

int main()
{
    char Txt[]="";
    char Pat[]="";
    int d,q;
    cout<<"Enter the text"<<endl;
    cin>>Txt;
    cout<<"Enter the patten"<<endl;
    cin>>Pat;
    cout<<"Enter the redex"<<endl;
    cin>>d;
    cout<<"Enter the qutiont /dividor"<<endl;
    cin>>q;
    Robin_Karp_String_Matcher(Txt,Pat,d,q);

    return 0;
}

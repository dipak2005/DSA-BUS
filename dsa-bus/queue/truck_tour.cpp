//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    int kami = 0;
    int balance = 0;
    int start = 0;
    int tour(petrolPump p[],int n)
    {
      for( int i = 0 ; i<n ; i++)
      {
          balance += p[i].petrol - p[i].distance;
          
          // petrol is not sufficient
          if(balance < 0 )
          {
              kami += balance;
              start = i+1;
              balance = 0;
          }
      }
      
      // sufficient pertrol then truck will complete the cycle
      if(kami + balance >= 0)
      return start;
      else
      return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
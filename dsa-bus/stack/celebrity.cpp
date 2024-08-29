//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// brude force t.c : O(n^2)
// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
      
      for( int i=0 ; i<mat.size() ; i++) {
          
          bool isCelebrity = true;
          
          // this person known everyone ( if is celebrity so every element should be 0)
          
          for(int  j = 0 ; j <mat[0].size() ; j++) {
              
              // if 1 so person was known every one and he is not a celebrity
              if(mat[i][j] == 1) {
                  isCelebrity = false;
                  break;
              }
          }
          
          // if person is celebrity so eneter this loop
          if(isCelebrity) {
              
              // in this row person known anyone so this person is not a celebrity 
              // he know  him so skip i==j
              // check the 1th column 
              // celebrity row has only 0s element
            for( int  j = 0 ; j <mat[0].size() ; j++){
                  if(i != j && mat[j][i] == 0){
                  isCelebrity = false;
                  break;
              }
            }
      }
      
      if(isCelebrity) {
          return i;
      }
      
     
      }
       return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends

// seocnd optimized approch t.c : O(n)
//{ Driver Code Starts
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   
		   queue<char> q;
		   unordered_map<char,int> map;
		   string ans = "";
		   
		   for(int i = 0 ; i<A.length() ; i++)
		   {
		       char ch = A[i];
		       
		       // count the frequency of character
		       map[ch]++;
		       
		       // push the element in the queue
		       q.push(ch);
		       
		       while(!q.empty()) 
		       {
		           // frequency is more then one
		           if(map[q.front()] > 1 )
		           {
		               q.pop();
		           }
		           else
		           {
		               // insert into string
		               ans.push_back(q.front());
		               break;
		           }
		       }
		       
		       if(q.empty())
		           ans.push_back('#');
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
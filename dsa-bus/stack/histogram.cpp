#include<iostream>
#include<stack>
#include<vector>
// #include<limits>
using namespace std;
class Solution {
private:

    vector<int> nextSmallerElement(vector<int>& arr,int length) {

        stack<int> s;
        s.push(-1);
        vector<int> ans(length);

        for(int i=length-1; i>=0 ; i--) {

            int curr=arr[i];
        
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr,int length) {
          stack<int> s;
        s.push(-1);
        vector<int> ans(length);

        for(int i= 0 ; i < length ; i++) {

            int curr=arr[i];
        
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {

      int length = heights.size();

      vector<int> next;
      next = nextSmallerElement(heights,length);

      vector<int> prev;
      prev=prevSmallerElement(heights,length);

      int area = -1; 
      for(int i=0; i<length; i++) {
        int l = heights[i];

        if(next[i] == -1) {
            next[i] = length;
        }

         int b = next[i]-prev[i]-1;

        int newArea = l*b;
          area = max(area,newArea); 
      }
       return area;
    }

    int main() {
   vector<int>  h = {2,1,5,6,2,3};

   
//    for (int i = 0; i < height.size(); i++)
//    {
//     cout<< height[i] << endl;
//    }
   cout<< largestRectangleArea(h)<< endl;
    
    }
};
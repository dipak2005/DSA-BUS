#include<iostream>
#include<vector>
#include <map>
using namespace std;

int findDuplicate(vector<int> &arr) 
{
    map<int,bool> visited;
     
    int n=arr.size();

    int i=0;

    while(i<=n)
    {
        int num= arr[i];
        if(visited[num] == true)
        {
            return num;
        }
        visited[num] = true;
        i++;
    }
	return -1;
}


#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> spiralMatrix(vector<vector<int>> nums)
{

   int row = nums.size();
   int col = nums[0].size();

   vector<vector<int>> ans;
   int total = row * col;
   int sri = 0 , eri = row-1;
   int sci = 0 , eci = col-1;

   int count = 0 ;

   while (count < total)
   {
    // first row upper side
    for (int i = sci; i < eci; i++)
    {
        ans.push_back(nums[sri][i]);
        count++;
    }
    sri++;
// last column last side
    for (int i = sri; i < eri; i++)
    {
        ans.push_back(nums[i][eci]);
        count++;
    }
    eci--;

   }
   
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    spiralMatrix(matrix);
    return 0;
}
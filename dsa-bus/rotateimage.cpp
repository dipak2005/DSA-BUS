#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// reverse the each element for each row
void reverse(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}
void image(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main()
{

    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(matrix); 
    cout << " after transpose :" << endl;
    image(matrix);
    
    print(matrix);
     cout << " after reverse :" << endl;
    reverse(matrix);

    print(matrix);
    return 0;
}
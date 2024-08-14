#include <iostream>  
#include <vector>  

using namespace std;  

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {  
    // Check this row on left side  
    for (int i = 0; i < col; i++)  
        if (board[row][i] == 1)  
            return false;  

    // Check upper diagonal on left side  
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)  
        if (board[i][j] == 1)  
            return false;  

    // Check lower diagonal on left side  
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)  
        if (board[i][j] == 1)  
            return false;  

    return true;  
}  

bool solveNQUtil(vector<vector<int>>& board, int col, int N) {  
    if (col >= N)  
        return true;  

    for (int i = 0; i < N; i++) {  
        if (isSafe(board, i, col, N)) {  
            board[i][col] = 1; // Place queen  

            if (solveNQUtil(board, col + 1, N))  
                return true;  

            board[i][col] = 0; // Backtrack  
        }  
    }  
    return false;  
}  

void solveNQ(int N) {  
    vector<vector<int>> board(N, vector<int>(N, 0));  
    if (solveNQUtil(board, 0, N) == false) {  
        cout << "Solution does not exist";  
        return;  
    }  

    for (int i = 0; i < N; i++) {  
        for (int j = 0; j < N; j++)  
            cout << " " << board[i][j] << " ";  
        cout << endl;  
    }  
}  

int main() {  
    int N = 4; // Change this value for different board sizes  
    solveNQ(N);  
    return 0;  
}
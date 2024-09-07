#include <iostream>
using namespace std;
int main()
{

    // char n = 'E';

    // for (char i = 'A'; i <= n; i++)
    // {
    //     for (char j = 'A'; j <= i; j++)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i <= 4; i++)
    // {
    //     for (int j = 1; j < i + 1; j++)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "after" << endl;
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (int j = i; j >= 1; j--)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    // char ch = 'A';
    // for (int i = 0; i < 4; i++)
    // {

    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << ch++ << " ";
    //     }
    //     cout << endl;
    // }

int n=4,num=1;
  for (int i = 0; i <n; i++)
  {
    for (int  j = 0; j < i; j++)
    {
        cout << " ";
    }

    for (int j = 0;j<n-i ; j++)
    {
        cout <<i+1;
    }
cout<< endl;
    
    
  }

  for(int i=0;i<n;i++){

    // space
    for(int j=0;j<n-i-1;j++){
        cout<< " ";
    }

    for(int j=1;j<=i+1;j++){
        cout<< j;
    }
    for (int j = i; j > 0; j--)
    {
        cout << j;
    }
    cout << endl;
    
  }
  
}
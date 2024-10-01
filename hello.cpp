#include<iostream>
using namespace std;
void sayDigit(int n,string arr[]){
    
    // base case
    if(n==0)
    return;
    
    int digit = n%10;
    n=n/10;
    
    sayDigit(n,arr);
    
    cout << "digits :" << arr[digit] << endl;
}
 

int main () {
    
    
    string arr[]={"zero","one","two","three","four","five","six","seven","eight","ning"};
    int n;
    cin >> n;
    int newnum = 0;
    while (n != 0)
    {
        int remainder = n%10;
        newnum = newnum *10+ remainder;
        n=n/10;
    }
    
    cout<< newnum << endl;
    // sayDigit(n,arr);
    
 return 0;   
}
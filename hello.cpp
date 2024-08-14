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
    
    
    sayDigit(n,arr);
    
 return 0;   
}
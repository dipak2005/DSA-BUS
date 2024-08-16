/*
#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    stack<char> str;
    for(int i=0; i <s.length() ; i++)
    {
      
      char ch=s[i];
      
      if(ch == '(' || ch == '+' || ch== '-' || ch=='*' || ch == '/')
      {
          s.push(ch);
      }
      else
      {
          if(ch == ')')
          {
              bool isReduandant= true;
            char top =   str.top();
              while(top != '(')
              {
                  if(top == '+' || top == '-' || top =='*' || top == '/')
              {
                  // not redandant 
                  isReduandant =false;
              }
              str.pop();
              }
             if(isReduandant== true)
         
             return  true;
             str.pop();
          } 
      }
    }
    return false;
}

*/
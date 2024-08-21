

bool isValidParenthesis(string s)
{
     stack<char> str;

    for(int i=0; i<s.length();i++){

       

        char ch = s[i];

        if( ch =='{' || ch == '(' || ch == '[')
        {
            str.push(ch);
        }else
        {

            if (!str.empty()) {
              char first = str.top();

              if ((ch == '}' && first == '{')||
               (ch == ')' && first =='(' ) ||
                (ch == ']' && first == '['))
                {
                    str.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
       
    }

     if(str.empty())
        
          return true;
        
        else
        
        return false;
        

}

// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> out;
        // Your code here
        for(int i=0;i<S.size();i++){
        
        if(S[i]=='*' || S[i]=='/' || S[i]=='+' || S[i]=='-'){
            int op1 = out.top();
            out.pop();
            int op2 = out.top();
            out.pop();
            int val;
            switch(S[i]){
                case '*': val = op2*op1;
                break;
                
                case '+': val = op2+op1;
                break;
                
                case '-': val = op2-op1;
                break;
                
                case '/': val = op2/op1;
                break;
            }
            out.push(val);
        }
        else{
            int num = (int)S[i]-48;
            out.push(num);
        }
        
    }
    return out.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
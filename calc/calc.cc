#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

stack<char> expStack;

//char infix_exp[600]; make it local
//////////////////////////
////// poxfix > infix ////
void infix (char* posfix_exp,char *infix_exp)
{
   int i = 0;
   while(*posfix_exp  )
   {
      if( *posfix_exp >= '0' && *posfix_exp <= '9' ) 
      {
         while( *posfix_exp >= '0' && *posfix_exp <= '9') 
         {
            infix_exp[i] = *posfix_exp;
            i++;
            posfix_exp++;
         }
         //add a flag # to indicate a Number ends!
         infix_exp[i] = '#';
         i++;
         posfix_exp--; // commom one in the end
      }
      else if (*posfix_exp == '(') 
      {
         expStack.push(*posfix_exp);
      } 
      else if (*posfix_exp == ')') 
      {
         // output stack until '('
         while(!expStack.empty())
         {
            if(expStack.top() != '(') {
               infix_exp[i] = expStack.top();
               i++;
               expStack.pop();
            } else {
               break;
            }            
         }
         // pop '('
         expStack.pop();
      }
      else if (*posfix_exp == '*' || *posfix_exp == '/')
      {
         while( !expStack.empty() )
         {
            if( expStack.top() != '+' && expStack.top() != '-' && expStack.top() != '(' )
            {
               infix_exp[i] = expStack.top();
               i++;
               expStack.pop();
            } 
            else
            {
               break;
            }
         }
         expStack.push(*posfix_exp);
      }
      else if (*posfix_exp == '+' || *posfix_exp == '-')
      {
         while( !expStack.empty() )
         {
            if(expStack.top() != '(') // top() should not be with empty(), it could be empty!
            {
               infix_exp[i] = expStack.top();
               i++;
               expStack.pop();
            } else {
               break;
            }
         }
         expStack.push(*posfix_exp);
      }
      posfix_exp ++;
   }
   // after read all, output expStack
   while( !expStack.empty() )
   {
      infix_exp[i] = expStack.top();
      i++;
      expStack.pop();
   }
   infix_exp[i]='\0';//make it end
}
//////////////////////////
///////  calculate ///////
int calcResult(char * infix_exp)
{
   stack<int> infixStack;
   int i = 0;
   while( infix_exp[i] )
   {
      if( infix_exp[i] >= '0' && infix_exp[i] <= '9' )
      {
         //cout<<"#"<<i<<",infix_exp["<<i<<"]:"<<infix_exp[i]<<endl;
         //char tmp = infix_exp[i];
         infixStack.push( atoi(&infix_exp[i]) );
         //by pass Number , until flag #
         while( infix_exp[i] != '#')
         {
             i++;
         }
      } else {
         int op1 = infixStack.top();
         infixStack.pop();
         int op2 = infixStack.top();
         infixStack.pop();
         
         switch(infix_exp[i])
         {
            case '+':
               infixStack.push(op1+op2);
               break;
            case '-':
               infixStack.push(op2-op1);
               break;
            case '*':
               infixStack.push(op1*op2);
               break;
            case '/':
               infixStack.push(op2/op1);
               break;
         }
      }
      i++;
   }
   return infixStack.top();
}

//////////////////////////
///////   main  //////////
int main()
{
   char posfix_exp[600];
   int round;
   cin >> round;
   int result[round];
   for(int i=0; i<round; i++)
   {
      cin >> posfix_exp;
      char infix_exp[600];//localize!
      infix(posfix_exp,infix_exp);
      //cout << infix_exp << endl;
      result[i] = calcResult(infix_exp);
   }
   for(int i=0; i<round; i++)
   {
      cout << result[i] << endl;
   }

   return 0;
}

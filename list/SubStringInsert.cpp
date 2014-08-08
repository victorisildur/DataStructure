#include <iostream>
#include "linkList.h"
#include <stdlib.h>
int main()
{
  linkList<char> mStr;
  linkList<char> mSubStr;
  char str[20];
  cin.getline(str,20);
  cout<<str<<endl;
  int i=0, hasSpace = 0, j=1;
  while(str[i] != '\0' && str[i] != '\n')
  {
    if( str[i] == ' ')
    {
       i++;
       hasSpace = 1;
       continue;
    }
    else if(hasSpace == 0)
    {
       mStr.insert(i+1,str[i]);
       i++;
    }
    else if(hasSpace == 1)
    {
       mSubStr.insert(j,str[i]);
       i++;j++;
    }
  }
  mStr.traverse();
  mSubStr.traverse();
  //here comes the algorithm
  i=2;
  int maxIndex;
 
  j=mStr.visit(1);
  while( i<=mStr.length() )
  {
     if( j<mStr.visit(i) )
     {
         j = mStr.visit(i);
         maxIndex = i;
     }
     i++;
  }
  for(i=0;i<2;i++)
  mStr.insert(maxIndex+i,mSubStr.visit(i));
 
  mStr.traverse();

  return 0;
}


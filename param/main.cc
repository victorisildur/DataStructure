#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main()
{
   char input[20];
   printf("please enter:\n");
//   gets(input);
   printf("input:%s\n",input);
   FILE *fp = fopen("inputFile","r");
   char command[30];
   while(   fscanf(fp,"%s",command) != EOF )
   {
      printf("command: %s\n",command);
   }

   stringstream ss;
   ss.str("1.23");
   ss.str("3.45");
   string str = ss.str();
   double dnum;
   ss >> dnum;
   cout<<"dnum:"<<dnum<<endl;
   printf("print dnum:%f",dnum);
   cout<<"sss:"<<str<<endl;

   return 0;
}

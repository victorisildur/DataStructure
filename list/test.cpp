#include "test.h"
#include <iostream>
#include <stdlib.h>
#include "linkList.h"

int main()
{
  cout<<"this is main."<<endl;
  cout<<"this is main2."<<endl;
  linkList<int> list;
  int data=211;
  //list.insert(0,111);
  list.insert(1,222);
  list.insert(2,222);
  list.insert(3,33);
  list.insert(4,44);
  list.traverse();  
  return 0;
}

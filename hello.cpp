#include <stdio.h>
#include <iostream>
int main()
{
  //printf("hello");
  std::cout<<"hello!"<<std::endl;
  char str[10];
    
  int array[5] = {3,56,867,548,22};
  int i,x,j;

  for(i=1;i<5;i++) {
    x=array[i];
    j = i-1;
    while((j>=0)&&(x>array[j])) {
      array[j+1] = array[j];
    }
  }
  
  std::cin>>str;

  return 0;

}

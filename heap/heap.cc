#include <iostream>

using namespace std;

int array[10000];
int currentSize;

int deQueue()
{
   currentSize --;
   if(currentSize < 0)
   {
      cout<< "heap is empty"<<endl;
      return -999;
   } else {
      int minItem = array[1];
      // go down
      int child;
     int hole = 1;
      int lastItem = array[currentSize+1]; 
      for(; hole*2 <= currentSize; hole=child)
      {
         child = hole*2;
         //choose the smaller child
         if( child!=currentSize && array[child+1] < array[child] )
             child++;
         //if smaller child < hole, hole going down!
         if(array[child] < lastItem) {
            array[hole] = array[child];
         } else {
            //if hole < smaller child, end!
            break;
         }
      }
      array[hole] = lastItem;
      // return array[1]
      return minItem;
   }
}
void enQueue(const int& x)
{
   currentSize ++;
   int hole = currentSize;
   // go up
   for(; hole>1 && x<array[hole/2]; hole /=2 ) 
   {
      array[hole] = array[hole/2];
   }
   array[hole] = x;
}

int main()
{
   int op_times;
   int groups;
   //input groups
   cin >> groups;
   int deQueueCount = 0;
   int deQueueItems[300000];
   //use the same array for every group

   for(int j=0;j<groups;j++)
   {
           currentSize = 0;
           //input operation times
	   cin >> op_times;
	   //input
	   for(int i = 0; i<op_times ; i++)
	   {
	      int op_name;
              //input operation type
	      cin >> op_name;
	      int input_num;
	      if(op_name == 1) 
	      {
                 //input added value
		 cin >> input_num;
		 enQueue(input_num);
	      } else if(op_name == 2) {
		 deQueueItems[deQueueCount] = deQueue();
		 deQueueCount ++;
	      }
	   }
   }   
   for(int i = 0; i<deQueueCount; i++)
   {
      cout<<deQueueItems[i]<<endl;
   }
}

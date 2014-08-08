#include <iostream>
#include <queue>

using namespace std;
#define SIZE 1000

////////////////////////////////////
///////////a brutal algorithm///////
int bfs( int n, int k)
{
   
   bool visited[SIZE] ;
   int step[SIZE];
   queue<int> farmer_queue;
   //farmer enQueue
   farmer_queue.push(n);
   int this_round_pos, next_round_pos;
   int i;
   while( ! farmer_queue.empty() ) {
      this_round_pos = farmer_queue.front();
      farmer_queue.pop();
      for(i=0; i<3; i++) {
        //for each round , we got 3 directions to go
        if(i==0) {
           next_round_pos = this_round_pos + 1;
        } 
        else if(i==1) {
           next_round_pos = this_round_pos - 1;
        }
        else {
           next_round_pos = this_round_pos * 2;
        }
        //
        if(next_round_pos > SIZE || next_round_pos < 0) 
           continue;
        //
        if( !visited[next_round_pos] )
        {
           farmer_queue.push(next_round_pos);
           step[next_round_pos] = step[this_round_pos] + 1;
           visited[next_round_pos] = true;
        }
        if( next_round_pos == k)
           return step[k];
      }
   }
 
}



////////////////////////////////////
////////////main////////////////////
int main()
{
   int n, k;
   cin >> n >> k;
   if(n >= k) {
      cout<< n-k <<endl;
   }
   else {
      cout << bfs(n,k) <<endl;
   }
   
}

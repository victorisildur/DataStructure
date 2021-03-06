#include <iostream>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph {
   public:
      adjListGraph(int vSize, const TypeOfVer d[]);
      ~adjListGraph();
      bool insert(int u,int v, TypeOfEdge w);
      TypeOfEdge prim(TypeOfEdge noEdge);
   private:
      struct edgeNode 
      {
         int end;    // edge point to which ver
         TypeOfEdge weight;
         edgeNode * next;
         edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL)
         {
            end = e;
            weight = w;
            next = n;
         }
      };

      struct verNode
      {
         TypeOfVer ver; // ver name in char
         edgeNode *head;
         bool deleted;
         verNode (edgeNode *h = NULL)
         {
            head = h;
            deleted = false;
         }
      };
      
      verNode *verList;
      int Vers;
      int Edges;
};

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[])
{
   Vers = vSize;
   Edges = 0;
   verList = new verNode[vSize];
   for( int i=0;i<vSize;++i)
      verList[i].ver = d[i];
}

template <class TypeOfVer, class TypeOfEdge>
adjListGraph<TypeOfVer,TypeOfEdge>::~adjListGraph()
{
   int i;
   edgeNode *p;
   
   for(i =0 ; i<Vers; ++i)
   {
       while( (p=verList[i].head) != NULL )
       {
          verList[i].head = p->next;
          delete p;
       }
   }
}


template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer,TypeOfEdge>::insert(int u,int v,TypeOfEdge w)
{
   verList[u].head = new edgeNode(v,w,verList[u].head); //right be NULL for the first time?
   verList[v].ver++;
   ++Edges;
   return true;
}

template <class TypeOfVer, class TypeOfEdge>
TypeOfEdge adjListGraph<TypeOfVer,TypeOfEdge>::prim(TypeOfEdge noEdge)
{
   bool *flag = new bool[Vers];
   int *startNode = new int[Vers];
   TypeOfEdge* lowCost = new TypeOfEdge[Vers];
   //initial
   for(int i=1;i<Vers;i++)
   {
      flag[i] = false;
      lowCost[i] = noEdge;
   }

   int start = 0;
   edgeNode *p;
   TypeOfEdge min;
   TypeOfEdge treeWeightSum = 0;
   for(int i=0;i<Vers;i++)
   {
      for(p=verList[start].head; p!= NULL ;p=p->next)
         if( !flag[p->end] && lowCost[p->end] > p->weight )
         {
            lowCost[p->end] = p->weight;
            startNode[p->end] = start;
         }
      flag[start] = true;
      min = noEdge;
      // finding the least weight edge from U to V-U
      for(int j=0;j<Vers;j++)
         if(lowCost[j]<min) {
            min = lowCost[j];
            start = j;
         }
      treeWeightSum += min;
      lowCost[start] = noEdge;
   }
   
   delete [] flag;
   delete [] startNode;
   delete [] lowCost;
   return treeWeightSum;
}


///////////////////////////
//////////main/////////////
int main()
{
   // input vers num , construct the graph
   int vers;           
   cin>>vers;
   char *d = new char[vers];
   for(int i=0;i<vers;i++)
   {
      d[i] = 'A'+i;
   }
   adjListGraph<char,int> g(vers,d);
   //input edges
   for(int i=1;i<vers;i++)
   {
      char verName;
      int edgeNum;
      cin>>verName>>edgeNum;
      for(int j=0;j<edgeNum;j++)
      {
         char verName2;
         int weight;
         cin>>verName2>>weight;
         g.insert(verName-'A',verName2-'A',weight);
         g.insert(verName2-'A',verName-'A',weight);
      } 
   }
   cout << g.prim(999) <<endl;
}

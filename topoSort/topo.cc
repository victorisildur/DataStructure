#include <iostream>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class adjListGraph {
   public:
      adjListGraph(int vSize, const TypeOfVer d[]);
      ~adjListGraph();
      bool insert(int u,int v, TypeOfEdge w);
      bool topoSort();
   private:
      struct edgeNode 
      {
         int end;
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
         TypeOfVer ver; // "in" degree
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
bool adjListGraph<TypeOfVer,TypeOfEdge>::topoSort()
{
   edgeNode *p;
   int i;
   for(int j=0;j<Vers;j++)
   {
      for(i=0;i<Vers;i++)
      {
         if(verList[i].ver == 0 && verList[i].deleted == false)
         {
            cout<<"v"<<i+1<<" ";
            while( (p=verList[i].head)!=NULL )
            {
               verList[p->end].ver--; // inDegree down
               verList[i].head = p->next;
               delete p;
            }
            verList[i].deleted = true;
            break;
         }
      }
   }
   cout<<endl; 
}

int main()
{
   int vers,edges;
   cin>>vers>>edges;
   int *d= new int[vers];
   for(int i=0;i<vers;i++)
   {
      d[i]=0;
   }
   adjListGraph<int,int> g(vers,d);
   int u,v;
   for(int i=0;i<edges;i++)
   {
       cin>>u>>v;
       g.insert(u-1,v-1,1);
   }
   g.topoSort();
}

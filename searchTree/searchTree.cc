#include <iostream>
#include <cstdio>

using namespace std;

class SearchTree
{
   private:
      struct Node
	   {
	     int data;
        Node *left;
	     Node *right;
		 
	     Node(const int &data,Node *leftNode,Node *rightNode):data(data),left(leftNode),right(rightNode)
		  {
		  }
      };
   public:
      SearchTree(Node *t = NULL)
		{ 
		   root=t;
		}
	   ~SearchTree()
		{
		}
	   bool find(const int &x) const;
	   void insert(const int &x);
	   void traverse();

   private:
		Node *root;
      void traverse( Node * &t);

      bool find(const int &x, Node * t) const;
      void insert(const int &x, Node * &t);
};

bool SearchTree::find(const int &x) const
{
   find(x,root);
}

bool SearchTree::find(const int &x, Node * t) const
{
   if(t == NULL) {
	   return false;
	} else if (x < t->data) {
	   return find(x, t->left);
	} else if (x > t->data) {
      return find(x, t->right);
	} else {
	   return true;
	}
}

void SearchTree::insert(const int &x)
{
   insert(x, root);
}

void SearchTree::insert(const int &x, Node * &t)
{
   if( t == NULL )
	{
      t = new Node(x,NULL,NULL);
	} else if ( x < t->data) {
	   insert(x, t->left);
	} else if ( x > t->data) {
	   insert(x, t->right);
	}
}

void SearchTree::traverse()
{
   if( root == NULL )
	   cout << "An empty tree!" <<endl;
	else {
      traverse( root );
	}
}

void SearchTree::traverse( Node * &t)
{
	//cout << t->data <<endl;
   
   printf("%d ",t->data);

	if( t->left != NULL )
      traverse(t->left);
	
	if( t->right != NULL )
	   traverse( t->right );

}

int main()
{
   SearchTree tree;
	int x;
   //int c;
	//while( scanf("%d ",&x) != 0 ) {
	//do {
      //scanf("%d",&x); //stop at the SPACE
		//printf("x: %d\n",x);
      //tree.insert(x);
		//c = getchar();
		//printf("c: %d\n",c);
	//} //while( c != 10 );

   char ch;
	int number = 0;
   while( (ch = getchar() ) != '\n')
	{
	   if(ch == ' ')
	   {
	      tree.insert(number);
			number = 0;
	   }
	   else
	   {
	      number*=10;
	      number+=ch-'0';  
	   }
	}


   tree.traverse();
	printf("\n");

	return 0;
}

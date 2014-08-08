#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class Trie 
{
public:
   Trie()
	{
      cnt = 0;
		for(int i=0; i<26; i++)
		{
		   next[i] = NULL;
		}
	}
   ~Trie()
	{
	}
   void insert(char *w);
	void findPrefix(char*w, char* pre);
	void insert(char *w, Trie * &t);
private:
   Trie *next[26];
	int cnt;
   
	void findPrefix(char *w, Trie *t, char* pre);
};

void Trie::insert(char *w)
{
   //insert(w,this);
}

void Trie::insert(char *w, Trie * &t)
{
	   if( t == NULL )
		{
		   t = new Trie();
		}
		t->cnt++;
	if( *w != '\0' ) 
	{
		insert(w+1,t->next[*w-'a']);  //essential shit!
		
	}
}

void Trie::findPrefix(char *w, char* pre)
{
   findPrefix(w,this,pre);
}

void Trie::findPrefix(char *w, Trie *t, char* pre)
{
	//char prefix[20];
   int i = 0;
	t = t->next[w[i]-'a'];
   
   //cout<<"-------------------"<<endl;
	//cout<<"w len:"<<strlen(w)<<endl;
   while( i<strlen(w) )
	{
	//   cout << "i:" << i<<endl;
   //   if( t == NULL ) {
			//pre[i] = w[i];
	//		i--;
	//		break;
	//	}
		if( t->cnt == 1) {
		   pre[i] = w[i];
		   break;
		} else if( t->cnt > 1) {
		   pre[i] = w[i];
		}
      //cout<<"w["<<i<<"]:"<<w[i]<<endl;
		//cout<<"t:"<<t<<endl;
		//cout<<"t->cnt:"<<t->cnt<<endl;

	   i++;		
		if( w[i] != '\0') {
	      t = t->next[w[i]-'a'];
		}
		//cout<<"after t:"<<t<<endl;
	}
	if( i== strlen(w) ) {
	   pre[i] = '\0';
	} else {
	   pre[i+1] = '\0';
	}
	//cout<< "pre length:"<<strlen(pre) <<endl;
	//cout<< "w length:"<<strlen(w) <<endl;
   //pre = prefix;
}


int main()
{
   Trie *rt = new Trie();
	//rt->insert("applepie",rt);
	//rt->insert("application",rt);
   int lines ;
   char word[20][20];
	//for( int i=0; i<lines; i++)
	{
	  // cin >> word[i];
     // rt->insert(word[i], rt);
		//cout << i<<":"<<word[i]<<endl;
	}
   int i=0;
   while (scanf("%s",word[i]) != EOF)
	{
      rt->insert(word[i],rt);
		i++;
	}

   lines = i;
//	cout << lines <<endl;

   //getchar();
   //getchar();
	char pre[20][20];
	for( i=0; i<lines; i++)
	{
	   rt->findPrefix(word[i],pre[i]);
		//getchar();
		cout<<word[i]<<" "<<pre[i]<<endl;
	}
   //getchar();
	//getchar();
   
   //delete rt;
   return 0;	
 	//rt->findPrefix("applepie",pre);
   //cout << pre <<endl;
}

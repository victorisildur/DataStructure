#ifndef _LINKLIST_H
  #define _LINKLIST_H
  #include "list.h"
  #include <stdlib.h>
  #include <iostream>
  using namespace std;

template <typename elemType>

class linkList: public list<elemType>
{ private:
    struct node {
      elemType data;
      node *prev, *next;
      
      node( const elemType &x, node *p = NULL, node *n = NULL) {
        data = x;
        prev = p;
        next = n;
      };
 
      node():next(NULL),prev(NULL) {}
   
      ~node() {}
    };

     node *head,*tail;
     int currentLength;

     node * move(int i) const;

   public:
     linkList();
     ~linkList() {
       clear();
       delete head;
       delete tail;
     }

     void clear();
     int length() const 
     {
       return currentLength;
     }

     void insert(int i, const elemType &x);
     void remove(int i);
     int search(const elemType &x) const;
    
     void traverse() const;
};

  #include "linkList.cpp"
#endif

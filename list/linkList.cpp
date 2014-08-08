template <typename elemType>
typename linkList<elemType>::node* linkList<elemType>::move(int i) const
{
  node *p = head;
  if(i<0 || i>currentLength) cout<<"out of bound."<<endl;
  while(i--)
    p=p->next;
  return p;
}

template <typename elemType>
linkList<elemType>::linkList()
{
  head = new node;
  head->next = tail = new node;
  tail->prev = head;
  currentLength = 0;
}

template <typename elemType>
void linkList<elemType>::clear()
{
  node * ptr, *tmp;
  ptr = head->next;
  while(ptr!=tail)
  {
    tmp = ptr->next;
    delete ptr;
    ptr = tmp;
  }
  head->next = tail;
  tail->prev = head;
  currentLength = 0;
}

template <typename elemType>
void linkList<elemType>::insert(int i, const elemType &x)
{
  ++currentLength;
  node *ptr = move(i);
  node *new_node = new node(x, ptr->prev,ptr);
  ptr->prev->next = new_node;
  ptr->prev = new_node;
}

template <typename elemType>
void linkList<elemType>::remove(int i)
{
  node *ptr;
  ptr = move(i);
  ptr->prev->next = ptr->next;
  ptr->next->prev = ptr->prev;
  delete ptr;
  currentLength--;
}

template <typename elemType>
int linkList<elemType>::search(const elemType &x) const
{
  node * ptr = head->next;
  int i=0;
  while (ptr->data != x && ptr != tail)
  {
     ptr = ptr->next;
     i++;
  }
  if(i==currentLength)
    return -1;
  return i;
} 

template <typename elemType>
void linkList<elemType>::traverse() const
{
  node *p = head->next;
  cout<<endl;
  while(p!=tail)
  {
    cout << p->data <<" ";
    p = p->next;
  }
  cout << endl;
}


   


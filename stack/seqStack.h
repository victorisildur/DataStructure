template <class elemType>
class seqStack:public stack <elemType>
{
private:
   elemType *elem;
   int top_p;
   int maxSize;
   
   void doubleSpace();
public:
   seqStack( int initSize = 10)
   {
      elem = new elemType[initSize];
      maxSize = initSize;
      top_p = -1;
   }

   ~seqStack()
   {
      delete [] elem;
   }

   bool isEmpty() const
   {
      return (top_p == -1);
   }

   

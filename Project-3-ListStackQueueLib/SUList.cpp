//defualt constructor
template<class DataType>
SUList<DataType>::SUList(){
  head=nullptr;
  tail=nullptr;
}
//Copy constructor
template<class DataType>
SUList<DataType>::SUList(const SUList& old){
  if(old.head==nullptr){//checks to see if there is a old head
    head=nullptr;
    tail=nullptr;
  }else{//if there is then
    ListNode* oldCursor=old.head;
    while(oldCursor){//pushes everything over
      putBack(oldCursor->data);
      oldCursor=oldCursor->next;
    }
  }
};
//equals overloaded operator
template<class DataType>
  SUList<DataType>& SUList<DataType>::operator=(const SUList<DataType>& old){
    if(this==&old){
      return *(this);
    }
    ListNode* oldCursor=old.head;
    while(oldCursor){
      putBack(oldCursor->data);
      oldCursor=oldCursor->next;
    }
  return *(this);
  }
//Deconstructor
template<class DataType>
SUList<DataType>::~SUList(){
  ListNode* cursor=head;
  while(head){
    cursor=head;
    head=head->next;
    delete cursor;
  }
}
//Pops the front/head
// template<class DataType>
// DataType SUList<DataType>::getFront(){
//   ListNode* cursor=head;
//   DataType rtn;
//   //TODO Need to fix if there is no head
//   if(!head){
//     throw "Queue is empty!";
//   }
//   if(!head->next){
//     rtn=head->data;
//     delete head;
//     head=nullptr;
//     tail=nullptr;
//     return rtn;
//   }
//   rtn=head->data;
//   head=head->next;
//   delete cursor;
//   return rtn;
// }
template<class DataType>
DataType SUList<DataType>::getFront(){
  ListNode* cursor=head;
  DataType rtn;
  //TODO Need to fix if there is no head
  if(!head){
    throw "Queue is empty!";
  }
  if(!head->next){
    rtn=head->data;
    delete head;
    head=nullptr;
    tail=nullptr;
    return rtn;
  }
  rtn=head->data;
  head=head->next;
  delete cursor;
  return rtn;
}
//pops the end of the list
// template<class DataType>
// DataType SUList<DataType>::getBack(){
//   ListNode* cursor=head;
//   ListNode* prev=head;
//   DataType temp;
//   if(!head){//if the stack is empty when it tries to pop
//     throw "Queue is empty!";
//   }
//   if(!head->next){//if there is only one item left than pop it
//     temp = head->data;
//     delete head;
//     head=nullptr;
//     return temp;
//   }
//   while(cursor->next){//finds end with a prev
//     prev=cursor;
//     cursor=cursor->next;
//   }
//   prev->next=nullptr;
//   temp = cursor->data;
//   delete cursor;//detatches and deltes end but before it sends it
//   return temp;
// }
template<class DataType>
DataType SUList<DataType>::getBack(){
  ListNode* cursor=head;
  ListNode* prev=head;
  DataType temp;
  if(!head){//if the stack is empty when it tries to pop
    throw "Queue is empty!";
  }
  if(head->next==tail){
    cursor=tail;
    temp=tail->data;
    head->next=nullptr;
    delete cursor;
    return temp;
  }
  if(head==tail){
    temp=head->data;
    delete head;
    return temp;
  }
  temp=tail->data;
  prev=tail;
  cursor=tail->previous;
  cursor->next=nullptr;
  delete prev;
  return temp;
}
//This will push a new dataType onto the front of the list
// template<class DataType>
// void SUList<DataType>::putFront(const DataType&x){
//   ListNode* newNode = new ListNode;
//   newNode->data=x;
//   newNode->next=head;
//   newNode->previous=nullptr;
//   //head->prev
//   head=newNode;
// }
template<class DataType>
void SUList<DataType>::putFront(const DataType&x){
  ListNode* newNode = new ListNode;
  newNode->data=x;
  if(!head){
    head=newNode;
    tail=newNode;
    newNode->next=nullptr;
    newNode->previous=nullptr;
  }
  newNode->next=head;
  newNode->previous=nullptr;
  head->previous=newNode;
  head=newNode;
}
//This will push a new Datatype into the bakc of the list
// template<class DataType>
// void SUList<DataType>::putBack(const DataType&x){
//   ListNode* newNode = new ListNode;
//   newNode->data=x;
//   newNode->next=nullptr;
//     tail=newNode;
//   if(!head){
//     head=newNode;
//     return;
//   }
//   ListNode* cursor=head;
//   while(cursor->next){
//     cursor=cursor->next;
//   }
//   cursor->next=newNode;
// }
template<class DataType>
void SUList<DataType>::putBack(const DataType&x){
  ListNode* newNode = new ListNode;
  newNode->data=x;
  newNode->next=nullptr;
  if(!head){
    head=newNode;
    tail=newNode;
    newNode->next=nullptr;
    newNode->previous=nullptr;
  }
  newNode->previous=tail;
  tail->next=newNode;
  tail=newNode;
}
//checks to see if there is a desired DataType in the list
//NOTE: This function will require that the datta type has the == operator
template<class DataType>
bool SUList<DataType>::contains(const DataType&x){
  ListNode* cursor=head;
  while(cursor){
    if(cursor->data==x){
      return true;
    }
    cursor=cursor->next;
  }
  return false;
}
//Display requires the overloaded << or you make your own overloaded tamplate
template<class DataType>
void SUList<DataType>::display() const{
  ListNode* cursor=head;
  if(!head){
    std::cout<<"Empty list!"<<std::endl;
    return;
  }
  while(cursor){
	  std::cout<<cursor->data<<std::endl;
    cursor=cursor->next;
  }

}
//Display overloaded for Payroll
template<>
void SUList<PayRoll>::display()  const{
  ListNode* cursor=head;
  if(!head){
    std::cout<<"Empty list!"<<std::endl;
    return;
  }
  while(cursor){
    cursor->data.printInfo();
    cursor=cursor->next;
  }

}

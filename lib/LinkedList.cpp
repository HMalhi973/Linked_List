#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&other) : _size(other._size),
                                                   _head(other._head),
                                                   _tail(other._tail)
{
    other._size = 0;
    other._head = nullptr;
    other._tail = nullptr;
}

template <typename T>
size_t LinkedList<T>::size() const { 
    return _size;
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::head() const{
    if(_head != nullptr){
        return _head; 
    }
    else{
        return nullptr;
    }
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::tail() const {
    if(_tail != nullptr){
        return _tail; 
    }
    else{
        return nullptr;
    }
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::prepend(T value){
   
   //This line creates a new dynamically allocated pointer and uses the constructor to set the value and have its
   ////next node  point to the head.
   LinkedListNode<T> * prependNode = new LinkedListNode<T>(value, _head);
   //Head is now pointing to the second node, so point it to the new node
   _head = prependNode;
   //Check for case where LinkedList had no nodes and tie tail to the first node as well. 
   if(!_size){
    _tail = prependNode;
   }
    //Increment size and return the Node you prepended
    _size++;
    return prependNode;
}

template <typename T>
LinkedListNode<T> * LinkedList<T>::append(T value){
   //This line creates a new dynamically allocated pointer and uses the constructor to set the value and have its
   ////next node  point to nullptr
   LinkedListNode<T> * appendNode = new LinkedListNode<T>(value, nullptr);
    //Check for case where LinkedList had no nodes and tie head and tail to the appended node as well. 
   if(!_size){
    _head = appendNode;
    _tail = appendNode;
   }
   else{
    //Tail is now pointing to the second to last node, so point the second to last node to the new node
   (*_tail)._next = appendNode;
    //Tail is now pointing to the second to last node, so point it to the new node
    _tail = appendNode;

   }
    //Increment size and return the Node you prepended
    _size++;
    return appendNode;
}

template <typename T>
LinkedListNode<T> * LinkedList<T>::find(T value) const {
    
    //Check if list is empty, if so, just return null.
    if(_size == 0){
        return nullptr;
    }

    LinkedListNode<T> * currentNode = _head; //saves the head ptr to be used in the while loop to iterate list.

    //iterate through the list until value is reached or the last node points to nullptr
    while( currentNode != nullptr  ){
        
        if((*currentNode).value == value){
            return currentNode;
        }
        else{
            //this line makes the current node turn into the _next ptr of the Node it was pointing to.
            currentNode = (*currentNode)._next; 
        }
    }

    return nullptr; //return null if value is not on the list.
}

template <typename T>
LinkedListNode<T> *LinkedList<T>::insertAfter(LinkedListNode<T> *node, T value){
    
    //Save the pointer in a temporary variable
    LinkedListNode<T> * prevNode = node;
    //Create a pointer to the new node being inserted that obtains value and has _next point to nullptr
    LinkedListNode<T> * insertNode = new LinkedListNode<T>(value, nullptr);

    //Check for case if there are no nodes or node is nullptr and just insert at the begining using the method prepend()
    if(node == nullptr || _head == nullptr){
        //deallocate dynamically allocated insertNode because we will not use it.
        delete insertNode; 
        return LinkedList<T>::prepend(value);  //call prepend method without creating instance of class
        //append method will handle when the list is empty
    }
    else{
        //insertNode's _next will now point at the same node prevNode pointed to
        (*insertNode)._next = (*prevNode)._next;
        //prevNode's _next will now point to insertNode
        (*prevNode)._next = insertNode;
        //set the value on insertNode
        (*insertNode).value = value;
    }

    //Increment size and return the inserted Node
    _size++; 
    return insertNode;  

}

template <typename T>
std::optional<T>  LinkedList<T>::removeHead(){
    
    //handle case in which list is empty
    if(_head == nullptr){
        return std::nullopt;
    }
    else { 
        //save value of the the first Node
        T removedValue = (*_head).value;
        //save pointer to first node in a variable other than _head
        LinkedListNode<T> * tempPtr = _head;
        //have head point to the second node through the first node's _next ptr;
        _head = (*_head)._next;
        //delete first node and decrement size
        delete tempPtr;
        _size--;
        //check if list is empty, set tail to nullptr if so 
        if (_size == 0) {
            _tail = nullptr;
        }
        //return value
        return removedValue;
    }
}

template <typename T>
bool LinkedList<T>::remove(T value){

    //Check if list is empty, if so, just return false
    if(_size == 0){
        return false;
    }

    LinkedListNode<T> * currentNode = _head; //saves the head ptr to be used in the while loop to iterate list.
    LinkedListNode<T> * prevNode = nullptr;  // this will keep track of the _next ptr from the node that points 
    ///the node being accesed. 

    //iterate through the list until value is reached or the last node becomes nullptr
    while(currentNode != nullptr ){
        
        //this case checks for whether the value is in the first node
        if(prevNode == nullptr && (*currentNode).value == value){
            //rewire head to point to the second node
            _head = (*currentNode)._next;
            //deallocate the first node and return true
            delete currentNode;
            _size--;
            //check for single node case to rewire head and tail
            if(_size == 0){
                _head = nullptr;
                _tail = nullptr;
            }
            return true;

        }
        else if(prevNode != nullptr && (*currentNode).value == value && (_tail != currentNode)){ 
            //this case checks for whether value is a node after first excluding the last node
            //rewire the prevNode's next to point to the same address next of deleted node is pointing to
            (*prevNode)._next = (*currentNode)._next;
            //deallocate currentNode and return true
            delete currentNode;
            _size--;
            return true;
        }
        else if(prevNode != nullptr && (*currentNode).value == value && (_tail == currentNode)){
            //this is similar to the case above, the only difference is that it checks if the node to be removed
            ////is the last node so we can handle rewiring the tail.
            (*prevNode)._next = (*currentNode)._next;
            //set tail to prevNode
            _tail = prevNode;
            //deallocate currentNode and return true
            delete currentNode;
            _size--;
            return true;
        }
        else{
            //have prevNode be the currentNode
            prevNode = currentNode;
            //this line makes the current node turn into the _next ptr of the Node it was pointing to.
            currentNode = (*currentNode)._next; 
        }
    }

    return false; //return null if value is not on the list.
}

template <typename T>
void LinkedList<T>::clear(){
    //handle case where list is empty
    if(_size == 0){
        return;
    }

    LinkedListNode<T> * currentNode = _head; //saves the head ptr to be used in the while loop to iterate list.
    

    //iterate through list
    while(  (currentNode != nullptr) ){

        LinkedListNode<T> * tempNode = currentNode; //pass the adress of currentNode to tempNode
        //this line makes the current node turn into the _next ptr of the Node it was pointing to,
        ////effectively iterating to the next node.
        currentNode = (*currentNode)._next;   
        //delete tempNode which is now the node before currentNode
        delete tempNode;
        _size--;   
    }

    //set head and tail to nullptr
    _head = nullptr;
    _tail = nullptr;

}

template <typename T>
 LinkedList<T>::LinkedList(const std::vector<T> &items){
    
    //set everything to default values
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
    
    //iterate through vector and use the append() method to append each value
    for (int i = 0; i < items.size(); i++) {
        T value = items[i];
        LinkedList<T>::append(value);

    }
}


template <typename T>
LinkedList<T>::~LinkedList() {
    LinkedList<T>::clear();
}


// TODO: Implement all other methods defined in LinkedList.hpp here

#endif

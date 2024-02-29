#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.hpp"

template <typename T>
Stack<T>::Stack() {}

template <typename T>
size_t Stack<T>::size() const{
    //calls the size() method from linkedList which returns the number of nodes.
    return _llist.size();
}

template <typename T>
void Stack<T>::push(T value){
    _llist.prepend(value);
}

template <typename T>
std::optional<T> Stack<T>::pop(){
   
   return _llist.removeHead();

}

template <typename T>
std::optional<T> Stack<T>::top() const{
    
    if(_llist.head() == nullptr){
        return std::nullopt;
    }
    else{
        return (*_llist.head()).value;
    }
}

template <typename T>
Stack<T>::Stack(const std::vector<T> &items){

//itirates through loop and prepends each value since the top of the stack is the head of the list
     for (int i = 0; i < items.size(); i++) {
        T value = items[i];
        _llist.prepend(value);

    }
}


// TODO: Implement all other methods defined in Stack.hpp here

#endif

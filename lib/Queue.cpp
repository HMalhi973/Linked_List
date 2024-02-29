#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.hpp"

template <typename T>
Queue<T>::Queue(LinkedList<T> &&llist) : _llist(std::move(llist)) {}

template <typename T>
Queue<T>::Queue() : Queue(LinkedList<T>()) {}

template <typename T>
Queue<T>::Queue(const std::vector<T> &items){
    //iterates through vector and uses prepend() to place queue elements in reverse order,
    // we will dequeue from the head and enqueue from tail which is why the reverse order matters
     for (int i = 0; i < items.size(); i++) {
        T value = items[i];
        _llist.prepend(value);

    }

}

template <typename T>
size_t Queue<T>::size() const{
    //calls the size() method from linkedList which returns the number of nodes.
    return _llist.size();
}

template <typename T>
void Queue<T>::enqueue(T value){
    //enqueue elements from the tail of the list by calling the function append()
    _llist.append(value);
}

template <typename T>
std::optional<T> Queue<T>::dequeue(){
    if(_llist.head() == nullptr){
        return std::nullopt;
    }
    else{
        return _llist.removeHead();
    }
}
// TODO: Implement all other methods defined in Queue.hpp here

#endif

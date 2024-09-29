# Linked List Implementation and Stack and Queue APIs

This project implments a singly linked linked list in C++ which is then in turn used to implement both Queue and Stack APIs. The learning objective of this work is to showcase how simple yet powerful data structures can be abstracted and built upon each other to create more complex structures. This prject was completed for ECS 36C at UC Davis

## Linked List Implementation Details

The `LinkedList` class is a template class that can be instantiated to form a singly linked list which manages a collection of `LinkedListNode` objects. Each one of these objects contains a variable that holds the value of the node and a pointer to another LinkedListNode object. LinkedList class allows for a decent amount of functionality with the following methods:

- Insertion:
  - `prepend` inserts a new node at the beggining of the list.
  - `append` inserts a new node at the end of the list.
  - `insertAfter` inserts the new node after the specified node passed in as an argument.
- Deletion:
  - `removeHead` removes the head node of the list.
  - `remove` removes the first node encountered with the value .specified
  - `clear` removes all nodes from the list.
- Other functions:
  - `find` searches for a node containing the specified value.
  - `size`, `head`, `tail` are getters that return number of nodes, which is the head node, and which is the tail node.
  - There also exists a move constructor, copy constructor, and a     constructor that takes in a vector.

## Stack Implementation Details
The `Stack` class is a blueprint for creating LIFO(Last In First Out) data structure leveraging `LinkedList` to carry out its function. Its key methods are the following:
- `push` adds an item to the top of the stack.
- `pop` removes and returns the item that was at the top of the stack.
- `top` does the same as pop but doesn't remove the element.
- `size` is a getter method that returns number of elements.
- There also exists a constructor that will take a vector and place elements sequentially until the last element sits at the top.

## Queue Implementation Details
The `Queue` class leverages `LinkedList` class as well but it provides a FIFO (First In First Out Data Structure). It has useful capabilities such as the following methods:
- `enqueue` adds an item to the end of the queue.
- `dequeue` removes the item at the front of the queue.
- `size` is a getter method that returns number of elements in queue.
- A contructor that takes in a vector also exists as well as a move constructor.

## Building and Running the Project

- Run the following commands to build

  ```bash
  cd ./Linked_List
  mkdir build
  cd build
  cmake ..
  ```

- Run the following to run test cases and verify functionality

```bash
cd build
make
./run_tests
```

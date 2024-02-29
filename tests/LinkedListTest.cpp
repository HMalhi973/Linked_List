#include <gtest/gtest.h>
#include "LinkedList.cpp"

TEST(LinkedListTest, InstantiateEmptyList)
{
    LinkedList<int> llist;

    ASSERT_EQ(llist.head(), nullptr);
    ASSERT_EQ(llist.tail(), nullptr);
    ASSERT_EQ(llist.size(), 0);
}

TEST(LinkedListTest, InstantiateFromVector)
{
    LinkedList<int> llist(std::vector<int>{17, 19, 23});

    ASSERT_EQ(llist.size(), 3);

    LinkedListNode<int> *node = llist.head();
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next()->value, 19);
    ASSERT_EQ(node->next()->next()->value, 23);
    ASSERT_EQ(node->next()->next()->next(), nullptr);
}

TEST(LinkedListTest, AppendToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.append(17);

    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());
    ASSERT_EQ(node->value, 17);
    ASSERT_EQ(node->next(), nullptr);
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, AppendToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *first = llist.append(17);
    LinkedListNode<int> *second = llist.append(19);

    ASSERT_EQ(first, llist.head());
    ASSERT_EQ(first->value, 17);
    ASSERT_EQ(first->next(), second);

    ASSERT_EQ(second, llist.tail());
    ASSERT_EQ(second->value, 19);
    ASSERT_EQ(second->next(), nullptr);

    ASSERT_EQ(llist.size(), 2);
}

// TODO: Add more tests for LinkedList here

TEST(LinkedListTest, PrependToEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node = llist.prepend(29);

    //Check if node and tail both point to the only node in the list
    ASSERT_EQ(node, llist.head());
    ASSERT_EQ(node, llist.tail());

    //Check if node's value is 29 and check if its next pointer points to nullptr
    ASSERT_EQ(node->value, 29);
    ASSERT_EQ(node->next(), nullptr);

    // Verify size to be 1
    ASSERT_EQ(llist.size(), 1);
}

TEST(LinkedListTest, PrependToNonEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *prevHead = llist.prepend(21);
    LinkedListNode<int> *node = llist.prepend(11);

    //New node is now the new head
    ASSERT_EQ(node, llist.head());

    //New node's value should be 11 and it hould point to prevHead
    ASSERT_EQ(node->value, 11);
    ASSERT_EQ(node->next(), prevHead);

    //prevHead must now be the last in the list
    ASSERT_EQ(prevHead, llist.tail());
    ASSERT_EQ(prevHead->value, 21);
    //prevhead's next ptr must point to nullptr
    ASSERT_EQ(prevHead->next(), nullptr);

    //Verify size to be 2
    ASSERT_EQ(llist.size(), 2);

}

TEST(LinkedListTest, PrependManytoEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *node1 = llist.prepend(27);
    LinkedListNode<int> *node2 = llist.prepend(91);
    LinkedListNode<int> *node3 = llist.prepend(32);
    LinkedListNode<int> *node4 = llist.prepend(11);

    //last prepended node must have head point to it
    ASSERT_EQ(node4, llist.head());

    //Verify the values of nodes and that their next pointers point to the correct nodes
    ASSERT_EQ(node4->value, 11);
    ASSERT_EQ(node4->next(), node3);
    ASSERT_EQ(node3->value, 32);
    ASSERT_EQ(node3->next(), node2);
    ASSERT_EQ(node2->value, 91);
    ASSERT_EQ(node2->next(), node1);
    ASSERT_EQ(node1->value, 27);
    ASSERT_EQ(node1->next(), nullptr);

    //tail must point to the first prepended node
    ASSERT_EQ(node1, llist.tail());

    //Verify size to be 4
    ASSERT_EQ(llist.size(), 4);
}

TEST(LinkedListTest, FindValueInEmptyList)
{
    LinkedList<int> llist;
    LinkedListNode<int> *findNode = llist.find(89);

    //verify that the method returns nullptr 
    ASSERT_EQ(findNode, nullptr);
}


TEST(LinkedListTest, FindExistingValue)

{
    //create a list and place some nodes with various values in it
    LinkedList<int> llist;
    llist.append(67);
    llist.append(82);
    llist.append(38);

    LinkedListNode<int> *findNode = llist.find(82);

    //Verify that findNode is not a nullptr and that its value is that passed into the method
    ASSERT_NE(findNode, nullptr);
    ASSERT_EQ(findNode->value, 82);

    //Ensure that findNode's next is the next node in the list
    ASSERT_EQ(findNode->next()->value, 38);
    }


TEST(LinkedListTest, FindNonExistingValue) {
    LinkedList<int> llist;
    llist.append(49);
    llist.append(74);

    LinkedListNode<int> *findNode = llist.find(1);

    // 1 does not exist in the list, so findNode should be nullptr
    ASSERT_EQ(findNode, nullptr);
}

TEST(LinkedListTest, FindValueAtEnd) {
    LinkedList<int> llist;
    llist.append(15);
    llist.append(13);
    llist.append(10);
    llist.append(80);

    LinkedListNode<int> *findNode = llist.find(80);

    // The value 80 exists at the end of the list, so foundNode should point to it
    ASSERT_NE(findNode, nullptr);
    ASSERT_EQ(findNode->value, 80);

    // Ensure that foundNode's next is nullptr since it's the last node
    ASSERT_EQ(findNode->next(), nullptr);
}


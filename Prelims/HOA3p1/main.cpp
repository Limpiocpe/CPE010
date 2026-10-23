#include <iostream>
#include "singly_ll.h"
#include "doubly_ll.h"

int main(){
// Create a list 'C P E'
    DoubleList<char>* head = CreateNewNode('C');
    DoubleList<char>* second = CreateNewNode('P');
    DoubleList<char>* third = CreateNewNode('E');

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    // Traversal
    std::cout << "Testing the DLL Traversal" << std::endl;
    dllTraverse(head);

    // Testing the insert at the head
    std::cout << "Testing the insertion at the head node" << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    // Testing the insert at the end
    std::cout << "Testing the insert at the end" << std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    // Testing the general insert
    std::cout << "Testing the general insert" << std::endl;
    dllGeneralInsert('1', head);
    dllTraverse(head);

    // Testing the delete node
    std::cout << "Testing the delete node" << std::endl;
    dllDeleteNode('C', &head);
    dllTraverse(head);
    return 0;
}
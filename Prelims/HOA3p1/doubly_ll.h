#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* prev = nullptr;
        DoubleList<T>* next = nullptr;

};

// Creating a node:
template <typename T>
DoubleList<T> *CreateNewNode(T newData){
    // Dynamically allocate a new memory for the node
    DoubleList<T> *newNode = new DoubleList<T>;

    // Store the data in the node
    newNode->data = newData;

    // Point next and prev to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    // Return the address of the newly created node
    return newNode;
}

template <typename T>
void dllTraverse(DoubleList<T>* currentNode){
    // Temp variable to store the last node visited
    DoubleList<T> *tail;

    // Check if the list is empty
    if(currentNode == nullptr){
        std::cout << "The list is empty." << std::endl;
        return;
    }
    std::cout << "Forward: \n";

    // Move forward
    while(currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }

    // Add a next line
    std::cout << std::endl;
    
    std::cout << "Backwards: \n";
    // Move backwards
    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << "\n";
}

// Inserting at the head of the list
template <typename T>
void dllInsertHead(T newData, DoubleList<T> ** currentHead){
    // Creating a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // New node should point to the current head
    newNode->next = *currentHead;

    // Current head should point back to the newNode
    (*currentHead)->prev = newNode;

    // Update the pointer head
    *currentHead = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currentHead){
    // Create a new node
    DoubleList<T>* newNode = CreateNewNode(newData);

    // Traverse until we reach the last node 
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    // Connect the last node to the new node
    currentHead->next = newNode;

    // Connect the new node back to the last node
    newNode->prev = currentHead;
}

// General Insert
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* currentNode){
    //1. Check if it is the head node (previous node is null)
    if(currentNode == nullptr){
        std::cout << "Previous value cannot be null" << std::endl;
        return;
    }

    DoubleList<T>* newNode = CreateNewNode(newData);

    newNode->next = currentNode->next;
    
    newNode->prev = currentNode;
    currentNode->next = newNode;
    currentNode->next = newNode;
}

template <typename T>
void dllDeleteNode(T findData, DoubleList<T>** head){
    // If there is nothing to be deleted
    if(*head == nullptr){return;}

    DoubleList<T>* currentNode = *head;
    DoubleList<T>* prevNode = nullptr;

    // Searching the node
    while(currentNode != nullptr && currentNode->data != findData){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if(currentNode == nullptr) {
        std::cout << "The data is not found \n" << std::endl;
        return;
    }

    // If data is found
    if(prevNode == nullptr){
        *head = currentNode->next;
        if(*head != nullptr)
            (*head)->prev = nullptr;
    } else{
        prevNode->next = currentNode->next;
        if(currentNode->next != nullptr)
            currentNode->next->prev = prevNode;
    }
    delete currentNode;
}
#endif
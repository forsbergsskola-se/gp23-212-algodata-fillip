#pragma once
#include <stdexcept> // For std::out_of_range exception

// Define a class for TurboLinkedList
template<typename T>
class TurboLinkedList {
    // Define a node structure for the linked list
    struct Node {
        T data;        // Data of the node
        Node* next;    // Pointer to the next node

        // Constructor to initialize the node with data
        Node(const T& newData) : data(newData), next(nullptr) {}
    };


public:


    Node* head; // Pointer to the first node in the linked list

    // Constructor to initialize the linked list
    TurboLinkedList() : head(nullptr) {}

    // Destructor to deallocate memory when the object is destroyed
    ~TurboLinkedList() {
        clear();
    }

    // Method to add a new node to the end of the linked list
    void Add(const T& newData) {
        Node* newNode = new Node(newData);  // Create a new node with the provided data
        if (head == nullptr) {
            head = newNode;  // If the list is empty, set the new node as the head
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Traverse the list to find the last node
            }
            temp->next = newNode;  // Connect the new node to the last node
        }
    }

    // Method to skip a specified number of nodes
    void Skip(int count) {
        if (head == nullptr || count <= 0) {
            // List is empty or skip count is non-positive, do nothing
            return;
        }

        Node* current = head;
        for (int i = 0; i < count && current != nullptr; ++i) {
            current = current->next;  // Traverse the list to the specified position
        }

        // Update the head pointer to the new current position
        head = current;
    }

    // Method to get the item at the specified index
    T Get(int index) const {
        int currentIndex = 0;
        Node* current = head;
        while (current != nullptr) {
            if (currentIndex == index) {
                return current->data;
            }
            current = current->next;
            ++currentIndex;
        }
        throw std::out_of_range("Index out of range");
    }

    // Method to set the item at the specified index
    void Set(int index, const T& value) {
        int currentIndex = 0;
        Node* current = head;
        while (current != nullptr) {
            if (currentIndex == index) {
                current->data = value;
                return;
            }
            current = current->next;
            ++currentIndex;
        }
        throw std::out_of_range("Index out of range");
    }

    // Method to remove all items from the list
    void Clear() {
        clear();
    }

    // Method to remove one item from the list at the specified index
    void RemoveAt(int index) {
        if (head == nullptr)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* current = head;
            for (int i = 0; i < index - 1 && current->next != nullptr; ++i) {
                current = current->next;
            }
            if (current->next == nullptr)
                return; // Invalid position
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Method to get the current amount of items contained in the list
    int Count() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Helper method to clear the linked list
    void clear() {
        while (head != nullptr) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }
};

#pragma once
#include <list>
using namespace std;


class SortedTemplateList
{


public:

    list<int> intList = { 1,5,7,3 };

    void Sort()
    {
        for (int i = 0; i < intList.size() - 2; i++)
        {
            int min = i;

            for (int j = 0; i < intList.size() - 1; i++)
            {
                if (j < min)
                {
                    min = j;
                }
            }


            //TODO ADD SWAP
            if (min != i)
            {
                auto it = intList.begin();
                std::advance(it, i);

                *it = min;

            }

        }
    }
};

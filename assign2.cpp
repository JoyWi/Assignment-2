using namespace std;

/**
 * Name: Joy Wilson
 * Course: Programming Language
 * Assignment Details: Implememt a linked list with the following functions
 * using dynamic memory allocation.
*/

#include <iostream>

using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // Insert a new node at the beginning of the list
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end of the list
    void insertAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Insert a new node at a specific index
    void insertAtIndex(int value, int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 0) {
            insert(value);
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;

        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Invalid index." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Delete a node with the specified value
    void remove(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Value not found in the list." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Update the value of a node at a specific index
    void update(int value, int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Invalid index." << endl;
            return;
        }

        current->data = value;
    }

    // Get the value at a specific index
    int get(int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return -1;
        }

        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Invalid index." << endl;
            return -1;
        }

        return current->data;
    }

    // Print the linked list
    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.insertAtTail(20);
    list.insertAtIndex(25, 2);

    cout << "Linked list: ";
    list.print(); // Output: 15 10 25 5 20

    list.update(30, 1);
    cout << "Updated list: ";
    list.print(); // Output: 15 30 25 5 20

    list.remove(10);
    cout << "List after deletion: ";
    list.print(); // Output: 15 30 25 5 20

    int value = list.get(2);
    cout << "Value at index 2: " << value << endl; // Output: Value at index 2: 25

    return 0;
}
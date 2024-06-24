#include <iostream>
#include <cstdlib>  // for system() function

using namespace std;

// Define the Node structure for the queue
struct Node {
    int data;   // Data held by the node (customer number)
    Node* next; // Pointer to the next node in the queue
};

// Define the Queue class
class Queue {
public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to add a customer to the queue
    void enqueue(int value) {
        Node* temp = new Node(); 
        temp->data = value;      
        temp->next = nullptr;    
        if (rear == nullptr) {   
            front = rear = temp; 
        } else {                 
            rear->next = temp;   
            rear = temp;         
        }
        cout << "Customer " << value << " added to the queue.\n";
    }

    // Function to serve (remove) the customer at the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No customer to serve.\n";
            return;
        }
        Node* temp = front;          
        cout << "Serving customer " << front->data << "\n"; 
        front = front->next;         
        if (front == nullptr) {      
            rear = nullptr;          
        }
        delete temp;                 
    }

    // Function to check if the queue is empty
    bool isEmpty() const {
        return front == nullptr; 
    }

    // Function to view the next customer to be served without removing them
    void peek() const {
        if (isEmpty()) { 
            cout << "Queue is empty.\n";
        } else {       
            cout << "Next customer to be served: " << front->data << ".\n";
        }
    }

    // Function to display all customers in the queue
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front; 
        cout << "Customers in the queue: ";
        while (temp != nullptr) { 
            cout << temp->data << " ";
            temp = temp->next;   
        }
        cout << "\n";
    }

private:
    Node* front; // Pointer to the front node of the queue
    Node* rear;  // Pointer to the rear node of the queue
};

int main() {
    Queue q; // Create a Queue object
    int choice, value;

    do {
        // Clear the screen based on the operating system
        #ifdef _WIN32
            system("CLS");
        #else
            system("clear");
        #endif

        // Display the menu
        cout << "===========MATTY'S PIZZARIA===========";
        cout << "\n1. Add Customer to Queue (enqueue)\n";
        cout << "2. Serve Customer (dequeue)\n";
        cout << "3. View Next Customer (peek)\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) {
            case 1:
                cout << "Enter customer number: ";
                cin >> value;
                q.enqueue(value); // Add customer to the queue
                break;
            case 2:
                q.dequeue(); // Serve the next customer in the queue
                break;
            case 3:
                q.peek(); // View the next customer to be served
                break;
            case 4:
                q.display(); // Display all customers in the queue
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore(); 
            cin.get();    // Wait for user to press Enter
        }
    } while (choice != 5);

    return 0;
}

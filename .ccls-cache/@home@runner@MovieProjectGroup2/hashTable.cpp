#include "hashTable.h"
#include <iostream>
#include <vector>
using namespace std;

// Constructor: Initialize vector with null pointers
hashTable::hashTable() : customerList(TABLE_SIZE, nullptr) {}

// Destructor: Free all nodes
hashTable::~hashTable() {
    for (auto& head : customerList) {
        while (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

// Print all customers in the hash table
void hashTable::print() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        node* current = customerList[i];
        while (current) {
            cout << "Customer ID: " << current->customer->getCustomerID() << endl;
            current = current->next;
        }
    }
}

// Add a customer to the hash table
void hashTable::add(Customer* customer) {
    int index = hash(customer->getCustomerID());
    customerList[index] = new node(customer, customerList[index]);
}

// Remove a customer from the hash table
bool hashTable::remove(Customer* customer) {
    return removeByKey(customer->getCustomerID());
}

// Remove a customer from the hash table by their ID
bool hashTable::removeByKey(int customerID) {
    int index = hash(customerID);
    node* current = customerList[index];
    node* prev = nullptr;

    while (current && current->customer->getCustomerID() != customerID) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return false; // Not found
    }

    if (prev) {
        prev->next = current->next;
    } else {
        customerList[index] = current->next;
    }
    delete current;
    return true;
}

// Get a customer by their ID
Customer* hashTable::getByKey(int customerID) {
    int index = hash(customerID);
    node* current = customerList[index];

    while (current) {
        if (current->customer->getCustomerID() == customerID) {
            return current->customer;
        }
        current = current->next;
    }

    return nullptr;
}

// Hash function: Compute the hash index
int hashTable::hash(int customerID) {
    return customerID % TABLE_SIZE;
}

// Test function (example usage)
void hashTable::test() { 
    cout << "Running hashTable tests" << endl;
}


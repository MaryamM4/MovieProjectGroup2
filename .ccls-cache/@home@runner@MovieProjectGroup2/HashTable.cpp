#include "HashTable.h"
#include "Customer.h"

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Constructor: Initialize vector with null pointers
HashTable::HashTable() : customerList(TABLE_SIZE, nullptr) {}

// Destructor: Free all nodes
HashTable::~HashTable() {
  for (auto &head : customerList) {
    while (head) {
      node *temp = head;
      head = head->next;
      delete temp;
    }
  }
}

// Initialize based off of file. Returns false if file invalid.
bool HashTable::build(const std::string &custFilename) {
  std::fstream infile;
  infile.open(custFilename);

  if (!infile.is_open()) {
    return false;
  }

  int uid;
  std::string fName;
  std::string lName;

  std::string currLine;
  while (std::getline(infile, currLine)) {
    std::istringstream iss(currLine);

    if (!(iss >> uid >> lName >> fName)) {
      std::cout << "Failed to add customer:\n" << currLine << "\n" << std::endl;
      continue; // Skip current line on fail.

    } else {
      Customer *newCustomer = new Customer(uid, fName, lName);
      add(newCustomer);
    }
  }

  return true;
}

// Print all customers in the hash table
void HashTable::print() {
  for (int i = 0; i < TABLE_SIZE; ++i) {
    node *current = customerList[i];
    while (current) {
      cout << "Customer ID: " << current->customer->UID << endl;
      current = current->next;
    }
  }
}

// Add a customer to the hash table
void HashTable::add(Customer *customer) {
  int index = hash(customer->UID);
  customerList[index] = new node(customer, customerList[index]);
}

bool HashTable::contains(Customer *customer) {
  return containsKey(customer->UID);
}

bool HashTable::containsKey(int key) { return (getByKey(key) != nullptr); }

// Remove a customer from the hash table
bool HashTable::remove(Customer *customer) {
  return removeByKey(customer->UID);
}

// Remove a customer from the hash table by their ID
bool HashTable::removeByKey(int customerID) {
  int index = hash(customerID);
  node *current = customerList[index];
  node *prev = nullptr;

  while (current && current->customer->UID != customerID) {
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
Customer *HashTable::getByKey(int customerID) {
  int index = hash(customerID);
  node *current = customerList[index];

  while (current) {
    if (current->customer->UID == customerID) {
      return current->customer;
    }
    current = current->next;
  }

  return nullptr;
}

// Hash function: Compute the hash index
int HashTable::hash(int customerID) { return customerID % TABLE_SIZE; }

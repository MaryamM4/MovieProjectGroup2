#ifndef HashTable_H
#define HashTable_H

#include "Customer.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct node {
  Customer *customer;
  node *next = nullptr;

  node(Customer *customer, node *next = nullptr)
      : customer(customer), next(next) {}
  ~node() { delete customer; }
};

// store as array; index
class HashTable {
public:
  static const int TABLE_SIZE = 100; // Example size, can be adjusted

  HashTable();
  ~HashTable();

  void print();
  bool build(const std::string &custFilename);

  void add(Customer *customer);
  bool remove(Customer *customer);
  bool removeByKey(int customerID);
  Customer *getByKey(int customerID);

  bool contains(Customer *customer);
  bool containsKey(int key);

private:
  std::vector<node *> customerList;

  // Takes key, returns the index where the customer is stored.
  int hash(int customerID);
};

#endif // HashTable_H

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
//#include "Movie.h"
using namespace std;
#include <fstream> 
#include <sstream>
#include <string>
#include "Movie.h"
#include "Customer.h"
#include <vector> 

const int TABLE_SIZE = 10; //example size adjust as necessary 

struct node{
    Customer* customer;  
    node* next; 
    node(Customer* customer, node* next = nullptr) : customer(customer), next(next) {}
    ~node() { delete customer; }
};
//store as array; index
class hashTable {
private:
    vector<node*> customerList; 
    static const int TABLE_SIZE = 100; // Example size, can be adjusted
    public: 
    hashTable(); 
    ~hashTable();
    void print();
    void build(string custFilename); //Maryam 
    void add(Customer* customer); // second
    bool remove(Customer* customer); //second 
    bool removeByKey(int customerID);
    Customer* getByKey(int customerID); //second 
    int hash(int customerID); //returns the index where the customer is stored first  
    void test(); //to be deleted when we submit assignment 
};
#endif


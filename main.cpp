/**
 * Driver for starting movie store tests
 */

#include "Store.h"

#include <iostream>
// forward declaration, implementation in store_test.cpp
void testAll() {
  Store store;

  std::string customerFilename = "data4customers.txt";
  std::string movieFilename = "data4movies.txt";
  std::string commandsFilename = "data4commands.txt";

  store.buildFromFiles(customerFilename, movieFilename, commandsFilename);
}

int main() {
  testAll();
  std::cout << "Done." << std::endl;
  return 0;
}

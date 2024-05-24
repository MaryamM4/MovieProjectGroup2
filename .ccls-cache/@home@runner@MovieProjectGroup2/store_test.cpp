
#include "Store.h"

#include <iostream>

void testAll() {
  Store store;

  std::string customerFilename = "data4customers.txt";
  std::string movieFilename = "data4movies.txt";
  std::string commandsFilename = "data4commands.txt";

  store.buildFromFiles(customerFilename, movieFilename, commandsFilename);
}
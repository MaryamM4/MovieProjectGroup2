#ifndef STORE_H
#define STORE_H

#include "hashTable.h"
#include "movie.h"

#include <fstream>

class Store {
public:
  ~Store();
  bool buildFromFiles(const std::string &customerFilename,
                      const std::string &movieFilename,
                      const std::string &commandsFilename);

  // Helper functions for buildFromFiles. Returns false if input is invalid.
  bool executeCommand(const std::string &command);

  // Command-related function(s):
  void printInventory();

  void displayCustomerHistory(Customer *customer);
  bool borrowMovie(Customer *customer, Movie *movie);
  bool returnMovie(Customer *customer, Movie *movie);

  // Helper/ Misc. fucntions:
  bool contains(Movie *movie);
  bool contains(Customer *customer);

private:
  HashTable customers;
  std::vector<Movie *> movies;

  Movie *returnEquivelent(Movie *movieToFind);
  Movie *returnEquivelent(std::string movieInfo);
};

#endif
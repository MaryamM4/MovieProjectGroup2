#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// This struct is used for history and for borrwing.
typedef struct borrowedMovie {
  borrowedMovie(Movie *movie) : movie(movie){};

  Movie *movie = nullptr;
  bool isBorrowing = true;
} borrowedMovie;

class Customer {
public:
  static const bool PRINT_ID = true; // For testing,

  ~Customer();

  // These variables never change after initialization.
  const int UID;
  const std::string firstName;
  const std::string lastName;

  // Constructor
  Customer(int id, std::string fName, std::string lName)
      : UID(id), firstName(fName), lastName(lName){};

  // Helper method,
  bool isBorrowing(Movie *movie);

  // Operator methods
  bool borrowMovie(Movie *movie);
  bool returnMovie(Movie *movie);

  // Factory methods
  static std::vector<Customer *> getCustomers(std::ifstream file);

  // Display methods
  void displayHistory();
  friend std::ostream &operator<<(std::ostream &os, const Customer &customer);

private:
  std::vector<borrowedMovie *>
      history; // Stores all movies currently/prev. borrowed.

  // Helper method
  borrowedMovie *getBorrow(Movie *movie); // returns nullptr if DNE.
};

#endif // CUSTOMER_H
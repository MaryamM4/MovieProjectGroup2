#include "customer.h"

#include <iostream>
#include <set>
#include <sstream>
#include <vector>

// Deconstructor. Clears history (borrowedMovie pointers).
Customer::~Customer() {
  for (borrowedMovie *CustMovie : history) {
    delete CustMovie;
  }
  history.clear();
}

// Returns true if the customer is borrowing the movie.
bool Customer::isBorrowing(Movie *movie) {
  for (borrowedMovie *bMovie : history) {
    if (Movie::equal(movie, bMovie->movie)) {
      return true;
    }
  }
  return false;
}

// Borrows the movie. Returns true if succesful.
bool Customer::borrowMovie(Movie *movie) {
  // Don't create duplicate snapshots
  borrowedMovie *bMovie = getBorrow(movie);
  if (bMovie != nullptr) {
    if (bMovie->isBorrowing == true) {
      std::cout << "Customer is already borrowing the Movie." << std::endl;
      return false;

    } else {
      bMovie->isBorrowing = true;
      return true;
    }
  }

  // If snapshot DNE, then create one
  borrowedMovie *newBorrow = new borrowedMovie(movie);
  history.push_back(newBorrow);

  return true;
}

// Borrows movie. Returns false if unsuccesful or already returned, true
// otherwise.
bool Customer::returnMovie(Movie *movie) {
  borrowedMovie *bMovie = getBorrow(movie);

  if (bMovie != nullptr) {
    if (bMovie->isBorrowing == true) {
      bMovie->isBorrowing = false;
      return true;

    } else {
      std::cout << "Customer already returned Movie.\n" << std::endl;
      return false;
    }
  }

  std::cout << "Customer cannot return a never-borrowed movie.\n" << std::endl;
  return false;
}

// Display methods
void Customer::displayHistory() {
  std::cout << "Borrowing History of " << lastName << ", " << firstName << ": ";
  std::cout << "(" << history.size() << " total)\n" << std::endl;

  for (borrowedMovie *bMovie : history) {
    std::string oStr = "(Prev. Borrowed) ";

    if (bMovie->isBorrowing) {
      oStr = "(Cur. Borrowing) ";
    }

    oStr += bMovie->movie->title;
    std::cout << oStr << "\n" << std::endl;
  }

  std::cout << "---------------\n" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
  if (customer.PRINT_ID) {
    os << std::string("[ID: ") << std::to_string(customer.UID)
       << std::string("] ");
  }

  os << customer.firstName << std::string(" ") << customer.lastName;
  return os;
}

// Helper method. Returns nullptr if movie never borrowed.
borrowedMovie *Customer::getBorrow(Movie *movie) {
  for (borrowedMovie *bMovie : history) {
    if (Movie::equal(movie, bMovie->movie)) {
      return bMovie;
    }
  }

  return nullptr;
}

// Factory method
std::vector<Customer *> Customer::getCustomers(std::ifstream infile) {
  std::vector<Customer *> customers;
  std::set<int> addedIDs;

  int UID;
  std::string firstName;
  std::string lastName;

  std::string currLine;
  while (std::getline(infile, currLine)) {
    std::istringstream iss(currLine);

    if (iss >> UID >> lastName >> firstName) {
      // Don't add duplicates
      if (addedIDs.count(UID) > 0) {
        addedIDs.insert(UID);

        Customer *newCustomer = new Customer(UID, firstName, lastName);
        customers.push_back(newCustomer);
      }

    } else { // Skip line on fail
      std::cout << "Failed to add customer:\n" << currLine << "\n" << std::endl;
      continue;
    }
  }

  return customers;
}
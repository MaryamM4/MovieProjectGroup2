#include "Customer.h"

#include <iostream>
#include <set>
#include <sstream>
#include <vector>

bool Customer::isBorrowing(Movie *movie) {
  for (borrowedMovie *bMovie : history) {
    if (movie == bMovie->movie) {
      return true;
    }
  }

  return false;
}

bool Customer::borrowMovie(Movie *movie) {
  for (borrowedMovie *bMovie : history) {
    if (movie == bMovie->movie) {

      if (bMovie->isBorrowing == true) {
        std::cout << "Customer is already borrowing the Movie." << std::endl;
        return false;

      } else {
        bMovie->isBorrowing = true;
        return true;
      }
    }
  }

  return false;
}

bool Customer::returnMovie(Movie *movie) {
  for (borrowedMovie *bMovie : history) {
    if (movie == bMovie->movie) {

      if (bMovie->isBorrowing == true) {
        bMovie->isBorrowing = false;
        return true;

      } else {
        std::cout << "Customer already returned Movie.\n" << std::endl;
        return false;
      }
    }
  }

  return false;
}

// Display methods
void Customer::displayHistory() {
  std::cout << "Borrwing History of " << lastName << ", " << firstName << ":\n"
            << std::endl;

  for (borrowedMovie *bMovie : history) {
    std::string oStr = "";

    if (bMovie->isBorrowing) {
      oStr += "(Currently Borrowing) ";
    }

    oStr += bMovie->movie->str();
    std::cout << oStr << "\n" << std::endl;
  }

  std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Customer &customer) {
  if (customer.PRINT_ID) {
    os << std::string("[ID: ") << std::to_string(customer.UID)
       << std::string("] ");
  }

  os << customer.firstName << std::string(" ") << customer.lastName;
  return os;
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
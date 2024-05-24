#include "Store.h"

bool Store::buildFromFiles(const std::string &customerFilename,
                           const std::string &movieFilename,
                           const std::string &commandsFilename) {

  customers.build(customerFilename);
  movies = Movie::build(movieFilename);

  // Execute commands

  std::fstream commandsFile;
  commandsFile.open(commandsFilename);

  if (!commandsFile.is_open()) {
    std::cout << "Failed to open the commands file.\n" << std::endl;
    return false;
  }

  std::string currCommand;
  while (std::getline(commandsFile, currCommand)) {
    std::cout << "Command: " << currCommand << std::endl; // Delete me
    executeCommand(currCommand);
  }

  return true;
}

// Helper functions for buildFromFiles. Returns false if input is invalid.
bool Store::executeCommand(const std::string &command) {
  std::istringstream iss(command);
  char commandType;

  if (iss >> commandType) {

    if (commandType == 'I') { // Display inventory
      printInventory();
      return true;

    } else {
      int customerID;

      if (iss >> customerID) {
        Customer *customer = customers.getByKey(customerID);

        if (customer == nullptr) {
          std::cout
              << "Cannot display history of non-existent customer. (No UID="
              << customerID << ").\n"
              << std::endl;
          return false;
        }

        if (commandType == 'H') { // Display customer history
          displayCustomerHistory(customer);
          return true;

        } else {
          std::ostringstream oss;
          Movie *movie = returnEquivelent(Movie::createMovie(oss.str()));

          if (movie == nullptr) {
            std::cout << "Cannot borrow/return a movie that DNE in the store.\n"
                      << std::endl;
            return false;
          }

          if (commandType == 'B') { // Borrow
            if (borrowMovie(customer, movie)) {
              return true;
            }
            std::cout << "Failed to borrow movie." << std::endl;

          } else if (commandType == 'R') { // Return
            if (returnMovie(customer, movie)) {
              return true;
            }

            std::cout << "Failed to return movie." << std::endl;
          }
        }
      }
    }
  }

  return false;
}

// =========================
// Command-related functions:
void Store::printInventory() {
  std::cout << "\n=============================\nInventory:\n" << std::endl;

  for (Movie *movie : movies) {
    std::cout << movie->str() << "\n" << std::endl;
  }

  std::cout << "[End of Inventory Display]\n=============================\n"
            << std::endl;
}

void Store::displayCustomerHistory(Customer *customer) {
  customer->displayHistory();
}

bool Store::borrowMovie(Customer *customer, Movie *movie) {

  if (movie->borrowMovie(movie)) {
    return customer->borrowMovie(movie);

  } else {
    std::cout << "Cannot borrow movie, as it is out of stock.\n" << std::endl;
  }

  return false;
}

bool Store::returnMovie(Customer *customer, Movie *movie) {
  if (movie->returnMovie(movie)) {
    return customer->returnMovie(movie);
  }

  std::cout << "Failed to return movie.\n" << std::endl;
  return false;
}

// =======================
// Helper / Misc. functions:

bool Store::contains(Movie *movie) {
  return (returnEquivelent(movie) != nullptr);
}

bool Store::contains(Customer *customer) {
  return customers.contains(customer);
}

Movie *Store::returnEquivelent(Movie *movieToFind) {
  for (Movie *movie : movies) {
    if (Movie::equal(movie, movieToFind)) {
      return movie;
    }
  }

  return nullptr;
}
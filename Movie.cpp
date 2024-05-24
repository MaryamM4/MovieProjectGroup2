// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

// method: build movie list from a file
std::vector<Movie *> Movie::build(const std::string &movieFilename) {
  std::vector<Movie *> movies;
  std::ifstream file(movieFilename);

  if (!file.is_open()) {
    std::cerr << "Error: file cannot be opened " << movieFilename << std::endl;
    return movies;
  }

  std::string line;
  while (std::getline(file, line)) {
    Movie *movie = Movie::createMovie(line);
    if (movie != nullptr) {
      movies.push_back(movie);
    }
  }
  file.close();

  // sort the movie vector as specified in directions
  std::sort(movies.begin(), movies.end(), [](Movie *current, Movie *other) {
    char currentGenre = current->getGenreTag();
    char otherGenre = other->getGenreTag();

    // genre
    if (currentGenre != otherGenre) {
      return currentGenre < otherGenre;
    }
    // comedy
    if (currentGenre == 'F') {
      return dynamic_cast<ComedyMovie *>(current) <
             dynamic_cast<ComedyMovie *>(other);
      // drama
    } else if (currentGenre == 'D') {
      return dynamic_cast<DramaMovie *>(current) <
             dynamic_cast<DramaMovie *>(other);
      // classic
    } else if (currentGenre == 'C') {
      return dynamic_cast<ClassicMovie *>(current) <
             dynamic_cast<ClassicMovie *>(other);
    }
    // alternative
    return false;
  });

  return movies;
}

// method: create a Movie object from a file line
Movie *Movie::createMovie(const std::string &fileLine) {
  std::istringstream ss(fileLine);
  char genre;
  ss >> genre;
  ss.ignore(1, ',');

  int stock;
  std::string director, title;
  int year;

  if (genre == 'F') { // Comedy tag
    ss >> stock;
    ss.ignore(1, ',');
    std::getline(ss, director, ',');
    std::getline(ss, title, ',');
    ss >> year;
    return new ComedyMovie(stock, director, title, year);

  } else if (genre == 'D') { // Drama tag
    ss >> stock;
    ss.ignore(1, ',');
    std::getline(ss, director, ',');
    std::getline(ss, title, ',');
    ss >> year;
    return new DramaMovie(stock, director, title, year);

  } else if (genre == 'C') { // Classic tag
    ss >> stock;
    ss.ignore(1, ',');
    std::getline(ss, director, ',');
    std::getline(ss, title, ',');
    std::string actor;
    int month;
    ss >> actor >> month >> year;
    return new ClassicMovie(stock, director, title, month, year, actor);

  } else { // Invalid tag
    std::cerr << "Error: Invalid movie genre code '" << genre << "'."
              << std::endl;
    return nullptr;
  }
}

// get available stock of the movie
int Movie::getStock() const { return availableStock; }

// borrow (reduce stock by 1)
bool Movie::borrowMovie(Movie *movie) {
  if (availableStock > 0) {
    availableStock--;
    return true;
  }
  return false;
}

// return (increase stock by 1)
bool Movie::returnMovie(Movie *movie) {
  availableStock++;
  return true;
}

// Greater priority -> greater weight.
// Comedy 'F' > Drama 'D' > Classic 'C' > Invalid.
int Movie::getGenrePriority(char genre) {
  switch (genre) {
  case 'C':
    return 1;
  case 'D':
    return 2;
  case 'F':
    return 3;
  }

  return 0; // For invalid.
}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {
  os << movie.str();
  return os;
}

std::string Movie::str() const {
  std::string genre(1, getGenreTag());
  std::string fullStr =
      genre + ", " + title + ", " + director +
      ".\nAvailable stock: " + std::to_string(availableStock) + ".";

  return fullStr;
}

bool Movie::equal(Movie *lMovie, Movie *rMovie) {
  CompareMoviePtrs cmp;

  if (cmp(lMovie, rMovie) || cmp(rMovie, lMovie)) {
    return false;
  }

  return true;
}
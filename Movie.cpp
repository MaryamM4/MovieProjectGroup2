// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "Movie.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

struct CompareMoviePtrs {
  bool operator()(Movie *lhs, Movie *rhs) const {
    // First compare by genre
    int genreComparison = lhs->getGenrePriority(rhs->getGenreTag()) -
                          lhs->getGenrePriority(lhs->getGenreTag());

    if (genreComparison < 0) {
      return true;
    } else if (genreComparison > 0) {

      return false;
    }

    if (lhs->getGenreTag() == 'F') {
      ComedyMovie *left = dynamic_cast<ComedyMovie *>(lhs);
      ComedyMovie *right = dynamic_cast<ComedyMovie *>(rhs);
      return (*left < *right);

    } else if (lhs->getGenreTag() == 'D') {

      DramaMovie *left = dynamic_cast<DramaMovie *>(lhs);
      DramaMovie *right = dynamic_cast<DramaMovie *>(rhs);
      return (*left < *right);

    } else {
      ClassicMovie *left = dynamic_cast<ClassicMovie *>(lhs);
      ClassicMovie *right = dynamic_cast<ClassicMovie *>(rhs);
      return (*left < *right);
    }
  }
};

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

  CompareMoviePtrs cmp;
  std::sort(movies.begin(), movies.end(), cmp);

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
    if (ss >> stock) {
      ss.ignore(1, ',');
      std::getline(ss, director, ',');
      std::getline(ss, title, ',');

      if (ss >> year) {
        return new ComedyMovie(stock, director, title, year);
      }
    }

  } else if (genre == 'D') { // Drama tag
    if (ss >> stock) {
      ss.ignore(1, ',');
      std::getline(ss, director, ',');
      std::getline(ss, title, ',');

      if (ss >> year) {
        return new DramaMovie(stock, director, title, year);
      }
    }

  } else if (genre == 'C') { // Classic tag
    if (ss >> stock) {
      ss.ignore(1, ',');
      std::getline(ss, director, ',');
      std::getline(ss, title, ',');

      std::string actorF;
      std::string actorL;
      int month;
      if (ss >> actorF >> actorL >> month >> year) {
        ClassicMovie *pClassic;
        pClassic = new ClassicMovie(stock, director, title, month, year,
                                    (actorF + " " + actorL));

        return pClassic;
      }
    }

  } else { // Invalid tag
    std::cerr << "Error: Invalid movie genre code '" << genre << "'."
              << std::endl;
  }

  return nullptr;
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
      ", year: " + std::to_string(year) +
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

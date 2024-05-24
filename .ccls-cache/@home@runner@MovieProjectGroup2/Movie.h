// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <typeinfo>
#include <vector>

class Movie {
public:
  const std::string director;
  const std::string title;

  Movie(const std::string &director, const std::string &title, int stock)
      : director(director), title(title), availableStock(stock) {}

  virtual ~Movie(){};

  int getStock() const;
  virtual char getGenreTag() const = 0; // Purely virtual. Parent has no genre.

  virtual bool borrowMovie(Movie *movie);
  virtual bool returnMovie(Movie *movie);

  // Comedy > Drama > Classic
  static int getGenrePriority(char genre);

  // Display methods
  friend std::ostream &operator<<(std::ostream &os, const Movie &movie);
  std::string str() const;

  // Factory Methods:
  static std::vector<Movie *> build(const std::string &movieFilename);
  static Movie *createMovie(const std::string &fileline);

  static bool equal(Movie *lMovie, Movie* rMovie);

protected:
  int availableStock;
};

struct CompareMoviePtrs {
  bool operator()(const Movie *lhs, const Movie *rhs) const {
    // First compare by genre
    int genreComparison = lhs->getGenrePriority(rhs->getGenreTag()) -
                          lhs->getGenrePriority(lhs->getGenreTag());

    if (genreComparison > 0) {
      return true;
    } else if (genreComparison < 0) {
      return false;
    }

    // If same class type, compare by attributes
    lhs = dynamic_cast<decltype(lhs)>(lhs);
    rhs = dynamic_cast<decltype(lhs)>(rhs);
    return (lhs < rhs);
  }
};

#endif // MOVIE_H
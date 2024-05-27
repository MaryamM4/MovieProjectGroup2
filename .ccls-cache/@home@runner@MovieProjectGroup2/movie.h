// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

class Movie {
public:
  const std::string director;
  const std::string title;
  const int year;

  Movie(const std::string &director, const std::string &title, int year,
        int stock)
      : director(director), title(title), year(year), availableStock(stock) {}

  virtual ~Movie(){};

  int getStock() const;
  virtual char getGenreTag() const = 0; // Purely virtual. Parent has no genre.

  // Operation commands.
  virtual bool borrowMovie(Movie *movie);
  virtual bool returnMovie(Movie *movie);

  // Comedy > Drama > Classic > Invalid
  static int getGenrePriority(char genre);

  // Display methods
  friend std::ostream &operator<<(std::ostream &os, const Movie &movie);
  std::string str() const;

  // Factory Methods:
  static std::vector<Movie *> build(const std::string &movieFilename);
  static Movie *createMovie(const std::string &fileline);

  static bool equal(Movie *lMovie, Movie *rMovie);

protected:
  int availableStock;
};

#endif // MOVIE_H
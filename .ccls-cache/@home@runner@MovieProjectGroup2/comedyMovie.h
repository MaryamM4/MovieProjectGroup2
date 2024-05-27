// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "movie.h"
#include <string>

class ComedyMovie : public Movie {
public:
  // Constructor
  ComedyMovie(int stock, const std::string &director, const std::string &title,
              int year)
      : Movie(director, title, year, stock) {}

  // Diconstructor
  ~ComedyMovie(){};

  // Overriden comparison operators
  bool operator<(const ComedyMovie &other) const;
  bool operator>(const ComedyMovie &other) const;
  bool operator==(const ComedyMovie &other) const;

  // Return char representing movie genre
  char getGenreTag() const override;
};
#endif

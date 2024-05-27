// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"
#include <string>

class DramaMovie : public Movie {
public:
  DramaMovie(int stock, const std::string &director, const std::string &title,
             int year)
      : Movie(director, title, year, stock) {}

  ~DramaMovie(){};

  // Overridden operators.
  bool operator<(const DramaMovie &other) const;
  bool operator>(const DramaMovie &other) const;
  bool operator==(const DramaMovie &other) const;

  // Returns char representing movie genre.
  char getGenreTag() const override;
};

#endif

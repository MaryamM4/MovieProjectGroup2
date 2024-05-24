// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "Movie.h"
#include <string>

class ComedyMovie : public Movie {
public:
  const int year;
  ComedyMovie(int stock, const std::string &director, const std::string &title,
              int year)
      : Movie(director, title, stock), year(year) {}

  ~ComedyMovie(){};

  bool operator<(const ComedyMovie &other) const;
  bool operator>(const ComedyMovie &other) const;
  bool operator==(const ComedyMovie &other) const;

  char getGenreTag() const override;
};
#endif

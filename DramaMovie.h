// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"
#include <string>

class DramaMovie : public Movie {
public:
  const int year;
  DramaMovie(int stock, const std::string &director, const std::string &title,
             int year)
      : Movie(director, title, stock), year(year) {}

  ~DramaMovie(){};

  bool operator<(const DramaMovie &other) const;
  bool operator>(const DramaMovie &other) const;
  bool operator==(const DramaMovie &other) const;

  char getGenreTag() const override;
};

#endif

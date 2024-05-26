// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H

#include "Movie.h"
#include <string>

class ClassicMovie : public Movie {
public:
  const std::string majorActor;
  const int month;

  ClassicMovie(int stock, const std::string &director, const std::string &title,
               int month, int year, const std::string &majorActor)
      : Movie(director, title, year, stock), majorActor(majorActor),
        month(month) {}

  ~ClassicMovie() {}

  bool operator<(const ClassicMovie &other) const;
  bool operator>(const ClassicMovie &other) const;
  bool operator==(const ClassicMovie &other) const;

  char getGenreTag() const override;
};
#endif
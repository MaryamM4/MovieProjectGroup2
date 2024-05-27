// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#ifndef MOVIETYPE_H
#define MOVIETYPE_H

class Movie;

class MovieType {
public:
  // Operation commands
  virtual bool borrow(Movie *movie);
  virtual bool returnMovie(Movie *movie);
};
#endif

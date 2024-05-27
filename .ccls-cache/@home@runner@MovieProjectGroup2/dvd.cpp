// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "dvd.h"
#include "movie.h"

// constructor
DVD::DVD() {}

// destructor
DVD::~DVD() {}

// borrow (reduce stock by 1)
bool DVD::borrow(Movie *movie) { return movie->borrowMovie(movie); }

// return (increase stock by 1)
bool DVD::returnMovie(Movie *movie) { return movie->returnMovie(movie); }
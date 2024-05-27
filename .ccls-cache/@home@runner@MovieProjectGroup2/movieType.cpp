// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "movieType.h"
#include "movie.h"

// borrow (reduce stock by 1)
bool MovieType::borrow(Movie *movie) { return movie->borrowMovie(movie); }

// return (increase stock by 1)
bool MovieType::returnMovie(Movie *movie) { return movie->returnMovie(movie); }
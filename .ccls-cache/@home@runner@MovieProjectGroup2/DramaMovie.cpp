// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "DramaMovie.h"

// get genre type of the movie
char DramaMovie::getGenreTag() const { return 'D'; }

// comparison operators
bool DramaMovie::operator<(const DramaMovie &other) const {
  // First compare by genre.
  int genreComparison =
      getGenrePriority(other.getGenreTag()) - getGenrePriority(getGenreTag());

  if (genreComparison > 0) {
    return true;
  } else if (genreComparison < 0) {
    return false;
  }

  // If same genre, then compare by attributes.
  if (director != other.director) {
    return director < other.director;
  }
  return title < other.title;
}

bool DramaMovie::operator>(const DramaMovie &other) const {
  return other < *this;
}

bool DramaMovie::operator==(const DramaMovie &other) const {
  return getGenreTag() == other.getGenreTag() && director == other.director &&
         title == other.title && year == other.year;
}

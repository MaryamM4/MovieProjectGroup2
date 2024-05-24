// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "ComedyMovie.h"

// get genre tag of the movie
char ComedyMovie::getGenreTag() const { return 'F'; }

// comparison operators
bool ComedyMovie::operator<(const ComedyMovie &other) const {
  // First compare by genre.
  int genreComparison =
      getGenrePriority(other.getGenreTag()) - getGenrePriority(getGenreTag());

  if (genreComparison > 0) {
    return true;
  } else if (genreComparison < 0) {
    return false;
  }

  // If same genre, then compare by attributes.
  if (title != other.title) {
    return title < other.title;
  }
  return year < other.year;
}

bool ComedyMovie::operator>(const ComedyMovie &other) const {
  return other < *this;
}

bool ComedyMovie::operator==(const ComedyMovie &rhs) const {
  if (getGenreTag() != rhs.getGenreTag()) {
    return false;
  }

  const ComedyMovie &other = static_cast<const ComedyMovie &>(rhs);
  return title == other.title && year == other.year;
}

// CSS343 Movie Project.
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala
// Dhayanidhi

#include "classicMovie.h"

// Get char representing the genre type of the movie
char ClassicMovie::getGenreTag() const { return 'C'; }

// Comparison operators
bool ClassicMovie::operator<(const ClassicMovie &other) const {
  // First compare by genre.
  int genreComparison =
      getGenrePriority(other.getGenreTag()) - getGenrePriority(getGenreTag());

  if (genreComparison > 0) {
    return true;
  } else if (genreComparison < 0) {
    return false;
  }

  // If same genre, then compare by attributes.
  if (year != other.year) {
    return year < other.year;
  } else if (month != other.month) {
    return month < other.month;
  }
  return majorActor < other.majorActor;
}

bool ClassicMovie::operator>(const ClassicMovie &other) const {
  return other < *this;
}

bool ClassicMovie::operator==(const ClassicMovie &other) const {
  return getGenreTag() == other.getGenreTag() && year == other.year &&
         month == other.month && majorActor == other.majorActor;
}
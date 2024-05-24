// CSS343 Movie Project
// Group 2: Jasleen Kaur Saini, Zaina Shaikh, Maryam Maabreh, Vinisha Bala Dhayanidhi

#ifndef DVD_H
#define DVD_H

#include "MovieType.h"

class DVD : public MovieType {
    public:
        DVD();
        ~DVD();

        bool borrow(Movie* movie) override;
        bool returnMovie(Movie* movie) override;
};
#endif 




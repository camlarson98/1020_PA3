#ifndef HFLIPFILTER_H
#define HFLIPFILTER_H
#include "../SimpleFilter.h"

class HFlipFilter : public SimpleFilter {
    protected:


    public:
        // Applies the horizontal flip to the image
        virtual void apply(Image&) const;
        
        // Constructors and destructor
        HFlipFilter();
        HFlipFilter(string);
        ~HFlipFilter();
};

#endif
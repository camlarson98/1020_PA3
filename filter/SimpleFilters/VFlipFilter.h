#ifndef VFLIPFILTER_H
#define VFLIPFILTER_H
#include "../SimpleFilter.h"

class VFlipFilter : public SimpleFilter {
    protected:


    public:
        // Applies the vertical flip to the image
        virtual void apply(Image&) const;
        // Constructors and destructor
        VFlipFilter();
        VFlipFilter(string);
        ~VFlipFilter();
};

#endif
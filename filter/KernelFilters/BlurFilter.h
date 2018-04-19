#ifndef BLURFILTER_H
#define BLURFILTER_H
#include "../KernelFilter.h"

class BlurFilter : public KernelFilter {
    protected:
        // Matrix for sharpen filter
        static const Matrix blur;
    
    public:
        // virtual as required by kernelFilter
        virtual void apply(Image&) const;
        // Parameter constructor
        BlurFilter(string);
        // Virtual destructor
        virtual ~BlurFilter();

};

#endif
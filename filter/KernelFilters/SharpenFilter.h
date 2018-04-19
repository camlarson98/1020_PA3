#ifndef SHARPENFILTER_H
#define SHARPENFILTER_H
#include "../KernelFilter.h"

class SharpenFilter : public KernelFilter {
    protected:
        // Matrix for sharpen filter
        static const Matrix K3;
    
    public:
        // virtual as required by kernelFilter
        virtual void apply(Image&) const;
        // Parameter constructor
        SharpenFilter(string);
        // Virtual destructor
        virtual ~SharpenFilter();

};

#endif
#ifndef PIXELFILTER_H
#define PIXELFILTER_H
#include "Filter.h"
#include <ctype.h>

using namespace std;


class PixelFilter : public Filter {
	protected:
		
		// Default and copy constructor
		PixelFilter();
		PixelFilter(const PixelFilter&);

	public:
		// Parameter constructor
		PixelFilter(string name);
		// Pure virtual destructor - makes class abstract
		virtual ~PixelFilter() = 0;
		// applies filter - virtual to require implementation by child classes
		virtual Pixel apply_transform(const Pixel&) const = 0;
        virtual void apply(Image&) const;

};


#endif
#ifndef SIMPLEFILTER_H
#define SIMPLEFILTER_H
#include "Filter.h"

using namespace std;


class SimpleFilter : public Filter {
	protected:
		// Default and copy constructor
		SimpleFilter();
		SimpleFilter(const SimpleFilter&);

	public:
		// Parameter constructor
		SimpleFilter(string name);
		// Pure virtual destructor - makes class abstract
		virtual ~SimpleFilter() = 0;
		// applies filter - virtual to require implementation by child classes
		virtual void apply(Image&) = 0;

};


#endif
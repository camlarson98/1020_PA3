#ifndef KERNELFILTER_H
#define KERNELFILTER_H
#include "Filter.h"

using namespace std;


class KernelFilter : public Filter {
	protected:
		virtual Pixel apply_kernel(Image&, int x, int y, const Matrix&) const;

		// Default and copy constructor
		KernelFilter();
		KernelFilter(const KernelFilter&);

	public:
		// Parameter constructor
		KernelFilter(string name);
		// Pure virtual destructor - makes class abstract
		virtual ~KernelFilter() = 0;
		// applies filter - virtual to require implementation by child classes
		virtual void apply(Image&, const Matrix) const;

};


#endif
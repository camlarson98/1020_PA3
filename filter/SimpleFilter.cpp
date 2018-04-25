#include "SimpleFilter.h"

// Parameter constructor that uses initializer list for name
SimpleFilter::SimpleFilter(string name) :
  Filter(name) {}

// Default destructor
SimpleFilter::~SimpleFilter() {}

// function to swap the two input pixels
void SimpleFilter::swap(Pixel& lhs, Pixel& rhs) const{
    Pixel tmp;
    tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
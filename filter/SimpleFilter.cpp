#include "SimpleFilter.h"

SimpleFilter::SimpleFilter(string name) :
  Filter(name) {}

SimpleFilter::~SimpleFilter() {}

void SimpleFilter::swap(Pixel& lhs, Pixel& rhs) const{
    Pixel tmp;
    tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
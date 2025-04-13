#include "element.h"

Element::Element(int data) : data{data} {}
Element::Element() {}

int Element::getData() { return data; }
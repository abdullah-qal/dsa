#include "element.hpp"

Element::Element(TreeNode *data) : data{data} {}
Element::Element() {}

TreeNode *Element::getData() { return data; }
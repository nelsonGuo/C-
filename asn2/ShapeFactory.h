#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H
#include "Shape.h"
#include <memory>
// headers, ...

struct ShapeFactory {
    // implement this method in ShapeFactory.cpp (note: this is somewhat
    // different from the ShapeFactory in the lecture)
    static std::unique_ptr<Shape> create(std::istream& is);
};

#endif

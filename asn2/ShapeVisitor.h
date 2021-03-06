#ifndef SHAPEVISITOR_H
#define SHAPEVISITOR_H
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
// headers, ...

class ShapeVisitor {
public:
    virtual ~ShapeVisitor() {}
    
    virtual void visitCircle(Circle *s) = 0;
    virtual void visitRectangle(Rectangle *s) = 0;
    virtual void visitTriangle(Triangle *s) = 0;
    
protected:
    ShapeVisitor() {}
};
#endif

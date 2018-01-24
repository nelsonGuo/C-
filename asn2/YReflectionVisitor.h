#ifndef YREFLECTIONVISITOR_H
#define YREFLECTIONVISITOR_H
#include "ShapeVisitor.h"

class  YReflectionVisitor: public ShapeVisitor {
public:
    virtual ~YReflectionVisitor() {}
    
    // provide implementation for the following in YReflectionVisitor.cpp
    // implementation should reflect the shape about the y-axis
    virtual void visitCircle(Circle *s) override;
    virtual void visitRectangle(Rectangle *s) override;
    virtual void visitTriangle(Triangle *s) override;
};
#endif

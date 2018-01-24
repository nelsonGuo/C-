#ifndef TRANSLATIONVISITOR_H
#define TRANSLATIONVISITOR_H
#include "Point.h"
#include "ShapeVisitor.h"
// headers, ...

class TranslationVisitor: public ShapeVisitor {
public:
    explicit TranslationVisitor(const Point& d = Point(0,0)): d_(d) {}
    virtual ~TranslationVisitor() {}
    
    Point getDisplacement() const { return d_; }
    void  setDisplacement(const Point& d) { d_ = d; }
    // provide implementation for the following in TranslationVisitor.cpp
    // implementation should translate the shape by the displacement d_
    virtual void visitCircle(Circle *s) override;
    virtual void visitRectangle(Rectangle *s) override;
    virtual void visitTriangle(Triangle *s) override;
private:
    Point  d_;  // the displacement
};
#endif

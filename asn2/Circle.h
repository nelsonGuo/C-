#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include "Shape.h"

// Note: If an implementation is needed, put it in Circle.cpp
class Circle:public Shape {
public:
    // read data for circle from 'is'; used by ShapeFactory object
    // should read in data members saved by 'save' (except for the type name)
    // should throw an exception on error (see README)
    explicit Circle(std::istream& is);
    
    int   getRadius() const { return radius_; }
    Point getCentre() const { return centre_; }
    
    void  setRadius(int radius) { radius_ = radius; }
    void  setCentre(const Point& centre) { centre_ = centre; }
    
    // write to standard output
    // sample output:  [C: (1,-2), 3]
    virtual void draw() const override;
    
    /* sample output:
     circle
     (1,-2) 3
     */
    virtual void save(std::ostream& os = std::cout) const override;
    
    // accept a visitor
    virtual void accept(ShapeVisitor& v) override;
    
private:
    Point  centre_;
    int    radius_;
};
#endif

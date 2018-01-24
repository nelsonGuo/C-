#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
#include "Shape.h"

// Note: See bottom of file to see where you should put your implementation
class Rectangle: public Shape {
public:
    // read data for Rectangle from 'is'; used by factory
    // should read in data members saved by 'save' (except for the type name)
    // should throw an exception on error (see README)
    explicit Rectangle(std::istream& is);
    // a Rectangle is specified by 2 (opposing) vertices
    // 'i' should be 0 or 1; if not, throw an exception
    Point getVertex(int i) const;
    
    // again, 'i' should be 0 or 1; if not, throw an exception
    void  setVertex(int i, const Point& p);
    
    // write to standard output
    // example output:  [R: (2,-3), (4,-5)]
    virtual void draw() const override;
        
        /* example output:
         rectangle
         (2,-3) (4,-5)
         */
    virtual void save(std::ostream& os = std::cout) const override;
        
        // accept a visitor
        virtual void accept(ShapeVisitor& visitor) override;
        
    private:
        // not shown; provide suitable data structure
        Point corner_left;
        Point corner_right;
        };
        
        // provide inline implementation of getVertex & setVertex here
        inline Point
        Rectangle::getVertex(int i) const{
            if(i == 0){
                return corner_left;
            }else if(i == 1){
                return corner_right;
            }else{
                throw "getVertex i should be 0 or 1";
            }
        }
        
        // again, 'i' should be 0 or 1; if not, throw an exception
        inline void
        Rectangle::setVertex(int i, const Point& p){
            if(i ==0){
                corner_left = p;
            }else if(i == 1){
                corner_right = p;
            }else{
                throw "setVertex i should be 0 or 1";
            }
        }
        // implement the other functions in Rectangle.cpp
#endif

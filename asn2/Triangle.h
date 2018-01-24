#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include "Shape.h"



// Note: See bottom of file to see where you should put your implementation
class Triangle: public Shape {
public:
    // read data for Triangle from 'is'; used by factory
    // should read in data members saved by 'save' (except for the type name)
    // should throw an exception on error (see README)
    explicit Triangle(std::istream& is);
    
    // a Triangle consists of 3 vertices
    // 'i' should be 0, 1, or 2; if not, throw an exception
    Point getVertex(int i) const;
    
    // 'i' should be 0, 1, or 2; if not, throw an exception
    void  setVertex(int i, const Point& p);
    
    // write to standard output
    // example output:  [T: (5,-6), (7,-8), (2,1)]
    virtual void draw() const override;
        
        /* example output:
         triangle
         (5,-6) (7,-8) (2,1)
         */
        virtual void save(std::ostream& os = std::cout) const override;
        
        // accept a visitor
       virtual void accept(ShapeVisitor& v) override;
        
    private:
        // provide suitable data structure
        Point pointA;
        Point pointB;
        Point pointC;
        };
        
        // provide inline implementation of getVertex & setVertex here
        inline
        Point Triangle::getVertex(int i) const {
            if(i ==0){
                return pointA;
            }else if(i == 1){
                return pointB;
            }else if(i == 2){
                return pointC;
            }else{
                throw "getVertex";
            }
        }
        
        inline
        void Triangle:: setVertex(int i, const Point& p){
            if(i ==0){
                pointA = p;
            }else if(i == 1){
                pointB = p;
            }else if(i == 2){
                pointC = p;
            }else{
                throw "setVertex";
            }
        }
        
        // implement the other functions in Triangle.cpp
#endif

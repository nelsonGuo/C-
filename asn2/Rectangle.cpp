//
//  Rectangle.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "Rectangle.h"
#include "ShapeVisitor.h"
using namespace std;

Rectangle::Rectangle(istream& is){
    
    is >> corner_left >> corner_right;
    if(corner_left.getX() == corner_right.getX() || corner_left.getY() == corner_right.getY()){
        throw "Rectangle::Rectangle(istream& is)";
    }
}

// write to standard output
// example output:  [R: (2,-3), (4,-5)]

void Rectangle::draw() const{
    std::cout<<"[R: "<<corner_left<<", "<<corner_right<<"]"<<std::endl;
}

/* example output:
 rectangle
 (2,-3) (4,-5)
 */
    void Rectangle::save(ostream& os) const{
    os << "rectangle" <<std::endl;
    os << corner_left<<' '<< corner_right<<std::endl;
}

void Rectangle::accept(ShapeVisitor& visitor){
    visitor.visitRectangle(this);
}

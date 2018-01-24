//
//  Circle.cpp
//  c++
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "Circle.h"
#include "ShapeVisitor.h"
using namespace std;

Circle::Circle(istream& is){
    if(!(is >> centre_ >> radius_)){
        throw "Circle(istream& is)";
    }
    
    if(radius_<0){
        throw "radius can not be negative";
    }
}

void Circle::draw() const {
    std::cout<<"[C: "<<centre_<<", "<<radius_<<"]"<<std::endl;
}

void Circle::save(ostream& os) const{
    os << "circle" <<std::endl;
    os << centre_<<' ' << radius_<<std::endl;
}

void Circle::accept(ShapeVisitor& v){
    v.visitCircle(this);
}

//
//  Triangle.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "Triangle.h"
#include <iostream>
#include "ShapeVisitor.h"
#include <cmath>

using namespace std;

Triangle::Triangle(istream& is){
    double sideA, sideB, sideC;
    
	
    is >> pointA>> pointB >> pointC;
	cerr << pointA << pointB << pointC << endl;
	
    sideA = sqrt( pow((pointA.getX() - pointB.getX()),2.0) + pow((pointA.getY() -pointB.getY()),2.0));
    sideB = sqrt( pow((pointA.getX() - pointC.getX()),2.0) + pow((pointA.getY()-pointC.getY()),2.0));
    sideC = sqrt( pow((pointB.getX() - pointC.getX()),2.0) + pow((pointB.getY() -pointC.getY()),2.0));
    if (sideA+sideB < sideC || sideA+sideC < sideB || sideB+sideC < sideA){
        throw "not a triangle";
    }
    
}
void Triangle::draw() const{
    cout<<"[T: "<<pointA<<", "<<pointB<<", "<<pointC<<"]"<<endl;
}

/* example output:
 triangle
 (5,-6) (7,-8) (2,1)
 */
void Triangle::save(ostream& os) const{
    os << "triangle" <<endl;
    os << pointA<<" " << pointB<<" "<<pointC<<endl;
}

void Triangle::accept(ShapeVisitor& v){
    v.visitTriangle(this);
}

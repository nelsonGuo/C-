//
//  ShapeFactory.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "ShapeFactory.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

unique_ptr<Shape>
ShapeFactory::create(istream& is){
    string type;
    unique_ptr<Shape> p;
    
    if(!(is >> type)){
        return p;
    }

    if(type == "circle"){
        p.reset(new Circle(is));
    }else if(type == "triangle"){
        p.reset(new Triangle(is));
    }else if(type == "rectangle"){
        p.reset(new Rectangle(is));
    }else{
        throw "shapeFactory create error";
    }
    return p;
}
                

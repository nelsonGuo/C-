//
//  XReflectionVisitor.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "XReflectionVisitor.h"
#include "Point.h"

void XReflectionVisitor::visitCircle(Circle *s){
    Point tmp(s->getCentre().getX(),-(s->getCentre().getY()));
    s->setCentre(tmp);
}

void XReflectionVisitor::visitRectangle(Rectangle *s) {
    for (int i = 0; i < 2; i++) {
        Point tmp = s->getVertex(i);
        tmp.setY(-tmp.getY());
        try {
            s->setVertex(i, tmp);
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
}

void XReflectionVisitor::visitTriangle(Triangle *s) {
    for (int i = 0; i < 3; i++) {
        Point tmp = s->getVertex(i);
        tmp.setY(-tmp.getY());
        try {
            s->setVertex(i, tmp);
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
}

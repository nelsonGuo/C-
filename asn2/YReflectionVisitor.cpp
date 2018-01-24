//
//  YReflectionVisitor.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//
#include "YReflectionVisitor.h"
#include "Point.h"

void YReflectionVisitor::visitCircle(Circle *s){
    Point tmp(s->getCentre().getX() *(-1),s->getCentre().getY());
    s->setCentre(tmp);
}

void YReflectionVisitor::visitRectangle(Rectangle *s) {
    for (int i = 0; i < 2; i++) {
        Point tmp = s->getVertex(i);
        tmp.setX(-tmp.getX());
        try {
            s->setVertex(i, tmp);
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
}

void YReflectionVisitor::visitTriangle(Triangle *s) {
    for (int i = 0; i < 3; i++) {
        Point tmp = s->getVertex(i);
        tmp.setX(-tmp.getX());
        try {
            s->setVertex(i, tmp);
        } catch (const char* msg) {
            std::cerr << msg << std::endl;
        }
    }
}

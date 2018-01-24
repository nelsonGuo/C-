//
//  TranslationVisitor.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "TranslationVisitor.h"
using namespace std;

void TranslationVisitor::visitCircle(Circle *s){
    try {
        s->setCentre(s->getCentre() +d_);
    } catch (const char* error) {
        cerr << error<< endl;
    }

}

void TranslationVisitor::visitRectangle(Rectangle *s){
    for (int i = 0; i < 2; i++) {
        try {
            s->setVertex(i, s->getVertex(i) + d_);
        }catch(const char* error) {
           cerr << error<< endl;
        }
    }
}

void TranslationVisitor::visitTriangle(Triangle *s) {
    for (int i = 0; i < 3; i++) {
        try {
            s->setVertex(i, s->getVertex(i) + d_);
        }catch(const char* error) {
           cerr << error<< endl;
        }
    }
}

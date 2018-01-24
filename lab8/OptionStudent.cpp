//
//  OptionStudent.cpp
//  lab8
//
//  Created by nelson guo on 2017-04-05.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include <stdio.h>
#include "OptionStudent.h"
#include <iostream>



using namespace std;
  size_t OptionStudent::count_ =0;
   OptionStudent::OptionStudent(string id,string lastname,string firstname,int term,string option):Student(id,lastname,firstname),term_(term),option_(option){
    	count_++;
    };

    OptionStudent::OptionStudent(const OptionStudent& s):Student(s),term_(s.term_),option_(s.option_){count_++;

    };


void OptionStudent::print(std::ostream& os) const {

    this->Student::print(os);

    os << " " << this->term_ << " "<< this->option_<<endl;
    
}
void OptionStudent::display(std::ostream& os) const{
    
    this->Student::display(os);
    os << "Term:" << this->term_ << endl << "Option: " << this -> option_ <<endl;
    
}

istream& operator>>(std::istream& is, OptionStudent& s){
    Student student;
    is >> student >>s.term_ >>s.option_;
    s.Student::operator=(student);
    return is;
}

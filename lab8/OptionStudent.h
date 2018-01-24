//
//  OptionStudent.h
//  lab8
//
//  Created by nelson guo on 2017-04-05.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#ifndef OptionStudent_h
#define OptionStudent_h
#include <iostream>
#include "Student.h"
#include <vector>

class OptionStudent: public Student {
public:
    explicit OptionStudent(std::string id,std::string lastname, std::string firstname,int term,std::string option);

    explicit OptionStudent(const OptionStudent& s);

    explicit OptionStudent(){count_++;};

    virtual ~OptionStudent(){count_--;}

    static size_t getCount(){ return count_;}

    virtual void print(std::ostream& os) const override;

    virtual void display(std::ostream& os) const override;
    
    friend std::istream& operator>>(std::istream& is, OptionStudent& s);
    
private:
    int  term_;
    std::string option_;
    static size_t count_;
    
};

#endif /* OptionStudent_h */

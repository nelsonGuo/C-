//
//  Student.h
//  c++
//
//  Created by nelson guo on 2017-03-22.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#define Student_h

#include <stdio.h>
#include <utility>
#include <string>
#include <iostream>
#include <string>



using Name  = std::pair<std::string,std::string>;

class Student{
    
public:
    Student(const std::string id,std::string lastname,std::string firstname):id_(id),name_(make_pair(toLowerCase(lastname),toLowerCase(firstname))){
        if(!isValidId(id) || !isValidName(make_pair(lastname,firstname))){
            throw "error";
        }
    }
    
    Student(){}
    
    friend std::ostream& operator<< (std::ostream& os,const Student& s){
        os << s.id_<<' '<<s.name_.first<<' '<<s.name_.second;
        return  os;
    }
    
   friend std::istream& operator >> (std::istream& is,Student& s){
       std::string sid = s.id_;
       std::string lastname = s.name_.first;
       std::string firstname = s.name_.second;
       
       if(!isValidId(sid)){
           throw "error";
       }
       if(!isValidName(make_pair(toLowerCase(lastname),toLowerCase(firstname)))){
           throw "error";
       }
        return is >>s.id_ >> s.name_.first>>s.name_.second;
    }
    
    friend bool operator< (const Student& rs, const Student& ls){
        return rs.id_.compare(ls.id_);
    }
    
    virtual ~Student(){}
    
private:
    std::string id_;
    Name  name_;
    static bool isValidId(const std::string& id){
        if(id[0] != 'a'){
            return false;
        }
        if(id.length() != 9){
            return false;
        }
        return true;
    }
    
    static bool isValidName(const Name& name){
        if(!name.first.empty() && name.first.find_first_of(' ') ==std::string::npos){
            return true;
        }
        if(!name.second.empty() && name.second.find_first_of(' ') == std::string::npos){
            return true;
        }
        return false;
    }
    
    static std::string toLowerCase(std::string& str){
        std::string s = str;
        transform(s.begin(), s.end(), s.begin(), tolower);
        return s;
    }

};



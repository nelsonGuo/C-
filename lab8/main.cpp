//
//  main.cpp
//  lab8
//
//  Created by nelson guo on 2017-04-05.
//  Copyright © 2017 nelson guo. All rights reserved.
//
#include "OptionStudent.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // insert code here...
    string input;
    OptionStudent ops;
    Student s;
    vector <Student> v;
   // Student s1("a00957058","guo","xin");
   // s1.print(cout);
   // string str ="a00957058 guo xin";
    //istringstream iss(str);
    //iss>>s;
    //s.print(cout);



    while(getline(cin,input)){
        istringstream iss(input);
        iss >> s;
        s.print(cout);
    	v.push_back(s);
    }

    for(auto& x : v){
    	x.display(cout);
    	x.print(cout);
    }
    


    return 0;
}

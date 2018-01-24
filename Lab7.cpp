//
//  Lab7.cpp
//  c++
//
//  Created by nelson guo on 2017-03-22.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include "Student.h"
#include <map>

using namespace std;

int main(){

    Student s("a12345678","Homer","Simpson");
    //Student s2("AAA","carl","carlson");
    cout<< s << endl;
    
    map <Student, int> m;
    Student s1;
    int score;
    
    while(cin >> s >> score){
        m[s] += score;
    }
    for(auto map: m){
        cout <<map.first <<" "<< map.second<<endl;
    }
    
}

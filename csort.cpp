//
//  assignment1.cpp
//  c++
//
//  Created by nelson guo on 2017-03-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <deque>


using namespace std;


struct Record{
    string line;
    vector<string> column;
};

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return " ";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool comparsion(const Record& p, const Record& q, deque<string> cmm){
    char aod;
    int num;
    char f;
    double first;
    double second;
    
        istringstream iss(cmm.at(0));
        if(cmm.at(0)[0] == '-'){
            iss >> aod >> num >> f;
            if(f == 'f'){
                first = stod(trim(p.column.at(num-1)));
                second = stod(trim(q.column.at(num-1)));
                if(first -second != 0){
                    return first > second;
                }else if(cmm.size() > 1){
                    cmm.pop_front();
                    return comparsion(p,q,cmm);
                }else return false;
            }else if(trim(p.column.at(num-1)) !=trim(q.column.at(num-1))){
                return trim(p.column.at(num-1))> trim(q.column.at(num-1));
            }else if(cmm.size() >1){
                cmm.pop_front();
                return comparsion(p,q,cmm);
            }else return false;
            
        }else{
            iss >>num>> f;
            if(f == 'f'){
                first = stod(trim(p.column.at(num-1)));
                second = stod(trim(q.column.at(num-1)));
                if(first !=second){
                    return first < second;
                }else if(cmm.size() > 1){
                    cmm.pop_front();
                    return comparsion(p,q,cmm);
                }else return false;
            }else if(trim(p.column.at(num-1)) != trim(q.column.at(num-1))){
                return trim(p.column.at(num-1)) < trim(q.column.at(num-1));
            }else if (cmm.size() >1){
                cmm.pop_front();
                return comparsion(p,q,cmm);
            }else return false;
        }
}

struct Cmp {
    
    deque<string> cmm;
    Cmp(deque<string> c):cmm(c){}

    inline bool operator()(const  Record& first, const Record& second){
         return comparsion(first,second,cmm);
    }
};

vector<string> split (const string& s){
    
    string str = s;
    vector<string> tokens;
    char *tok;
     tok = strtok (&str[0],",");

    while( tok != NULL )
    {
        tokens.push_back(tok);
        tok = strtok( NULL, "," );
    } 
    return tokens;
}

ostream& operator <<(ostream & os, const Record & r){
   
    os<<r.column.at(0);
    for(size_t i =1; i<r.column.size();i++){
       os<<','<<r.column.at(i);
    }
    return os;
}

bool check_input(Record& r,deque<string> d){
    int n = 0;
    char c;
    char f;
    int max = 0;
    int checknum;
    
    for(auto x: d){
        istringstream iss(x);
        if(x[0] == '-'){
            iss >> c >> n >> f;
        }
        iss >> n >>f;
        if(n > max){
            max =n;
        }
        if(f == 'f'){
            istringstream iss(r.column.at(n-1));
            iss >>checknum;
            if(checknum == 0){
                return  false;
            }
        }
    }  
    if(r.column.size() <max){
        return false;
    }else{
        return true;
    }   
}

int main(int argc, char *argv[]){
    string input;
    vector<Record> records;
    Record r;
    deque<string> sortcolumn;
    
    if(argc !=2){
        cout<<"invalid"<<endl;
        exit(0);
    }
    
    vector<string> v = split(argv[1]);
    copy(v.begin(), v.end(), inserter(sortcolumn, sortcolumn.end()));
    
    while(getline(cin, input)){
        r.line = input;
        r.column = split(input);
        if(check_input(r, sortcolumn)){
          records.push_back(r);
        }
    }
    
    sort(records.begin(), records.end(), Cmp(sortcolumn));
    
    for(auto & x:records){
        cout<< x << endl;
    }
    
}

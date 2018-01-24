//
//  main.cpp
//  COMP3512
//
//  Created by nelson guo on 2017-04-01.
//  Copyright © 2017 nelson guo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include "Shape.h"
#include "ShapeFactory.h"
#include "TranslationVisitor.h"
#include "XReflectionVisitor.h"
#include "YReflectionVisitor.h"
#include <string>


using namespace std;

int main(int argc, char *argv[]){
    ShapeFactory factory;
    vector<shared_ptr<Shape>>  v;
    string input;
    char c = '\0';
    if(argc !=2){
        cerr<<"invalid"<<endl;
        return 0;
    }
    
    if(argc == 2){
        //int count=0;
        string line;
        ifstream myfile (argv[1],ios_base::in | ios_base::binary);
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                
                string type;

                myfile >> type;
                if(type =="circle"){
                    string center;
                    string radius;
                    myfile >> center >> radius;
                    istringstream iss("circle "+ center + " " + radius);
                    v.push_back(factory.create(iss));
                   // cout << center<<" " <<radius<<endl;
                }else if(type == "triangle"){
                    string A;
                    string B;
                    string C;
                    myfile >> A >> B >> C;
                    istringstream iss("triangle "+ A + " " + B + " " +C);
					v.push_back(factory.create(iss));
                }else if(type == "rectangle"){
                    string cornerA;
                    string cornerB;
                    myfile >> cornerA >> cornerB;
                    istringstream iss("rectangle "+ cornerA + " " + cornerB);
                    v.push_back(factory.create(iss));
                }else{
                    break;
                }
            }
            for(auto& x: v){
                x->draw();
            }
           myfile.close();
        }
        
	//	cerr << "Reading is ready" << endl;
        string input;
		
        //while(!cin.eof()){
		while(getline(cin, input)) {
                cerr<< "> ";
            //    string input;
            //    getline(cin, input);
                istringstream iss(input);
                iss >> c;
          //  cout<<"c: " << c <<endl;
            if(c == 'c'){
                try {
                    v.push_back(factory.create(iss));
                } catch (const char *s) {
                    cerr <<s<< endl;
                }
            } else if(c == 'x'){
                XReflectionVisitor x;
                for (auto& shape : v){
                    shape->accept(x);
                }
            } else if(c == 'y'){
                YReflectionVisitor y;
                for (auto& shape : v){
                    shape->accept(y);
                }

            } else if(c == 't'){
                Point d;
                iss >> d;
                TranslationVisitor t(d);
                for(auto& shape :v){
                    shape ->accept(t);
                }
            } else if(c == 'd'){
            } else {
                continue;
            }
            for(auto& x: v){
                x->draw(); 
            }
            //cerr << "end of cmd" << endl;
        }
        
	//	cerr << "ready to close the program: save every shape" << endl;
        cin.clear();
        ofstream ofs(argv[1], ios_base::out | ios_base::binary | ios_base::trunc);
        for(auto& shape: v){
            shape->save(ofs);
        }
        ofs.close();
    }
    
}

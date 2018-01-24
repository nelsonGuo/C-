//
//  Lab6.cpp
//  c++
//
//  Created by nelson guo on 2017-03-07.
//  Copyright © 2017 nelson guo. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <map>
#include <vector>
#include <set>

#define N 10000000


using namespace std;

int main(){
    string smallest;
    map<string,set<int>> container;
    bitset <N> isprime;
    isprime.set();
    
    for(size_t i = 2; i < sqrt(N); i++){
        if(isprime[i] ==1){
            for(size_t j = i*i;j < N; j=j+i){
                isprime[j] = 0;
            }
        }
    }
    
    for(size_t i = 2; i < N; i++){
        if(isprime[i]){
            smallest = to_string(i);
           sort(smallest.begin(),smallest.end());
            container[smallest].insert((int)i);
        }
    }
    
    set<int> max;
    for(auto& x:container) {
        if(max.size() < x.second.size())
            max = x.second;
    }
    
    cout << endl;
    for(auto& y:max) {
        cout<<y<<" ";
    }
    cout<<endl;
    cout<<"Size: "<<max.size()<<endl;
    cout<<endl;
    
}

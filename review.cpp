

#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;
typedef pair<vector<int>,vector<int>> mypair;

pair<vector<int>,vector<int>> partition(const vector <int>& v, bool(*f)(int)){
	vector<int> v1;
	vector<int> v2;

	for(auto & x: v){
		if(f(x)){
			v1.push_back(x);
		}else{
			v2.push_back(x);
		}
	}
	return make_pair(v1,v2);
}

bool is_even(int n){
	return n%2 == 0;
}

int main()
{	
	list<int> lst{9,8,7,6};
	vector <int> v ={3,2,7,6,8,1,4,5};
	vector <int> v2 ={3,2,7,6,8};
	vector <int> v3= {9,8,7,6,-98,-88,-2,122,283,991};

	//a)
	//copy(v.end()-5,v.end(),ostream_iterator<int>(cout,"\n"));

	//b)
	//copy(lst.rbegin(),lst.rend(),ostream_iterator<int>(cout,"\n"));

	//c)
	//copy(lst.begin(),lst.end(),v.begin()+2);

	//d)
	 copy_if(lst.begin(),lst.end(),inserter(v,v.end()),[](int i){return i*3;});

	//e)
	//sort(v.begin(),v.end(),[](const int a,const int b){return a < b;});

	//f)
	//transform(lst.begin(),lst.end(),inserter(v,v.end()),[](int i){ return i*3;});

	//g
	//v.erase(remove_if(v.begin(),v.end(),[](int i){return i < 5;}),v.end());

	//h
	 
	 struct myFunctor{
	 	
	 	int x = 0;
	 	int y = 0;
	 	void operator() (int i){
	 		if(i > 100){
	 			x++;
	 		}
	 		if(i<0){
	 			y++;
	 		}
	 	}
	 };

	//auto count= for_each(v3.begin(),v3.end(),[](int i){ return i*3;});
	//cout<<count.x<< " "<< count.y << endl;
	

	//i
	//sort(v2.begin(),v2.end());
	//v2.erase(unique(v2.begin(),v2.end()),v2.end());
	

    for(auto &s:v3){
		cout <<s << " ";
	}
/*
	mypair pair = partition(v2,is_even);

	for(auto& x :pair.first){
		cout<< x << " ";
	}
 	cout<< endl;
	for(auto& x :pair.second){
		cout<< x << " ";
	}
	*/
	return 0;

}

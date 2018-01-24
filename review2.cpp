#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream> 

using namespace std;
typedef pair<string,string> Name;

struct Student{
	string id;
	Name name;
	int score;
};

struct Idscore{
	string id;
	int score;
	Idscore(const string id,const int score);
	
};

ostream& operator << (ostream & os, const Student& s){
	os<<s.id<<endl<<s.name.first <<' '<< s.name.second<<endl<<' '<<s.score <<endl;
	return os;
}

istream& operator >>(istream& is, Student& s){
	is>>s.id>>s.name.first>>s.name.second>>s.score;
	return is;
}

bool Cmp(const Student& lhs,const Student& rhs){
	return lhs.score < rhs.score;
}

int main(){
	Student s;
	vector<Student> v;
	vector<Student> ok;

	vector<int> v1 ={9,8,7,6};
	vector<int> v2 ={3,2,7,6,8};


	ifstream myReadFile;
	myReadFile.open("test");
	while(!myReadFile.eof()){
		myReadFile>>s;
		v.push_back(s);
	}

	//copy_if(v.begin(),v.end(),back_inserter(ok),[](const Student & s){ return s.score > 50;});

	//v.erase(remove_if(v.begin(),v.end(),[](const Student & s){ return s.score > 50;}),v.end());

	transform(v.begin(),v.end(),back_inserter(ok),
		[](Student& s)->Student{
			
		  Student x;
		  x.score = s.score;
		  return x;	
	});

	//sort(v.begin(),v.end(),Cmp);
	for(auto& x: ok){
		cout<<x <<endl;
	}
}	
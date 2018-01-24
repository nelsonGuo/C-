

#include <iostream>
#include <cctype> 
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream> 
#include <ostream> 
#include <vector>
#include <typeinfo>

using namespace std;

typedef pair<string, int>  Grede;

struct  Student 
{
	string id;
	vector<Grede>  grades; 	
};

struct MaxFinder{
	string course;
	int max;
	string id;
	MaxFinder(const string& s):course(s),max(0){};
	void operator()(const Student& s){
		for(auto& x:s.grades){
			if(x.first == course){
				if(x.second >max){
					max = x.second;
					id=s.id;
				}
			}
		}
	}
};

struct Cmp{

	string course;
	Cmp(const string & s):course(s){};

	 bool operator() (const Student & lhs, const Student & rhs){
	 	int score1 = 101;
	 	int score2 = 101;
	 	for(auto& x: lhs.grades){
	 		if(x.first == course){
	 			score1 = x.second;
	 		}
	 	}
	 	for(auto& y: rhs.grades){
	 		if(y.first == course){
	 			score2 = y.second;
	 		}
	 	}
	 	return score1 < score2;
	 }
};

istream& operator >> (istream& is, Student & s){
	size_t n;

	if(!(is >> s.id)){
		return is;
	}
	is >> n;
	s.grades.clear();
	for(size_t i = 0; i < n; i++){
		string course;
		int score;
		is >> course >> score;
		s.grades.push_back(make_pair(course,score));
	}

	return is;

}

ostream& operator <<(ostream & os, const Student & s){
	int no = s.grades.size();
	 os<<s.id<<endl<<no<<endl;

	for(auto& x: s.grades){
		os << x.first << " " << x.second << endl;
	}
	os<<endl;
	return os;
}

int main()
{
	vector<Student> v;
	Student s;
	ifstream myReadFile;
	myReadFile.open("test");

	while(!myReadFile.eof()){
		myReadFile >> s;
		v.push_back(s);
	}
    sort(v.begin(),v.end(),Cmp("comp3512"));
	for(auto & x: v){
		cout << x;
	}
	MaxFinder m = for_each(v.begin(),v.end(),MaxFinder("comp3512"));
	cout<<"max: "<<m.id<<" "<<m.max <<endl;
	return 0;
}


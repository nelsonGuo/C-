#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){

	string line;
	string fmt;
	string number;

	int width;
	char c;
	char pos;
	char dot;
	
	int integer;
	int precision;
	float flt;
	size_t found;
 	
	
	while(getline (cin,line)){

	 istringstream iss (line);

	 if(!(iss >> fmt >> number)){
		 continue;
	 }
	 
	 istringstream f(fmt);


	 found=number.find('.');

  if (found!=npos){

  	istringstream fl(number);
	 fl >> flt;

	  if(!(f >> width >> dot >> precision >>c)){
	  	continue;
	  }

	  if((width < 0) || (precision < 0)){
		continue;
	 }

  }else {

  	istringstream d(number);
	 d >> integer;

	  if(!((f >> width>> c) || ( f >> pos >> width >> c))){
		continue;
	 }
	 if(width < 0){
	 	continue;
	 }

  }

	 switch (c) {

		 case 'd':
		 cout <<dec<<setw(width)<<right<<setfill(' ')<<integer<<endl;
		 break;

		 case 'o':
		 cout <<oct<<setw(width)<<right<<setfill(' ')<<integer<<endl;
		 break;

		 case 'x':
		 cout <<hex<<setw(width)<<right<<setfill(' ')<<integer<<endl;
		 break;

		 case 'X':
		 cout <<hex<<setw(width)<<uppercase<<right<<setfill(' ')<<integer<<endl;
		 break;

		 case'f':
		 cout.precision(precision);
		 cout << fixed << setw(width) << setfill(' ') << flt <<endl;
		 break;

		 case'e':
		 cout.precision(precision);
		  cout << scientific << setw(width) << setfill(' ') << flt <<endl;
		 break;

		 case'E':
		 cout.precision(precision);
		 cout << scientific << uppercase << setw(width) << setfill(' ') << flt <<endl;
		 break;
		 
	 }
	  		
	}

	return 0;
	
}
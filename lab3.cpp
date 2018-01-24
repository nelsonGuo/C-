#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string rtrim(const string& s, bool (* is_junk)(char));
string replace_all(const string& s, const string& oldstr, const string& newstr);
string squeeze(const string& s, char c);
vector<string> split (const string& s, const string& delim);

int main()
{
	
	count << rtrim("   hello world\t ", is_whitespace) <<endl;
	count << replace_all("alley_dalley","al","oke") << endl;
	count << squeeze("naahaaaaapeemaapetilon",'a') <<endl;
	return 0;
}




string rtrim(const string& s, bool (* is_junk)(char)){
	string:: size_type i;

	for(i = s.size(); i > 0; i--){
		 if(is_junk(s[i-1]) == false){
	 		break;
	  }
	}

	return s.substr(0,i);
}

bool is_whitespace(char c){
	return isspace(c);
}


string replace_all(const string& s, const string& oldstr, const string& newstr){

	string:: size_type idx,odlen = oldstr.length(),newlen = newstr.length();
	string  reStr = s;

	while((idx = reStr.find(oldstr,idx)) != string:npos){

		reStr.replace(idx,odlen,newstr);
		idx += newlen;
	}

	return reStr;

}

string squeeze(const string& s, char c){
	string:: size_type i;
	string newString;

	char pre = 0;
	if(i = 0; i < s.length(); i++){

		if(!(pre == c && s[i] == c)){
			newString.push_back(s[i]);
		}
			pre = s[i];
	}
	return newString;

}

vector<string> split (const string& s, const string& delim){
	String::size_type start, pos;
	vector<char> v;
	String tok;


	for(start = 0; start < s.length(), s++){
	 	if(s[i] == delim[0]){
	 		pos = i;
	 		continue;
	 	}
	 	tok = s.substr(start,pos);
	 	v.push_back(tok);
	 	start = pos;
	}

	tok=s.substr(start);
	v.push_back(tok);

}





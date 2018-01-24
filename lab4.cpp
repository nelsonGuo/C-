
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> interleave(int x,const vector<int>& v);
vector<vector<int>> permute(size_t n);

int main()
{
	vector<vector<int>> v;
	v = permute(3);
	for(auto& x:v){
		for(auto& y:x){
			cout<<y;
		}
		cout<<' ' <<endl;
	}
	return 0;

}

 vector<vector<int>> interleave(int x, const vector<int>& v){
	vector<vector<int>> q;
	vector<int> p = v;
	
	for(int i = 0; i <=(int)v.size(); i++) {
		p.insert(p.begin()+i,x);
		q.push_back(p);
		p = v;
	}
		
	return q;

}

vector<vector<int> > permute(size_t n){

	vector<vector<int>> q;
	vector<vector<int>> o;
	
	if(n == 0){
		return {{}};
	}
		q = permute(n-1);
		for(auto& x: q){	
			for(auto& y: interleave(n,x)){
				o.push_back(y);
			}
		}
	return o;
		
}
     

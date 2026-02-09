#include<iostream>
using namespace std;

int main(){
	string s;
	cout<<"Enter The String"<<endl;
	cin>>s;
	int count=0;
	if(s.size()<10){
		cout<<s<<endl;
	}
	else if(s.size()>=10 && s.size()<100){
		for(char c : s){
		count++;	
		}
		cout<<s[0]<<count-2<<s.back();
	}
	
	return 0;
}

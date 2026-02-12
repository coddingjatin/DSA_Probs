#include <bits/stdc++.h>
using namespace std;

int main() {

int X, Y;
cin>>X>>Y;
if(X>=0 || X<=7){
	if(Y>=0 || Y<=7){
		int res=X+Y;
		if(res<=7){
			int result=7-X-Y;
			cout<<result;
		}
	}
}
return 0;

}

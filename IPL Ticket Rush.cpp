#include <bits/stdc++.h>
using namespace std;

int main() {
    int T,N,M;
    cin>>T;
    while(T--){
        cin>>N>>M;
        int result=N-M;
        if(result<=0){
            result=0;
        }
        cout<<result<<endl;
}

}

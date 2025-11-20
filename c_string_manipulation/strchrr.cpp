//o find a tatgeted character in string
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[]{"hello this is tanishx here!"};
    char*output = a,target = 's';
    int count{};
    while((output = strchr(output,target)) !=nullptr){
        cout<<"found "<<endl;
        cout<<"Searching for "<<endl;
        ++output;
        ++count;
    }
    cout<<"Total count :"<<count<<endl;
    cout<<output<<endl;
    return 0;
}

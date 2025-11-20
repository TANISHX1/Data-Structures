//to compare two strings upto 'n' characters

#include<iostream>
#include<cstring>

using namespace std;
int main(){
      char a[100];
      char b[100];
cout<<"Enter the string A : ";
cin>>a;      
cout<<"Enter the string B : ";
cin>>b;
if(!strncmp(a,b,4))cout<<"Strings are equal \n";
else if(strncmp(a,b,4)>0) cout<<"strings are not equal 1\n";
else if(strncmp(a,b,4)<0) cout<<"strings are not equal 2\n";
return 0;      
    }
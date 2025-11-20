//strcat to concatenating two strings (cnnectingor joining two strings)
//use of strcat = join two string

#include<iostream>
#include<cstring>
using namespace std;
int main(){
cout<<"STRCAT : "<<endl;
    char *source = new char[30]{'H','e','l','l','o',' ','t','h','i','s', 'i','s',' ','p','r','a','c','t','i','c','e','\0'};
    char *destination = new char[60]{'I',' ','a','m',' ','t','a','n','i','s','h','x',' ','A','n','d', '\0'};
    cout<<"Length of string (source)      :  "<<strlen(source)<<endl;
    cout<<"Length of string (Destination) :  "<<strlen(destination)<<endl;
    cout<<"Concatenating both strings(adding strings)......\n";
    strcat(destination,source);
    cout<<"Length of string (Destination) :  "<<strlen(destination)<<endl;
    cout<<destination<<endl;
cout<<"---------------------------------------------------------\n";    
cout<<"STRNCAT : "<<endl;
    char sour[40]{" One and only The great CS student "};
    char dest[80]{" I am Tanishx ,"};
    cout<<"Length of string (source)      :  "<<strlen(sour)<<endl;
    cout<<"Length of string (Destination) :  "<<strlen(dest)<<endl;
    cout<<"Concatenating both strings(adding strings)......\n";
    strncat(dest,sour,10);
    cout<<"Length of string (Destination) :  "<<strlen(dest)<<endl;
    cout<<dest<<endl;    
    return 0;
}
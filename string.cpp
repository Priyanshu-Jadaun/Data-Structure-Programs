#include<iostream> 
#include<string.h> 
using namespace std; 
int main () 
{ 
    char s[50]; 
    int i=0; 
    cout << "Enter a string : "; 
    gets(s); 
    cout<<s[0]<<" "; 
    while (s[i] != '\0') { 
        if (s[i] == ' ' && s[i+1]!=' ')
             cout<<s[i+1]<<" "; 
        i++; 
    } 
    cout<<endl; 
    return 0; 
}
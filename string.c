#include<bits/stdc++.h>
using namespace std; 
void concatenate_string(char* a, char* b) 
{ 
    int i; int j = strlen(a); 
    for (i = 0; b[i] != '\0'; i++) { 
        a[i + j] = b[i]; 
    } 
    a[i + j] = '\0'; 
    return; 
} 
int main() 
{
    char a[5000], b[5000]; 
    cout<<"Enter the first string: "; 
    gets(a); 
    cout<<"Enter the second string: "; 
    gets(b); 
    concatenate_string(a,b); 
    cout<<"Concatenated String is: "<<a<<endl; 
    return 0;
}
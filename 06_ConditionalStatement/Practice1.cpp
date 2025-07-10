#include<iostream>
using namespace std;

int main(){

    char ch;
    cout<<"Enter character:";
    cin>> ch;

    if (ch>='a' && ch<='z'){
        cout<< "Chracter is Lower Case.";
    }
    else{
        cout<< "Chracter is Upper Case.";
    }
    return 0;
}
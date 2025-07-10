#include<iostream>
using namespace std;

int main(){
    int marks;
    cout<<"Enter the Marks:";
    cin>> marks;

    if(marks >=90){
        cout<<"Passed with Grade A";
    }
    else if(marks >=80 && marks <90){
         cout<<"Passed with Grade B";
    }
    else if(marks >=70 && marks <80){
         cout<<"Passed with Grade C";
    }
    else if(marks >=35 && marks <70){
         cout<<"Passed with Grade D";
    }
   else{
    cout<<"BETTER LUCK NEXT TIME!";
   }
   return 0;


}
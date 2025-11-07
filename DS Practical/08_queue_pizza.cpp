#include <iostream>
using namespace std;
#define M 5

class Queue {
    int front, rear;
    string q[M];
public:
    Queue(){ front = rear = -1; }

    void add(string x){
        if(rear == M-1){
            cout<<"Queue Full\n"; return;
        }
        if(front == -1) front = 0;
        q[++rear] = x;
    }

    void remove(){
        if(front == -1 || front > rear){
            cout<<"Queue Empty\n"; return;
        }
        cout<<"Served: "<< q[front++] <<"\n";
    }

    void display(){
        if(front == -1 || front > rear){
            cout<<"No Pending Jobs\n"; return;
        }
        for(int i=front;i<=rear;i++)
            cout<<q[i]<<endl;
    }
};

int main(){
    Queue ob;
    int ch; string j;
    do{
        cout<<"\n1.Add  2.Serve  3.Show  4.Exit: ";
        cin>>ch;
        if(ch==1){ cout<<"Job: "; cin>>j; ob.add(j); }
        else if(ch==2) ob.remove();
        else if(ch==3) ob.display();
    }while(ch!=4);
}

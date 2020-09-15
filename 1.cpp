/*Create a class student which stores name, roll number and age of a student. 
Derive a class test from student class, which stores marks in 5 subjects. 
Input and display the details of a student.*/
#include<iostream>
#include<string.h>
using namespace std;

class student{
    char *name;
    int roll;
    int age;
    public:
        void set(char *n,int r,int a){
            name=new char[strlen(n)];
            strcpy(name,n);
            roll=r;
            age=a;
        }
        void get(){
            cout<<"--------------------------------------------------------"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Roll Number: "<<roll<<endl;
            cout<<"Age: "<<age<<endl;
        }
        ~student(){
            delete(name);
        }
};

class test:public student{
    int marks[5];
    public:
        void set(char *n,int r,int a,int *m){
            student::set(n,r,a);
            for(int i=0;i<5;i++){
                marks[i]=m[i];
            }
        }
        void get(){
            student::get();
            cout<<"Marks of student are: "<<endl;
            for(int i=0;i<5;i++){
                cout<<"Marks of subject "<<i+1<<": "<<marks[i]<<endl;
            }
        }
        ~test(){
            delete(marks);
        }
};

int main(){
    cout<<"Enter the Number of student data you want to enter:";
    int n;
    cin>>n;
    test t[n];
    char *name = new char[50];
    int roll;
    int age;
    int marks[5];
    cout<<"--------------------------------------------------------"<<endl;
    cout<<"Enter Details of students:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"--------------------------------------------------------"<<endl;
        cout<<"Enter Details of "<<i+1<<"st students:"<<endl;
       cout<<"Enter name: ";
       cin.ignore();
       cin.getline(name,50); 
       cout<<"Enter Roll Number: ";
       cin>>roll;
       cout<<"Enter Age: ";
       cin>>age;
       cout<<"Enter Marks of student : "<<endl;
        for(int j=0;j<5;j++){
            cout<<"Enter Marks of subject "<<j+1<<": ";
            cin>>marks[j];
        }
        t[i].set(name,roll,age,marks);
    }
    for(int i=0;i<n;i++){
        t[i].get();
    }
    return 0;
}
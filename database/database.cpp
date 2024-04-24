#include <iostream>
#include <fstream>
using namespace std;
struct student{
    string name;
    int age;
    char gender;
    string batch;
};
void read(int &n){
    cout<<"How many records do you want to enter"<<endl;
    cin>>n;
    student *s = new student[n];
    fstream ifile;  
    ifile.open("student_data.dat", ios::binary);
    if(ifile){
        cout<<"----Enter your records----"<<endl<<"Notice: Fill them respectivly!"<<endl<<"1:Name"<<endl<<"2:Age"<<endl<<"3:gender(M/F)"<<endl<<"4:Batch"<<endl;
        for(int i =0,j=1;i<n;++i,++j){
            cout<<"Record"<<j<<endl;
            cin>>s[i].name;
            cin>>s[i].age;
            cin>>s[i].gender;
            cin>>s[i].batch;
            ifile.write((char*)&s[i], sizeof(student));
        } 
    }
    ifile.close();
}

void display(const int n){
    cout<<" 1:Name"<<"  2:Age"<< " 3:gender(M/F)"<<" 4:Batch"<<endl; 
    student *a; 
    fstream ofile;
    ofile.open("student_data.dat", ios::binary);
    if(ofile){ 
        for(int i =0,j=1;i<n;++i,++j){        
            ofile.read((char*)&a[i],sizeof (student));
            cout<<" "<<a[i].name<<"    "<<a[i].age<<"    "<<a[i].gender<<"             "<<a[i].batch<<endl;
        }
    }
    ofile.close();
}

int main(){
    int n;
    read(n);
    display(n);
}

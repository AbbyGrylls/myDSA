#include<fstream>
#include<iostream>
#include<algorithm>
#include<string>
#include<array>
#include<istream> 
using namespace std;
#define MAX_STUDENTS 10

struct student//struture is kinda varible with a user defined datatype and that contains many other basic variables.
{
    string name;// do not confuse with c-type declation of char array with string declarion,if not getline function..
    int roll;//causes a problem->a compiler error or bug causes infinite iterations.
    string teleph;
    string adrs;
    student() : name(""), roll(0), teleph(""), adrs("") {};//student() is a cnstr assigned to the student struct,
    //intiliases mem varibles to default values- DEFAULT CONSTRUCTOR
};
struct sreg{
    int count=0;
    struct student s[MAX_STUDENTS];
};
int add(sreg &sr, const student &s) {
    if (sr.count >= MAX_STUDENTS) return 0;
    for (int i=0;i<sr.count;++i){// loop to check duplicates of roll no.
        if (sr.s[i].roll==s.roll){
            return 0;//lambda equations would of good use here if know them.
        }
    }
    sr.s[sr.count]=s;//adds student data in s array at index of the count using sr structure
    sr.count++;
    return 1;
}
student get(sreg &sr, int r) {
    for (int i=0;i<sr.count;++i){
        if(sr.s[i].roll==r){
            return sr.s[i];// if given roll matches, function returns the data of that students,
        }//as the func returns a structure of data, so its return data type should of that struct. same as void for cout.
    }
    return student();//if no match, return the D-constuctor.
    //return {"",0,"",""};
}
int deletestud(sreg &sr,int r){
    int p=-1;//used to store the index of the matched roll in s-array
    for(int i=0;i<sr.count;i++){
        if(sr.s[i].roll==r){
            p=i;//store the value of index i in p and breaks the loop,leaving remaining terms untouched 
            break;//so basically deletes the element on that position-creates a void gap at that index
        }
    }
    if(p==-1){
        return 0;
    }
    for(int i=p;i<sr.count-1;i++){
        sr.s[i]=sr.s[i+1];//sarting from p index, shits every student data to left
    }
    sr.count--;
    return -1;//function basically returns a value when called but in main it means to stop.
}
int modify(sreg &sr,int r){
    student s=get(sr,r);
    if(s.roll==0){
        return 0;
    }
    int choice;
    do{
        cout<<"which fields is to modify :\n1) name\n2) roll no\n3) telephone\n4) address\n5) exit";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1:
            cout<<"enter new name:";
            getline(cin,s.name);
            cin.ignore();
            break;
            case 2:
            cout<<"ente new roll number:";
            cin>>s.roll;
            break;
            case 3:
            cout<<"enter new telephone: ";
            getline(cin,s.teleph);
            cin.ignore();
            break;
            case 4:
            cout<<"enter new address:";
            getline(cin,s.adrs);
            cin.ignore();
            break;
            case 5:
            cout<<"modifications saved:";
            break;
            default :
            cout<<"invalid coice:"<<endl;
        }
    }while(choice!=5);
    for(int i=0;i<sr.count;i++){
        if(sr.s[i].roll==r){
            sr.s[i]=s;
            return 1;
        }
    }
    return 0;
}
void sort(sreg &sr){//dont confuse with c style char array,in c++ strings have inbuild function that modifies "<" operator,
    for(int i=0;i<sr.count-1;i++){//we already know this-- "operator overloading". this makes string compare lexicogrphically. its build in c++ string library.
        for(int j=0;j<sr.count-i-1;j++){//for c- it is strcmp function a build in function for string library
            if(sr.s[j].name>sr.s[j+1].name){
                student temp =sr.s[j];
                sr.s[j]=sr.s[j+1];
                sr.s[j+1]=temp;
            }
        }
    }
}
int counting(sreg &sr){
    cout<<"number of existing students in the list are: "<<sr.count<<endl;
    return 0;
}
void getreg(sreg &sr){
    for(int i=0;i<sr.count;i++){
        cout<<"Name: "<<sr.s[i].name<<endl<<"Roll: "<<sr.s[i].roll<<endl<<"Telephone: "<<sr.s[i].teleph<<"Address: "<<endl<<sr.s[i].adrs<<endl;
    }
}
void importData(sreg &sr, const string &filename) {
    ifstream file(filename); // Open a file for reading
    if (file.is_open()) {
        file >> sr.count; // Read the number of students
        file.ignore(); // Ignore the newline character after the count
        for (int i = 0; i < sr.count; ++i) {
            string label;
            getline(file,label);
            //file.ignore();
            getline(file, sr.s[i].name);// Read each student's name
            getline(file,label);
            //file.ignore(); 
            file >> sr.s[i].roll; // Read each student's roll number
            file.ignore(); // Ignore the newline character after the roll number
            getline(file,label);
            //file.ignore();
            getline(file, sr.s[i].teleph); // Read each student's telephone number
            getline(file,label);
            //file.ignore();
            getline(file, sr.s[i].adrs); // Read each student's address
        }
        file.close(); // Close the file
        cout << "Data imported successfully from " << filename << ".\n";
    } else {
        cout << "Unable to open file for reading.\n";
    }
}
void exportData(const sreg &sr, const string &filename) {
    ofstream file(filename); // Open a file for writing
    if (file.is_open()) {
        file << sr.count << endl; // Write the number of students
        for (int i = 0; i < sr.count; ++i) {
            file<<"Name:  " << sr.s[i].name << endl; // Write each student's name
            file<<"Roll number: " << sr.s[i].roll << endl; // Write each student's roll number
            file<<"telephone number: " << sr.s[i].teleph << endl; // Write each student's telephone number
            file<<"Address: " << sr.s[i].adrs << endl; // Write each student's address
        }
        file.close(); // Close the file
        cout << "Data exported successfully to " << filename << ".\n";
    } else {
        cout << "Unable to open file for writing.\n";
    }
}
int main() {
    sreg sr;//initialses sr,student regester
    sr.count = 0;
    int choice;
    
    do {//do-while loop is used to display the menu to process the user input till user chooses to exit 
        cout << "1. Add Student\n2. Delete Student\n3. Get Student\n5. Exit\n4. modify student\n6. sort alphabetically\n7. total students count\n8. Student data list\n9 export data\n10 import data\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character left in the buffer

        if (choice == 1) {
            student s;//initiallises student struct with ref as s
            cout << "Enter name (Last, First): ";
            getline(cin, s.name);//used when a string is the datatype of the varible,should contain cin and var name
            cout << "Enter roll number: ";
            cin >> s.roll;
            cin.ignore();
            cout << "Enter telephone: ";
            getline(cin, s.teleph);
            cout << "Enter address: ";
            getline(cin, s.adrs);
            if (add(sr, s)) {
                cout << "Student added successfully.\n";
            } else {
                cout << "Failed to add student. Roll number might already exist or register is full.\n";
            }
        } else if (choice == 2) {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;
            if (deletestud(sr, roll)) {
                cout << "Student deleted successfully.\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 3) {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;
            student s = get(sr, roll);//the result of the get functution will be assigned to s varible of type student(struct)
            if (s.roll != 0) {
                cout << "Student found: \n" <<"Name: "<< s.name <<endl<< "Telephone number: " << s.teleph << "\n " <<"Address: "<< s.adrs << "\n";
            } else {
                cout << "Student not found.\n";
            }
        }
        else if(choice==4){
            int roll;
            cout<<"enter roll number of student to modify data:";
            cin>>roll;
            student s;
            if(modify(sr,roll)){
                cout<<"student data modified successully:";
            }
            else{
                cout<<"student not found\n"<<endl;
            }
        }
        else if(choice==6){
            sort(sr);
            cout<<"sorted successfully\n";
        }
        else if(choice==7){
            counting(sr);
        }
        else if(choice==8){
            cout<<"students data:"<<endl;
            getreg(sr);
        }
        else if(choice==9){
            //ofstream 
            exportData(sr,"StudentData.txt");
        }
        else if(choice==10){
            importData(sr,"StudentData.txt");
        }
    } while (choice != 5);
    return 0;
}
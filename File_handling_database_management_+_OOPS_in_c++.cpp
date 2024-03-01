#include<iostream>
#include<fstream>
using namespace std;

int ID=0;///global variable, it will be ID of last student(value in ID.txt)

//OOPs
class Student{

    public:
        int id;
        string name;
        int age;
        string stream;

        void addStudent(){ 
            // object is already created and will call this function with it so implicitly the value can be accessed
            ID++;  //after fetching ID of last student our new ID will be 1+previous
            id = ID;
            cout << "Enter Name\n";
            cin>> name;

            cout << "Enter age\n";
            cin >> age;

            cout << "Enter stream\n";
            cin >> stream;

            //adding these details into file
            ofstream fout;
             fout.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt", ios::app);  // in append mode
            if(!fout){
                 cout << "File Not created/found";
            }else {
                
            fout<<id;  // value stored in MEMBER VARIABLE to copy into file 
            fout<<"\n"<<name;
            fout<<"\n"<<age;
            fout<<"\n"<<stream;
            fout << "\n";
            fout << "\n"; // new line before entry start, bydefault file pointer will be at end
            }

            fout.close();

            fout.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/ID.txt", ios::app);
            // enter last id in ID.txt as well
            fout<<id;
            fout << "\n";
            fout.close();

            cout << "    Record added\n\n";
        }

        void printAllStudent(){
            ifstream fin; // to read
            fin.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt");
            
            if(!fin){
            cout << "File Not present  !!!";
            }else {

                cout << "ID   Name   Age   Stream\n";
                while(!fin.eof())
                {
                    string line;
                    int count = 0;
                    while(count!=5){
                        count++;
                        getline(fin, line);
                        cout << line<< "    ";
                       
                    }
                cout << "\n";
                }
            }

            fin.close();
        }

        void searchStudent(int id)
        {
            ifstream fin;
            fin.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt");

            Student s; // object of Student is created, will act as container 
            int present=0;
            while(!fin.eof())
                {
                    // reading from file and storing into memeber variables
                    fin >> s.id;
                    fin.ignore(); // clean input buffer if it contain \n
                    getline(fin, s.name);
                    fin >> s.age;
                    fin>> s.stream;

                    if(s.id==id){
                        cout << " \nID = " << s.id;
                        cout << " \nName = " << s.name;
                        cout << " \nAge = " << s.age;
                        cout << " \nStream = " << s.stream<< "\n";
                        present = 1;
                        break; //so as to move out of while loop as well
                    }
                }
                if (present ==0){
                    cout << " No Student with this id !!!" <<" \n";
                }
        }
     

        void deleteStudent(int id)
        {
            
            ifstream fin;
            fin.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt");

            ofstream fout; //creating temporary file where we will copy(write)
            fout.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/temp.txt");

            Student s; // object of Student is created

            while (!fin.eof() )
            {
                fin >> s.id;
                fin >> s.name;
                fin >> s.age;
                fin >> s.stream;

                if(s.id != id  && s.id <= ID){  //writing into temp file by fout object
                    // && (s.id < ID) is checked so that "\n" at the end should not create any problem
                    fout<<s.id;
                    fout<<"\n"<<s.name;
                    fout<<"\n"<<s.age;
                    fout<<"\n"<<s.stream;
                    fout << "\n";
                    fout << "\n";

                    s.id = s.id + 1;
                    }
            }// all student details copied to temp file except one whose id matches with given id
            fin.close();
            fout.close();

            // deleting old  student file
            remove("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt");

            // rename temp file to Student.txt
            rename("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/temp.txt", "D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt");


            cout << "Record deleted successfully \n";
        }

       
        void updateStudent(int id){
            // we will first delete that student whole detail then add that student whole new detail on same id
            deleteStudent(id);
            // this approach is to be used even if we are to delete only particular member variable value
            //  because if our new value is big and need to be added on next line, shifting not possible
            //  manually asking that student information again, , will not use addStudent() function as it automatically generate id
            Student s;
            cout << "- Again enter the whole record of student\n";
            cout << "Enter Name\n";
            cin>> s.name;

            cout << "Enter age\n";
            cin >> s.age;

            cout << "Enter stream\n";
            cin >> s.stream;

            ofstream fout;
            fout.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/Student.txt", ios::app);
            
            if(!fout){
                 cout << "File Not created/found";
            }else {
                
            fout<<id;
            fout<<"\n"<<s.name;
            fout<<"\n"<<s.age;
            fout<<"\n"<<s.stream;
            fout << "\n";
            fout << "\n";
            }
            fout.close();

            cout << "Record updated successfully \n";
        }
};

int main()
{
    int choice;
    int id;
 
 //first getting to know about last id in ID.txt file
    ifstream fin; // to read 
    fin.open("D:/My C coding/Project2_File_handling(database management)_+_OOPS_in_c++/ID.txt");

    
    if(!fin){
        cout << "File Not created/found";
    }else { // will need to reach end of file
       // fin.seekg(0, ios_base::end);
       
       while(!fin.eof() ){ // until we reach end of file
           fin >> ID;  // value will be stored into ID global variable one by one , 
           //at last it will contain last id value
       
       }
       fin.close();
    }
    // id is initialized, and now it contains last value of ID in ID.txt file

    

    while (true)
    {
        cout << "===============================================\n ";
        cout << "Enter choice\n";
        cout << "1. Add Student \n";
        cout << "2. Print all students \n";
        cout << "3. Search a student detail \n";
        cout << "4. Delete a student detail\n";
        cout << "5. Update a student detail\n";
        cin >> choice; // taking input
        cout << "\n";

        Student s; // object os class created
        // this object acts as container and data from member variables is to be stored into file
        //  or read data from file and store it into object member variables

        switch (choice)
        {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.printAllStudent();
            break;
        case 3:
            cout << "Enter student id to search\n";
            cin >> id;
            s.searchStudent(id);
            break;
        case 4:
            cout << "Enter student id to delete\n";
            cin >> id;
            s.deleteStudent(id);
            break;
        case 5:
            cout << "Enter student id to update\n";
            cin >> id;
            s.updateStudent(id);
            break;
        default:
            cout << "Invalid input";
            return 0;
            break;
    }
    }

    return 0;
}
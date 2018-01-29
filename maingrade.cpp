#include <iostream>  

#include <fstream>  

#include <cstring>  

#include <iomanip>  

#include <string>

#include "studentlist.h"

using namespace std;  



const int maxSize = 20; 

const int nameLength = student::nameLength;

const int idLength = student::idLength;

studentList studList(10); 

ofstream outfile;  

ifstream infile;    

char input_file_name[21], output_file_name[21], name[nameLength+1]; 

string id;  

  



void menu()

{

        cout<<"Enter the follwing integer to display the following options:"<<endl;

        cout<<"Enter A or a to display the student list."<<endl;

        cout<<"Enter B or b to display the current scores."<<endl;

        cout<<"Enter C or c to process the scores."<<endl;

        cout<<"Enter D or d to search student's name or ID."<<endl;

        cout<<"Enter E or e to add a new student to the list."<<endl;

        cout<<"Enter F or f to change a student's test score."<<endl;

        cout<<"Enter G or g to change a student's homework score."<<endl;

        cout<<"Enter H or h to display and print the grades."<<endl;

        cout<<"Enter I or i to display this menu."<<endl;

        cout<<"Enter J or j to save and exit."<<endl;

}



void loadstudent()

{

        student stud_temp;

        float Homework[10];

        float Participation;

        float Test [4];

        

        cout << "Please enter name of the data file:  ";  

        cin >> input_file_name;  

        infile.open(input_file_name);  

        if ( !infile)  

    {   

                cout << "Could not open input file \n";  

                infile.close();  

                infile.clear();  

                return;  

    }  

        

        infile >> name; 

        stud_temp.setName(name);  

        

        while(!infile.eof()) 

        {

                infile >> id; 

                stud_temp.setID(id);   

                for (int i =0; i < 10; i++)

                { 

                        infile >> Homework[i];

                        stud_temp.setHomework(Homework);

                }

                

                for (int i =0; i < 4; i++)

                {

                        infile >> Test[i];

                        stud_temp.setTest (Test);

                }



                studList.addStudent(stud_temp);

                infile >> name; 

                stud_temp.setName(name);     

        }

        infile.close();  

        infile.clear(); 

}

void loadscores()

{

        studList.writeData(cout);

}

void processscores()

{

        studList.processGrade();

}

void searchstudent()

{

        char c; int i; 

        

        cout << "Please enter 0 to search by name and anything else to search by id: ";

        cin >> c;

        if((c == '0'))

    {

                cout << "Please enter name of the person: ";

                cin >> name;

                i = studList.searchName(name);

    }

        else

    {

                cout << "Please enter id of the person: ";

                cin >> id;

                i = studList.searchID(id);

    }

        if (i!= -1)

    studList.getStudent(i).printstudent(cout);

        else

    cout << "Sorry, the student could not be found \n";

        

}

void addstudent()

{

        student s_temp;  

        float homework[10];

        float test[4];

        

  

        cout << "Please enter name of the person: ";  

        cin >> name; 

        s_temp.setName(name);

        

        cout << "Please enter id of the person:  ";  

        cin >> id; 

        s_temp.setID(id);  

        

        cout << "Please input homework scores (10 numbers): \n ";

                for (int i =0; i < 10; i++)

                { 

                        cin >> homework[i];

                        s_temp.setHomework(homework);

                };

        

        cout << "Please input test scores (4 numbers):  \n "; 

                for (int i =0; i < 4; i++)

                {

                        cin >> test[i];

                        s_temp.setTest (test);

                }

         

        if (studList.addStudent(s_temp))

                cout << "Successfully added student. \n";

        else

                cout << "Sorry, the student could not be added. \n"; 

}

void changetest()

{

        int i; 

        int score;

        int a;

        cout << "Please enter id of the person: ";

        cin >> id;

        i = studList.searchID(id);

        if ( i!= -1)    

        {      

                cout<<"Enter which test score you want to change (Enter 0-3): ";

                cin>> a;

                

                cout<<"Enter the score: ";

                cin>> score;

                

                (studList.getStudent(i)).changeTest(score,a);

        }

        else  

        cout << "Sorry, there is no such student \n";   

        

}

void changehomework()

{

        int i; float score;  

        int a; 

        cout << "Please enter id of the person: ";

        cin >> id;

        i = studList.searchID(id);

        if ( i!= -1)    

        {      

                cout << "Please enter which homework score you want to change (Enter 0-9): ";

                cin >> a;

                

                cout << "Please enter a new homework score: ";

                cin >> score;  



                (studList.getStudent(i)).changeHomework(score,a); 

        }

        else  

        cout << "Sorry, there is no such student \n";   

}



void printgrade()

{       

        studList.printstudent(cout);

        cout << "Please enter name of output file: ";

        cin >> output_file_name;

        outfile.open(output_file_name);

        studList.printstudent(outfile);

        outfile.close();

        outfile.clear();

}

void saveinfo()

{

        cout << "Please enter name of the new data file: ";  

        cin >> output_file_name;  

        outfile.open(output_file_name);  

        if ( !outfile)  

    {   

      cout << "Could not open file \n";  

      outfile.close();  

      outfile.clear();  

      return;  

    }  

  studList.printstudent(outfile);

  outfile.close();

  outfile.clear();

}



int main()  

{  

  

  char choice;  

  

  menu();  

  cout << "Please indicate your choice of operation (I or i for menu): ";  

  cin >> choice;  

  

  while ((choice != 'J')&& (choice != 'j'))  

    {  

      switch(choice)  

        {  

        case 'a':  

        case 'A': loadstudent(); break;  

    case 'b':

        case 'B': loadscores(); break;

        case 'c':  

        case 'C': processscores();break;  

        case 'd':  

        case 'D': searchstudent();break;  

        case 'e':  

        case 'E': addstudent();break;  

        case 'f':  

        case 'F': changetest();break;  

        case 'g':  

        case 'G': changehomework();break;  

        case 'h':

        case 'H': printgrade();break;

        case 'i':

        case 'I': menu(); break;

        default : cout << "Not a valid choice" << endl;  

        }  

      cin.ignore(200, '\n'); cin.clear(); //clear out all input  

      cout << "Please indicate your choice of operation (I or i for menu): ";  

      cin >> choice;  

    }  

  saveinfo();  

  cout << "The program have ended.\n";  

}

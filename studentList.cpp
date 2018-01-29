#include <iostream>

#include <fstream>

#include <cstring>

#include <iomanip>

#include "student.h"

#include "studentlist.h"

#include<vector>

using namespace std;



bool studentList::addStudent(student stud)

{

        if ((studList.size())>= maxsize)

        {

                return false;

        }

        

        studList.push_back(stud);

        return true;

}



void studentList::writeData(ostream& outfile)

{

        for (unsigned int index =0; index < studList.size(); index++)

        {

                (studList.at(index)).writestudent(outfile);

                outfile<<endl;

                

        }

}



void studentList::processGrade()

{

        for(unsigned int index = 0; index < studList.size(); index++)  

        {

                (studList.at(index)).processStudent();

        }

}



void studentList::printstudent(ostream& outfile)

{

  for(unsigned int index = 0; index < studList.size(); index++)

  {  

   (studList.at(index)).printstudent(outfile);

  }

}



student& studentList::getStudent(int i)

{ 

  return studList.at(i);

}



int studentList::searchName(char name[])

{

        for (unsigned int index = 0; index < studList.size(); index++)    

    { 

        if (strcmp(name, (studList.at(index)).getName()) == 0)

                return index;    

    }

  return -1;

}



int studentList::searchID(string ID)

{

        for (unsigned int index = 0; index < studList.size(); index++)

    {

                if ((studList.at(index)).getid() == ID)

                return index;

    }

        return -1;

}

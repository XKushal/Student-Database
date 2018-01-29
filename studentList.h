#include <fstream>

#include <iostream>

#include <cstring>

#include <vector>

#include <iomanip>

#include "student.h"

#ifndef STUDENTLIST

#define STUDENTLIST

using namespace std;



class studentList

{

        private:

        unsigned int maxsize;

        int nameLength;

        int idlength;

        vector<student> studList;

        

        public:

        

        studentList( unsigned int size = 0)

        {

                maxsize = size;

                nameLength = student::nameLength;

        }

        

        bool addStudent(student);

        void writeData(ostream& outfile);

        void processGrade();

        void printstudent(ostream& outfile);

        student& getStudent(int i);

        int searchName(char name[]);

        int searchID(string ID);

        

};

#endif

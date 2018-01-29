#include <iostream>  

#include <fstream>  

#include <cstring>  

#include <string> 

#include <iomanip> 

#ifndef STUDENT

#define STUDENT 

using namespace std;



class student

{       

        public:

  

        const static int nameLength = 20;   

        const static int idLength = 9; 

        const static int HworkLength = 10;

        const static int TestLength = 4;

        int count;

        int Hwork;

        float test;

        float HworkScores;

        float TestScores;

        

        private:

        char name[nameLength];  

        string id;

        float Hworked[HworkLength];

        float H_total;

        float Tworked[TestLength]; 

        float T_total;

        float Participation;

        float Total;

        char Grade;

        float HworkTotal; 

        float TestTotal; 

        float HworkFinal; 

        float TestFinal;

        float H_work;

        float Test;

        float Lowhworkscore;

        float FinalTest;

        

        

        public:

        

        void computescores(float Hwork, float Test)

        {

                HworkTotal = (Hwork*0.10);

                HworkFinal = HworkTotal*0.5;

                

                TestTotal = Test*0.25;

                TestFinal = TestTotal*0.5;

                

                Total = HworkFinal + TestFinal;

        }       

        

        void computegrade()

        {

                

                if (Total< 0 || Total > 100)

                {

                        Grade = 'Z';

                }

                

                else if (Total < 60)

                {

                        Grade = 'F';

                }

                

                else if (Total < 70)

                {

                        Grade = 'D';

                }

                

                else if (Total < 80)

                {

                        Grade = 'C';

                }

                

                else if (Total < 90)

                {

                        Grade = 'B';

                }

                

                else 

                {

                        Grade = 'A';

                }

        }

        

        void setName(char n[])

        {

                strcpy(name, n);

        }

        

        void setID(string n)

        {

                id = n;

        }

        

        void setHomework (float Homework[])

        {

                for(int i=0; i< 10; i++)

                {

                        Hworked[i]=Homework[i];

                }

        }

        

        void setParticipation (float Part)

        {

                Participation = Part;

        }

        

        void setTest(float Test[]) 

        {

                

                for(int i=0; i <4; i++)

                {

                        Tworked[i] = Test[i];

                }

        }

        

        void changeTest(float Tscore, int i)

        {

                Tworked[i] = Tscore;

        }

        

        void changeHomework (float Hscore, int i)

        {

                Hworked[i] = Hscore;

        }

        

        void setTotal (float total)

        {

                Total = total;

        }

        

        void setGrade(char grade)

        {

                Grade = grade;

                

        }

        

        char* getName()

        {

                return name;

        }

        

        string getid ()

        {

                return id;

        }

        

        float getTotal()

        {

                return Total;

        }

        

        char getGrade()

        {

                return Grade;

        }

        

        void processStudent()

        {

                float Hwork = 0;

                float Findlow = 0;

                float Lowhworkscore = 0;

                float Test = 0;

                bool error = false; 

                

                for (int i=0; i < 10; i++)

                {

                        Hwork += Hworked[i];

                        if ((Hworked[i] < 0) || (Hworked[i] > 100))

                        {

                                error = true;

                        }

        

                }

                

                for (int i=0; i < 4; i++)

                {

                        Test += Tworked[i];

                        if ((Tworked[i] < 0) || (Tworked[i] > 100))

                        {

                        error = true;

                        }

                }

                

        if (error) 

                {

                        Hwork = -1;

                        Test = -1;

                }

                

                computescores(Hwork, Test);

                computegrade ();

                

                

                

        }

        

        void writestudent(ostream& outfile)

        {

                int i =0;

                char space = ' ';

                outfile << name << space << id <<space;

                outfile << endl;

                for (int i = 0; i < 10; i++)

        outfile << Hworked[i] << space;

                outfile << endl;

                for (int i = 0; i < 4; i++)

                outfile << Tworked[i] << space;

                outfile << endl;



        }

        

        void printstudent(ostream & outfile)

        {

                outfile <<"Name: "<<  name << endl  

                                <<"Id: "<<  id << endl   

                                <<"Total Homework Score: " << HworkTotal << endl  

                                <<"Total Test Scores: " << TestTotal << endl 

                                <<"Total: "<< Total << endl

                                <<"Grade: "<< Grade << endl

                                <<" "<< endl;

                                        

        }

};

#include <iostream>
#include <cmath>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
//#include "Course.cpp"

using namespace std;


void endline();
int endword();
void addtobuffer(char letter);
int Student(string studentID, string studentName);

string studpass;
string studid;
string courses[4];

int credithours;
float studavg;
int courseindex=0;
char str[30] = {0};
int strsize=0;

string Course1;
string Course2;
string Course3;
string Course4;

string desiredstud = "Harry Potts"; // SAMPLE


/* 
Students
Weiss Adams;45033;MAC2313;HUM2305;COP3530;MAC3473;56;83.01
Emile Airn;34215;PHY2048;CHM2046;MAC3473;ENG2300;48;76.64
Christine Alpine;34151;PHY2048;CHM2046;COP3530;MAC3473;52;84.21
Professors
*/

bool stud = false;				// GLOBAL Variables.
bool usernamedone = false;
bool credithrdone = false;
bool done = false;

int main()
{
	ifstream textfile("mainlist.txt");
	if (!textfile)
	{
	cout << "Error in opening file, check file name and its presence in directory";
	return 0;
	}
	string s;
	char c;
	while(getline(textfile, s)) // Read each character one at a time (to account for no spaces).
	{
		string temp = s;
		
		// cout << temp << endl;
  
		if(temp=="Professors")
			break;
		if(stud)
		{
			
			for(int i=0; i<s.size();i++)
			{
			 	c = s[i];
				if(c==';')
				{
					endword();
				}
				else 
				{
					addtobuffer(c);
				}
				if(i==(s.size()-1)) 				//last run of loop
				{
					endword();
					courseindex=0;
				}
			}
			
			if(studpass==desiredstud)
				break;
			
			
		}

		if(temp=="Students")
			stud= true;
	
	}

	cout << "end results: " << studid << " " << studpass << " " << "their four courses " << courses[0] << " " << courses[1] << " " << courses[2] << " " << courses[3] << " " << credithours << " " << studavg << endl;

	// CREATE YOUR STUDENT OBJECT HERE NOW.
	Course1 = courses[0]; 
	Course2 = courses[1];
	Course3 = courses[2];
	Course4 = courses[3];
	
	Student(studpass, studid);
	
	
}

void addtobuffer(char letter)
{
	
	str [strsize] = letter;
	strsize++;	

}


int endword()
{
		bool alpha = false;
		bool numpres = false; 
		for(int i = 0; i<=strsize; i++)	
		{
			if(int(str[i])>47 && int(str[i])<58) 
			{
				numpres = true;								
			}
			if((int(str[i])>64 && int(str[i])<91) || (int(str[i])>96 && int(str[i])<123)) 		
			{
				alpha = true;
			}
			
		}
		if(alpha && !numpres)
		{
			studpass = string(str);
		 //	cout << "this is the password " << studpass << endl;
			
		}
		else if(numpres && !alpha)
		{
			if(!usernamedone && !credithrdone)
			{
				studid = string(str);
			//	cout << "this is the username " << studid << endl;
				usernamedone = true;
			}
			else if(usernamedone && !credithrdone)
			{
				credithours = atoi(string(str).c_str());
			//	cout << "this is the credit hour number " << credithours << endl;
				credithrdone = true;
			}
			else if(usernamedone && credithrdone)
			{
				studavg = atof(string(str).c_str());
			//	cout << "this is the student's average " << studavg << endl; 
				usernamedone = false;
				credithrdone = false;
			}
		}
		else if(alpha && numpres)
		{
			courses[courseindex] = string(str);
			// cout << "this is a course "  << courses[courseindex] ;	
			courseindex++;
			// cout << " (number " << courseindex << ")" << endl;	
		}
		else
		{ 
			cout << "uncategorizable error" << endl; 
		}
		for(int i=0; i<=19; i++)				// Empty the char array.
		{
			str[i]=0;
		}
		strsize=0;	
		
		return 0;			

}

//void StringAlerts(string)
//call Course studentViewGrades
// Course studentGrade
//2.0 GPA Probation	
//Below a C, failing this course
//

//void CalcSemGPA(int[] courseID)
//{
	
//}
void StringAlerts(float semesterGPA)
{
	if (semesterGPA <= 2.0)
	{
		cout<< " _____________________________________________________________\n";
		cout<< "|                                                             |\n";
		cout<< "|                                                             |\n";
		cout<< "|              WARNING YOU ARE CURRENTLY FAILING              |\n";
		cout<< "|                                                             |\n";
		cout<< "|_____________________________________________________________|\n";
	}
	else 
	{
		cout << "There are no alerts right now. \n";
	}
		
}

int validation(int last)
{
	int n; std::cin >> n;
	bool valid = false;
	while (!valid)
	{
		if (n<=last && n>=1)
		{
			valid = true;
		}
		else
		{
			if (!std::cin) //prevents char from breaking code
			{
				std::cin.clear();
				std::cin.ignore();
				/*With multiple char the err message repeats
				But will still run code*/
			}
			std::cout << "\n Please input a valid option: ";
			std::cin >> n;
	}
	}
	return n;
}

	
	int choice1; 
	int choice2;
	int choice3;
	int choice4;
	
	int semesterGPA;
	int totalGPA;
int Student(string studentID, string studentName)
{
	
	MainMenu:
	
	for (int i = 0; i >= 0; i++) //Main menu
	{
	cout << "Welcome. What would you like to do today? \n" << "1. View Course Grade \n" << "2. View GPA \n" << "3. Manage Alerts \n" << "4. Logout \n";
	
	choice1 = validation(4);

	
	
	switch(choice1)
	{
		case 1: //Menu Option 1: View Course Grade
		for (int j = 0; j >= 0; j++)
		{
			cout << "Select your course: \n" << "1. " << Course1 << "\n" << "2. " << Course2 << "\n" << "3. " << Course3 << "\n" << Course4 << "\n" << "5. Exit \n";

			choice2 = validation(5);
	
			
			switch(choice2)
			{
				case 1:
				
				cout << "Your grade in " << Course1 << " is: "  << " \n" ;
				
				break;
				
				case 2:
				
				cout << "Your grade in " << Course2 << " is: " << " \n";
				
				break;
				
				case 3:
				
				cout << "Your grade in " << Course3 << " is: " << " \n";
			
				break;
				
				case 4:
				
				cout << "Your grade in " << Course4 << " is: " << " \n";
				
				break;
				
				case 5:
				goto MainMenu;
				break;
				
			}
		}

		break;
		
		
		case 2: //Menu Option: View GPA
		for (int k = 0; k >= 0; k++)
		{
		cout << "Would you like to check your: \n" << "1. Semester GPA \n" << "2. Total GPA \n" <<"3. Return to Main Menu \n";
		choice3 = validation(3);
		
		
		switch(choice3) //Sub Menu Option: Selected either Semester GPA or Total GPA
		{
			case 1:
			
			cout << "Your Semester GPA is: " << semesterGPA << " \n" ;
			
			break;
			
			case 2:
			
			cout << "Your Total GPA is: " << totalGPA << " \n";
			break;
			
			case 3:
		
			goto MainMenu;
			
			default:
			cout << "\n";
			cout << "Please select an option from the menu. \n";
		}
	}
		break;
		
		case 3:   //Menu Option: Manage Alerts
		for (int l = 0; l >= 0 ; l++)
		{
			cout << "Would you like to: \n" << "1. Display Alerts \n" << "2. Delete Alerts \n" << "3. Return to Main Menu \n";
			choice4 = validation(3);
			
			switch(choice4)
			{
				case 1:
				float choice5; 
				cin >> choice5;
				StringAlerts(choice5);
				
				break;
				
				case 2:
				
				break;
				
				case 3:
				
				goto MainMenu;
				
				break;
			}
				
		}
		break;
		
	
		
		case 4: //Menu Option: Logout back into the Login Screen
		cout << "Goodbye and have a wonderful day \n";
		//menu();
		return 0;
		break;
		
		default:
		cout << "\n";
		cout << "Please select an option from the menu \n";
		break;
	
}
}
	
}





//Student //all methods private except menu
//int menu() //First pick course, then pick option
//int CalcSemGPA(int[] courseID)
//int CalcTotalGPA(int points, int hours, int[] courseID)
//void ViewGrades(int courseID) /*will access multidimensional array/vector/linkedlist and display student’s grades*/
//void ViewAlerts(void) //String[] Alerts will be in outer menu

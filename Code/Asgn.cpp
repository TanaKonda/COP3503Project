#include "Asgn.h"
#include <iostream>
#include <limits>
// assignment class methods
// constructor
Asgn::Asgn(std::string nm, std::string tp, int pt, std::string dt, std::vector<std::string> st, std::vector<int> grds){ // how should students be loaded? (Passed or from file?)
	this->name = nm;
	this->type = tp;
	this->points = pt;
	this->duedate = dt;
	this->students = st;
	this->grades = grds;
}
// public method for adding grades to list
void Asgn::pushGrade(double grade){
	// load from file
	grades.push_back(grade);
	
}
// assign grades for all students for this assignemnt
void Asgn::gradeAsgn(std::string nm){
	for(int i = 0; i < students.size(); i++){
		// display current student and grade
		std::cout << "Student: " << students[i] << ", Current Grade: ";
		if(grades[i] == -1){ // -1 indicates no existing grade
			std::cout << "None\n";
		}else{
			std::cout << grades[i] << "\n";
		}
		bool valid = false;
		int grd;
		// new grade inputed, validity checked
		while(!valid){
			std::cout << "Enter grade (-1 for no grade, -2 to exit): ";
			std::cin >> grd;
			if ((grd < points || points!= 0) && grd >= -2)
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
				std::cout << "Invalid grade. Valid grade range for this assignment is 0 to " << points << ".\n"; 
				std::cin >> grd;
			}
		}
		// if user does not exit, replace old grade with new one
		if(grd != -2){
			grades[i] = grd;
			std::cout << "\n";
		}else{
			i = students.size();
		}
	}
}
// change grade for a single student
void Asgn::changeGrade(std::string nm, std::string stud){
	int stud_index = -1;
	int i = 0;
	int grd;
	// find student in student array
	while(i < students.size() && stud_index == -1){
		if(students[i].compare(stud) == 0){
			stud_index = i;
		}
		i++;
	}
	// produce error if student not found
	if(stud_index == -1){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Student not found. Press enter to return to main menu.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
	}else{
		std::cout << "Student: " << students[stud_index] << ", Current Grade: ";
		if(grades[stud_index] == -1){
			std::cout << "None\n";
		}else{
			std::cout << grades[stud_index] << "\n";
		}
		bool valid = false;
		while(!valid){
			std::cout << "Enter grade or -1 to exit : ";
			std::cin >> grd;
			if ((grd < points || points!= 0) && grd >= -1)
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
				std::cout << "Invalid grade. Valid grade range for this assignment is 0 to " << points << ".\n"; 
				std::cin >> grd;
			}
		}
		if(grd != -1){
			grades[stud_index] = grd;
		}
		else
		{
			std::cout << "Grade unchanged.";
		}
	}
}
void Asgn::studentViewGrades(int stud_index){
	std::cout << "Assignment: " << name << ", Grade: " << grades[stud_index] << "\n";
}
void Asgn::viewGrades(void){
	std::cout << "Grades for " << name << "\n";
	for(int i = 0; i < students.size(); i++){
		std::cout << "Student: " << students[i] << ", Grade: ";
			if(grades[i] == -1){
				std::cout << "None";
			}else{
				std::cout << grades[i];
			}
			std::cout << "\n";
	}
}
std::string Asgn::getName(){
	return name;
}
//gives assigment type
std::string Asgn::getType()
{
	return type;
}
// gives assigment points
int Asgn::getPoints()
{
	return points;
}
//gives assigment date
std::string Asgn::getDue()
{
	return duedate;
}
//gives grades 
std::vector<int> Asgn::getGrades()
{
	return grades;
}

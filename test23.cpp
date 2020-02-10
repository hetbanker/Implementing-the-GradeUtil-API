/*test01.cpp*/
//
// <<Het Banker>>
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #01: Grade Analysis
// 

// *****************************************************************
//
// Test cases:
// 
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

TEST_CASE( "Test 23", "[Project01]" ) 
{       
	//A B C D F I S U W NR 
	//Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
	Course bioA= ParseCourse("BIOE,101,01,Intro to Bioengineering,  22,8,2,1,0,1,0,0,0,5,Eddington");
	Course bioB= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,0,0,0,0,0,0,100,1,0,5,Het");
	Course bioC= ParseCourse("BIOE,103,03,Intro to Bioengineering 3,22,8,2,1,0,1,0,0,0,5,Ria");
	
	Course csA = ParseCourse("CS,101,04,Program Design,  22,8,2,1,0,0,0,0,0,5,Theys");
	Course csB = ParseCourse("CS,101,05,Data Structure,22,8,2,1,0,1,0,0,0,5,Hummel");
	Course csC = ParseCourse("CS,101,06,Intro to CS,22,8,2,1,0,1,0,0,0,5,Kev");
	
	College college("UIC");
	Dept bioDept("BIOE");
	Dept csDept("CS");
	
	bioDept.Courses.push_back(bioA);
	bioDept.Courses.push_back(bioB);
	bioDept.Courses.push_back(bioC);

	csDept.Courses.push_back(csA);
	csDept.Courses.push_back(csB);
	csDept.Courses.push_back(csC);
	
	college.Depts.push_back(bioDept);
	college.Depts.push_back(csDept);
	
	//Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
	vector<Course> findCourse= FindCourses(college,101);
	REQUIRE(findCourse.size()==4);
	REQUIRE(findCourse[0].Dept=="BIOE");
	REQUIRE(findCourse[1].Dept=="CS");
	REQUIRE(findCourse[0].Number==101);
	REQUIRE(findCourse[1].Number==101);
	REQUIRE(findCourse[2].Number==101);
	REQUIRE(findCourse[3].Number==101);
	//REQUIRE(findCourse[4].Number==102);
	REQUIRE(findCourse[0].Section==01);
	REQUIRE(findCourse[1].Section==04);
	REQUIRE(findCourse[2].Section==05);
	REQUIRE(findCourse[3].Section==06);
	REQUIRE(findCourse[0].Instructor=="Eddington");
	REQUIRE(findCourse[1].Instructor=="Theys");
	REQUIRE(findCourse[2].Instructor=="Hummel");
	REQUIRE(findCourse[3].Instructor=="Kev");
	REQUIRE(findCourse[0].Title=="Intro to Bioengineering");
	REQUIRE(findCourse[1].Title=="Program Design");
	REQUIRE(findCourse[2].Title=="Data Structure");
	REQUIRE(findCourse[3].Title=="Intro to CS");
	
}
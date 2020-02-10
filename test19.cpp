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

TEST_CASE( "Test 19", "[Project01]" ) 
{       
	//Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
	Course bioA= ParseCourse("BIOE,101,01,Intro to Bioengineering,  22,8,2,1,0,1,0,0,0,5,Eddington");
	Course bioB= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,0,0,0,0,0,0,100,1,0,5,Het");
	Course bioC= ParseCourse("BIOE,103,03,Intro to Bioengineering 3,22,8,2,1,0,1,0,0,0,5,Ria");
	
	Course csA = ParseCourse("CS,101,01,Program Design,  22,8,2,1,0,0,0,0,0,5,Theys");
	Course csB = ParseCourse("CS,101,02,Data Structure,22,8,2,1,0,1,0,0,0,5,Hummel");
	Course csC = ParseCourse("CS,101,03,Intro to CS,22,8,2,1,0,1,0,0,0,5,Kev");
	
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
	
	vector<Course> findCourse= FindCourses(csDept,101);
	REQUIRE(findCourse.size()==3);
	Course x= findCourse[0];
	Course y = findCourse[1];
	Course z = findCourse[2];
	REQUIRE(x.Title=="Program Design");
	REQUIRE(x.Section==01);
	REQUIRE(y.Title=="Data Structure");
	REQUIRE(z.Title=="Intro to CS");
	REQUIRE(x.Instructor=="Theys");
	REQUIRE(y.Instructor=="Hummel");
	REQUIRE(z.Instructor=="Kev");
	vector<Course> findCourse1= FindCourses(csDept,104);
	REQUIRE(findCourse1.size()==0);
}
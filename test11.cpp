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

TEST_CASE( "Test 11", "[Project01]" ) 
{
	Course bioA= ParseCourse("BIOE,101,01,Intro to Bioengineering,  22,8,2,1,0,1,0,0,0,5,Eddington");
	Course bioB= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,22,8,2,1,0,1,0,0,0,5,Het");
	Course bioC= ParseCourse("BIOE,103,03,Intro to Bioengineering 3,22,8,2,1,0,1,0,0,0,5,Raj");
	
	Course csA = ParseCourse("CS,101,01,Intro to CS,  22,8,2,1,0,1,0,0,0,5,Theys");
	Course csB = ParseCourse("CS,102,02,Intro to CS 2,22,8,2,1,0,1,0,0,0,5,Hummel");
	Course csC = ParseCourse("CS,103,03,Intro to CS 3,22,8,2,1,0,1,0,0,0,5,Sam");
	
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
	
	GradeStats scoreCollege = GetGradeDistribution(college);
	
	REQUIRE(scoreCollege.N==198);
  REQUIRE(scoreCollege.NumA == 132);
  REQUIRE(scoreCollege.NumB == 48);           
  REQUIRE(scoreCollege.NumC == 12);
  REQUIRE(scoreCollege.NumD == 6);
  REQUIRE(scoreCollege.NumF == 0);
	
	REQUIRE(Approx(scoreCollege.PercentA).epsilon(0.001)==66.6667);
	REQUIRE(Approx(scoreCollege.PercentB).epsilon(0.001)==24.2424);
	REQUIRE(Approx(scoreCollege.PercentC).epsilon(0.001)==6.06061);
	REQUIRE(Approx(scoreCollege.PercentD).epsilon(0.001)==3.0303);
	REQUIRE(Approx(scoreCollege.PercentF).epsilon(0.001)==0); 
  
}
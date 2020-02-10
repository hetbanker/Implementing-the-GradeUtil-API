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

TEST_CASE( "Test 10", "[Project01]" ) 
{
	Course bioA= ParseCourse("BIOE,101,01,Intro to Bioengineering,  22,8,2,1,0,1,0,0,0,5,Eddington");
	Course bioB= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,22,8,2,1,0,1,0,0,0,5,Het");
	 
	Course csA = ParseCourse("CS,101,01,Intro to CS,  22,8,2,1,0,1,0,0,0,5,Theys");
	Course csB = ParseCourse("CS,102,01,Intro to CS 2,22,8,2,1,0,1,0,0,0,5,Hummel");
	
	College college("UIC");
	Dept bioDept("BIOE");
	Dept csDept("CS");
	
	bioDept.Courses.push_back(bioA);
	bioDept.Courses.push_back(bioB);

	csDept.Courses.push_back(csA);
	csDept.Courses.push_back(csB);
	
	college.Depts.push_back(bioDept);
	college.Depts.push_back(csDept);
	
	GradeStats scoreCollege = GetGradeDistribution(college);
	
	REQUIRE(scoreCollege.N==132);
  REQUIRE(scoreCollege.NumA == 88);
  REQUIRE(scoreCollege.NumB == 32);           
  REQUIRE(scoreCollege.NumC == 8);
  REQUIRE(scoreCollege.NumD == 4);
  REQUIRE(scoreCollege.NumF == 0);
  
	
  REQUIRE(Approx(scoreCollege.PercentA).epsilon(0.001)==66.6667);
	REQUIRE(Approx(scoreCollege.PercentB).epsilon(0.001)==24.2424);
	REQUIRE(Approx(scoreCollege.PercentC).epsilon(0.001)==6.06061);
	REQUIRE(Approx(scoreCollege.PercentD).epsilon(0.001)==3.0303);
	REQUIRE(Approx(scoreCollege.PercentF).epsilon(0.001)==0); 
}


TEST_CASE( "Test 1001", "[Project01]" ) 
{
	Course bioA= ParseCourse("BIOE,101,01,Intro to Bioengineering,  0,0,0,0,0,0,0,0,0,0,Eddington");
	Course bioB= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,0,0,0,0,0,0,0,0,0,0,Het");
	 
	Course csA = ParseCourse("CS,101,01,Intro to CS,  0,0,0,0,0,0,0,0,0,0,Theys");
	Course csB = ParseCourse("CS,102,01,Intro to CS 2,0,0,0,0,0,0,0,0,0,0,Hummel");
	
	College college("UIC");
	Dept bioDept("BIOE");
	Dept csDept("CS");
	
	bioDept.Courses.push_back(bioA);
	bioDept.Courses.push_back(bioB);

	csDept.Courses.push_back(csA);
	csDept.Courses.push_back(csB);
	
	college.Depts.push_back(bioDept);
	college.Depts.push_back(csDept);
	
	GradeStats scoreCollege = GetGradeDistribution(college);
	
	REQUIRE(scoreCollege.N==0);
  REQUIRE(scoreCollege.NumA == 0);
  REQUIRE(scoreCollege.NumB == 0);           
  REQUIRE(scoreCollege.NumC == 0);
  REQUIRE(scoreCollege.NumD == 0);
  REQUIRE(scoreCollege.NumF == 0);
  
	
  REQUIRE(Approx(scoreCollege.PercentA).epsilon(0.001)==0);
	REQUIRE(Approx(scoreCollege.PercentB).epsilon(0.001)==0);
	REQUIRE(Approx(scoreCollege.PercentC).epsilon(0.001)==0);
	REQUIRE(Approx(scoreCollege.PercentD).epsilon(0.001)==0);
	REQUIRE(Approx(scoreCollege.PercentF).epsilon(0.001)==0); 
}
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


TEST_CASE( "Test 08", "[Project01]" ) 
{
	College someCollege("medical");
	
	Dept someClass("BIOE");
	Dept someclass("CS");
									     //Dept,Number,Section,Title,             A,B,C,D,F,I,NR,S,U,W,Instructor  
  Course C= ParseCourse("BIOE,101,01,Intro to Bioengineering,  22,8,2,1,0,1, 0,0,0,5,Eddington");
	Course D= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,11,3,5,1,6,1, 0,0,0,8,Het");
	someClass.Courses.push_back(C);
	someclass.Courses.push_back(D);	
	someCollege.Depts.push_back(someClass);
	someCollege.Depts.push_back(someclass);
	int DFW=0,N=0;
	double c= GetDFWRate(someCollege,DFW,N);
	
	REQUIRE(N==72); 
	REQUIRE(DFW==21); 
    REQUIRE(Approx(c).epsilon(0.001)==29.1667);
}

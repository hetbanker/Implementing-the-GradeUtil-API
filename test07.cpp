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


TEST_CASE( "Test 07", "[Project01]" ) 
{
	Dept someClass("BIOE");
									     //Dept,Number,Section,Title,             A,B,C,D,F,I,NR,S,U,W,Instructor  
    Course C= ParseCourse("BIOE,101,01,Intro to Bioengineering,  22,8,2,1,0,1, 0,0,0,5,Eddington");
	Course D= ParseCourse("BIOE,102,02,Intro to Bioengineering 2,11,3,5,1,6,1, 0,0,0,8,Het");
	someClass.Courses.push_back(C);
	someClass.Courses.push_back(D);	
    int DFW=0,N=0;
	double c= GetDFWRate(someClass,DFW,N);
	
 
	REQUIRE(N==72.0); //total
	REQUIRE(DFW==21.0); //d f w
  REQUIRE(Approx(c).epsilon(0.001)==29.1667);
}

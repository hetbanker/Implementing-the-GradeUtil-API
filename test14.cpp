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

TEST_CASE( "Test 14", "[Project01]" ) 
{
	Course bioA= ParseCourse("BIOE,101,01,Intro to Bioengineering,  0,0,0,0,0,10,10,10,10,10,Eddington");
	Course csA = ParseCourse("CS,101,01,Program Design,  22,8,2,0,0,0,0,0,0,10,Theys");

	College college("UIC");
	Dept bioDept("BIOE");
	Dept csDept("CS");
	
	bioDept.Courses.push_back(bioA);
	csDept.Courses.push_back(csA);
	college.Depts.push_back(bioDept);
	college.Depts.push_back(csDept);
	
	int DfW,N;
	GetDFWRate(college,DfW,N);
	REQUIRE(DfW==10);
}
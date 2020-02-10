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


TEST_CASE( "Test 25", "[Project01]" ) 
{       
	
    Course csA= ParseCourse("CS,362,01,Computer Design 2,50,100,200,300,400,500,880,1,0,6,He");
    Course csB = ParseCourse("CS,362,02,Systems Programming,20,50,60,50,0,0,0,0,0,0,He");
    Course csC = ParseCourse("CS,261,01,Machine Organization,40,13,12,11,0,0,0,0,0,5,He");

    College one("UIC");
    Dept csDept("CS");
    csDept.Courses.push_back(csA);
    csDept.Courses.push_back(csB);
    csDept.Courses.push_back(csC);
    one.Depts.push_back(csDept);

    vector<Course> findCourse = FindCourses(csDept, "He" );
    REQUIRE(findCourse[2].Title == "Systems Programming");  
}
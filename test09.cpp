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

TEST_CASE( "Test 09", "[Project01]" ) 
{
 Course C("BIOE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 60, 50, 40, 30, 10, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
	Course D("BIOE", "Intro to Bioengineering",101,01,"Eddington",22,8,2,1,0,1,0,0,0,5);
	Dept dept("BIOE");
	dept.Courses.push_back(D);
	dept.Courses.push_back(C);

	GradeStats score= GetGradeDistribution(dept);
	
	REQUIRE(score.N == 223);
  REQUIRE(score.NumA == 82);
  REQUIRE(score.NumB == 58);           
  REQUIRE(score.NumC == 42);
  REQUIRE(score.NumD == 31);
  REQUIRE(score.NumF == 10);
  
  REQUIRE(Approx(score.PercentA).epsilon(0.001)==36.7713);
	REQUIRE(Approx(score.PercentB).epsilon(0.001)==26.009);
	REQUIRE(Approx(score.PercentC).epsilon(0.001)==18.8341);
	REQUIRE(Approx(score.PercentD).epsilon(0.001)==13.9013);
	REQUIRE(Approx(score.PercentF).epsilon(0.001)==4.4843);
}

TEST_CASE( "Test 0901", "[Project01]" ) 
{
 Course C("BIOE", "Professional Seminar", 0, 0, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
	Course D("BIOE", "Intro to Bioengineering",0,0,"Eddington",0,0,0,0,0,0,0,0,0,0);
	Dept dept("BIOE");
	dept.Courses.push_back(D);
	dept.Courses.push_back(C);

	GradeStats score= GetGradeDistribution(dept);
	
	REQUIRE(score.N == 0);
  REQUIRE(score.NumA == 0);
  REQUIRE(score.NumB == 0);           
  REQUIRE(score.NumC == 0);
  REQUIRE(score.NumD == 0);
  REQUIRE(score.NumF == 0);
  
  REQUIRE(Approx(score.PercentA).epsilon(0.001)==0);
	REQUIRE(Approx(score.PercentB).epsilon(0.001)==0);
	REQUIRE(Approx(score.PercentC).epsilon(0.001)==0);
	REQUIRE(Approx(score.PercentD).epsilon(0.001)==0);
	REQUIRE(Approx(score.PercentF).epsilon(0.001)==0);
}
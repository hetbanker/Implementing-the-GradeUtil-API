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

TEST_CASE( "Test 12", "[Project01]" ) 
{
 Course C("BIOE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 60, 50, 40, 30, 10, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);

	GradeStats score= GetGradeDistribution(C);
	
	REQUIRE(score.N == 190);
  REQUIRE(score.NumA == 60);
  REQUIRE(score.NumB == 50);           
  REQUIRE(score.NumC == 40);
  REQUIRE(score.NumD == 30);
  REQUIRE(score.NumF == 10);
  
  REQUIRE(Approx(score.PercentA).epsilon(0.001)==31.5789);
	REQUIRE(Approx(score.PercentB).epsilon(0.001)==26.3158);
	REQUIRE(Approx(score.PercentC).epsilon(0.001)==21.0526);
	REQUIRE(Approx(score.PercentD).epsilon(0.001)==15.7895);
	REQUIRE(Approx(score.PercentF).epsilon(0.001)==5.26316); 
}

TEST_CASE( "Test 1201", "[Project01]" ) 
{
 Course C("BIOE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);

	GradeStats score= GetGradeDistribution(C);
	
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
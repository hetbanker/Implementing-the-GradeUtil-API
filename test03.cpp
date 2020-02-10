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

TEST_CASE( "Test 03", "[Project01]" ) 
{
 Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 60, 50, 40, 30, 10, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
	int DFW=0,N=0;
	double c= GetDFWRate(C,DFW,N);
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
	//mal
  REQUIRE(N==190); //total
	REQUIRE(DFW==40); //d f w
  
  REQUIRE(C.NumA == 60);
  REQUIRE(C.NumB == 50);           
  REQUIRE(C.NumC == 40);
  REQUIRE(C.NumD == 30);
  REQUIRE(C.NumF == 10);
  
  REQUIRE(C.NumI == 2);
  REQUIRE(C.NumS == 88);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 1);  
  
  REQUIRE(Approx(c).epsilon(0.001)==21.0526);
}
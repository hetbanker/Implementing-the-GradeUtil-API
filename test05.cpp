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


TEST_CASE( "Test 05", "[Project01]" ) 
{
	//Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
   //        /*A-F*/ 0, 0, 0, 0, 0, 
    //       /*I,S,U,W,NR*/ 2, 88, 0, 0, 1); 
  Course C("BIOE", "Intro to Bioengineering",101,01,"Eddington",22,8,2,1,0,1,0,0,0,5);
	Dept dept("BIOE");
	dept.Courses.push_back(C);
	int DFW=0,N=0;
	double c= GetDFWRate(C,DFW,N);
  REQUIRE(C.Dept == "BIOE");
  REQUIRE(C.Title == "Intro to Bioengineering");
  REQUIRE(C.Number == 101);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Eddington");
  
	//mal
  REQUIRE(N==33); //total
	REQUIRE(DFW==1); //d f w
	
  REQUIRE(C.NumA == 22);
  REQUIRE(C.NumB == 8);           
  REQUIRE(C.NumC == 2);
  REQUIRE(C.NumD == 1);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 1);
  REQUIRE(C.NumS == 0);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 5);  
  
	REQUIRE(Approx(c).epsilon(0.001)==3.0303);
}
TEST_CASE( "Test 0501", "[Project01]" ) 
{
  Course C("BIOE", "Intro to Bioengineering",101,01,"Eddington",0,0,0,0,0,0,0,0,0,0);
	Dept dept("BIOE");
	dept.Courses.push_back(C);
	int DFW=0,N=0;
	double c= GetDFWRate(C,DFW,N);
  REQUIRE(C.Dept == "BIOE");
  REQUIRE(C.Title == "Intro to Bioengineering");
  REQUIRE(C.Number == 101);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Eddington");
  
  REQUIRE(N==0); //total
	REQUIRE(DFW==0); //d f w
	
  REQUIRE(C.NumA == 0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 0);
  REQUIRE(C.NumS == 0);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 0);  
  
	REQUIRE(Approx(c).epsilon(0.001)==0);
}

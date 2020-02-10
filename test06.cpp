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


TEST_CASE( "Test 06", "[Project01]" ) 
{
	
									     //Dept,Number,Section,Title,           A,B,C,D,F,I,NR,S,U,W,Instructor  
  Course C= ParseCourse("BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1, 0,0,0,5,Eddington");
  int DFW=0,N=0;
	double c= GetDFWRate(C,DFW,N);
	
	REQUIRE(N==38.0); //total
	//REQUIRE(DFW==1); //d f w
	
  REQUIRE(C.NumA == 22);
  REQUIRE(C.NumB == 8);           
  REQUIRE(C.NumC == 2);
  REQUIRE(C.NumD == 1);
  REQUIRE(C.NumF == 0);
	
	REQUIRE(C.NumI==1);
	REQUIRE(C.NumNR==0);
	REQUIRE(C.NumS==0);
	REQUIRE(C.NumU==0);
	REQUIRE(C.NumW==5);
	REQUIRE(DFW==6.0); //d f w
  REQUIRE(Approx(c).epsilon(0.001)==15.789);
}

TEST_CASE( "Test 0601", "[Project01]" ) 
{
	
									     //Dept,Number,Section,Title,           A,B,C,D,F,I,NR,S,U,W,Instructor  
  Course C= ParseCourse("BIOE,101,01,Intro to Bioengineering,0,0,0,0,0,0, 0,0,0,0,Eddington");
  int DFW=0,N=0;
	double c= GetDFWRate(C,DFW,N);
	
	REQUIRE(N==0); 

	
  REQUIRE(C.NumA ==0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
	
	REQUIRE(C.NumI==0);
	REQUIRE(C.NumNR==0);
	REQUIRE(C.NumS==0);
	REQUIRE(C.NumU==0);
	REQUIRE(C.NumW==0);
	REQUIRE(DFW==0); //d f w
  REQUIRE(Approx(c).epsilon(0.001)==0.0);
}

TEST_CASE( "Test 0602", "[Project01]" ) 
{
	        
   Course C("CS", "Professional Seminar", 499, 01, "Hummel", /*A-F*/ 0, 0, 0, 0, 0, /*I,S,U,W,NR*/ 2, 88, 0, 1, 1);
  int DFW=0,N=0;
	GetDFWRate(C,DFW,N);
	
	REQUIRE(N==0.0); //total
	
  REQUIRE(C.NumA ==0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
	
	REQUIRE(C.NumI==2);
	REQUIRE(C.NumNR==1);
	REQUIRE(C.NumS==88);
	REQUIRE(C.NumU==0);
	REQUIRE(C.NumW==1);
	
	REQUIRE(DFW==0.0); //d f w
  REQUIRE(C.getGradingType()==Course::Satisfactory);
}

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

TEST_CASE( "Test 04", "[Project01]" ) 
{
	//GradeStats(int n, int numA, int numB, int numC, int numD, int numF,
	//PercentA(percentA), PercentB(percentB), PercentC(percentC), PercentD(percentD), PercentF(percentF)
	GradeStats someClass (50, 10, 10, 10,10,10, 5.5, 6.6, 7.7,8.8,9.9);
	REQUIRE(someClass.N==50);
	REQUIRE(someClass.NumA==10);
	REQUIRE(someClass.NumB==10);
	REQUIRE(someClass.NumC==10);
	REQUIRE(someClass.NumD==10);
	REQUIRE(someClass.NumF==10);
	REQUIRE(someClass.PercentA==5.5);
	REQUIRE(someClass.PercentB==6.6);
	REQUIRE(someClass.PercentC==7.7);
	REQUIRE(someClass.PercentD==8.8);
	REQUIRE(someClass.PercentF==9.9);
	
}

TEST_CASE( "Test 0401", "[Project01]" ) 
{
	//GradeStats(int n, int numA, int numB, int numC, int numD, int numF,
	//PercentA(percentA), PercentB(percentB), PercentC(percentC), PercentD(percentD), PercentF(percentF)
	GradeStats someClass (0, 0, 0, 0,0,0, 0, 0, 0,0,0);
	REQUIRE(someClass.N==0);
	REQUIRE(someClass.NumA==0);
	REQUIRE(someClass.NumB==0);
	REQUIRE(someClass.NumC==0);
	REQUIRE(someClass.NumD==0);
	REQUIRE(someClass.NumF==0);
	REQUIRE(someClass.PercentA==0);
	REQUIRE(someClass.PercentB==0);
	REQUIRE(someClass.PercentC==0);
	REQUIRE(someClass.PercentD==0);
	REQUIRE(someClass.PercentF==0);
	
}

TEST_CASE( "Test 0402", "[Project01]" ) 
{
	//GradeStats(int n, int numA, int numB, int numC, int numD, int numF,
	//PercentA(percentA), PercentB(percentB), PercentC(percentC), PercentD(percentD), PercentF(percentF)
	GradeStats someClass (0, 0, 0, 0,0,0.0, 0.0, 0.0, 0.0,0.0,0.0);
	REQUIRE(someClass.N==0);
	REQUIRE(someClass.NumA==0);
	REQUIRE(someClass.NumB==0);
	REQUIRE(someClass.NumC==0);
	REQUIRE(someClass.NumD==0);
	REQUIRE(someClass.NumF==0);
	REQUIRE(someClass.PercentA==0.0);
	REQUIRE(someClass.PercentB==0.0);
	REQUIRE(someClass.PercentC==0.0);
	REQUIRE(someClass.PercentD==0.0);
	REQUIRE(someClass.PercentF==0.0);
	
}
/*gradeutil.cpp*/

//
// << Het Banker >>
// U. of Illinois, Chicago
// CS 341, Fall 2019
// Project #02: GradeUtil API
// 

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>
#include "gradeutil.h"
using namespace std;

void Dept::addCourse(Course course)
{
	// Add course to Courses.
	Dept::Courses.push_back(course);	
	
}

void College::addDepartment(Dept department)
{
	// Add department to Depts.
	College::Depts.push_back(department);
	
}

//
// API:
//
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//

/****************************************************************************/
Course ParseCourse(string csvline)
{
	stringstream sso(csvline);
	string Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor;
	getline(sso,Dept,',');
	getline(sso,Number,',');
	getline(sso,Section,',');
	getline(sso,Title,',');
	getline(sso,A,',');
	getline(sso,B,',');
	getline(sso,C,',');
	getline(sso,D,',');
	getline(sso,F,',');
	getline(sso,I,',');
	getline(sso,NR,',');
	getline(sso,S,',');
	getline(sso,U,',');
	getline(sso,W,',');
	getline(sso,Instructor);
	
    Course c(Dept, Title, stoi(Number), stoi(Section), Instructor, stoi(A), stoi(B), stoi(C), 
				stoi(D), stoi(F), stoi(I), stoi(S), stoi(U), stoi(W), stoi(NR));
	
	return c;
}

/****************************************************************************/
//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{
	double total= 0.0;
	DFW = c.NumD + c.NumF + c.NumW;
	N   =c.NumD + c.NumF + c.NumW + c.NumA+c.NumB+c.NumC ;
	if(c.getGradingType() != Course::Letter) 
	{
		DFW=0;
		N=0;
		return total;
	}
	return (double(DFW)/double(N))*double(100);
}

/****************************************************************************/					
double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
	int A=0,B=0,C=0,D=0,F=0,W=0;
	for(const auto& a : dept.Courses)
	{
		if(a.getGradingType() == Course::Letter)
		{
			A=A+a.NumA;
			B=B+a.NumB;
			C=C+a.NumC;
			D=D+a.NumD;
			F=F+a.NumF;
			W=W+a.NumW;
		}
	}
	N=A+B+C+D+F+W;
	DFW = D+F+W;
	
	if(N!=0 || DFW!=0) return (double(DFW)/double(N))*double(100);
	return 0.0;
}

/****************************************************************************/					
double GetDFWRate(const College& college, int& DFW, int& N)
{
	int A=0, B=0,C=0,D=0,F=0, W=0;
	for(const auto& a : college.Depts)
	{
		for(const auto& b : a.Courses)
		{
			if(b.getGradingType() == Course::Letter)
			{
				A=A+b.NumA;
				B=B+b.NumB;
				C=C+b.NumC;
				D=D+b.NumD;
				F=F+b.NumF;
				W=W+b.NumW; 
			}
		}
	}
	N=A+B+C+D+F+W;
	DFW = D+F+W;
	
	if(N!=0 || DFW!=0) return (double(DFW)/double(N))*double(100);
	return 0.0;
}  

/****************************************************************************/
//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
/****************************************************************************/
GradeStats GetGradeDistribution(const Course& c)
{
	int total= c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
	GradeStats noStudents ;

	if(total==0 || c.getGradingType() != Course::Letter) return noStudents;

	return GradeStats(total,c.NumA,c.NumB,c.NumC,c.NumD,c.NumF,(double(c.NumA )/ double(total))*double(100),(double(c.NumB )/ double(total))*double(100), 
					   (double(c.NumC )/ double(total))*double(100),(double(c.NumD )/ double(total))*double(100),(double(c.NumF )/ double(total))*double(100));  
}
/****************************************************************************/
GradeStats GetGradeDistribution(const Dept& dept)
{
	int A=0,B=0,C=0,D=0,F=0,total=0,empty=0;
	GradeStats noStudents ;
	
	for(const auto& a : dept.Courses)
	{
		if(a.getGradingType() == Course::Letter)
		{
			A=A+a.NumA;
			B=B+a.NumB;
			C=C+a.NumC;
			D=D+a.NumD;
			F=F+a.NumF;
		}
	}
	total=A+B+C+D+F;

	if(total==empty) return noStudents; //everything 0
	
	return GradeStats (total,A,B,C,D,F,(double(A)/ double(total))*double(100),(double(B)/ double(total))*double(100),(double(C)/ double(total))*double(100),
					   (double(D)/ double(total))*double(100),(double(F)/ double(total))*double(100)); 
}
/****************************************************************************/
GradeStats GetGradeDistribution(const College& college)
{ 
	int A=0,B=0,C=0,D=0,F=0,total=0,empty=0;
	GradeStats noStudents ;
	
	for(const auto&a : college.Depts)
	{
		for(const auto&b : a.Courses)
		{
			if(b.getGradingType() == Course::Letter)
			{
				A=A+b.NumA;
				B=B+b.NumB;
				C=C+b.NumC;
				D=D+b.NumD;
				F=F+b.NumF;
			}
		}
	}
	total=A+B+C+D+F;
	if(total==empty) return noStudents;

	return GradeStats (total,A,B,C,D,F,(double(A)/ double(total))*double(100),(double(B)/ double(total))*double(100),(double(C)/ double(total))*double(100),
					   (double(D)/ double(total))*double(100),(double(F)/ double(total))*double(100)); 
}
/****************************************************************************/

//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.

/****************************************************************************/					
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
	vector<Course>  courses;
	Dept addd;
	for(const auto& a : dept.Courses)
	{
		if(a.Number==courseNumber)
		{
			addd.addCourse(a);
			courses.push_back(a);
		}
	}
	//lamda
	std::sort(courses.begin(), courses.end(), [](const Course& x, const Course& y) {
		return x.Section<y.Section;
	});
	return courses;
}


/****************************************************************************/
//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.

/****************************************************************************/					 
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
	vector<Course>  courses;
	Dept addd;
	for(const auto& a : dept.Courses)
	{
			std::string stringConcatenate = ("("+(instructorPrefix)+")(.*)");
			std::smatch match;
			std::regex checker(stringConcatenate);
            if(regex_match(a.Instructor, checker)!=0)
			{
				addd.addCourse(a);
                courses.push_back(a);
			}
	}
	//lamda
	std::sort(courses.begin(), courses.end(), [](const Course& x, const Course& y)
			  {
				  if(x.Number<y.Number) return true;
				  else if(x.Number>y.Number) return false;
				  else if(x.Section<y.Section) return true;
				  else return false; 
			  });
  return courses;
}

/****************************************************************************/
//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.

/****************************************************************************/					 
					 
vector<Course> FindCourses(const College& college, int courseNumber)
{
	vector<Course>  courses;
	College addd;
	for(const auto& a:college.Depts)
	{
		for(const auto& b : a.Courses)
		{
			if(b.Number==courseNumber)
			{
				addd.addDepartment(a);
				courses.push_back(b);
			}
		}
	}
	std::sort(courses.begin(), courses.end(), [](const Course& x, const Course& y)
			  {
				  if(x.Dept<y.Dept) return true;
				  else if(x.Dept>y.Dept) return false;
				  else if(x.Number<y.Number) return true;
				  else if(x.Number>y.Number) return false;
				  else if(x.Section<y.Section) return true;
				  else return false;   
			  });
	
  return courses;
}

/****************************************************************************/
//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department,
// then course number, and then section.

/****************************************************************************/					
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
	vector<Course>  courses;
	College addd;
	
	for(const auto& a: college.Depts)
	{
		for(const auto& b : a.Courses)
		{
			std::string stringConcatenate = ("("+(instructorPrefix)+")(.*)");
			std::smatch match;
            std::regex checker(stringConcatenate);
            if(regex_match(b.Instructor, checker)!=0)
			{
				addd.addDepartment(a);
                courses.push_back(b);
			}
		}
	}
	//lamda
	std::sort(courses.begin(), courses.end(), [](const Course &x,const Course& y)
			  {
				  if(x.Dept<y.Dept) return true;
				  else if(x.Dept>y.Dept) return false;
				  if(x.Number<y.Number) return true;
				  else if(x.Number>y.Number) return false;
				  else if(x.Section<y.Section) return true;
				  else return false;
			  });
  return courses;
}
/****************************************************************************/
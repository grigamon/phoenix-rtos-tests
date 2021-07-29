/* Test Cases groups
1. Accuracy of cos() functions for normal cases [cosNormalCases]
2. Accuracy of cos() function in the edges [cosEdgesCases]
3. Checking the parity of cos() function (cos x = cos(-x)) [cosParityCases]
4. Checking the frequency of cos() function (cos x = cos (x+ 2*pi)) [cosFrequencyCases]
5. Checking the repeatability (since that the most of all cos() functions implementations use Maclaurin) [cosRepeatabilityCases]
*/

#include <math.h>

#include "unity_fixture.h"

float tolerance = 0.0001, deltaRadians = 0.00001;


TEST_GROUP(testCos);


TEST_SETUP(testCos);
{
/*
*/
}


TEST_TEAR_DOWN(testCos)
{
/*
*/
}


// 1. cosNormalCases
TEST(testCos, cosNormalCases)
{
//First quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,1.0, cos(0))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.86602, cos(M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.70710, cos(M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.5, cos(M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0, cos(M_PI/2))

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.5, cos(2*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.70710, cos(3*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.86602, cos(5*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-1.0, cos(M_PI))

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.86602, cos(7*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.70710, cos(5*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.5, cos(4*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0, cos(3*M_PI/2))

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.5, cos(5*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.70710, cos(7*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.86602, cos(11*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,1.0, cos(2*M_PI))
}


//2.cosEdgesCases
TEST(testCos, cosEdgesCases)
{
//First quadrant + deltaRadians
TEST_ASSERT_FLOAT_WITHIN(tolerance,1.0, cos(0 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.86602, cos(M_PI/6 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.70710, cos(M_PI/4 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.5, cos(M_PI/3 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0, cos(M_PI/2 + deltaRadians))

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.5, cos(2*M_PI/3 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.70710, cos(3*M_PI/4 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.86602, cos(5*M_PI/6 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-1.0, cos(M_PI + deltaRadians))

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.86602, cos(7*M_PI/6 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.70710, cos(5*M_PI/4 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,-0.5, cos(4*M_PI/3 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0, cos(3*M_PI/2 + deltaRadians))

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.5, cos(5*M_PI/3 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.70710, cos(7*M_PI/4 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,0.86602, cos(11*M_PI/6 + deltaRadians))
TEST_ASSERT_FLOAT_WITHIN(tolerance,1.0, cos(2*M_PI + deltaRadians))
}


//3.cosParityCases
TEST(testCos, cosParityCases)
{
//First quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-M_PI/6), cos(M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-M_PI/4), cos(M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-M_PI/3), cos(M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-M_PI/2, cos(M_PI/2))

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-2*M_PI/3), cos(2*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-3*M_PI/4), cos(3*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-5*M_PI/6), cos(5*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-M_PI), cos(M_PI))

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-7*M_PI/6), cos(7*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-5*M_PI/4), cos(5*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-4*M_PI/3), cos(4*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-3*M_PI/2), cos(3*M_PI/2))

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-5*M_PI/3), cos(5*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-7*M_PI/4), cos(7*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-11*M_PI/6), cos(11*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(-2*M_PI), cos(2*M_PI))
}


//4.cosFrequencyCases
TEST(testCos, cosFrequencyCases)
{
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(M_PI/6 + 2*M_PI), cos(M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(M_PI/4 + 2*M_PI), cos(M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(M_PI/3), cos(M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(M_PI/2, cos(M_PI/2))

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(2*M_PI/3 + 2*M_PI), cos(2*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(3*M_PI/4 + 2*M_PI), cos(3*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(5*M_PI/6 + 2*M_PI), cos(5*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(M_PI + 2*M_PI), cos(M_PI))

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(7*M_PI/6 + 2*M_PI), cos(7*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(5*M_PI/4 + 2*M_PI), cos(5*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(4*M_PI/3 + 2*M_PI), cos(4*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(3*M_PI/2 + 2*M_PI), cos(3*M_PI/2))

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(5*M_PI/3 + 2*M_PI), cos(5*M_PI/3))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(7*M_PI/4 + 2*M_PI), cos(7*M_PI/4))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(11*M_PI/6 + 2*M_PI), cos(11*M_PI/6))
TEST_ASSERT_FLOAT_WITHIN(tolerance,cos(2*M_PI + 2*M_PI), cos(2*M_PI))

}

//5.cosRepeatabilityCases
TEST(testCos, cosRepeatability)
{
//First quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/6), cos(M_PI/6))
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/4), cos(M_PI/4))
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/3), cos(M_PI/3))
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/2, cos(M_PI/2))

//Second quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(2*M_PI/3), cos(2*M_PI/3))
TEST_ASSERT_EQUAL_FLOAT(cos(3*M_PI/4), cos(3*M_PI/4))
TEST_ASSERT_EQUAL_FLOAT(cos(5*M_PI/6), cos(5*M_PI/6))
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI), cos(M_PI))

//Third quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(7*M_PI/6), cos(7*M_PI/6))
TEST_ASSERT_EQUAL_FLOAT(cos(5*M_PI/4), cos(5*M_PI/4))
TEST_ASSERT_EQUAL_FLOAT(cos(4*M_PI/3), cos(4*M_PI/3))
TEST_ASSERT_EQUAL_FLOAT(cos(3*M_PI/2), cos(3*M_PI/2))

//Fourth quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(5*M_PI/3), cos(5*M_PI/3))
TEST_ASSERT_EQUAL_FLOAT(cos(7*M_PI/4), cos(7*M_PI/4))
TEST_ASSERT_EQUAL_FLOAT(cos(11*M_PI/6), cos(11*M_PI/6))
TEST_ASSERT_EQUAL_FLOAT(cos(2*M_PI), cos(2*M_PI))
}

void runner(void)
{
	RUN_TEST_GROUP(testCos);
}

TEST_GROUP_RUNNER(testCos)
{
	RUN_TEST_CASE(testCos, cosNormalCases);
}

int main(int argc, char *argv[])
{
	UnityMain(argc, (const char **)argv, runner);
	return 0;
}
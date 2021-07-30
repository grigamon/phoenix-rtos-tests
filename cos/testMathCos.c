/* Test Cases groups (assuming those 5 high level requirements)
1. Accuracy of cos() functions for normal cases [cosNormalCases]
2. Accuracy of cos() function in the edges [cosEdgesCases]
3. Checking the parity of cos() function (cos x = cos(-x)) [cosParityCases]
4. Checking the frequency of cos() function (cos x = cos (x+ T)) [cosPeriodicityCases]
5. Checking the repeatability (since that the most of all cos() functions implementations use Maclaurin) [cosRepeatabilityCases]
*/

#include <math.h>
#include <stdlib.h>

#include "unity_fixture.h"


#define TOLERANCE	0.0001
#define DELTA_RADIANS	0.00001
#define MAXIMUM_ITERATION	10000
#define MAXIMUM_RANDOM	1000


TEST_GROUP(testCos);


TEST_SETUP(testCos)
{
/*
*/
}


TEST_TEAR_DOWN(testCos)
{
/*
*/
}


/* 1. cosNormalCases
Since we want to verify the accuracy of cos() function for normal cases, we will use remarkable angles as strategy to verify the results because their values are known.
*/
TEST(testCos, cosNormalCases)
{
//First quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 1.0, cos(0));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0.86602, cos(M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0.70710, cos(M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0.5, cos(M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0, cos(M_PI/2));

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -0.5, cos(2*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -0.70710, cos(3*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -0.86602, cos(5*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -1.0, cos(M_PI));

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -0.86602, cos(7*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -0.70710, cos(5*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, -0.5, cos(4*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0, cos(3*M_PI/2));

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0.5, cos(5*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0.70710, cos(7*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 0.86602, cos(11*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE, 1.0, cos(2*M_PI));
}


/* 2.cosEdgesCases
For this group of tests we will exercise the accuracy of cos() function in the edges, using for comparison: randomic x + a small value DELTA_RADIANS and
the same randomic x - a small value DELTA_RADIANS
*/
TEST(testCos, cosEdgesCases)
{
int j;
float radRand;

radRand = rand() % MAXIMUM_RANDOM;

for (j=1; j<=MAXIMUM_ITERATION; j++)
{
	if (cos(radRand + DELTA_RADIANS) - cos(radRand - DELTA_RADIANS)>TOLERANCE)
	{
		TEST_FAIL_MESSAGE("FAILED during the Edges comparison testing.");
	}
}
TEST_PASS();

}


/*3.cosParityCases
For this group of tests we will exercise the parity of cos() functions, using randomic values as inputs to validate the assertion cos x = cos(-x).
*/
TEST(testCos, cosParityCases)
{
int k;
float radRandParity;

radRandParity = rand() % MAXIMUM_RANDOM;

for (k=1; k<=MAXIMUM_ITERATION; k++)
{
	if (cos(-radRandParity)-cos(radRandParity)>TOLERANCE)
	{
		TEST_FAIL_MESSAGE("FAILED during the Parity check testing.");
	}	
}
TEST_PASS();

}


/*4.cosPeriodicityCases
Once cos() is a periodic function which format is cos x = cos (x + T) and T=2*pi it's necessary to check the Periodicity. For that it's necessary to iterating 
the function as below and check the tolerance for each iteration.
*/
TEST(testCos, cosPeriodicityCases)
{
	int i;

	for (i=1; i<=MAXIMUM_ITERATION; i++)
	{
		if (cos(M_PI/6 + 2*M_PI*i) - cos(M_PI/6)>TOLERANCE)
		{
			TEST_FAIL_MESSAGE("FAILED during the periodicity testing.");
		}
	}
	TEST_PASS();

}

/*5.cosRepeatabilityCases
*/
TEST(testCos, cosRepeatability)
{
//First quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/6), cos(M_PI/6));
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/4), cos(M_PI/4));
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/3), cos(M_PI/3));
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI/2), cos(M_PI/2));

//Second quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(2*M_PI/3), cos(2*M_PI/3));
TEST_ASSERT_EQUAL_FLOAT(cos(3*M_PI/4), cos(3*M_PI/4));
TEST_ASSERT_EQUAL_FLOAT(cos(5*M_PI/6), cos(5*M_PI/6));
TEST_ASSERT_EQUAL_FLOAT(cos(M_PI), cos(M_PI));

//Third quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(7*M_PI/6), cos(7*M_PI/6));
TEST_ASSERT_EQUAL_FLOAT(cos(5*M_PI/4), cos(5*M_PI/4));
TEST_ASSERT_EQUAL_FLOAT(cos(4*M_PI/3), cos(4*M_PI/3));
TEST_ASSERT_EQUAL_FLOAT(cos(3*M_PI/2), cos(3*M_PI/2));

//Fourth quadrant
TEST_ASSERT_EQUAL_FLOAT(cos(5*M_PI/3), cos(5*M_PI/3));
TEST_ASSERT_EQUAL_FLOAT(cos(7*M_PI/4), cos(7*M_PI/4));
TEST_ASSERT_EQUAL_FLOAT(cos(11*M_PI/6), cos(11*M_PI/6));
TEST_ASSERT_EQUAL_FLOAT(cos(2*M_PI), cos(2*M_PI));
}

void runner(void)
{
	RUN_TEST_GROUP(testCos);
}

TEST_GROUP_RUNNER(testCos)
{
	RUN_TEST_CASE(testCos, cosNormalCases);
	RUN_TEST_CASE(testCos, cosEdgesCases);
	RUN_TEST_CASE(testCos, cosParityCases);
	RUN_TEST_CASE(testCos, cosPeriodicityCases);
//	RUN_TEST_CASE(testCos, cosRepeatabilityCases);
}

int main(int argc, char *argv[])
{
	UnityMain(argc, (const char **)argv, runner);
	return 0;
}
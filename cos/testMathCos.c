/* Test Cases groups
1. Accuracy of cos() functions for normal cases [cosNormalCases]
2. Accuracy of cos() function in the edges [cosEdgesCases]
3. Checking the parity of cos() function (cos x = cos(-x)) [cosParityCases]
4. Checking the frequency of cos() function (cos x = cos (x+ T)) [cosPeriodicityCases]
5. Checking the repeatability [cosRepeatabilityCases]
6. Accuracy of cos() function in the edges [cosEdgesCasesControl] using known values as inputs.
7. Checking the parity of cos() function (cos x = cos(-x)) [cosParityCasesControl] using known values as inputs.
8. Checking the frequency of cos() function (cos x = cos (x+ T)) [cosPeriodicityCasesControl] using known values as inputs.
9. Checking the repeatability (since that the most of all cos() functions implementations use Maclaurin) [cosRepeatabilityCasesControl] using known values as inputs.
*/

#include <math.h>
#include <stdlib.h>

#include "unity_fixture.h"


#define TOLERANCE	0.0001
#define DELTA_RADIANS	0.00001
#define MAXIMUM_ITERATION	10000 //could be adjusted
#define MAXIMUM_RANDOM	1000 //could be adjusted


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


/*------------------------------------------------------------ Begin Exhaustives tests ------------------------------------------------------------*/

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
the same randomic x - a small value DELTA_RADIANS.
*/
TEST(testCos, cosEdgesCases)
{
int j;
float radRand;

radRand = rand() % MAXIMUM_RANDOM;

for (j=1; j<=MAXIMUM_ITERATION; j++)
{
	if (fabs(fabs(cos(radRand + DELTA_RADIANS)) - fabs(cos(radRand - DELTA_RADIANS)))>TOLERANCE)
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
	if (fabs(cos(-radRandParity)-cos(radRandParity))>TOLERANCE)
	{
		TEST_FAIL_MESSAGE("FAILED during the Parity check testing.");
	}	
}
TEST_PASS();
}


/*4.cosPeriodicityCases
Once cos() is a periodic function which format is x = cos (x + T) and T=2*n*pi it's necessary to check the Periodicity, using randomic values as 
inputs to validate the assertion cos x = cos (x + T), where T=2*n*pi and n is a integer.
*/
TEST(testCos, cosPeriodicityCases)
{
	int i;

	for (i=1; i<=MAXIMUM_ITERATION; i++)
	{
		if (fabs(cos(M_PI/6 + 2*M_PI*i) - cos(M_PI/6))>TOLERANCE)
		{
			TEST_FAIL_MESSAGE("FAILED during the periodicity testing.");
		}
	}
	TEST_PASS();

}

/*5.cosRepeatabilityCases
Since that the most of all cos() functions implementations use Maclaurin, it's necessary to check the repeatability of the function. For this purpose, in this test,
we will compare a random value of angle as input to validate the assertion cos x = cos x for any x.
*/
TEST(testCos, cosRepeatabilityCases)
{
int l;
float radRandRepeatability, comparisonValue1, comparisonValue2;

radRandRepeatability = rand() % MAXIMUM_RANDOM;

for (l=1; l<=MAXIMUM_ITERATION; l++)
{
	comparisonValue1 = cos(radRandRepeatability);
	comparisonValue2 = cos(radRandRepeatability);

	if (fabs(comparisonValue1-comparisonValue2)>TOLERANCE)
	{
		TEST_FAIL_MESSAGE("FAILED during the Repeatabilitty check testing.");
	}
}
TEST_PASS();
}

/*------------------------------------------------------------ End Exhaustives tests ------------------------------------------------------------*/


/*------------------------------------------------------------ Begin Control tests ------------------------------------------------------------*/

/*Those tests could be used to calibrate the TOLERANCE and DELTA_RADIANS.*/

/* 6.cosEdgesCasesControl
The same idea of cosEdgesCases, but using known values.
*/
TEST(testCos, cosEdgesCasesControl)
{
//First quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,1.0, cos(0 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.86602, cos(M_PI/6 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.70710, cos(M_PI/4 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.5, cos(M_PI/3 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0, cos(M_PI/2 + DELTA_RADIANS));

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.5, cos(2*M_PI/3 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.70710, cos(3*M_PI/4 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.86602, cos(5*M_PI/6 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-1.0, cos(M_PI + DELTA_RADIANS));

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.86602, cos(7*M_PI/6 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.70710, cos(5*M_PI/4 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.5, cos(4*M_PI/3 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0, cos(3*M_PI/2 + DELTA_RADIANS));

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.5, cos(5*M_PI/3 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.70710, cos(7*M_PI/4 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.86602, cos(11*M_PI/6 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,1.0, cos(2*M_PI + DELTA_RADIANS));

TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,1.0, cos(0 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.86602, cos(M_PI/6 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.70710, cos(M_PI/4 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.5, cos(M_PI/3 + DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0, cos(M_PI/2 + DELTA_RADIANS));

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.5, cos(2*M_PI/3 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.70710, cos(3*M_PI/4 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.86602, cos(5*M_PI/6 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-1.0, cos(M_PI - DELTA_RADIANS));

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.86602, cos(7*M_PI/6 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.70710, cos(5*M_PI/4 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,-0.5, cos(4*M_PI/3 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0, cos(3*M_PI/2 - DELTA_RADIANS));

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.5, cos(5*M_PI/3 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.70710, cos(7*M_PI/4 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,0.86602, cos(11*M_PI/6 - DELTA_RADIANS));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,1.0, cos(2*M_PI - DELTA_RADIANS));
}


/*7.cosParityCasesControl
The same idea of cosParityCasesControl, but using known values.
*/
TEST(testCos, cosParityCasesControl)
{
//First quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-M_PI/6), cos(M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-M_PI/4), cos(M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-M_PI/3), cos(M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-M_PI/2), cos(M_PI/2));

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-2*M_PI/3), cos(2*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-3*M_PI/4), cos(3*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-5*M_PI/6), cos(5*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-M_PI), cos(M_PI));

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-7*M_PI/6), cos(7*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-5*M_PI/4), cos(5*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-4*M_PI/3), cos(4*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-3*M_PI/2), cos(3*M_PI/2));

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-5*M_PI/3), cos(5*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-7*M_PI/4), cos(7*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-11*M_PI/6), cos(11*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(-2*M_PI), cos(2*M_PI));
}


/*8.cosFrequencyCasesControl
The same idea of cosFrequencyCases, but using known values.
*/
TEST(testCos, cosPeriodicityCasesControl)
{
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(M_PI/6 + 2*M_PI), cos(M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(M_PI/4 + 2*M_PI), cos(M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(M_PI/3 + 2*M_PI), cos(M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(M_PI/2 + 2*M_PI), cos(M_PI/2));

//Second quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(2*M_PI/3 + 2*M_PI), cos(2*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(3*M_PI/4 + 2*M_PI), cos(3*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(5*M_PI/6 + 2*M_PI), cos(5*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(M_PI + 2*M_PI), cos(M_PI));

//Third quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(7*M_PI/6 + 2*M_PI), cos(7*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(5*M_PI/4 + 2*M_PI), cos(5*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(4*M_PI/3 + 2*M_PI), cos(4*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(3*M_PI/2 + 2*M_PI), cos(3*M_PI/2));

//Fourth quadrant
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(5*M_PI/3 + 2*M_PI), cos(5*M_PI/3));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(7*M_PI/4 + 2*M_PI), cos(7*M_PI/4));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(11*M_PI/6 + 2*M_PI), cos(11*M_PI/6));
TEST_ASSERT_FLOAT_WITHIN(TOLERANCE,cos(2*M_PI + 2*M_PI), cos(2*M_PI));
}


/*9.cosRepeatabilityCasesControl
The same idea of cosRepeatabilityCases, but using known values.
*/
TEST(testCos, cosRepeatabilityCasesControl)
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

/*------------------------------------------------------------ End Control tests ------------------------------------------------------------*/

void runner(void)
{
	RUN_TEST_GROUP(testCos);
}

TEST_GROUP_RUNNER(testCos)
{
	//Running exhaustive tests
	RUN_TEST_CASE(testCos, cosNormalCases);
	RUN_TEST_CASE(testCos, cosEdgesCases);
	RUN_TEST_CASE(testCos, cosParityCases);
	RUN_TEST_CASE(testCos, cosPeriodicityCases);
	RUN_TEST_CASE(testCos, cosRepeatabilityCases);
	
	//Running control tests
	RUN_TEST_CASE(testCos, cosEdgesCasesControl);
	RUN_TEST_CASE(testCos, cosParityCasesControl);
	RUN_TEST_CASE(testCos, cosPeriodicityCasesControl);
	RUN_TEST_CASE(testCos, cosRepeatabilityCasesControl);
}

int main(int argc, char *argv[])
{
	UnityMain(argc, (const char **)argv, runner);
	return 0;
}
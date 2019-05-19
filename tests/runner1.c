#include "unity.h"		// Unit test
#include "stdio.h"		// Only for Windows

/* Mocked headers */
#include "MockMod1.h"	

/* Production code headers */
#include "func1.h"

/* Test variables and functions */
static unsigned int counter = 0;

void setUp(void)
{
  //This is run before EACH TEST
  counter++;
  //printf("Start test %d\n",counter);
}

void tearDown(void)
{//This is run after EACH TEST
	//printf("\nEnd test %d.",counter);
}

/* ------- Tests by order ---------*/

void TS1_test1(void){
	TEST_ASSERT_EQUAL(0,0);
}


void TS1_basicTest2_receiveFunctionShallReturn_1(void){
	unsigned char a1 = 1;
	unsigned char b1 = 0x10;
	unsigned char c1 = 0;

	Mod1_read_signal_a_ExpectAnyArgs();
	Mod1_read_signal_b_ExpectAnyArgsAndReturn(0);
	Mod1_read_signal_c_ExpectAnyArgsAndReturn(0);

	Mod1_read_signal_a_ReturnThruPtr_a(&a1);
	Mod1_read_signal_b_ReturnThruPtr_b(&b1);
	Mod1_read_signal_c_ReturnThruPtr_c(&c1);

	TEST_ASSERT_EQUAL(1, receiveInputAndReturnBoolean());
}

void TS1_basicTest3_receiveFunctionShallReturn_0(void){
	unsigned char a1 = 5;
	unsigned char b1 = 0;
	unsigned char c1 = 0;

	Mod1_read_signal_a_ExpectAnyArgs();
	Mod1_read_signal_b_ExpectAnyArgsAndReturn(0);
	Mod1_read_signal_c_ExpectAnyArgsAndReturn(0);

	Mod1_read_signal_a_ReturnThruPtr_a(&a1);
	Mod1_read_signal_b_ReturnThruPtr_b(&b1);
	Mod1_read_signal_c_ReturnThruPtr_c(&c1);

	Mod1_write_signal_error_Expect(0x25);

	TEST_ASSERT_EQUAL(0, receiveInputAndReturnBoolean());
}

/* Test runner */
int main(int argc, char** argv){
	UNITY_BEGIN();

	RUN_TEST(TS1_test1);
	RUN_TEST(TS1_basicTest2_receiveFunctionShallReturn_1);
	RUN_TEST(TS1_basicTest3_receiveFunctionShallReturn_0);

	return UNITY_END();
}
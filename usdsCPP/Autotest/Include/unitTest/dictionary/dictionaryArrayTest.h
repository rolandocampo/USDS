#ifndef USDS_DICTIONARY_ARRAY_TEST_H
#define USDS_DICTIONARY_ARRAY_TEST_H

#include "usdsAutotest.h"

class DictionaryArrayTest
{
public:
	DictionaryArrayTest() {};
	~DictionaryArrayTest() {};

	void runTest(int32_t number);

private:

	void test_1();
	void test_2();

	int32_t testNumbers;

};

#endif
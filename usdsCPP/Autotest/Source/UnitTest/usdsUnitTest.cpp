#include "unitTest\usdsUnitTest.h"

#include "unitTest\base\usdsErrorTest.h"
#include "unitTest\base\usdsBinaryInputTest.h"
#include "unitTest\base\usdsBinaryOutputTest.h"
#include "unitTest\base\usdsObjectPoolTest.h"

#include "unitTest\dictionary\dictionaryArrayTest.h"
#include "unitTest\dictionary\dictionarySimpleTest.h"
#include "unitTest\dictionary\dictionaryStringTest.h"
#include "unitTest\dictionary\dictionaryStructTest.h"
#include "unitTest\dictionary\dictionaryTagLinkTest.h"
#include "unitTest\dictionary\usdsDictionaryTest.h"

#include "unitTest\body\usdsIntTest.h"
#include "unitTest\body\usdsArrayTest.h"

void UnitTest::runTest(int32_t number)
{
	if (!needStart(number, UNIT_TESTS))
		return;
	
	std::cout << "==========================================================\n";
	std::cout << UNIT_TESTS << ": Unit tests are started at ";
	printTime();
	std::cout << "==========================================================\n";

	// Base classes
	{
		ErrorTest err_test;
		err_test.runTest(number);

		BinaryInputTest bin_input_test;
		bin_input_test.runTest(number);

		BinaryOutputTest bin_output_test;
		bin_output_test.runTest(number);

		ObjectPoolTest object_pool_test;
		object_pool_test.runTest(number);

	}

	// Dictionary classes
	{
		DictionaryArrayTest dictionary_array_test;
		dictionary_array_test.runTest(number);

		DictionarySimpleTest dictionary_simple_test;
		dictionary_simple_test.runTest(number);

		DictionaryStringTest dictionary_string_test;
		dictionary_string_test.runTest(number);

		DictionaryStructTest dictionary_struct_test;
		dictionary_struct_test.runTest(number);

		DictionaryTagLinkTest dictionary_tag_link_test;
		dictionary_tag_link_test.runTest(number);

		DictionaryTest dictionary_test;
		dictionary_test.runTest(number);
	}

	// Body classes
	{
		UsdsIntTest body_int_test;
		body_int_test.runTest(number);

		UsdsArrayTest body_array_test;
		body_array_test.runTest(number);

	}

};


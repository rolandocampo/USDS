#include "unitTest\dictionary\dictionaryStringTest.h"

#include "dictionary\dataTypes\dictionaryString.h"

void DictionaryStringTest::runTest(int32_t number)
{
	if (!needStart(number, UNIT_TESTS__DICTIONARY_STRING))
		return;
	testNumbers = number;

	std::cout << UNIT_TESTS__DICTIONARY_STRING << " ------------- Dictionary String Class --------------\n";

	test_1();
	//test_2();
	//test_3();

};

void DictionaryStringTest::test_1()
{
	int32_t test_number = UNIT_TESTS__DICTIONARY_STRING_1;
	if (!needStart(testNumbers, test_number))
		return;

	std::cout << test_number << ": ";

	// step 1

	usds::DictionaryString object(0);
	if (object.getType() != usds::USDS_STRING)
	{
		std::cout << "Failed at the step 1\n";
		throw test_number;
	}

	// step 2

	object.init(0, 1, "string", 0);
	if (object.getEncode() != usds::USDS_NO_ENCODE)
	{
		std::cout << "Failed at the step 2\n";
		throw test_number;
	}

	// step 3
	try
	{
		object.finalize();
		std::cout << "Failed at the step 3\n";
		throw test_number;
	}
	catch (usds::ErrorStack& err)
	{
		if (err.getCode() != usds::DIC_STRING__ERROR_ENCODE)
		{
			std::cout << "Failed at the step 3\n";
			throw test_number;
		}
	}

	// step 4

	object.setEncode(usds::USDS_UTF8);
	if (object.getEncode() != usds::USDS_UTF8)
	{
		std::cout << "Failed at the step 4\n";
		throw test_number;
	}

	// step 5
	try
	{
		object.finalize();
	}
	catch (usds::ErrorStack)
	{
		std::cout << "Failed at the step 5\n";
		throw test_number;
	}
	


	std::cout << "Successful!\n";
}
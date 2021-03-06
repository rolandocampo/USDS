#ifndef USDS_TYPES_H
#define USDS_TYPES_H

#include "base\usdsErrors.h"

#ifdef _MSC_VER
	#if _MSC_VER >= 1600
		#pragma warning (disable : 4005)
		#include <cstdint>
	#else
		typedef __int8              int8_t;
		typedef __int16             int16_t;
		typedef __int32             int32_t;
		typedef __int64             int64_t;
		typedef unsigned __int8     uint8_t;
		typedef unsigned __int16    uint16_t;
		typedef unsigned __int32    uint32_t;
		typedef unsigned __int64    uint64_t;
	#endif
	#elif __GNUC__ >= 3
		#include <cstdint>
#endif

namespace usds
{
	enum usdsTypes
	{
		USDS_NO_TYPE = 0,
		USDS_TAG = 1,
		USDS_BOOLEAN = 2,
		USDS_BYTE = 3,
		USDS_UNSIGNED_BYTE = 4,
		USDS_SHORT = 5,
		USDS_UNSIGNED_SHORT = 6,
		USDS_BIGENDIAN_SHORT = 7,
		USDS_BIGENDIAN_UNSIGNED_SHORT = 8,
		USDS_INT = 9,
		USDS_UNSIGNED_INT = 10,
		USDS_BIGENDIAN_INT = 11,
		USDS_BIGENDIAN_UNSIGNED_INT = 12,
		USDS_LONG = 13,
		USDS_UNSIGNED_LONG = 14,
		USDS_BIGENDIAN_LONG = 15,
		USDS_BIGENDIAN_UNSIGNED_LONG = 16,
		USDS_INT128 = 17,
		USDS_UNSIGNED_INT128 = 18,
		USDS_BIGENDIAN_INT128 = 19,
		USDS_BIGENDIAN_UNSIGNED_INT128 = 20,
		USDS_FLOAT = 21,
		USDS_BIGENDIAN_FLOAT = 22,
		USDS_DOUBLE = 23,
		USDS_USDS_BIGENDIAN_DOUBLE = 24,
		USDS_VARINT = 25,
		USDS_UNSIGNED_VARINT = 26,
		USDS_STRING = 27,
		USDS_ARRAY = 28,
		USDS_LIST = 29,
		USDS_MAP = 30,
		USDS_POLYMORPH = 31,
		USDS_STRUCT = 32,
		USDS_FUNCTION = 33,
		USDS_LAST_TYPE = 34
	};

	enum usdsTypeSizes
	{
		USDS_NO_TYPE_SIZE = -1,
		USDS_TAG_SIZE = 0,
		USDS_BOOLEAN_SIZE = 1,
		USDS_BYTE_SIZE = 1,
		USDS_UNSIGNED_BYTE_SIZE = 1,
		USDS_SHORT_SIZE = 2,
		USDS_UNSIGNED_SHORT_SIZE = 2,
		USDS_BIGENDIAN_SHORT_SIZE = 2,
		USDS_BIGENDIAN_UNSIGNED_SHORT_SIZE = 2,
		USDS_INT_SIZE = 4,
		USDS_UNSIGNED_INT_SIZE = 4,
		USDS_BIGENDIAN_INT_SIZE = 4,
		USDS_BIGENDIAN_UNSIGNED_INT_SIZE = 4,
		USDS_LONG_SIZE = 8,
		USDS_UNSIGNED_LONG_SIZE = 8,
		USDS_BIGENDIAN_LONG_SIZE = 8,
		USDS_BIGENDIAN_UNSIGNED_LONG_SIZE = 8,
		USDS_INT128_SIZE = 16,
		USDS_UNSIGNED_INT128_SIZE = 16,
		USDS_BIGENDIAN_INT128_SIZE = 19,
		USDS_BIGENDIAN_UNSIGNED_INT128_SIZE = 16,
		USDS_FLOAT_SIZE = 4,
		USDS_BIGENDIAN_FLOAT_SIZE = 4,
		USDS_DOUBLE_SIZE = 8,
		USDS_USDS_BIGENDIAN_DOUBLE_SIZE = 8,
		USDS_VARINT_SIZE = 0,
		USDS_UNSIGNED_VARINT_SIZE = 0,
		USDS_STRING_SIZE = 0,
		USDS_ARRAY_SIZE = 0,
		USDS_LIST_SIZE = 0,
		USDS_MAP_SIZE = 0,
		USDS_POLYMORPH_SIZE = 0,
		USDS_STRUCT_SIZE = 0,
		USDS_FUNCTION_SIZE = 0,
		USDS_LAST_TYPE_SIZE = -1
	};

	enum usdsEncodes
	{
		USDS_NO_ENCODE = 0,
		USDS_UTF8 = 2,
		USDS_UTF16 = 3,
		USDS_UTF32 = 4,
		USDS_UTF7 = 5,
		USDS_LAST_ENCODE = 6
	};

	extern const char* typeName(usdsTypes code) throw(...);
	
	// returns 0 if unfixed
	extern int32_t typeSize(usdsTypes code) throw(...);
	
	extern const char* encodeName(usdsEncodes code) throw(...);

	enum usdsSignature
	{
		USDS_MAJOR_SIGNATURE = '$',
		USDS_MINOR_SIGNATURE = 'S',
		USDS_MAJOR_VERSION = 1,
		USDS_MINOR_VERSION = 0,
		USDS_DICTIONARY_SIGNATURE = 'd',
		USDS_DICTIONARY_SIGNATURE_WITH_SIZE = 'D',
		USDS_TAG_SIGNATURE = 't',
		USDS_FIELD_SIGNATURE = 'f',
		USDS_TAG_RESTRICTION_SIGNATURE = 'R',
		USDS_TAG_RESTRICTION_NOT_ROOT_SIGNATURE = 'r',
		USDS_BODY_SIGNATURE = 'b',
		USDS_BODY_SIGNATURE_WITH_SIZE = 'B'
	};

};


#endif
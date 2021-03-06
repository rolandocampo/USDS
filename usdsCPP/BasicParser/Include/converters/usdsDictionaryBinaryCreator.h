#ifndef USDS_DICTIONARY_BINARY_CREATOR_H
#define USDS_DICTIONARY_BINARY_CREATOR_H

#include "base\usdsTypes.h"
#include "base\usdsErrors.h"

namespace usds
{
	class BinaryOutput;
	class Dictionary;
	class DictionaryBaseType;

	class DictionaryBinaryCreator
	{
	public:

		DictionaryBinaryCreator();
		~DictionaryBinaryCreator();
		
		// Generate Binary Dictionary without size and signature
		void generate(BinaryOutput* buff, Dictionary* dict) throw (...);

	private:
		
		void (DictionaryBinaryCreator::*writeIndex[USDS_LAST_TYPE])(DictionaryBaseType*);

		void writeTag(DictionaryBaseType* object) throw (...);
		void writeBoolean(DictionaryBaseType* object) throw (...);
		void writeByte(DictionaryBaseType* object) throw (...);
		void writeUByte(DictionaryBaseType* object) throw (...);
		void writeShort(DictionaryBaseType* object) throw (...);
		void writeUShort(DictionaryBaseType* object) throw (...);
		void writeBEShort(DictionaryBaseType* object) throw (...);
		void writeBEUShort(DictionaryBaseType* object) throw (...);
		void writeInt(DictionaryBaseType* object) throw (...);
		void writeUInt(DictionaryBaseType* object) throw (...);
		void writeBEInt(DictionaryBaseType* object) throw (...);
		void writeBEUInt(DictionaryBaseType* object) throw (...);
		void writeLong(DictionaryBaseType* object) throw (...);
		void writeULong(DictionaryBaseType* object) throw (...);
		void writeBELong(DictionaryBaseType* object) throw (...);
		void writeBEULong(DictionaryBaseType* object) throw (...);
		void writeInt128(DictionaryBaseType* object) throw (...);
		void writeUInt128(DictionaryBaseType* object) throw (...);
		void writeBEInt128(DictionaryBaseType* object) throw (...);
		void writeBEUInt128(DictionaryBaseType* object) throw (...);
		void writeFloat(DictionaryBaseType* object) throw (...);
		void writeBEFloat(DictionaryBaseType* object) throw (...);
		void writeDouble(DictionaryBaseType* object) throw (...);
		void writeBEDouble(DictionaryBaseType* object) throw (...);
		void writeVarint(DictionaryBaseType* object) throw (...);
		void writeUVarint(DictionaryBaseType* object) throw (...);
		void writeString(DictionaryBaseType* object) throw (...);
		void writeArray(DictionaryBaseType* object) throw (...);
		void writeList(DictionaryBaseType* object) throw (...);
		void writeMap(DictionaryBaseType* object) throw (...);
		void writePolymorph(DictionaryBaseType* object) throw (...);
		void writeStruct(DictionaryBaseType* object) throw (...);
		void writeFunction(DictionaryBaseType* object) throw (...);


		BinaryOutput* outBuffer;

	};
}

#endif


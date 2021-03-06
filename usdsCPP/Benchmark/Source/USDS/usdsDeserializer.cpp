// This file must be autogenerated

#include "USDS\usdsDeserializer.h"

UsdsDeserializer::UsdsDeserializer()
{
	usds_buff = 0;
	buff_last_pos = 0;
	buff_current_pos = 0;
	buff_body_pos = 0;
	buff_body_last_pos = 0;

	head_included = false;
	dictionary_included = false;

	usds_major = 0;
	usds_minor = 0;
	dictionary_major = 0;
	dictionary_minor = 0;
	full_dictionary_version = 0;
};

UsdsDeserializer::~UsdsDeserializer()
{

};

int UsdsDeserializer::clean()
{
	usds_buff = 0;
	buff_last_pos = 0;
	buff_current_pos = 0;
	buff_body_pos = 0;
	buff_body_last_pos = 0;
	buff_body_last_pos = 0;

	head_included = false;
	dictionary_included = false;

	usds_major = 0;
	usds_minor = 0;
	dictionary_major = 0;
	dictionary_minor = 0;
	full_dictionary_version = 0;

	return 0;
}

//====================================================================================================================
// Settings
// Set for binary
int UsdsDeserializer::setUsdsVersion(int major, int minor)
{
	usds_major = major;
	usds_minor = minor;

	return 0;
};
int UsdsDeserializer::setDictionaryVersion(int major, int minor)
{
	dictionary_major = major;
	dictionary_minor = minor;
	full_dictionary_version = dictionary_major * 256 + dictionary_minor;
	return 0;
};

// Get from binary (deserialization)
int UsdsDeserializer::getUsdsVersion(int* major, int* minor)
{
	*major = usds_major;
	*minor = usds_minor;
	return 0;
};
int UsdsDeserializer::getDictionaryVersion(int* major, int* minor)
{
	*major = dictionary_major;
	*minor = dictionary_minor;
	return 0;
};
int UsdsDeserializer::getBinaryInfo(bool* head, bool* dictionary, bool* body, bool* index)
{

	return 0;
};

//====================================================================================================================
// Deserialization
int UsdsDeserializer::setBinary(unsigned char* data, int data_size)
{
	if (data == 0 || data_size == 0)
		return -1;
	
	usds_buff = data;
	buff_last_pos = usds_buff + data_size;
	buff_current_pos = usds_buff;

	if (buff_current_pos[0] == '$')
	{
		if (buff_current_pos[4] != 120 || buff_current_pos[5] != 3 || buff_current_pos[6] != 0 || buff_current_pos[7] != 0)
			return -1;
		if (buff_current_pos[8] != 1 || buff_current_pos[9] != 0)
			return -2;
		head_included = true;
		usds_major = buff_current_pos[2];
		usds_minor = buff_current_pos[3];
		dictionary_major = buff_current_pos[8];
		dictionary_minor = buff_current_pos[9];
		full_dictionary_version = dictionary_major * 256 + dictionary_minor;
		buff_current_pos += 10;
	}

	if (buff_current_pos[0] == 'D')
	{
		buff_current_pos++;
		int dict_size = 0;
		if(getVarint(&dict_size)!=0)
			return -3;
		buff_current_pos += dict_size;

	}

	if (buff_current_pos[0] == 'B')
	{
		buff_body_pos = buff_current_pos + 1;
		buff_body_last_pos = buff_last_pos - 1;
		if (*buff_body_last_pos != 0)
			return -4;
	}

	return 0;
};

int UsdsDeserializer::findFirstAndInit(TicketSales* data)
{
	if (buff_body_pos == 0)
		return -1;
	if (usds_major != 1 && usds_minor != 0)
		return -2;

	buff_current_pos = buff_body_pos;

	switch (full_dictionary_version)	// checking dictionary version
	{
		case 256:
		{

			// Finding first tag USDSTicketSales in document
			while (*buff_current_pos != 1)
			{
				// go to next tag
				// but it is impossible for the test

				if (buff_current_pos >= buff_body_last_pos)		// if tag USDSTicketSales not found
					return -4;

			};
			// Go to first fild
			buff_current_pos++;
			// Tag have found, initialising TicketSales
			if (buff_body_last_pos - buff_current_pos < 22)	// checking minimal size of a USDSTicketSales
				return -5;
			// set shiftNumber
			int shiftNumber;
			if (getVarint(&shiftNumber) != 0)
				return -6;
			data->setShiftNumber(shiftNumber);
			if (buff_body_last_pos - buff_current_pos < 21)
				return -5;
			// set cashRegister
			int cashRegister;
			getLEInt(&cashRegister);
			data->setCashRegister(cashRegister);
			// set startShift
			time_t startShift;
			setLETimestamp64(&startShift);
			data->setStartShift(startShift);
			// set endShift
			time_t endShift;
			setLETimestamp64(&endShift);
			data->setEndShift(endShift);
			// check size of vouchers
			int numVouchers;
			if (getVarint(&numVouchers) != 0)
				return -7;
			if (numVouchers == 0)
				return 0;
			// add array
			voucher* vouchers = data->getVouchers();
			for (int i = 0; i < numVouchers; i++)
			{
				if (buff_body_last_pos - buff_current_pos < 20)
					return -9;
				// set voucher_number
				if (getVarint(&(vouchers[i].voucher_number)) != 0)
					return -10;
				if (buff_body_last_pos - buff_current_pos < 19)
					return -11;
				// set summ
				setLEDouble(&(vouchers[i].summ));
				// set goods_name
				if (setStringUTF8NoConvert(vouchers[i].goods_name, 128) != 0)
					return -12;
				if (buff_body_last_pos - buff_current_pos < 5)
					return -13;
				// set time_of_sell
				setLETimestamp64(&(vouchers[i].time_of_sell));
				// set status
				setBool(&(vouchers[i].status));

			};

			return 0;

		}
		default:
			// Unsupportable dictionary version
			return -6;
	}


	return 0;
};
int UsdsDeserializer::findNextAndInit(TicketSales* data)
{
	return 0;
};
int UsdsDeserializer::findFirstAndCreate(TicketSales** data)
{
	return 0;
};
int UsdsDeserializer::findNextAndCreate(TicketSales** data)
{
	return 0;
};

inline int UsdsDeserializer::getVarint(int* value)
{
	int step = 0;
	int buf = 0;
	*value = 0;
	while (true)
	{
		buf = (*buff_current_pos) & 127;
		*value += (buf << (step*7));
		if (*buff_current_pos < 128)
			break;
		buff_current_pos++;
		step++;
		if (buff_current_pos >= buff_body_last_pos)
			return -2;
		if (step == 5)
			return -1;
	};
	if (step == 4 && (*buff_current_pos) > 7)
		return -3;
	
	buff_current_pos++;

	return 0;
};

inline void UsdsDeserializer::getLEInt(int* value)
{
	memcpy(value, buff_current_pos, 4);
	buff_current_pos += 4;

};

inline void UsdsDeserializer::setLETimestamp64(time_t* value)
{
	memcpy(value, buff_current_pos, 8);
	buff_current_pos += 8;
};

inline void UsdsDeserializer::setLEDouble(double* value)
{
	memcpy(value, buff_current_pos, 8);
	buff_current_pos += 8;
};

inline int UsdsDeserializer::setStringUTF8NoConvert(char* value, int max_size)
{
	// read size of string
	int string_size;
	if (getVarint(&string_size) != 0)
		return -2;
	if (string_size >= max_size)
		return -3;
	if (buff_body_last_pos - buff_current_pos < string_size)
		return -4;
	memcpy(value, buff_current_pos, string_size);
	value[string_size] = 0;
	buff_current_pos += string_size;


	return 0;
};

inline void UsdsDeserializer::setBool(bool* value)
{
	if (*buff_current_pos == 255)
		*value = true;
	else
		*value = false;
	buff_current_pos++;

}
#include "nibs/BinaryArchive.h"

namespace nibs
{
	void BinaryArchive::SetBoolValue(const std::string& Key, bool Value)
	{
		if (DoesKeyExist(Key))
		{
			mBinaryStream.seekp(GetDataOffset(Key));
			mBinaryStream << reinterpret_cast<unsigned char*>(&Value);

			mBinaryStream.seekp(GetBinaryStreamSize());
		}

		mBinaryStream.seekp(0, std::ios::end);
		mBinaryStream.write(reinterpret_cast<char*>(&Value), sizeof(bool));
		mBinaryLayout.emplace(Key, mBodySize);

		mBodySize += sizeof(bool);
	}

	void BinaryArchive::SetCharValue(const std::string& Key, char Value)
	{
		if (DoesKeyExist(Key))
		{
			mBinaryStream.seekp(GetDataOffset(Key));
			mBinaryStream << reinterpret_cast<unsigned char*>(&Value);

			mBinaryStream.seekp(GetBinaryStreamSize());
		}

		mBinaryStream.seekp(0, std::ios::end);
		mBinaryStream.write(reinterpret_cast<char*>(&Value), sizeof(char));
		mBinaryLayout.emplace(Key, mBodySize);

		mBodySize += sizeof(char);
	}

	void BinaryArchive::SetIntValue(const std::string& Key, int Value)
	{
		if (DoesKeyExist(Key))
		{
			mBinaryStream.seekp(GetDataOffset(Key));
			mBinaryStream << reinterpret_cast<unsigned char*>(&Value);

			mBinaryStream.seekp(GetBinaryStreamSize());
		}

		mBinaryStream.seekp(0, std::ios::end);
		mBinaryStream.write(reinterpret_cast<char*>(&Value), sizeof(int));
		mBinaryLayout.emplace(Key, mBodySize);

		mBodySize += sizeof(int);
	}

	void BinaryArchive::SetFloatValue(const std::string& Key, float Value)
	{
		if (DoesKeyExist(Key))
		{
			mBinaryStream.seekp(GetDataOffset(Key));
			mBinaryStream << reinterpret_cast<unsigned char*>(&Value);

			mBinaryStream.seekp(GetBinaryStreamSize());
		}

		mBinaryStream.seekp(0, std::ios::end);
		mBinaryStream.write(reinterpret_cast<char*>(&Value), sizeof(float));
		mBinaryLayout.emplace(Key, mBodySize);

		mBodySize += sizeof(float);
	}

	bool BinaryArchive::GetBoolValue(const std::string& Key, bool* OutputValue)
	{

		if (DoesKeyExist(Key))
		{
			uint32_t DataOffset = GetDataOffset(Key);

			mBinaryStream.seekg(DataOffset);

			bool Value = false;
			mBinaryStream.read(reinterpret_cast<char*>(&Value), sizeof(bool));
			*OutputValue = Value;

			return true;
		}

		return false;

	}

	bool BinaryArchive::GetCharValue(const std::string& Key, char* OutputValue)
	{
		if (DoesKeyExist(Key))
		{
			uint32_t DataOffset = GetDataOffset(Key);

			mBinaryStream.seekg(DataOffset);

			char Value = 0;
			mBinaryStream.read(reinterpret_cast<char*>(&Value), sizeof(char));
			*OutputValue = Value;

			return true;
		}

		return false;
	}

	bool BinaryArchive::GetIntValue(const std::string& Key, int* OutputValue)
	{
		if (DoesKeyExist(Key))
		{
			uint32_t DataOffset = GetDataOffset(Key);

			mBinaryStream.seekg(DataOffset);

			int Value = -1;
			mBinaryStream.read(reinterpret_cast<char*>(&Value), sizeof(int));
			*OutputValue = Value;

			return true;
		}

		return false;
	}

	bool BinaryArchive::GetFloatValue(const std::string& Key, float* OutputValue)
	{
		if (DoesKeyExist(Key))
		{
			uint32_t DataOffset = GetDataOffset(Key);

			mBinaryStream.seekg(DataOffset);

			float Value = -1.0f;
			mBinaryStream.read(reinterpret_cast<char*>(&Value), sizeof(float));
			*OutputValue = Value;

			return true;
		}

		return false;
	}
}
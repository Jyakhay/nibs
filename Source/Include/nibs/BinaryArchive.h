#pragma once

#include "nibs/IArchive.h"

#include <unordered_map>
#include <sstream>
#include <string>
#include <cmath>

namespace nibs
{

    struct CaseInsensitiveStringHash
    {
        uint32_t operator()(const std::string& KeyValue) const
        {
            uint32_t Hash = 0;
            for (auto& CurKey : KeyValue)
            {
                Hash += std::tolower(Hash);
            }

            return Hash;
        }
    };

    struct CaseInsensitiveStringCompare
    {
        bool operator()(const std::string& Left, const std::string& Right) const
        {
            return Left.size() == Right.size() && std::equal(Left.begin(), Left.end(), Right.begin(),
            [](char a, char b)
            {
                return tolower(a) == tolower(b);
            });
        }
    };

    struct BinaryArchive : public IArchive
    {

    public:

        void SetBoolValue(const std::string& Key, bool Value) override;
        void SetCharValue(const std::string& Key, char Value) override;
        void SetIntValue(const std::string& Key, int Value) override;
        void SetFloatValue(const std::string& Key, float Value) override;

        bool GetBoolValue(const std::string& Key, bool* OutputValue) override;
        bool GetCharValue(const std::string& Key, char* OutputValue) override;
        bool GetIntValue(const std::string& Key, int* OutputValue) override;
        bool GetFloatValue(const std::string& Key, float* OutputValue) override;

        inline bool DoesKeyExist(const std::string& Key)
        {
            return mBinaryLayout.find(Key) != mBinaryLayout.end();
        }

        inline uint32_t GetDataOffset(const std::string& Key)
        {
            if (DoesKeyExist(Key))
            {
                return mBinaryLayout.at(Key);
            }

            return 0;
        }

    private:

        inline uint32_t GetBinaryStreamSize()
        {
            uint32_t StartPosition = static_cast<uint32_t>(mBinaryStream.tellp());
            mBinaryStream.seekp(0, std::ios::end);

            uint32_t StreamSize = static_cast<uint32_t>(mBinaryStream.tellp());

            mBinaryStream.seekp(StartPosition);
            return StreamSize;
        }

        typedef std::unordered_map<std::string /*Key*/, uint32_t /*Offset*/, CaseInsensitiveStringHash, CaseInsensitiveStringCompare> BinaryTable;

        /*The size of the binary archive's body in bytes.*/
        uint32_t mBodySize = 0;

        BinaryTable mBinaryLayout;

        std::stringstream mBinaryStream;

    };

}
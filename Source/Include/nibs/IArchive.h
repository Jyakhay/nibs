#pragma once

#include <string>

namespace nibs
{

    struct IArchive
    {

    public:

        virtual void SetBoolValue(const std::string& Key, bool Value) = 0;
        virtual void SetCharValue(const std::string& Key, char Value) = 0;
        virtual void SetIntValue(const std::string& Key, int Value) = 0;
        virtual void SetFloatValue(const std::string& Key, float Value) = 0;

        virtual bool GetBoolValue(const std::string& Key, bool* OutputValue) = 0;
        virtual bool GetCharValue(const std::string& Key, char* OutputValue) = 0;
        virtual bool GetIntValue(const std::string& Key, int* OutputValue) = 0;
        virtual bool GetFloatValue(const std::string& Key, float* Value) = 0;

    private:


    };

}
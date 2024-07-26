#pragma once

#include "IArchive.h"

namespace nibs
{

    struct ISerializable
    {

    public:

        virtual void Serialize(IArchive& Archive) = 0;
        virtual void Deserialize(const IArchive& Archive) = 0;

    private:

    };

}
#pragma once

#include"Blindness.hpp"

namespace NBlindness::NLevel{
    inline class CTranslation{
        private : friend class CLevel;

        private : void FInitialize();
        private : void FUpdate();
    }
    GTranslation;
}
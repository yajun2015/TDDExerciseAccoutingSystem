#pragma once
#include <gmock/gmock.h>
#include "SomeInterface.hpp"

class SomeInterfaceMock : public ISomeInterface
  {
    public:
       MOCK_METHOD0(SetTypeandLineNumber,std::shared_ptr<ISomeInterface>());
       MOCK_METHOD0(SetTypeandMinutesUsed,std::shared_ptr<ISomeInterface>());
       MOCK_METHOD0(SetCustomInfo,std::shared_ptr<ISomeInterface>());
  }



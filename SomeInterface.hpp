#pragma once
#include <string>

class ISomeInterface
{
 public:
      ISomeInterface(){}
      virtual ~ISomeInterface(){}
      
      virtual std::shared_ptr<ISomeInterface> SetTypeandLineNumber() = 0;
      virtual std::shared_ptr<ISomeInterface> SetTypeandMinutesUsed() = 0;
      virtual std::shared_ptr<ISomeInterface> SetCustomInfo() = 0;
};

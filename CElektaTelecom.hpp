#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <memory>
#include "SomeInterface.hpp"
class ISomeInterface;
class CElektaTelecom
{
public:

  //CFileAnalyzer& operator=(const CFileAnalyzer&);
  CElektaTelecom();
 ~CElektaTelecom();
  CElektaTelecom(ISomeInterface& someinfo);
  CElektaTelecom& operator=(const CElektaTelecom&);
  


 
  int calculateMonthlyBillBaseOnCustomInfo();
  int calculateMonthlyBillBaseOnCustomInfo();
  int SetTypeandLineNumber();
  int SetTypeandMinutesUsed();
  int SetCustomInfo() ;
  int calculateMonthlyBillForSilverBaseOnLineMinutesUsed();
  int calculateMonthlyBillForGoldBaseOnLineMinutesUsed();
  int calculateMonthlyBillForGoldBaseOnLineNumbers();
  int CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndHas3Lines();
  
private:

  enum l_TypeOfPlan={ Gold, Silver };
  int l_NumOfLines;
  int l_MinutesUsed;

};



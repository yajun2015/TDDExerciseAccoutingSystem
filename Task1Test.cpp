#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "CElektaTelecom.hpp"
#include "ElektaTelecomMock.hpp"
#include "string"
using namespace std;
using ::testing::Return;
using namespace ::testing;
struct ElektaTelecomInfo1 :  Test
{
    enum l_TypeOfPlan={ Gold, Silver };;
    int l_NumOfLines;
    CElektaTelecomMock ElektaObjMock;
};


TEST_F(ElektaTelecomInfo1, CalculateMonthlyPhoneBillBaseonPlanTypeIsGoldAndOnlyHasOneLine)
{
    l_NumOfLines=1;
    EXPECT_CALL(ElektaObjMock, SetTypeandLineNumber()).Times(1).WillOnce(Return(l_TypeOfPlan::Gold,l_NumOfLines));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForGoldBaseOnLineNumbers(), 49.95);     
}
TEST_F(ElektaTelecomInfo1, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHasOneLine)
{
    l_NumOfLines=1;
    EXPECT_CALL(ElektaObjMock, SetTypeandLineNumber()).Times(1).WillOnce(Return(l_TypeOfPlan::Silver,l_NumOfLines));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForSilverBaseOnLineNumbers(), 29.95);    
}
TEST_F(ElektaTelecomInfo1, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndHas3Lines)
{
    l_NumOfLines=3;
    EXPECT_CALL(ElektaObjMock, SetTypeandLineNumber()).Times(1).WillOnce(Return(l_TypeOfPlan::Silver,l_NumOfLines));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForSilverBaseOnLineNumbers(), 72.95);    
}
TEST_F(ElektaTelecomInfo1, CalculateMonthlyPhoneBillBaseonPlanTypeIsGoldAndHas2Line)
{
    l_NumOfLines=2;
    EXPECT_CALL(ElektaObjMock, SetTypeandLineNumber()).Times(1).WillOnce(Return(l_TypeOfPlan::Gold,l_NumOfLines));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForGoldBaseOnLineNumbers(), 64.45);    
}

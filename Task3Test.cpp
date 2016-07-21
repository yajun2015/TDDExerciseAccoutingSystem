#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "CElektaTelecom.hpp"
#include "ElektaTelecomMock.hpp"
#include "string"
using namespace std;
using ::testing::Return;
using namespace ::testing;
struct ElektaTelecomInfo :  Test
{
    enum l_TypeOfPlan={ Gold, Silver };;
    int l_NumOfLines;
    int l_MinutesUsed;
    CElektaTelecomMock ElektaObjMock;
};
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonTypeandMinutesUseWhichIsSilverHaveFourLineslessthenBaserate)
{
    l_NumOfLines=4;
    l_MinutesUsed=499
    EXPECT_CALL(ElektaObjMock, SetCustomInfo()).Times(1).WillOnce(Return(l_NumOfLines,l_TypeOfPlan::Silver,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillBaseOnCustomInfo(), 77.95);     
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHaveFiveLinesmorethenbaserate)
{
    l_NumOfLines=5;
    l_MinutesUsed=501;
    EXPECT_CALL(ElektaObjMock, SetCustomInfo()).Times(1).WillOnce(Return(l_NumOfLines,l_TypeOfPlan::Silver,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillBaseOnCustomInfo(), 83.49);    
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsGoldAndOnlyHavetwoLineslessthenbaserate)
{
    l_NumOfLines=2;
    l_MinutesUsed=900;    
    EXPECT_CALL(ElektaObjMock, SetCustomInfo()).Times(1).WillOnce(Return(l_NumOfLines,l_TypeOfPlan::Gold,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillBaseOnCustomInfo(), 64.45);    
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHaveThreeLineslessthenbaserate)
{
    l_NumOfLines=3;
    l_MinutesUsed=999;    
    EXPECT_CALL(ElektaObjMock, SetCustomInfo()).Times(1).WillOnce(Return(l_NumOfLines,l_TypeOfPlan::Gold,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillBaseOnCustomInfo(), 78.95);    
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHaveFourLineslessthenbaserate)
{
    l_NumOfLines=4;
    l_MinutesUsed=800;    
    EXPECT_CALL(ElektaObjMock, SetCustomInfo()).Times(1).WillOnce(Return(l_NumOfLines,l_TypeOfPlan::Gold,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillBaseOnCustomInfo(), 83.95);    
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHaveFourLinesmorethenbaserate)
{
    l_NumOfLines=4;
    l_MinutesUsed=1001;    
    EXPECT_CALL(ElektaObjMock, SetCustomInfo()).Times(1).WillOnce(Return(l_NumOfLines,l_TypeOfPlan::Gold,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillBaseOnCustomInfo(), 84.40);    
}
#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "CElektaTelecom.hpp"
#include "ElektaTelecomMock.hpp"
#include "string"
using namespace std;
using ::testing::Return;
using namespace ::testing;
struct ElektaTelecomInfo2 :  Test
{
    enum l_TypeOfPlan={ Gold, Silver };;
    int l_MinutesUsed;
    CElektaTelecomMock ElektaObjMock;
};


TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverOnlyHaveOneLinelessthenbaserate)
{
    l_MinutesUsed=499;
    EXPECT_CALL(ElektaObjMock, SetTypeandMinutesUsed()).Times(1).WillOnce(Return(l_TypeOfPlan::Silver,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForSilverBaseOnLineMinutesUsed(), 29.95);     
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHaveOneLinemorethenbaserate)
{
    l_MinutesUsed=520;
    EXPECT_CALL(ElektaObjMock, SetTypeandMinutesUsed()).Times(1).WillOnce(Return(l_TypeOfPlan::Silver,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForSilverBaseOnLineMinutesUsed(), 40.75);    
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsGoldAndOnlyHaveOneLinelessthenbaserate)
{
    l_MinutesUsed=999;
    EXPECT_CALL(ElektaObjMock, SetTypeandMinutesUsed()).Times(1).WillOnce(Return(l_TypeOfPlan::Gold,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForGoldBaseOnLineMinutesUsed(), 49.95);    
}
TEST_F(ElektaTelecomInfo, CalculateMonthlyPhoneBillBaseonPlanTypeIsSilverAndOnlyHaveOneLinemorethenbaserate)
{
    l_MinutesUsed=1001;
    EXPECT_CALL(ElektaObjMock, SetTypeandMinutesUsed()).Times(1).WillOnce(Return(l_TypeOfPlan::Gold,l_MinutesUsed));
    std::unique_ptr<CElektaTelecom> ElektaObj(std::make_unique<CElektaTelecom>(ElektaObjMock));
    ASSERT_EQ(ElektaObj->calculateMonthlyBillForGoldrBaseOnLineMinutesUsed(), 50.40);    
}
#include "awards.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>

using namespace ::testing;
using namespace ::std;

class RankListMock : public RankList {
 public:
  MOCK_METHOD(string, getNext, ());
};

class AwardCeremonyActionsMock : public AwardCeremonyActions {
 public:
  MOCK_METHOD(void, playAnthem, ());
  MOCK_METHOD(void, turnOffTheLightsAndGoHome, ());
  MOCK_METHOD(void, awardBronze, (string recipient));
  MOCK_METHOD(void, awardSilver, (string recipient));
  MOCK_METHOD(void, awardGold, (string recipient));
};

TEST(AwardsTest, testPerformAwardCeremony) {
  RankListMock ranklist;
  AwardCeremonyActionsMock actionsMock;

  performAwardCeremony(ranklist, actionsMock);
}

TEST(AwardsTest, testAllwaysRankPaul) {
  RankListMock ranklist;
  AwardCeremonyActionsMock actionsMock;

  ON_CALL(ranklist, getNext()).WillByDefault(Return("Paul"));

  performAwardCeremony(ranklist, actionsMock);
}

TEST(AwardsTest, testCeremony) {
  NiceMock<RankListMock> ranklist;
  StrictMock<AwardCeremonyActionsMock> actionsMock;

  ON_CALL(ranklist, getNext()).WillByDefault(Return("Paul"));

  EXPECT_CALL(actionsMock, playAnthem());
  EXPECT_CALL(actionsMock, turnOffTheLightsAndGoHome());
  EXPECT_CALL(actionsMock, awardBronze(StrEq("Paul")));
  EXPECT_CALL(actionsMock, awardSilver(StrEq("Paul")));
  EXPECT_CALL(actionsMock, awardGold(StrEq("Paul")));

  performAwardCeremony(ranklist, actionsMock);
}

TEST(AwardsTest, testCeremonySequence) {
  NiceMock<RankListMock> ranklist;
  StrictMock<AwardCeremonyActionsMock> actionsMock;

  ON_CALL(ranklist, getNext()).WillByDefault(Return("Paul"));

  {
    InSequence s;
    EXPECT_CALL(actionsMock, playAnthem());
    EXPECT_CALL(actionsMock, awardBronze(StrEq("Paul")));
    EXPECT_CALL(actionsMock, awardSilver(StrEq("Paul")));
    EXPECT_CALL(actionsMock, awardGold(StrEq("Paul")));
    EXPECT_CALL(actionsMock, turnOffTheLightsAndGoHome());
  }

  performAwardCeremony(ranklist, actionsMock);
}

TEST(AwardsTest, testFairCeremony) {
  NiceMock<RankListMock> ranklist;
  StrictMock<AwardCeremonyActionsMock> actionsMock;

  EXPECT_CALL(ranklist, getNext()).WillOnce(Return("Palle")).RetiresOnSaturation();
  EXPECT_CALL(ranklist, getNext()).WillOnce(Return("Polle")).RetiresOnSaturation();
  EXPECT_CALL(ranklist, getNext()).WillOnce(Return("Ruth")).RetiresOnSaturation();

  {
    InSequence s;
    EXPECT_CALL(actionsMock, playAnthem());
    EXPECT_CALL(actionsMock, awardBronze(StrEq("Ruth")));
    EXPECT_CALL(actionsMock, awardSilver(StrEq("Polle")));
    EXPECT_CALL(actionsMock, awardGold(StrEq("Palle")));
    EXPECT_CALL(actionsMock, turnOffTheLightsAndGoHome());
  }

  performAwardCeremony(ranklist, actionsMock);
}



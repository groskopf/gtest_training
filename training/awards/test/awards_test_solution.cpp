#include "awards.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>

using namespace ::testing;
using namespace ::std;

class RankListMock : public RankList {
 public:
  MOCK_METHOD0(getNext, string());
};

class AwardCeremonyActionsMock : public AwardCeremonyActions {
 public:
  MOCK_METHOD0(playAnthem, void());
  MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
  MOCK_METHOD1(awardBronze, void(string recipient));
  MOCK_METHOD1(awardSilver, void(string recipient));
  MOCK_METHOD1(awardGold, void(string recipient));
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

  EXPECT_CALL(ranklist, getNext()).Times(3).WillRepeatedly(Return("Paul"));

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

  EXPECT_CALL(ranklist, getNext()).Times(3).WillRepeatedly(Return("Paul"));

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

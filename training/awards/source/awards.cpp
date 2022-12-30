#include "awards.h"

void performAwardCeremony(RankList& recipients, AwardCeremonyActions& actions) {
  actions.playAnthem();
  actions.awardBronze(recipients.getNext());
  actions.awardSilver(recipients.getNext());
  actions.awardGold(recipients.getNext());
  actions.turnOffTheLightsAndGoHome();
}

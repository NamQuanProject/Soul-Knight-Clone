
#include "bigHealingPotion.h"

BigHealingPotion::BigHealingPotion() {
    // SetInteractiveText("Big Healing Potion", InteractiveText::MYTHIC);
}


void BigHealingPotion::Start() {
    Collectable::Start();
}

void BigHealingPotion::Update(float deltaTime) {
    Collectable::Update(deltaTime);
}

void BigHealingPotion::LoadResources() {
    // AddAnimation({"Resources/collectable/big_healing_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void BigHealingPotion::Interactive(Player* player) {
    // player->Healing(4);
   AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}
void BigHealingPotion::Initialize() {
    return ;
}
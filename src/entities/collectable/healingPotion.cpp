
#include "healingPotion.h"

HealingPotion::HealingPotion() {
    // SetInteractiveText("Healing Potion", InteractiveText::MYTHIC);
}

void HealingPotion::Start() {
    Collectable::Start();
}

void HealingPotion::Update(float deltaTime) {
    Collectable::Update(deltaTime);
}

void HealingPotion::LoadResources() {
    // AddAnimation({"Resources/collectable/healing_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void HealingPotion::Interactive(Player* player) {
    // player->Healing(2);
    // AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}

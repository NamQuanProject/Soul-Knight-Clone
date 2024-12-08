
#include "mpPotion.h"

MpPotion::MpPotion() {
    // SetInteractiveText("MP Potion", InteractiveText::RARE);
}

void MpPotion::Start() {
    Collectable::Start();
}

void MpPotion::Update(float deltaTime) {
    Collectable::Update(deltaTime);
}

void MpPotion::LoadResources() {
    // AddAnimation({"Resources/collectable/mp_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void MpPotion::Interactive(Player* player) {
    // player->RecoverMP(80);
    // AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}

void MpPotion::Initialize() {
    return;
}
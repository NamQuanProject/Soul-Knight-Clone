#include "bigMpPotion.h"

BigMpPotion::BigMpPotion() {
   
}



void BigMpPotion::Update(float deltaTime) {
    Collectable::Update(deltaTime);
}

void BigMpPotion::LoadResources() {
    // AddAnimation({"Resources/collectable/big_mp_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void BigMpPotion::Interactive(Player* player) {
    // player->RecoverMP(150);
    // AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}

void BigMpPotion::Initialize() {
    return ;
}
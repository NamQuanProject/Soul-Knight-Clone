#include "compositePotion.h"

CompositePotion::CompositePotion() {
    // SetInteractiveText("Composite Potion", InteractiveText::EPIC);
}

void CompositePotion::Start() {
    Collectable::Start();
}

void CompositePotion::Update(float deltaTime ) {
    Collectable::Update(deltaTime);
}

void CompositePotion::LoadResources() {
    // AddAnimation({"Resources/collectable/composite_potion.bmp"}, RGB(255,255,255), 1000, false);
}

void CompositePotion::Interactive(Player* player) {
    // player->Healing(1);
    // player->RecoverMP(40);
    // AddTag(Tag::REMOVE_ON_NEXT_FRAME);
}

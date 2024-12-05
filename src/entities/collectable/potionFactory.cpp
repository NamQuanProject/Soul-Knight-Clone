#include "potionFactory.h"

#include "bigCompositePotion.h"
#include "bigHealingPotion.h"
#include "bigMpPotion.h"
#include "compositePotion.h"
#include "healingPotion.h"
#include "mpPotion.h"

Collectable* PotionFactory::Create(PotionType type) {
    switch (type) {
    case HEALING:
        return new HealingPotion();
    case BIG_HEALING:
        return new BigHealingPotion();
    case MP:
        return new MpPotion();
    case BIG_MP:
        return new BigMpPotion();
    case COMPOSITE:
        return new CompositePotion();
    case BIG_COMPOSITE:
        return new BigCompositePotion();
    default:
        return nullptr;
    }
}

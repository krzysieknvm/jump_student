//
// Created by kkoni on 13.03.2025.
//

#include "../module/MainCharacter.h"

MainCharacter::MainCharacter(const QString &characterInRest, const QString &characterInJump) {
    characterInRestPX = QPixmap(characterInRest).scaled(57,72);
    characterInJumpPX = QPixmap(characterInJump).scaled(57,66);

    setPixmap(characterInRestPX);
}

void MainCharacter::inJump(bool in_jump) {
    setPixmap(in_jump ? characterInJumpPX : characterInRestPX);
}


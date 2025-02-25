#include "SramData.hpp"
#include "bn_log.h"

SramData& SramData::getInstance() {
    static SramData instance;
    if(!instance._loaded) {
        instance._loaded = true;
        instance.load();
    }
    return instance;
}

void SramData::load() {
    _SramData::data savedData;
    bn::sram::read(savedData);

    this->highScore = savedData.highScore;
}

void SramData::write() {
    _SramData::data savedData;
    savedData.highScore = this->highScore;
    BN_LOG("savedData.highScore", savedData.highScore);
    bn::sram::write(savedData);
}

void SramData::clear() {
    bn::sram::clear(bn::sram::size());
}

int SramData::getHighScore() {
    return this->highScore;
}

SramData* SramData::setHighScore(int _highScore) {
    this->highScore = _highScore;
    return this;
}
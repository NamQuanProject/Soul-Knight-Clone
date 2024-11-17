#include "soundManager.h"
#include <iostream>

SoundManager::SoundManager() : currentMusic(nullptr) {
    loadAllMusic();
}

SoundManager::~SoundManager() {
    stopMusic();
}

void SoundManager::loadAllMusic() {
    loadMusic("background", "../resources/sound/background.mp3");
}

void SoundManager::loadMusic(const std::string& name, const std::string& filename) {
    auto music = std::make_unique<sf::Music>(); // Create a unique_ptr
    if (music->openFromFile(filename)) {
        musicTracks[name] = std::move(music); // Move the unique_ptr into the map
    } else {
        std::cerr << "Error loading music: " << filename << std::endl;
    }
}

void SoundManager::playMusic(const std::string& name) {
    if (musicTracks.find(name) != musicTracks.end()) {
        if (currentMusic) {
            currentMusic->stop(); 
        }
        currentMusic = musicTracks[name].get(); // Get the raw pointer to the music
        currentMusic->setLoop(true); 
        currentMusic->setVolume(1);
        currentMusic->play();
    } else {
        std::cerr << "Music not found: " << name << std::endl;
    }
}

void SoundManager::stopMusic() {
    if (currentMusic) {
        currentMusic->stop();
        currentMusic = nullptr;
    }
}

void SoundManager::setVolume(float volume) {
    if (currentMusic) {
        currentMusic->setVolume(volume);
    }
}

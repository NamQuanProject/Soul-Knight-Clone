#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <string>
#include <map>
#include <memory> // Include for std::unique_ptr

class SoundManager {
public:
    SoundManager();
    ~SoundManager();

    void loadMusic(const std::string& name, const std::string& filename);
    void loadAllMusic(); 
    void playMusic(const std::string& name);
    void stopMusic();
    void setVolume(float volume);

private:
    std::map<std::string, std::unique_ptr<sf::Music>> musicTracks; // Use unique_ptr for music tracks
    sf::Music* currentMusic; // Pointer to currently playing music
};

#endif // SOUNDMANAGER_H

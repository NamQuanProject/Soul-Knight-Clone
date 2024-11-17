#include "keyboardManager.h"
#include <iostream>

KeyboardManager::KeyboardManager() {
    // Initially, all keys are considered as released
}

KeyboardManager::~KeyboardManager() {
    // Destructor can be used to clean up, but here there's nothing to clean
}

void KeyboardManager::Update() {
    for (auto& entry : keyStates) {
        int key = entry.first;
        KeyState currentState = entry.second;

        // Check if the key is just pressed or released based on previous state
        if (prevKeyStates.find(key) != prevKeyStates.end()) {
            if (prevKeyStates[key] == KeyState::PRESSED && currentState == KeyState::HELD) {
                // Key is being held
                prevKeyStates[key] = KeyState::HELD;
            } else if (prevKeyStates[key] == KeyState::HELD && currentState == KeyState::RELEASED) {
                // Key is released
                prevKeyStates[key] = KeyState::RELEASED;
            }
        }

        // Update previous state for the next frame
        prevKeyStates[key] = currentState;
    }
}

bool KeyboardManager::IsKeyPressed(int key) const {
    auto it = keyStates.find(key);
    if (it != keyStates.end() && it->second == KeyState::PRESSED) {
        return true;
    }
    return false;
}

bool KeyboardManager::IsKeyReleased(int key) const {
    auto it = keyStates.find(key);
    if (it != keyStates.end() && it->second == KeyState::RELEASED) {
        return true;
    }
    return false;
}

bool KeyboardManager::IsKeyHeld(int key) const {
    auto it = keyStates.find(key);
    if (it != keyStates.end() && it->second == KeyState::HELD) {
        return true;
    }
    return false;
}

void KeyboardManager::SetKeyState(int key, KeyState state) {
    keyStates[key] = state;
}

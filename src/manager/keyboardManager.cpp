#include "keyboardManager.h"

KeyboardManager::KeyboardManager() {
}

KeyboardManager::~KeyboardManager() {
}

void KeyboardManager::Update() {
    prevKeyStates = keyStates;
    for (auto& [key, state] : keyStates) {
        if (state == KeyState::PRESSED) {
            keyStates[key] = KeyState::HELD;
        } else if (state == KeyState::RELEASED) {
            keyStates.erase(key); // Remove key from active state tracking
        }
    }
}

bool KeyboardManager::IsKeyPressed(int key) const {
    auto current = keyStates.find(key);
    auto previous = prevKeyStates.find(key);

    return (current != keyStates.end() && current->second == KeyState::PRESSED) &&
           (previous == prevKeyStates.end() || previous->second != KeyState::PRESSED);
}

bool KeyboardManager::IsKeyReleased(int key) const {
    auto current = keyStates.find(key);
    auto previous = prevKeyStates.find(key);

    return (current != keyStates.end() && current->second == KeyState::RELEASED) &&
           (previous != prevKeyStates.end() && previous->second != KeyState::RELEASED);
}

bool KeyboardManager::IsKeyHeld(int key) const {
    auto current = keyStates.find(key);
    return current != keyStates.end() && current->second == KeyState::HELD;
}

void KeyboardManager::SetKeyState(int key, KeyState state) {
    keyStates[key] = state;
}

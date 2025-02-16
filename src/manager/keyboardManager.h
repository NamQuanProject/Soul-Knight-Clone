#pragma once

#include <unordered_map>


enum class KeyState {
    PRESSED,
    RELEASED,
    HELD
};

class KeyboardManager {
public:
    

    KeyboardManager();
    ~KeyboardManager();

    void Update();

    bool IsKeyPressed(int key) const;

    bool IsKeyReleased(int key) const;

    bool IsKeyHeld(int key) const;

    void SetKeyState(int key, KeyState state);

private:
    std::unordered_map<int, KeyState> keyStates;

    std::unordered_map<int, KeyState> prevKeyStates;
};

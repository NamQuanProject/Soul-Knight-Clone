#pragma once

#include <unordered_map>

class KeyboardManager {
public:
    // Enum to represent the key state
    enum class KeyState {
        PRESSED,
        RELEASED,
        HELD
    };

    KeyboardManager();
    ~KeyboardManager();

    void Update();                       // Update key states (must be called every frame)
    bool IsKeyPressed(int key) const;     // Check if a key was pressed in the current frame
    bool IsKeyReleased(int key) const;    // Check if a key was released in the current frame
    bool IsKeyHeld(int key) const;        // Check if a key is being held down
    void SetKeyState(int key, KeyState state);  // Set the state of a key

private:
    std::unordered_map<int, KeyState> keyStates;   // Map of key codes to their states
    std::unordered_map<int, KeyState> prevKeyStates;  // Map of previous key states (for detecting key up/down)
};

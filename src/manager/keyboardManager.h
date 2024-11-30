// #pragma once

// #include <unordered_map>

// class KeyboardManager {
// public:
//     // Enum to represent the key state
//     enum class KeyState {
//         PRESSED,
//         RELEASED,
//         HELD
//     };

//     KeyboardManager();
//     ~KeyboardManager();

//     // Update key states (must be called every frame)
//     void Update();

//     // Check if a key was pressed in the current frame
//     bool IsKeyPressed(int key) const;

//     // Check if a key was released in the current frame
//     bool IsKeyReleased(int key) const;

//     // Check if a key is being held down
//     bool IsKeyHeld(int key) const;

//     // Set the state of a key
//     void SetKeyState(int key, KeyState state);

// private:
//     // Map of key codes to their current states
//     std::unordered_map<int, KeyState> keyStates;

//     // Map of key codes to their previous states (for detecting key changes)
//     std::unordered_map<int, KeyState> prevKeyStates;
// };

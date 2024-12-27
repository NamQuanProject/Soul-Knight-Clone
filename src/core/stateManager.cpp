
#include "stateManager.h"
#include "menuState.h"   
#include "gameState.h"   
#include "pauseState.h"  
#include "selectionState.h"

StateManager* StateManager::instance = nullptr;

StateManager* StateManager::Instance() {
    if (instance == nullptr) {
        instance = new StateManager();
    }
    return instance;
}
State* StateManager::GetCurrentState() {
    return currentState;
}

StateManager::StateManager() {
    Initialize();
}

StateManager::~StateManager() {
    // delete currentState;
    // currentState = nullptr;
}

void StateManager::Initialize() {
    currentState = new MenuState();   
}

void StateManager::Update(float deltaTime) {
    currentState->update(deltaTime);
}

void StateManager::Render(sf::RenderWindow& window) {
    currentState->render(window);
}

void StateManager::HandleEvent(const sf::Event& event, sf::RenderWindow& window) {
    currentState->handleEvent(event, window);
}

void StateManager::SwitchState(StateType type) {
    if (currentState != nullptr) {
        delete currentState;
        currentState = nullptr;
    }

    switch (type) {
    case StateType::MENU_STATE:
        currentState = new MenuState();   
        break;
    case StateType::SELECTION_STATE:
        currentState = new SelectionState();
        break;
    case StateType::GAME_STATE:
        currentState = new GameState();
        break;
    case StateType::PAUSE_STATE:
        currentState = new PauseState();
        break;
    }
    // currentState->Initialize();
}
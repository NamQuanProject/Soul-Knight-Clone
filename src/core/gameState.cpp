#include "gameState.h"

GameState::GameState() {
    Initialize();
    soundManager.playMusic("background");
   
}

GameState::~GameState() {
    
}


void GameState::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed) {
        window.close();
    }
    
    Vec newSpeed(0.0, 0.0);
    double speed = 0.05;
    double diagSpeed = speed / std::sqrt(2);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        newSpeed.SetX(+diagSpeed);
        newSpeed.SetY(-diagSpeed);
        objectManager->GetPlayer()->runRight();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        newSpeed.SetX(-diagSpeed);
        newSpeed.SetY(-diagSpeed);
        objectManager->GetPlayer()->runLeft();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        newSpeed.SetX(+diagSpeed);
        newSpeed.SetY(+diagSpeed);
        objectManager->GetPlayer()->runRight();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        newSpeed.SetX(-diagSpeed);
        newSpeed.SetY(+diagSpeed);
        objectManager->GetPlayer()->runLeft();
    }

    // Handle single-direction movement
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        
        newSpeed.SetY(-speed);
        if (objectManager->GetPlayer()->CheckFace() == Knight::RIGHT) {
            objectManager->GetPlayer()->runRight();
        } else {
            objectManager->GetPlayer()->runLeft();
        }
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (objectManager->GetPlayer()->CheckFace() == Knight::RIGHT) {
            objectManager->GetPlayer()->runRight();
        } else {
            objectManager->GetPlayer()->runLeft();
        }
        
        newSpeed.SetY(+speed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        objectManager->GetPlayer()->runLeft();
        newSpeed.SetX(-speed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        objectManager->GetPlayer()->runRight();
        newSpeed.SetX(+speed);
        
    }
    else {
        if (objectManager->GetPlayer()->CheckFace() == Knight::RIGHT) {
            objectManager->GetPlayer()->standRight();
        } else {
            objectManager->GetPlayer()->standLeft();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
        objectManager->GetPlayer()->Attack(); 
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        objectManager->GetPlayer()->SetInteractive(true); 
    }
    else {
        objectManager->GetPlayer()->SetInteractive(false); 
    }

    // Update player speed
    objectManager->GetPlayer()->setSpeed(newSpeed);
}


void GameState::Initialize() {
    std::cout << "INitialize object manager" << std::endl;
    objectManager->Initialize();
     std::cout << "FINISH Initialize object manager" << std::endl;

    std::cout << "Pool initilize" << std::endl;
    projectilePool->Initialize();
    monsterPool->Initialize();
    std::cout << "Pool initilize finish" << std::endl;
    

    std::cout << "INitialize stage manager" << std::endl;
    stageManager->Initialize();
    std::cout << "Finish stage manager" << std::endl;

    uiManager->Initialize();

}

void GameState::update(float deltaTime) {
    
    stageManager->Update(deltaTime);
    objectManager->Update(deltaTime);
    uiManager->Update(deltaTime);
    
}

void GameState::render(sf::RenderWindow& window) {
    stageManager->GetStage()->Render(window);
    objectManager->Render(window);
    uiManager->Render(window);
}

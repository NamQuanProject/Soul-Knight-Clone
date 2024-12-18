#include <SFML/Graphics.hpp>
#include "camera.h"
#include "objectManager.h"

class UIManager {
public:
    static UIManager* Instance();
    UIManager();  
    ~UIManager(); 

    void Initialize();             
    void Update(float deltaTime);  
    void applyView(sf::RenderWindow& window); 
    void Render(sf::RenderWindow& window);  
    void setWorldBounds(sf::FloatRect worldBounds);
private:
    static UIManager* instance;
    Camera camera;                  
  
    sf::Texture playerTexture;     
    sf::Sprite playerSprite;       
};

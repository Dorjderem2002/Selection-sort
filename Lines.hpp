#ifndef Lines_hpp
#define Lines_hpp

#include <SFML/Graphics.hpp>
#include <stdlib.h>

namespace line {
    
    class Lines {
    public:
    
        Lines(float h);
        void draw(sf::RenderWindow &window);
        void move(float speed);
        sf::Vector2f getPos();
        void setPos(float x);
        void setColor(sf::Color color);
        float getHeight();
        void setH(float h);
    private:
        sf::RectangleShape line;
        float height;
    };

}


#endif /* Lines_hpp */

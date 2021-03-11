//
//  main.cpp
//  SelectionSort
//
//  Created by Dode Pep on 11/21/19.
//  Copyright © 2019 Dode. All rights reserved.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include "Lines.hpp"
#include <iostream>
using namespace sf;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    srand(time(0));
    RenderWindow window(VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),"Selection Sort");
    
    std::vector<line::Lines> lines;
    int height = 760;
    int width = 800/2;
    int k=0,f=0;
    bool running = true;
    for(int i=0;i<width*2;i+=2) {
        line::Lines l(rand()%height);
        l.setPos(i);
        lines.push_back(l);
    }
    window.setFramerateLimit(60);
    while (window.isOpen() && running) {
        Event e;
        while (window.pollEvent(e)) {
            if(e.type == Event::Closed) {
                window.close();
            }
        }
        for(int d=0;d<100;d++) {
            if(k > width -1) {
                running = false;
            }
            float a = lines[f].getHeight();
            float b = lines[f+1].getHeight();
            if(a > b) {
                std::swap(lines[f], lines[f+1]);
                float pos = lines[f+1].getPos().x;
                lines[f+1].setPos(lines[f].getPos().x);
                lines[f].setPos(pos);
            }
            f++;
            if(f >=  width-1) {
                f = 0;
                k++;
            }
        }
        window.clear();
        for(int i=0;i<width;i++) {
            lines[i].draw(window);
        }
        window.display();
    }
    return 0;
}

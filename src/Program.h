//
// Created by hunde on 3/30/2024.
//

#ifndef PROGRAM_H
#define PROGRAM_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "BlackHole.h"
#include "LightSource.h"
#include "Photon.h"

class Program {

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    float dt;

    LightSource* light1;
    LightSource* light2;
    LightSource* light3;
    LightSource* light4;
    BlackHole m_blackHole;


    void Update();
    void HandleEvents();
    void HandleKeyboardInput(sf::Keyboard::Key key);
    void Render();


    std::list<Photon> m_photons;


public:
    Program();
    ~Program();
    void Run();


};



#endif //PROGRAM_H

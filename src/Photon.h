//
// Created by hunde on 3/30/2024.
//

#ifndef PHOTON_H
#define PHOTON_H
#define PI 3.14159
#include <SFML/Graphics.hpp>
#include <cmath>


class Photon {

    sf::Vertex m_vertex;
    float m_speed;
    float m_lifeSpan;
    float m_maxSpeed;
    float m_dampStrength;

public:
    Photon(sf::Vector2f lightPos);
    sf::Vector2f velocity;
    void ManageVertex(float dt);
    const sf::Vertex& GetVertex();
    const float& GetLifespan();


    bool b_queuedForDeletion;
};



#endif //PHOTON_H

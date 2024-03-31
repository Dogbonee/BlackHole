//
// Created by hunde on 3/30/2024.
//

#include "Photon.h"

#include <iostream>

Photon::Photon(sf::Vector2f lightPos) : m_speed(100), b_queuedForDeletion(false), m_lifeSpan(10.f), m_maxSpeed(200), m_dampStrength(500)
{
    m_vertex.color = sf::Color(255, 208, 0);
    m_vertex.position = lightPos;

    float randAngle = static_cast<float>(std::rand() % 3600) / 10.f;
    float radAngle = randAngle * PI / 180.f;


    sf::Vector2f normalizedVelocity(sin(radAngle) * m_speed, cos(radAngle) * m_speed);

    velocity = normalizedVelocity;

    //std::cout<< velocity.x << ' ' <<velocity.y<<'\n';

}

void Photon::ManageVertex(float dt)
{
    sf::Vector2f direction(abs(velocity.x) / velocity.x, abs(velocity.y) / velocity.y);
    if(abs(velocity.x) > m_maxSpeed) velocity.x -= m_dampStrength * direction.x * dt;
    if(abs(velocity.y) > m_maxSpeed) velocity.y -= m_dampStrength * direction.y * dt;
    m_vertex.position.x += velocity.x * dt;
    m_vertex.position.y += velocity.y * dt;

    m_lifeSpan -= dt;
}

const sf::Vertex & Photon::GetVertex()
{
    return m_vertex;
}

const float & Photon::GetLifespan()
{
    return m_lifeSpan;
}

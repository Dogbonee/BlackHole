//
// Created by hunde on 3/30/2024.
//

#include "BlackHole.h"

#include <iostream>


BlackHole::BlackHole(std::list<Photon> &photons) : p_photons(&photons), m_gravity(5000000), m_explosionStrength(10000000)
{
    m_shape.setFillColor(sf::Color::Black);
    m_shape.setRadius(75);
    m_shape.setOrigin(m_shape.getRadius(), m_shape.getRadius());
}

void BlackHole::ManageBlackHole(float dt)
{
    for(auto& photon : *p_photons)
    {
        sf::Vector2f distanceTriangle(m_position.x - photon.GetVertex().position.x, m_position.y - photon.GetVertex().position.y);

        if(distanceTriangle.x < 1 && distanceTriangle.x > -1) distanceTriangle.x = 1;
        if(distanceTriangle.y < 1 && distanceTriangle.y > -1) distanceTriangle.y = 1;

        sf::Vector2f direction (distanceTriangle.x/abs(distanceTriangle.x),  distanceTriangle.y/abs(distanceTriangle.y));
        float distance = sqrt(pow(distanceTriangle.x,2) + pow(distanceTriangle.y, 2));


        if(distance < m_shape.getRadius() - 10) distance += 100000;
        float appliedGravity = abs(m_gravity / pow(distance,2));

        //if(appliedGravity > m_gravity) std::cout<<appliedGravity<<'\n';

        photon.velocity.x += appliedGravity * direction.x * dt;
        photon.velocity.y += appliedGravity * direction.y * dt;

        //photon.velocity = NormalizeVector(photon.velocity);

    }
}

void BlackHole::Explode()
{
    std::cout<<"Exploding\n";
    for(auto& photon : *p_photons)
    {
        sf::Vector2f distanceTriangle(m_position.x - photon.GetVertex().position.x, m_position.y - photon.GetVertex().position.y);

        if(distanceTriangle.x < 1 && distanceTriangle.x > -1) distanceTriangle.x = 1;
        if(distanceTriangle.y < 1 && distanceTriangle.y > -1) distanceTriangle.y = 1;

        sf::Vector2f direction (distanceTriangle.x/abs(distanceTriangle.x),  distanceTriangle.y/abs(distanceTriangle.y));
        float distance = sqrt(pow(distanceTriangle.x,2) + pow(distanceTriangle.y, 2));

        float appliedExplosionStrength = abs(m_explosionStrength / pow(distance,2));


        photon.velocity.x -= appliedExplosionStrength * direction.x;
        photon.velocity.y -= appliedExplosionStrength * direction.y;


    }
}

void BlackHole::SetBlackHolePosition(sf::Vector2f position)
{
    m_position = position;
    m_shape.setPosition(m_position);
}

void BlackHole::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_shape);
}



sf::Vector2f BlackHole::NormalizeVector(const sf::Vector2f &vector)
{
    //Doesn't work
    float magnitude = sqrt(pow(vector.x,2) + pow(vector.y, 2));

    float angle = std::atan(vector.y / vector.x);

    sf::Vector2f normalizedVector(cos(angle) * magnitude, sin(angle) * magnitude);
    //std::cout<<normalizedVector.x<< ' ' << normalizedVector.y<<'\n';

    return normalizedVector;



}

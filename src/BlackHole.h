//
// Created by hunde on 3/30/2024.
//

#ifndef BLACKHOLE_H
#define BLACKHOLE_H
#include <list>

#include "Photon.h"


class BlackHole : public sf::Drawable{

    float m_gravity;
    float m_explosionStrength;
    sf::Vector2f m_position;
    std::list<Photon>* p_photons;
    sf::CircleShape m_shape;

    sf::Vector2f NormalizeVector(const sf::Vector2f& vector);


public:
    BlackHole(std::list<Photon>& photons);

    void ManageBlackHole(float dt);
    void Explode();
    void SetBlackHolePosition(sf::Vector2f position);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



#endif //BLACKHOLE_H

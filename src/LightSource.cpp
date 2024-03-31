//
// Created by hunde on 3/30/2024.
//

#include "LightSource.h"

LightSource::LightSource(sf::Vector2f position, std::list<Photon>& vPhotons) : p_photons(&vPhotons), m_rate(2500), m_position(position)
{
}

void LightSource::ManageLightSource(float dt)
{
    unsigned long queuedPhotons = m_rate * dt;
    for(unsigned long i = 0; i < queuedPhotons; i++)
    {
        p_photons->emplace_back(m_position);
    }

}


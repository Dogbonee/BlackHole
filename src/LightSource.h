//
// Created by hunde on 3/30/2024.
//

#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include <list>
#include <vector>

#include "Photon.h"


class LightSource{

    //The shared vector of photons between all light sources
    std::list<Photon>* p_photons;
    //The photons managed by this light


    //photons per second exerted
    unsigned long m_rate;
    sf::Vector2f m_position;

public:
    LightSource(sf::Vector2f position, std::list<Photon>& vPhotons);
    void ManageLightSource(float dt);


};



#endif //LIGHTSOURCE_H

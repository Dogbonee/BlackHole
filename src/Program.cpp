//
// Created by hunde on 3/30/2024.
//

#include "Program.h"

Program::Program() : SCREEN_RES{sf::VideoMode::getDesktopMode()},m_window(SCREEN_RES, "Default Name", sf::Style::Fullscreen),
                      m_blackHole(m_photons)
{
    light1 = new LightSource(sf::Vector2f(200, 270), m_photons);
    light2 = new LightSource(sf::Vector2f(SCREEN_RES.width - 200, 270), m_photons);
    light3 = new LightSource(sf::Vector2f(200, SCREEN_RES.height - 270), m_photons);
    light4 = new LightSource(sf::Vector2f(SCREEN_RES.width-200, SCREEN_RES.height - 270), m_photons);
}

Program::~Program()
{
    delete light1;
    delete light2;
    delete light3;
    delete light4;
}

void Program::Update()
{
    HandleEvents();
    dt = m_clock.restart().asSeconds();
    light1->ManageLightSource(dt);
    light2->ManageLightSource(dt);
    light3->ManageLightSource(dt);
    light4->ManageLightSource(dt);
    m_blackHole.ManageBlackHole(dt);

    for(auto it = m_photons.begin(); it != m_photons.end(); it++)
    {
        it->ManageVertex(dt);
        if(it->GetLifespan() <= 0)
        {
            it = m_photons.erase(it);
        }
    }

    Render();
}

void Program::HandleEvents()
{
    for(sf::Event event{}; m_window.pollEvent(event);)
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                HandleKeyboardInput(event.key.code);
                break;
            case sf::Event::MouseMoved:
                m_blackHole.SetBlackHolePosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
                break;
            case sf::Event::MouseButtonPressed:
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    m_blackHole.Explode();
                }
                break;

        }
    }
}

void Program::HandleKeyboardInput(sf::Keyboard::Key key)
{
    switch(key)
    {
        case sf::Keyboard::Escape:
            m_window.close();
            break;
        default:
            std::cout << "Key pressed: " << key << '\n';
    }
}

void Program::Render()
{
    m_window.clear();
    for(auto& vertex : m_photons)
    {
        m_window.draw(&vertex.GetVertex(), 1, sf::Points);
    }
    m_window.draw(m_blackHole);
    m_window.display();
}

void Program::Run()
{
    m_window.setVerticalSyncEnabled(true);
    std::srand(std::time(nullptr));
    while(m_window.isOpen())
    {
        Update();
    }
}

#include "average_game_time.hpp"
#include "SDL.h"

bool AverageGameTime::IsActive()
{
    return m_is_active_;
}

void AverageGameTime::Activate()
{
    m_is_active_ = true;
}

void AverageGameTime::Deactivate()
{
    m_is_active_ = false;
}

float AverageGameTime::Delta()
{
    float delta = (float)(SDL_GetPerformanceCounter() - m_last_time_) / (float)SDL_GetPerformanceFrequency(); // in seconds
    m_last_time_ = SDL_GetPerformanceCounter();
    return delta;
}
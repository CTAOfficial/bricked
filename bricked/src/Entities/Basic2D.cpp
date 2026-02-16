#include "Basic2D.h"
#include "../RGBA.h"
#include "../EntityManager.h"

Basic2D::Basic2D() {
    EntityManager::Add(this);
}

Basic2D::~Basic2D()
{
    EntityManager::Remove(this);
}

void Basic2D::Draw(SDL_Renderer* renderer)
{
    rect = SDL_FRect{ position.X, position.Y, rect.w, rect.h };
    SDL_SetRenderDrawColor(renderer, colour.R, colour.G, colour.B, colour.A);
    SDL_RenderFillRect(renderer, &rect);
}

bool Basic2D::IsOverlapping(Basic2D& other)
{
    return SDL_HasRectIntersectionFloat(const_cast<SDL_FRect*>(&rect), const_cast<SDL_FRect*>(&other.rect));
}

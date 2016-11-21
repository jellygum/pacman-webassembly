#include <iostream>
#include <stdexcept>
#include "GCursor.h"
#include "TextureManager.h"
#include "GGame.h"

using namespace std;

GCursor::GCursor() : m_nX(0),
		     m_nY(0),
		     m_nAnimFrame(0)
{
  SDL_GetMouseState(&m_nX, &m_nY);

  m_nLastAnim = SDL_GetTicks();

  Uint32 colorKey = 0x121415;

  if (!TheTextureManager::Instance()->load("assets/gfx/cursor.png", "cursor", TheGGame::Instance()->getRenderer(), &colorKey))
  {
    cerr << "Unable to load cursor texture." << endl;
  }
}

void GCursor::anim()
{
  m_nAnimFrame = int(((SDL_GetTicks() / CURSOR_ANIM_TIME) % CURSOR_MAX_FRAMES));
}

void GCursor::draw()
{
  TheTextureManager::Instance()
      ->drawFrame("cursor", getX(), getY(), 32, 32, 0, m_nAnimFrame, TheGGame::Instance()->getRenderer(), 0, SDL_ALPHA_OPAQUE);
}

#include "../src/Tileset.hpp"



Tileset::Tileset(ResourceManager* mng)
{
	m_mng = mng;
}

Tileset::Tileset(ResourceManager* mng, const std::string& id)
{
	m_mng = mng;
}

Tileset::~Tileset()
{

}

void Tileset::setTexture(const std::string& id)
{

}

void Tileset::getTile(int id)
{

}
void Tileset::getTile(int row, int column)
{

}

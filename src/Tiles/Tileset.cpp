#include "../../includes/Tiles/Tileset.hpp"



Tileset::Tileset(ResourceManager* mng)
{
	m_mng = mng;
}

Tileset::Tileset(ResourceManager* mng, const std::string& id)
{
	m_mng = mng;
	char teste = id.at(0);
	teste = 'b';
}

Tileset::~Tileset()
{

}

void Tileset::setTexture(const std::string& id)
{
	char teste = id.at(0);
	teste = 'b';
}

void Tileset::getTile(int id)
{
	id++;
}
void Tileset::getTile(int row, int column)
{
	row = column;
}

#ifndef TILESET_HPP
#define TILESET_HPP

#include <string>

#include "../includes/Managers/ResourceManager.hpp"

struct Tileset
{
	Tileset(ResourceManager* mng);
	Tileset(ResourceManager* mng, const std::string& id);
	~Tileset();

	void setTexture(const std::string& id);

	void getTile(int id);
	void getTile(int row, int column);

	ResourceManager*	m_mng;
	sf::Texture*		m_texture;
	unsigned int		m_rows;
	unsigned int		m_columns;

};

#endif

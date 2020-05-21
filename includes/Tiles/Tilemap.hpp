#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "SFML/Graphics.hpp"

#include "../Managers/ResourceManager.hpp"

class Tilemap : public sf::Drawable, public sf::Transformable
{
	public:

	Tilemap(ResourceManager* mng = nullptr, sf::Vector2f tileSize = sf::Vector2f(32.0f,32.0f), sf::Vector2u mapSize = sf::Vector2u(10,10));
	~Tilemap();

	void loadVertexBuffer(const int* tiles,
							sf::Vector2u tileSize ,
							unsigned int width,
							unsigned int height
							);

	void setTexture(const std::string& id)
	{
		m_texture = (m_mng->getTexture(id).get());
	}

	sf::Vector2f getTileSize() const {return m_sizeTiles;}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

	sf::Texture*		m_texture;
	ResourceManager*	m_mng;
	sf::VertexBuffer	m_buffer;
	sf::Vector2f		m_sizeTiles;
	sf::Vector2u		m_mapSize;

};

struct TileProperties
{
	unsigned int		m_guid;
	sf::Vector2u		m_size;
};

#endif /* ifndef TILEMAP_HPP */



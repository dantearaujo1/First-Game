#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include "SFML/Graphics.hpp"
#include "../includes/ResourceManager.hpp"

class Tilemap : public sf::Drawable, public sf::Transformable
{
	public:

	Tilemap(ResourceManager* mng);
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
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

	sf::VertexBuffer	m_buffer;
	sf::Texture*		m_texture;
	ResourceManager*	m_mng;

};

#endif /* ifndef TILEMAP_HPP */

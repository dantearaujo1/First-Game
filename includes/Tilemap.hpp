#ifndef TILEMAP_HPP
#define TILEMAP_HPP #include "SFML/Graphics/VertexBuffer.hpp"

#include "SFML/Graphics.hpp"

class Tilemap : public sf::Drawable, public sf::Transformable
{
	public:

	Tilemap();
	~Tilemap();

	void loadVertexBuffer  (sf::VertexBuffer& buffer,
							sf::VertexArray& va,
							sf::Vector2u tileSize ,
							unsigned int width,
							unsigned int height);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

	sf::VertexBuffer	m_buffer;
	sf::Texture*		m_texture;

};

#endif /* ifndef TILEMAP_HPP */

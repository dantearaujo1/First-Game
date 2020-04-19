#include "../includes/Tilemap.hpp"

Tilemap::Tilemap()
{

}

Tilemap::~Tilemap()
{

}

void Tilemap::loadVertexBuffer(sf::VertexBuffer& buffer, sf::VertexArray& va, sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
	size_t vertices = 4;

	if (buffer.isAvailable())
	{
		buffer.setPrimitiveType(sf::PrimitiveType::Quads); // Setting the type of geometro to be a Quad
		buffer.create(width * height * vertices); // This creates a buffer big enought to hold data for this quantity of vertices
		buffer.setUsage(sf::VertexBuffer::Usage::Dynamic); // Dynamic usage type means that we will send to GPU data sometimes
		va.setPrimitiveType(sf::PrimitiveType::Quads); // Setting the type of geometro to be a Quad
		va.resize(width * height * vertices); // This creates an array of vertices big enought to hold width * height quads
	}
	else return;

	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; ++x)
		{
			//Getting the tile ID
			/* int tileNumber =  tiles[ x + y * width ]; */

			// Find its position in the tileset texture
			/* int tu = tileNumber % ( tileset.getSize().x / tileSize.x ); */
			/* int tv = tileNumber / ( tileset.getSize().x / tileSize.x ); */

			sf::Vertex* quad = &va[( x + y * width ) * vertices ];

			quad[0].texCoords = sf::Vector2f( x * tileSize.x, y * tileSize.y);
			quad[1].texCoords = sf::Vector2f( ( x + 1 )* tileSize.x, y * tileSize.y);
			quad[2].texCoords = sf::Vector2f( ( x + 1 ) * tileSize.x, ( y + 1 ) * tileSize.y);
			quad[3].texCoords = sf::Vector2f( x * tileSize.x, ( y + 1 ) * tileSize.y);

			quad[0].position = sf::Vector2f(0.0f,0.0f);
			quad[1].position = sf::Vector2f(32.0f,0.0f);
			quad[2].position = sf::Vector2f(32.0f,32.0f);
			quad[3].position = sf::Vector2f(0.0f,32.0f);

		}
	}


}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	states.transform *= getTransform();

	states.texture = m_texture;

	target.draw(m_buffer,states);

}

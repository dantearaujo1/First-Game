#include "../includes/Tilemap.hpp"

Tilemap::Tilemap(ResourceManager* mng)
{
	m_mng = mng;
}

Tilemap::~Tilemap()
{

}

void Tilemap::loadVertexBuffer(const int* tiles, sf::Vector2u tileSize, unsigned int width, unsigned int height)
{
	sf::VertexArray varray;
	size_t vertices = 4;
	size_t size = width * height * vertices;

	if (m_buffer.isAvailable())
	{
		// Making sure that buffer is set for handle the vertices
		m_buffer.setPrimitiveType(sf::PrimitiveType::Quads); // Setting the type of geometro to be a Quad
		m_buffer.setUsage(sf::VertexBuffer::Usage::Dynamic); // Dynamic usage type means that we will send to GPU data sometimes
		m_buffer.create(size); // This creates a buffer big enought to hold data for this quantity of vertices

		varray.setPrimitiveType(sf::PrimitiveType::Quads);
		varray.resize(size);
	}
	else return;

	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; ++x)
		{
			//Getting the tile ID
			int tileNumber =  tiles[ x + y * width ];

			// 0 should be an empty image
			if (tileNumber == 0) continue;
			tileNumber -= 1;

			// Find its position in the tileset texture
			int tu = tileNumber % ( m_texture->getSize().x / tileSize.x );
			int tv = tileNumber / ( m_texture->getSize().x / tileSize.x );

			sf::Vertex* quad = &varray[( x + y * width ) * vertices ];

			quad[0].position = sf::Vector2f( (float)x * tileSize.x, (float)y * tileSize.y);
			quad[1].position = sf::Vector2f( ( (float)x + 1 )* tileSize.x, (float)y * tileSize.y);
			quad[2].position = sf::Vector2f( ( (float)x + 1 ) * tileSize.x, ( (float)y + 1 ) * tileSize.y);
			quad[3].position = sf::Vector2f( (float)x * tileSize.x, ( (float)y + 1 ) * tileSize.y);

			quad[0].texCoords = sf::Vector2f((float)( tu * tileSize.x ), (float)( tv * tileSize.y ));
			quad[1].texCoords = sf::Vector2f((float)( (tu+1) * tileSize.x ), (float)( tv * tileSize.y ));
			quad[2].texCoords = sf::Vector2f((float)( (tu+1) * tileSize.x ), (float)( (tv+1) * tileSize.y ));
			quad[3].texCoords = sf::Vector2f((float)( tu * tileSize.x ), (float)( (tv+1) * tileSize.y ));

		}
	}

	m_buffer.update(&varray[0],size,0);


}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	states.transform *= getTransform();

	states.texture = m_texture;

	target.draw(m_buffer,states);

}

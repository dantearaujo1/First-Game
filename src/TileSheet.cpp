#include "../includes/TileSheet.hpp"

TileSheet::TileSheet()
{
	m_tileSize = sf::Vector2f(32.0f,32.0f);
	m_columns = -1;
	m_rows = -1;
	m_rmng = nullptr;
}

TileSheet::TileSheet(ResourceManager* ptr)
{
	m_tileSize = sf::Vector2f(32.0f,32.0f);
	m_columns = -1;
	m_rows = -1;
	m_rmng = ptr;
}

TileSheet::~TileSheet()
{

}

bool TileSheet::setTileSheet(const std::string& id)
{
	if(!m_rmng)
	{
		return false;
	}
	m_texture = m_rmng->getTexture(id).get();

	// This code is used to get the info in texture
	// and generate data about how many columns and rows
	// the tilesheet have.
	sf::Vector2u size = m_texture->getSize();
	m_columns = size.y / (int)m_tileSize.y;
	m_rows = size.x / (int)m_tileSize.x;
	return true;
}

sf::IntRect TileSheet::getTileRect(int row, int column)
{
	sf::IntRect rect;
	rect.top = column * (int)m_tileSize.y;
	rect.left = row * (int)m_tileSize.x;
	rect.width = (int)m_tileSize.x;
	rect.height = (int)m_tileSize.y;

	return rect;
}

void TileSheet::setTileSize(float x, float y)
{
	m_tileSize.x = x;
	m_tileSize.y = y;
}

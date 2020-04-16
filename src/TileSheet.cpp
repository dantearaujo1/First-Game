#include "../includes/TileSheet.hpp"

TileSheet::TileSheet()
{
	m_tileSize = sf::Vector2f(16.0f,16.0f);
	m_columns = -1;
	m_rows = -1;
	m_rmng = nullptr;
}

TileSheet::TileSheet(ResourceManager* ptr)
{
	m_tileSize = sf::Vector2f(16.0f,16.0f);
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

#include "SFML/Graphics.hpp"
#include "../includes/ResourceManager.hpp"

class TileSheet
{
	public:

		TileSheet();
		TileSheet(ResourceManager* ptr);
		~TileSheet();

		bool setTileSheet(const std::string& id);
		sf::IntRect getTileRect(int row, int column);
		sf::Texture* getTexture() { return m_texture;}

		void setTileSize(float x, float y);

	private:

		sf::Texture*		m_texture;
		ResourceManager*	m_rmng;
		sf::Vector2f		m_tileSize;
		int					m_rows;
		int					m_columns;

};

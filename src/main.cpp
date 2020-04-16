#include "../includes/TileSheet.hpp"
#include "../includes/ResourceManager.hpp"

void loadTextures(ResourceManager& mng)
{
  mng.loadTextureFromFile("tileset1","../assets/Tilesets/Pipoya RPG Tileset 32x32/test.png");
}

int main()
{
  sf::RenderWindow window;
  window.create(sf::VideoMode(800, 600), "SFML WORKS");
  bool running = true;

  ResourceManager mng;
  loadTextures(mng);

  TileSheet sheet(&mng);
  sheet.setTileSheet("tileset1");

  sf::Sprite sprite;
  sprite.setTexture(*sheet.getTexture());
  sprite.setTextureRect(sf::IntRect(0,0,32,32));

  sf::Event e;

  while (running)
  {
    while (window.pollEvent(e))
	{
      if (e.type <= sf::Event::Closed)
	  {
        running = false;
        window.close();
      }
	  if (e.type == sf::Event::KeyPressed)
	  {
		  if (e.key.code == sf::Keyboard::Escape)
		  {
			  running = false;
			  window.close();
		  }
	  }
	}

	window.clear(sf::Color::Blue);
	window.draw(sprite);
	window.display();

  }
}

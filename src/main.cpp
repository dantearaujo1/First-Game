#include "../includes/TileSheet.hpp"
#include "../includes/ResourceManager.hpp"
#include "SFML/Graphics/Rect.hpp"

void loadTextures(ResourceManager& mng)
{
  mng.loadTextureFromFile("tileset1","..\\assets\\Tilesets\\Pipoya RPG Tileset 32x32\\test.png");
  mng.loadTextureFromFile("tileset2","..\\assets\\Tilesets\\Pipoya RPG World Tileset 48x48 40x40 32x32\\32x32\\pipo-map001.png");
}


int main()
{
  sf::RenderWindow window;
  int WIDTH  = 800;
  int HEIGHT = 600;
  window.create(sf::VideoMode(WIDTH, HEIGHT), "SFML WORKS");

  sf::View gameView(sf::FloatRect(0.0f, 0.0f, 800.0f, 600.0f));
  gameView.zoom(0.4f);
  gameView.setCenter(sf::Vector2f(0.0f,0.0f));
  window.setView(gameView);

  bool running = true;

  ResourceManager mng;
  loadTextures(mng);

  TileSheet sheet(&mng);
  sheet.setTileSize(32.0f,32.0f);
  sheet.setTileSheet("tileset1");

  sf::Sprite sp;
  sp.setTexture(*sheet.getTexture());


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
	window.draw(sp);
	window.display();

  }
}

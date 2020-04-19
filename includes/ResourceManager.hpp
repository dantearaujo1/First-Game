#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <unordered_map>
#include <memory>

#include "SFML/Graphics.hpp"

// At first this is a texturemanager class but
// we should upgrade this to handle all types we should use
// in our game.
class ResourceManager{

	public:

		ResourceManager();										// Constructor with no arguments
		ResourceManager(const ResourceManager& copy) = delete;	// Deleting the Copy Constructor
		ResourceManager(ResourceManager&& other) = delete;		// Deleting Move Constructor
		~ResourceManager();										// Destructor

		bool loadTextureFromFile(const std::string& id, const std::string& filepath);
		bool removeTexture(const std::string& id);
		bool hasID(const std::string& id);
		std::shared_ptr<sf::Texture> getTexture(const std::string& id);

	private:

		std::unordered_map<std::string ,std::shared_ptr<sf::Texture>>	m_textures;
};

#endif /* ifndef  */

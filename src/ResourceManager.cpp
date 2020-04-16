#include "../includes/ResourceManager.hpp"
#include <iostream>

ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

bool ResourceManager::loadTextureFromFile(const std::string& id, const std::string& filepath)
{
	if(hasID(id))
	{
		std::cout << "This ID is already in use: " << id << std::endl;
		return false;
	}

	std::shared_ptr<sf::Texture> temp = std::make_shared<sf::Texture>();

	if (temp->loadFromFile(filepath))
	{
		m_textures[id] = temp;
		return true;
	}
	return false;
}

bool ResourceManager::removeTexture(const std::string& id)
{
	if(!hasID(id))
	{
		return false;
	}
	m_textures.erase(id);
	return true;
}

bool ResourceManager::hasID(const std::string& id)
{
	if (m_textures.find(id) != m_textures.end())
	{
		return true;
	}
	std::cout << "We couldn't find this texture in the manager" << std::endl;
	return false;
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string& id)
{
	if(!hasID(id))
	{
		return nullptr;
	}
	return m_textures[id];
}

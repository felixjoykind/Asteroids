#include "AssetManager.h"

AssetManager::AssetManager()
{ }

AssetManager::~AssetManager()
{ }

const sf::Texture& AssetManager::GetTexture(std::string name) const
{
	return _textures.at(name);
}

const sf::Font& AssetManager::GetFont(std::string name) const
{
	return this->_fonts.at(name);
}

void AssetManager::LoadTexture(std::string name, std::string filename)
{
	sf::Texture texture;
	if (!texture.loadFromFile(filename))
		std::cout << "[!] Can't load texture from " << filename << std::endl;
	else
	{
		texture.setSmooth(true);
		this->_textures[name] = texture;
	}
}

void AssetManager::LoadFont(std::string name, std::string filename)
{
	sf::Font font;
	if (!font.loadFromFile(filename))
		std::cout << "[!] Failed to load font from " << filename << std::endl;
	else
	{
		this->_fonts[name] = font;
	}
}

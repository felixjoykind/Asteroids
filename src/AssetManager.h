#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;

public:
	AssetManager();
	~AssetManager();
	
	// Getters
	const sf::Texture& GetTexture(std::string name) const;
	const sf::Font& GetFont(std::string name) const;

	// Loaders
	void LoadTexture(std::string name, std::string filename);
	void LoadFont(std::string name, std::string filename);

};


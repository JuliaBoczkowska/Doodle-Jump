#include "TextureHolder.h"
#include <iostream>
#include <exception>

void TextureHolder::load(const std::string& name, const std::string& path)
{
	//Checking if the textures was double loaded
	if (textureMap.find(name) == textureMap.cend())
	{
		std::unique_ptr<sf::Texture> texture(new sf::Texture());

		try {

			if (!texture->loadFromFile(path)) //sf::Texture::loadFromFile() returns a Boolean value that is true in case of success, and false in case of failure
			{
				throw std::runtime_error("TextureHolder::load - Failed to load a texture");
			}
			const auto inserted = textureMap.insert(std::make_pair(name, std::move(texture))); //im using move because i need to "transfer" the content of pointer to texture to map, without doing a copy 

			if (inserted.second == false)
				throw std::logic_error("TextureHolder::insert - Failed to insert");
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (std::logic_error& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

const sf::Texture& TextureHolder::get(const std::string& name)
{
	const auto foundTexture = textureMap.find(name);
	try
	{
		if (foundTexture == textureMap.cend())
			throw std::runtime_error("Texture holder::get - Cannot find a texture");
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return *foundTexture->second;
}


#include "TileSet.h"
#include <iostream>
namespace Engine
{
	TileSet::TileSet(const TileSet& other)
		: name(other.name),
		firstID(other.firstID),
		tileWidth(other.tileWidth),
		tileHeight(other.tileHeight),
		count(other.count),
		columns(other.columns),
		sourceImage(other.sourceImage),
		texWidth(other.texWidth),
		textHeight(other.textHeight)
	{
#if DEBUG>0
		std::cout << "TileSet copied" << std::endl;
#endif
		for (const auto t : other.tiles)
		{
			tiles.push_back(t);
		}
	}

	TileSet& TileSet::operator=(const TileSet& other)
	{
#if DEBUG>0
		std::cout << "TileSet assignment" << std::endl;
#endif
		if (this == &other)
			return *this;
		name = other.name;
		firstID = other.firstID;
		tileWidth = other.tileWidth;
		tileHeight = other.tileHeight;
		count = other.count;
		columns = other.columns;
		sourceImage = other.sourceImage;
		texWidth = other.texWidth;
		textHeight = other.textHeight;
		for (const auto t : other.tiles)
		{
			tiles.push_back(t);
		}
		return *this;
	}

	sf::Texture* TileSet::getTexture()
	{
		return &sourceImage;
	}



	void TileSet::logInfo() const
	{
		std::cout << "name: " << name << std::endl;
		std::cout << "firstID: " << firstID << std::endl;

		std::cout << "tileWidth: " << tileWidth << std::endl;
		std::cout << "tileHeight: " << tileHeight << std::endl;

		std::cout << "count: " << count << std::endl;
		std::cout << "columns: " << columns << std::endl;

		std::cout << "texWidth: " << texWidth << std::endl;
		std::cout << "textHeight: " << textHeight << std::endl;

		std::cout << name << " contains " << tiles.size() << " tiles" << std::endl;
	}

	void TileSet::parseTileSet(const std::string& path, XMLElement* tileSet)
	{
		name = tileSet->Attribute("source");
		firstID = tileSet->IntAttribute("firstgid");

		std::string file;
		file.append(path);
		file.append(name);

		XMLDocument doc;
		XMLError error = doc.LoadFile(file.c_str());
		if (error != XML_SUCCESS)
		{
			std::cout << "Error Loading TileSet <" << file << ">" << std::endl;
			return;
		}

		XMLElement* tileset = doc.FirstChildElement("tileset");
		tileWidth = tileset->IntAttribute("tilewidth");
		tileHeight = tileset->IntAttribute("tileheight");
		spacing = tileset->IntAttribute("spacing", 0);
		margin = tileset->IntAttribute("margin", 0);
		count = tileset->IntAttribute("tilecount");
		columns = tileset->IntAttribute("columns");

		XMLElement* image = tileset->FirstChildElement("image");

		file = path;
		file.append(image->Attribute("source"));
		sourceImage.loadFromFile(file);
	//	sourceImage.setSmooth(false);
		texWidth = image->IntAttribute("width");
		textHeight = image->IntAttribute("height");

		int x = 0;
		int y = 0;

		for (int gid = 0; gid < count; gid++)
		{
	//		tiles.emplace_back( this, sf::IntRect(
	//				x * (tileWidth + spacing * 2) + margin,
	//				y * (tileHeight + spacing * 2) + margin,
	//				tileWidth, 
	//				tileHeight
	//		) );

			tiles.emplace_back(this, sf::IntRect(
				x * (tileWidth + spacing ) + margin,
				y * (tileHeight + spacing ) + margin,
				tileWidth,
				tileHeight
			));

			x++;
			if (x >= columns)
			{
				x = 0;
				y++;
			}
		}

	}

	TileSetTile* TileSet::getTile( int gid)
	{
		return &tiles[gid - firstID ];
	}



	bool TileSet::containsID(int gid) const
	{
		return gid >= firstID || gid < firstID + count;
	}

}	//	namespace Engine



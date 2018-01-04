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

	//----------------------------------------------------------------------------------
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

	//----------------------------------------------------------------------------------
	sf::Texture* TileSet::getTexture()
	{
		return &sourceImage;
	}

	//----------------------------------------------------------------------------------
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

	void TileSet::createTileSetTiles()
	{
		int x = 0;
		int y = 0;

		for (int gid = 0; gid < count; gid++)
		{
			auto rect = sf::IntRect(
				            /* xPos */ x * (tileWidth + spacing ) + margin,
							/* yPos */ y * (tileHeight + spacing ) + margin,
							/* w, h */ tileWidth, tileHeight
			);

			tiles.emplace_back(this, rect);

			x++;
			if (x >= columns)
			{
				x = 0;
				y++;
			}
		}
	}

	//----------------------------------------------------------------------------------
	void TileSet::parseTileSet(const std::string& path, XMLElement* tileSet)
	{
		name = tileSet->Attribute("source");
		firstID = tileSet->IntAttribute("firstgid");

		//	Attempt to load the TileSet file from disk
		XMLDocument doc;
		if (doc.LoadFile((path + name).c_str()) != XML_SUCCESS)
		{
			std::cout << "Error Loading TileSet <" << (path + name) << ">" << std::endl;
			return;
		}

		//	Parse the TileSet data
		XMLElement* tileset = doc.FirstChildElement("tileset");
		tileWidth = tileset->IntAttribute("tilewidth");
		tileHeight = tileset->IntAttribute("tileheight");
		spacing = tileset->IntAttribute("spacing", 0);
		margin = tileset->IntAttribute("margin", 0);
		count = tileset->IntAttribute("tilecount");
		columns = tileset->IntAttribute("columns");


		//	Load in the Source Texture
		XMLElement* image = tileset->FirstChildElement("image");
		sourceImage.loadFromFile(path + image->Attribute("source"));
		texWidth = image->IntAttribute("width");
		textHeight = image->IntAttribute("height");

		createTileSetTiles();
	}

	//----------------------------------------------------------------------------------
	TileSetTile* TileSet::getTile( int gid)
	{
		return &tiles[gid - firstID ];
	}

	//----------------------------------------------------------------------------------
	bool TileSet::containsID(int gid) const
	{
		return gid >= firstID || gid < firstID + count;
	}

}	//	namespace Engine



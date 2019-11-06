#pragma once
//*********************************************
//Image class to hold and allow manipulation of images once read into the code
//from https://www.scratchapixel.com/
//*********************************************
#include <cstdlib> 
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

class Image
{
#ifndef Image_H
#define Image_H
public:
	// Rgb structure, i.e. a pixel 
	struct Rgb
	{
		Rgb() : r(0), g(0), b(0) {}
		Rgb(float c) : r(c), g(c), b(c) {}
		Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
		bool operator != (const Rgb &c) const
		{
			return c.r != r || c.g != g || c.b != b;
		}
		Rgb& operator *= (const Rgb &rgb)
		{
			r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
		}
		Rgb& operator += (const Rgb &rgb)
		{
			r += rgb.r, g += rgb.g, b += rgb.b; return *this;
		}
		friend float& operator += (float &f, const Rgb rgb)
		{
			f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
		}
		float r, g, b;
	};

	Image() : w(0), h(0), pixels(nullptr) { /* empty image */ }
	Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack) :
		w(_w), h(_h), pixels(NULL)
	{
		pixels = new Rgb[w * h];
		for (int i = 0; i < w * h; ++i)
			pixels[i] = c;
	}
	//copy constructor
	Image(const Image &im)
	{
		w = im.w;
		h = im.h;
		cd = im.cd;
		fileName = im.fileName;
		pixels = new Rgb[im.w * im.h];
		for (int i = 0; i < im.w * im.h; ++i)
			pixels[i] = im.pixels[i];
	}
	//copy assignment operator
	Image& operator=(const Image& other)
	{
		w = other.w;
		h = other.h;
		cd = other.cd;
		fileName = other.fileName;

		pixels = new Rgb[other.w * other.h];
		for (int i = 0; i < other.w * other.h; ++i)
			pixels[i] = other.pixels[i];

		return *this;

	}
	void imgInfo()
	{
		std::cout << "FileName: " << fileName << std::endl;
		std::cout << "Width: " << w<< std::endl;
		std::cout << "Height: " << h << std::endl;
		std::cout << "Colour Depth: " << cd << std::endl;
		std::cout << "Number of Pixels: " << h * w << std::endl;

		std::ofstream ofs(
			"log_file.txt", std::ios_base::out | std::ios_base::app);
		ofs << "FileName: " << fileName << std::endl;
		ofs << "Width: " << w << std::endl;
		ofs << "Height: " << h << std::endl;
		ofs << "Colour Depth: " << cd << std::endl;
		ofs << "Number of Pixels: " << h * w << std::endl;
		ofs.close();
	}

	const Rgb& operator [] (const unsigned int &i) const
	{
		return pixels[i];
	}
	Rgb& operator [] (const unsigned int &i)
	{
		return pixels[i];
	}
	~Image()
	{

	}
	//unsigned int w, h; // Image resolution 
	int w, h, cd; // Image resolution
	std::string fileName;
	Rgb *pixels; // 1D array of pixels 
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
};



#endif
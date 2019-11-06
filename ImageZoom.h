#pragma once
//*********************************************
//Image Zoom Class, a derivative class of the base class image.
//*********************************************
#include <cstdlib> 
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "Image.h"


class ImageZoom:
#ifndef ImageZoom_H
#define ImageZoom_H
	public Image{
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

		ImageZoom() : w(0), h(0), pixels(nullptr) { /* empty image */ }
		ImageZoom(const unsigned int &_w, const unsigned int &_h, const unsigned int &_zm,const Rgb &c = kBlack) :
			w(_w), h(_h), zm(_zm),pixels(NULL)
		{
			pixels = new Rgb[w * h];
			for (int i = 0; i < w * h; ++i)
				pixels[i] = c;
		}
		//copy constructor
		ImageZoom(const ImageZoom &im)
		{
			w = im.w;
			h = im.h;
			cd = im.cd;
			zm = im.zm;
			fileName = im.fileName;
			pixels = new Rgb[im.w * im.h];
			for (int i = 0; i < im.w * im.h; ++i)
				pixels[i] = im.pixels[i];
		}
		//copy assignment operator
		ImageZoom& operator=(const ImageZoom& other)
		{
			w = other.w;
			h = other.h;
			cd = other.cd;
			zm = other.zm;
			fileName = other.fileName;

			pixels = new Rgb[other.w * other.h];
			for (int i = 0; i < other.w * other.h; ++i)
				pixels[i] = other.pixels[i];

			return *this;

		}
		void imgInfo()//Polymorphed function that displays information about the image and saves it to a log file. This inherited version 
					  //add a statistic for a zoom multiplier.	
		{
			//displays the images statistics
			std::cout << "FileName: " << fileName << std::endl;
			std::cout << "Width: " << w << std::endl;
			std::cout << "Height: " << h << std::endl;
			std::cout << "Colour Depth: " << cd << std::endl;
			std::cout << "Number of Pixels: " << h * w << std::endl;
			std::cout << "Zoom Multiplier: " << zm << std::endl;

			//saves the statistics to a text file name "log_file.txt"
			std::ofstream ofs(
				"log_file.txt", std::ios_base::out | std::ios_base::app);
			ofs << "FileName: " << fileName << std::endl;
			ofs << "Width: " << w << std::endl;
			ofs << "Height: " << h << std::endl;
			ofs << "Colour Depth: " << cd << std::endl;
			ofs << "Number of Pixels: " << h * w << std::endl;
			ofs << "Zoom Multiplier: " << zm << std::endl;
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
		~ImageZoom()
		{

		}
		//unsigned int w, h; // Image resolution 
		int w, h, cd,zm; // Image resolution
		std::string fileName;
		Rgb *pixels; // 1D array of pixels 
		static const Rgb kBlack, kWhite, kRed, kGreen, kBlue; // Preset colors 
	};

#endif
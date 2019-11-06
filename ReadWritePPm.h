#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "ImageZoom.h"

//class for reading and writing ppm files 

class ReadWritePPm
{
#ifndef ReadWritePPm_H
#define ReadWritePpm_H
private:


public:
	//variables
	std::ifstream ifs;
	Image src;
	std::string header;
	int w, h, b;

	//default constructor
	ReadWritePPm();
	//default destructor
	~ReadWritePPm();

	Image read(char * filename);//member function for reading a ppm file
	void write(const Image &img, const char *filename);//member function for writing a ppm file
	void write(const ImageZoom &img, const char *filename);//overriden function for accepting imageZoom class instead of Image Class







};

#endif

#include "imageManipulation.h"

imageManipulation::imageManipulation()
{
	//default values for the images. Overridable with the get/set accessor functions
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img1 = readWrite->read("Images/ImageStacker_set1/IMG_1.ppm");
	*img2 = readWrite->read("Images/ImageStacker_set1/IMG_2.ppm");
	*img3 = readWrite->read("Images/ImageStacker_set1/IMG_3.ppm");
	*img4 = readWrite->read("Images/ImageStacker_set1/IMG_4.ppm");
	*img5 = readWrite->read("Images/ImageStacker_set1/IMG_5.ppm");
	*img6 = readWrite->read("Images/ImageStacker_set1/IMG_6.ppm");
	*img7 = readWrite->read("Images/ImageStacker_set1/IMG_7.ppm");
	*img8 = readWrite->read("Images/ImageStacker_set1/IMG_8.ppm");
	*img9 = readWrite->read("Images/ImageStacker_set1/IMG_9.ppm");
	*img10 = readWrite->read("Images/ImageStacker_set1/IMG_10.ppm");
	*imgZoom = readWrite->read("Images/Zoom/zIMG_1.ppm");
	readWrite->~ReadWritePPm();
	setImagesVector();

}

//accessor functions
void imageManipulation::setImg1(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img1 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg2(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img2 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg3(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img3 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg4(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img4 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg5(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img5 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg6(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img6 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg7(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img7 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg8(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img8 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg9(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img9 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImg10(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*img10 = readWrite->read(s);
	readWrite->~ReadWritePPm();
}

void imageManipulation::setImgZoom(char* s)
{
	ReadWritePPm *readWrite = new ReadWritePPm;
	*imgZoom = readWrite->read(s);
	readWrite->~ReadWritePPm();
}


Image imageManipulation::getImg1()
{
	return *img1;
}

Image imageManipulation::getImg2()
{
	return *img2;
}

Image imageManipulation::getImg3()
{
	return *img3;
}

Image imageManipulation::getImg4()
{
	return *img4;
}

Image imageManipulation::getImg5()
{
	return *img5;
}

Image imageManipulation::getImg6()
{
	return *img6;
}

Image imageManipulation::getImg7()
{
	return *img7;
}

Image imageManipulation::getImg8()
{
	return *img8;
}

Image imageManipulation::getImg9()
{
	return *img9;
}

Image imageManipulation::getImg10()
{
	return *img10;
}

Image imageManipulation::getImgZoom()
{
	return *imgZoom;
}

Image imageManipulation::getMedianImage()
{
	return *medianBlendedImage;
}

Image imageManipulation::getMeanImage()
{
	return *meanBlendedImage;
}

Image imageManipulation::getSigmaImage()
{
	return *sigmaClippedImage;
}

ImageZoom imageManipulation::getZoom2()
{
	return *ZoomedImage2;
}

ImageZoom imageManipulation::getZoom4()
{
	return *ZoomedImage4;
}

void imageManipulation::setImagesVector()
{
	
	images.push_back(*img1);
	images.push_back(*img2);
	images.push_back(*img3);
	images.push_back(*img4);
	images.push_back(*img5);
	images.push_back(*img6);
	images.push_back(*img7);
	images.push_back(*img8);
	images.push_back(*img9);
	images.push_back(*img10);
}

void imageManipulation::meanMedian(int pixels, bool mean)
{
	//vectors for storing pixel values
	std::vector<int> pixelred;
	std::vector<int> pixelblue;
	std::vector<int> pixelgreen;

	//vectors for storing median values
	std::vector<int> medianRed;
	std::vector<int> medianBlue;
	std::vector<int> medianGreen;

	//vector for storing the result
	std::vector< std::vector<int> > result;

	int red, blue, green;

	for (int j = 0; j < (images[0].w * images[0].h); j++)
	{
		//resets the vectors for a new pixel
		pixelred.clear();
		pixelblue.clear();
		pixelgreen.clear();

		for (int i = 0; i < pixels; i++)//loops through each image
		{
			pixelred.push_back((images[i].pixels[j].r) * 255);
			pixelblue.push_back((images[i].pixels[j].b) * 255);
			pixelgreen.push_back((images[i].pixels[j].g) * 255);

		}

		if (mean == false)//median
		{
			
			red = imageManipulation::medianBlending(pixelred);
			blue = imageManipulation::medianBlending(pixelblue);
			green = imageManipulation::medianBlending(pixelgreen);
		}

		if (mean == true)//mean
		{
			red = imageManipulation::meanBlending(pixelred);
			blue = imageManipulation::meanBlending(pixelblue);
			green = imageManipulation::meanBlending(pixelgreen);
		}

		medianRed.push_back(red);
		medianBlue.push_back(blue);
		medianGreen.push_back(green);

	}

	result.push_back(medianRed);//adds final median to a vector of results
	result.push_back(medianBlue);
	result.push_back(medianGreen);

	//writes new image

	ReadWritePPm *readWrite = new ReadWritePPm;
	if (mean == false)
	{
		for (int test = 0; test < (images[0].w * images[0].h); test++)
		{

			medianBlendedImage->pixels[test].r = result[0][test] / 255.f;
			medianBlendedImage->pixels[test].b = result[1][test] / 255.f;
			medianBlendedImage->pixels[test].g = result[2][test] / 255.f;

		}
		std::cout << "Median Blending..." << std::endl;
		readWrite->write(*medianBlendedImage, "blendedMedianPPM.ppm");
	}

	if (mean == true)
	{
		for (int test = 0; test < (images[0].w * images[0].h); test++)
		{

			meanBlendedImage->pixels[test].r = result[0][test] / 255.f;
			meanBlendedImage->pixels[test].b = result[1][test] / 255.f;
			meanBlendedImage->pixels[test].g = result[2][test] / 255.f;

		}
		std::cout << "Mean Blending..." << std::endl;
		readWrite->write(*meanBlendedImage, "blendedMeanPPM.ppm");
	}
	
	readWrite->~ReadWritePPm();

}

int imageManipulation::medianBlending(std::vector<int> onePixel)
{
	int median;
	if (onePixel.size() != 0)
	{
		std::sort(onePixel.begin(), onePixel.end());

		if (onePixel.size() % 2 != 0)//determines whether the median is a real value or needs to be calculated based on whether the amount of data is odd or even.
			median = (onePixel[onePixel.size()]);
		else
			median = (((onePixel[(onePixel.size() / 2)] - 1) + onePixel[onePixel.size() / 2]) / 2);

	}

	else
	{
		median = 0;//if for some reason a vector of 0 values is passed
	}

	return median;
}

int imageManipulation::meanBlending(std::vector<int> onePixel)
{
	int total = 0;

	for (int i = 0; i < onePixel.size() - 1; i++)
	{
		total += onePixel[i];
	}

	int mean = total / onePixel.size();

	return mean;
}

float imageManipulation::standardDeviation(std::vector<int> onePixel)
{
	int mean = imageManipulation::meanBlending(onePixel);

	float sd = 0;
	for (int i = 0; i < onePixel.size(); i++)
	{
		sd = sd + powf(onePixel[i] - mean, 2);
	}

	sd = sqrtf(sd / onePixel.size());
	return sd;

}

void imageManipulation::sigmaClipping(int pixels)
{
	//vectors for storing pixels
	std::vector<int> pixelred;
	std::vector<int> pixelblue;
	std::vector<int> pixelgreen;

	std::vector< std::vector<int> > results(3);

	float rmedian, bmedian, gmedian,rmedian2, bmedian2, gmedian2, rsd, bsd, gsd;//floats needed for sigma clipping




	for (int j = 0; j < (images[0].w * images[0].h); j++)//loops through each pixel
	{
		//resets the vectors for a new pixel
		pixelred.clear();
		pixelblue.clear();
		pixelgreen.clear();

		for (int i = 0; i < pixels; i++)//loops through each image
		{
			pixelred.push_back((images[i].pixels[j].r) * 255);
			pixelblue.push_back((images[i].pixels[j].b) * 255);
			pixelgreen.push_back((images[i].pixels[j].g) * 255 );

		}

		rmedian = imageManipulation::medianBlending(pixelred);
		bmedian = imageManipulation::medianBlending(pixelblue);
		gmedian = imageManipulation::medianBlending(pixelgreen);

		rsd = imageManipulation::standardDeviation(pixelred);
		bsd = imageManipulation::standardDeviation(pixelblue);
		gsd = imageManipulation::standardDeviation(pixelgreen);


		std::vector<int> rvalues;
		std::vector<int> bvalues;
		std::vector<int> gvalues;

		for (int i = 0; i < 5; i++)//loops through 5 times and removes items of data that dont adhere to the sigma clip
		{
			
			if ((pixelred[i] < (rmedian - rsd)) == false)
			{
				rvalues.push_back(pixelred[i]);
			}
			if ((pixelred[i] > (rmedian + rsd))== false)
			{
				rvalues.push_back(pixelred[i]);
			}
			if ((pixelblue[i] < (bmedian - bsd ) )== false)
			{
				bvalues.push_back(pixelblue[i]);
			}
			if (pixelblue[i] > (bmedian + bsd) == false)
			{
				bvalues.push_back(pixelblue[i]);
			}
			if (pixelgreen[i] < (gmedian - gsd) ==  false)
			{
				gvalues.push_back(pixelgreen[i]);
			}
			if (pixelgreen[i] > (gmedian + gsd) == false)
			{
				gvalues.push_back(pixelgreen[i]);
			}

		}

		//finds the median of the remaining values
		rmedian2 = imageManipulation::medianBlending(rvalues);
		bmedian2 = imageManipulation::medianBlending(bvalues);
		gmedian2 = imageManipulation::medianBlending(gvalues);

		//adds these results to the results vector
		results[0].push_back(rmedian2);
		results[1].push_back(bmedian2);
		results[2].push_back(gmedian2);

	}

	//writes the sigma clipped image to a ppm file
	ReadWritePPm *readWrite = new ReadWritePPm;
	for (int test = 0; test < (images[0].w * images[0].h); test++)
	{

		sigmaClippedImage->pixels[test].r = results[0][test] / 255 ;
		sigmaClippedImage->pixels[test].b = results[1][test] /255 ;
		sigmaClippedImage->pixels[test].g = results[2][test] / 255;

	}
	std::cout << "SigmaClipping" << std::endl;
	readWrite->write(*meanBlendedImage, "sigmaClippedPPM.ppm");
	

	readWrite->~ReadWritePPm();

	

}

void imageManipulation::twoTimesZoom()
{
	int height = imgZoom->h;
	int width = imgZoom->w;

	//calculates the new dimensions of the scaled image
	int newHeight = (2 * height);
	int newWidth = (2 * width);
	int size = newHeight * newWidth;

	std::vector< std::vector<int> > zoomed;
	std::vector<int> red(size);
	std::vector<int> blue(size);
	std::vector<int> green(size);




	double x_ratio = height / double(newHeight);
	double y_ratio = width / double(newWidth);
	double px, py;
	for (int i = 0; i < newHeight; i++)
	{
		for (int j = 0; j < newWidth; j++)
		{
			px = floor(j*x_ratio);
			py = floor(i*y_ratio);
			//assigns new values to approriate pixels
			red[(i*newWidth) + j] = (imgZoom->pixels[int((py*width) + px)].r) * 255;
			blue[(i*newWidth) + j] = (imgZoom->pixels[int((py*width) + px)].b) * 255;
			green[(i*newWidth) + j] = (imgZoom->pixels[int((py*width) + px)].g) * 255;

		}
	}



	zoomed.push_back(red);
	zoomed.push_back(blue);
	zoomed.push_back(green);

	std::cout << "2x Zoom..." << std::endl;


	//for loop for assinnging new pixels to the new image
	for (int test = 0; test < ZoomedImage2->w * ZoomedImage2->h; test++)
	{
		ZoomedImage2->pixels[test].r = zoomed[0][test] / 255.f;
		ZoomedImage2->pixels[test].b = zoomed[1][test] / 255.f;
		ZoomedImage2->pixels[test].g = zoomed[2][test] / 255.f;

	}
	ReadWritePPm *readWrite = new ReadWritePPm;
	readWrite->write(*ZoomedImage2, "2xZoomedPPM.ppm");

}

void imageManipulation::fourTimesZoom()
{
	int height = imgZoom->h;
	int width = imgZoom->w;

	//calculates the new dimensions of the scaled image
	int newHeight = (4 * height);
	int newWidth = (4 * width);
	int size = newHeight * newWidth;

	std::vector< std::vector<int> > zoomed;
	std::vector<int> red(size);
	std::vector<int> blue(size);
	std::vector<int> green(size);




	double x_ratio = height / double(newHeight);
	double y_ratio = width / double(newWidth);
	double px, py;
	for (int i = 0; i < newHeight; i++)
	{
		for (int j = 0; j < newWidth; j++)
		{
			px = floor(j*x_ratio);
			py = floor(i*y_ratio);
			//assigns new values to approriate pixels
			red[(i*newWidth) + j] = (imgZoom->pixels[int((py*width) + px)].r) * 255;
			blue[(i*newWidth) + j] = (imgZoom->pixels[int((py*width) + px)].b) * 255;
			green[(i*newWidth) + j] = (imgZoom->pixels[int((py*width) + px)].g) * 255;

		}
	}



	zoomed.push_back(red);
	zoomed.push_back(blue);
	zoomed.push_back(green);

	std::cout << "4x Zoom..." << std::endl;


	//for loop for assinnging new pixels to the new image
	for (int test = 0; test < ZoomedImage4->w * ZoomedImage4->h; test++)
	{
		ZoomedImage4->pixels[test].r = zoomed[0][test] / 255.f;
		ZoomedImage4->pixels[test].b = zoomed[1][test] / 255.f;
		ZoomedImage4->pixels[test].g = zoomed[2][test] / 255.f;

	}
	ReadWritePPm *readWrite = new ReadWritePPm;
	readWrite->write(*ZoomedImage4, "4xZoomedPPM.ppm");
	

}




imageManipulation::~imageManipulation()
{
}

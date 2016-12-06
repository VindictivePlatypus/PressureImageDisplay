#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <iostream>

static std::vector<std::vector<double>> currentImage = std::vector<std::vector<double>>();
static std::vector<double> currentImageSim =std::vector<double>();

static std::ifstream* istream;

static int indexes[361] = {
	522,523,524,525,547,548,549,550,572,573,574,575,397,398,399,400,422,423,424,425,447,448,449,450,472,473,474,475,
	241,242,243,244,266,267,268,269,291,292,293,294,141,142,143,144,166,167,168,169,191,192,193,194,16,17,18,19,41,42,43,44,66,67,68,69,91,92,93,94,
	236,237,238,239,261,262,263,264,286,287,288,289,136,137,138,139,161,162,163,164,186,187,188,189,11,12,13,14,36,37,38,39,61,62,63,64,86,87,88,89,
	231,232,233,234,256,257,258,259,281,282,283,284,131,132,133,134,156,157,158,159,181,182,183,184,6,7,8,9,31,32,33,34,56,57,58,59,81,82,83,84,
	226,227,228,229,251,252,253,254,276,277,278,279,126,127,128,129,151,152,153,154,176,177,178,179,1,2,3,4,26,27,28,29,51,52,53,54,76,77,78,79,
	326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,417,418,419,
	612,613,614,615,616,617,618,619,620,637,638,639,640,641,642,643,644,645,662,663,664,665,666,667,668,669,670,687,688,689,690,691,692,693,694,695,712,713,714,715,716,717,718,719,720,
	501,502,503,504,526,527,528,529,551,552,553,554,576,577,578,579,601,602,603,604,626,627,628,629,630,631,632,633,651,652,653,654,655,656,657,658,676,677,678,679,680,681,682,683,701,702,703,704,705,706,707,708
};

static void ResetVector() {
	currentImage = std::vector<std::vector<double>>();
}

static std::vector<double> NextImage(int index) {
	return currentImage.at(index);
}

static std::vector<double> LoadFile(const std::string path, int* s) {
	ResetVector();
	istream = new std::ifstream(path);
	std::string currString = "";
	while (true) {
		*istream >> currString;
		std::vector<double> curVect = std::vector<double>();
		if (istream->eof()) break;
		else curVect.push_back(atof(currString.c_str()));
		for (int i = 2; i < 726; i++) {
			*istream >> currString;
			if (std::find(std::begin(indexes), std::end(indexes), i) == std::end(indexes)) curVect.push_back(-0.01);
			else curVect.push_back(atof(currString.c_str()));
		}
		currentImage.push_back(curVect);
	}
	*s = currentImage.size()-1;
	return NextImage(0);
}

static std::vector<double> readDataFromSim(std::string path) {
	istream = new std::ifstream(path);
	std::string currString = "";
	currentImageSim.clear();
	for (int i = 1; i < 726; i++) {
		*istream >> currString;
		if (std::find(std::begin(indexes), std::end(indexes), i) == std::end(indexes)) currentImageSim.push_back(-0.01);
		else currentImageSim.push_back(atof(currString.c_str()));
	}
	return currentImageSim;
}



static QColor getColor(double value, double max = 0.8) {
	//We want to match the interval of value 0->0.8 to the interval of angle 180°->0° to get a color going from cyan to red
	int hue = (int)(180 - (value / max) * 180);
	int light;
	value < 0 ? light = 255 : light = 128;
	return QColor::fromHsl(hue, 255, light);
}
#pragma once
#include <iostream>
#include<vector>
#include <numeric>
#include <cmath>
#include<complex>
#include <string>
#include <sstream>
#include <algorithm>
#include<fstream>
#define PI  3.1415926
//using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

using std::vector;
using std::complex;

extern 

class FT
{
private:
	
public:
	FT();
	void DiscreteFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void DFT(double** pFreqReal, double** pFreqImag, int** InputImage, int h, int w, int u, int v);

	void InverseDiscreteFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void InverseDFT(double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y);

	void FastFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void FFT(double** pFreqReal, double** pFreqImag, int** InputImage, int h, int w, int u, int v);

	void InverseFastFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void InverseFFT(double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y);



	void LowpassFilter(double** Real, double** Img, double** filter);
	void HighpassFilter(double** Real, double** Img, double** filter);

	double** Filter(int h, int w, double n, double  cut, bool isLow);
	void LowpassFilter(double** Real, int ** OutputImg, double** filter, int h, int w);

	
	

private:

};
Bitmap^FFTtest(Bitmap^ inputIMG);
vector<complex<double>>FFTarray(vector<complex<double>>fftArray);
Bitmap^IFFTtest(Bitmap^ inputIMG);
vector<complex<double>>IFFTarray(vector<complex<double>>fftArray);
vector<complex<double>>getTemppp();
Bitmap^ PassFilter(Bitmap^ inputIMG, double CutOff, double attenuation, bool isLow);

void setTemppp(vector<complex<double>>& n);
int Index_Bit(int index, int bits);




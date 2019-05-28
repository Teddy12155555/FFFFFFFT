#include "FT.h"

vector<complex<double>>temppp;

FT::FT()
{
}

void FT::DiscreteFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
	int M = h;
	int N = w;

	double** pFreq = new double*[M];
	for (int newcnt = 0; newcnt<M; newcnt++)
	{
		pFreq[newcnt] = new double[N]; // 傅立葉頻率陣列
	}
	for (int forzero_i = 0; forzero_i<M; forzero_i++)
	{
		for (int forzero_j = 0; forzero_j<N; forzero_j++)
		{
			pFreq[forzero_i][forzero_j] = 0.0f;
		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DFT(FreqReal, FreqImag, InputImage,M, N, j, i);
		}
	}

	//debug file
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//cout<< FreqReal[i][j] << " + j " << FreqImag[i][j] << endl;
			// 將計算好的傅立葉實數與虛數部分作結合 
			pFreq[i][j] = sqrt(pow(FreqReal[i][j], (double) 2.0) + pow(FreqImag[i][j], (double) 2.0));
			// 結合後之頻率域丟入影像陣列中顯示 
			OutputImage[i][j] = pFreq[i][j];
		}
	}
	//-------------------------------------------
	for (int delcnt = 0; delcnt < M; delcnt++)
	{
		delete[] pFreq[delcnt];
	}
	delete[] pFreq;
}

void FT::DFT(double ** pFreqReal, double ** pFreqImag, int ** InputImage, int h, int w, int u, int v)
{
	// M = N 必須是方陣
	int M = h;
	int N = w;

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			// 可先計算Eular's equation e^{j*theta} = cos{theta}+j*sin{theta}			
			double angleDFT = (-1.0f * 2.0f * 3.14159 * (double)(u*x + v*y) / (double)M);
			double c = cos(angleDFT);
			double s = sin(angleDFT);

			// 利用Eular's equation計算傅立葉之實虛數部分
			pFreqReal[u][v] += (double)InputImage[y][x] * c;
			pFreqImag[u][v] -= (double)InputImage[y][x] * s;
		}
	}

	pFreqReal[u][v] = pFreqReal[u][v] / (double)(M);
	pFreqImag[u][v] = pFreqImag[u][v] / (double)(M);
}

void FT::InverseDiscreteFourierTransform(int ** InputImage, int ** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
	int M = h;
	int N = w;

	double** InverseReal = new double*[M];
	double** InverseImag = new double*[M];
	double** pFreq = new double*[M];

	for (int i = 0; i<M; i++)
	{
		InverseReal[i] = new double[N];
		InverseImag[i] = new double[N];
		pFreq[i] = new double[N]; // 傅立葉頻率陣列
	}

	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{
			InverseReal[i][j] = 0.0f;
			InverseImag[i][j] = 0.0f;
			pFreq[i][j] = 0.0f;
		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			InverseDFT(InverseReal, InverseImag,FreqReal, FreqImag, M, N, j, i);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 將計算好的傅立葉實數與虛數部分作結合 
			pFreq[i][j] = sqrt(pow(InverseReal[i][j], (double) 2.0) + pow(InverseImag[i][j], (double) 2.0));
			// 結合後之頻率域丟入影像陣列中顯示 
			OutputImage[i][j] = pFreq[i][j];
			//存下反傅立葉實數與虛數部分
			FreqReal[i][j] = InverseReal[i][j];
			FreqImag[i][j] = InverseImag[i][j];

		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		delete[] pFreq[i];
		delete[] InverseReal[i];
		delete[] InverseImag[i];

	}
	delete[] pFreq;
	delete[] InverseReal;
	delete[] InverseImag;

}

void FT::InverseDFT(double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y)
{
	// M = N 必須是方陣
	int M = h;
	int N = w;

	for (int v = 0; v < M; v++)
	{
		for (int u = 0; u < N; u++)
		{
			// 可先計算Eular's equation e^{j*theta} = cos{theta}+j*sin{theta}			
			double angleIDFT = (2.0f * 3.14159 * (double)(u*x + v*y) / (double)M);
			double c = cos(angleIDFT);
			double s = sin(angleIDFT);

			// 利用Eular's equation計算傅立葉之實虛數部分
			InverseReal[x][y] += (pFreqReal[v][u] * c - pFreqImag[v][u] * s);
			InverseImag[x][y] += (pFreqReal[v][u] * s + pFreqImag[v][u] * c);
		}
	}
	InverseReal[x][y] = InverseReal[x][y] / (float)M;
	InverseImag[x][y] = InverseImag[x][y] / (float)M;
}

void FT::FastFourierTransform(int ** InputImage, int ** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
}

void FT::FFT(double ** pFreqReal, double ** pFreqImag, int ** InputImage, int h, int w, int u, int v)
{
}

void FT::InverseFastFourierTransform(int ** InputImage, int ** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
}

void FT::InverseFFT(double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y)
{
}


void FT::LowpassFilter(double** Real, int ** OutputImg, double** filter, int h, int w)
{
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			OutputImg[i][j] = Real[i][j] *= filter[i][j];
}

void FT::LowpassFilter(double** Real, double** Img, double** filter)
{

}

void FT::HighpassFilter(double** Real, double** Img, double** filter)
{
}

double** FT::Filter(int h, int w, double n, double  cut, bool isLow) {
	double **filter;
	int u, v;
	filter = new double*[h];
	for (int i = 0; i < h; ++i)
		filter[i] = new double[w]();

	if (isLow) {
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				u = j - w / 2;
				v = i - h / 2;
				filter[i][j] = 1 / (1 + pow((sqrt(u*u + v * v) / cut), 2 * n));
			}
	}
	else {
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				u = j - w / 2;
				v = i - h / 2;
				filter[i][j] = 1 - (1 / (1 + pow((sqrt(u*u + v * v) / cut), 2 * n)));
			}
	}
	return filter;
}


Bitmap^FFTtest(Bitmap^ inputIMG)
{
	//TaiMing_method = true;
	Bitmap ^outputIMG = gcnew Bitmap(inputIMG->Width, inputIMG->Height);
	BitmapData ^inputData = inputIMG->LockBits(Rectangle(0, 0, inputIMG->Width, inputIMG->Height), ImageLockMode::ReadOnly, PixelFormat::Format24bppRgb);
	BitmapData ^outputData = outputIMG->LockBits(Rectangle(0, 0, inputIMG->Width, inputIMG->Height), ImageLockMode::WriteOnly, PixelFormat::Format24bppRgb);
	Byte * input = (Byte*)inputData->Scan0.ToPointer();
	Byte * output = (Byte*)outputData->Scan0.ToPointer();
	//三小平移的
	int HW = inputIMG->Width * inputIMG->Height;
	vector<complex<double>>IMG(HW); 
	int h = inputIMG->Height;
	int w = inputIMG->Width;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			IMG[i*w + j] = (double)pow((float)-1, (float)(i + j)) *complex<double>(input[(i*w + j) * 3],0);

	vector<complex<double>>FFTarray_W(w);
	vector<complex<double>>FFTarray_H(h);
	vector<vector<complex<double>>>R(h,vector<complex<double>>(w));
	////compute w
	vector<complex<double>> row;
	for (int i = 0; i< h; i++)
	{
		auto it = IMG.begin() + i * w;
		row.assign(it, it + w);
		row = FFTarray(row);
		for (int j = 0; j < w;j++)
			*(it + j) = row[j];
	}
	////compute h
	vector<complex<double>> col(h);
	for (int i = 0; i< w; i++)
	{
		auto it = IMG.begin() + i;
		for (int j = 0; j <h; j++)
			col[j] = *(it + j * w);
		col = FFTarray(col);
		for (int j = 0; j < h; j++)
			*(it + j * w) = col[j];
	}
	vector<complex<double>>rowTemp;
	// h == w 
	//for (int i=0; i < h; i++)
	//{
	//	auto it = IMG.begin() + i * w;
	//	rowTemp.assign(it, it + w);
	//	for (int j = 0; j < w; j++)
	//	{
	//		R[j][h - i-1] = rowTemp[j];
	//	}
	//}
	////2Mapping1
	//for (int i = 0; i < h; i++)
	//{
	//	for (int j = 0; j < w; j++)
	//	{
	//		IMG[i*w + j] = R[i][j];
	//	}
	//}

	//for (int i = 0; i < HW; i++)
	//{
	//	cout << IMG[i].real() << " +j " << IMG[i].imag() << endl;
	//}
	//scale
	for (int i = 0; i < HW; i++)
		IMG[i] /= sqrt(HW);
	temppp = IMG;
	//temppp = IMG;
	//output
	for (int i = 0; i < IMG.size(); i++)
	{
		double p = abs(IMG.at(i));
		if (p > 255) p = 255;
		if (p < 0) p = 0;
		for (int j = 0; j < 3; j++)
			output[i * 3 + j] = p;
	}
	inputIMG->UnlockBits(inputData);
	outputIMG->UnlockBits(outputData);
	
	return outputIMG;
}
vector<complex<double>>FFTarray(vector<complex<double>>fftArray)
{
	vector<complex<double>>cloneArray = fftArray;
	int points = fftArray.size();
	int stage = log2(points);
	//comput index with bit
	for (int i = 0; i < points; i++)
		fftArray[i] = cloneArray[Index_Bit(i, stage)];

	//fucking compute
	for (int i = 2; i <= points; i <<=1)
	{
		//e -j2pi/N
		complex<double>w(exp(complex<double>(0.0, -(2*PI) / i)));

		for (int j = 0; j != points; j += i)
		{
			//1+j0
			complex<double>theta(1.0, 0.0);

			for (int l = j; l < j + i / 2; l++)
			{
				complex<double>a = fftArray[l];
				complex<double>b = fftArray[l + i / 2] * theta;
				fftArray[l] = a + b;
				fftArray[l + i / 2] = a - b;

				theta *= w;
			}
			
		}
	}
	return fftArray;
}
Bitmap^IFFTtest(Bitmap^ inputIMG)
{
	Bitmap ^outputIMG = gcnew Bitmap(inputIMG->Width, inputIMG->Height);
	BitmapData ^outputData = outputIMG->LockBits(Rectangle(0, 0, inputIMG->Width, inputIMG->Height), ImageLockMode::WriteOnly, PixelFormat::Format24bppRgb);
	Byte * output = (Byte*)outputData->Scan0.ToPointer();
	//三小平移的
	int HW = inputIMG->Width * inputIMG->Height;
	vector<complex<double>>IMG(HW);
	int h = inputIMG->Height;
	int w = inputIMG->Width;
	/*for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			IMG[i*w + j] = complex<double>(input[(i*w + j) * 3], 0);*/
	IMG = temppp;

	vector<complex<double>>FFTarray_W(w);
	vector<complex<double>>FFTarray_H(h);
	//compute w
	vector<complex<double>> row;
	for (int i = 0; i < h; i++)
	{
		auto it = IMG.begin() + i * w;
		row.assign(it, it + w);
		row = IFFTarray(row);
		for (int j = 0; j < w; j++)
			*(it+ j) = row[j];
	}
	////compute h
	vector<complex<double>> col(h);
	for (int i = 0; i < w; i++)
	{
		auto it = IMG.begin() + i;

		for (int j = 0; j <h; j++)
			col[j] = *(it + j * w);

		col = IFFTarray(col);

		for (int j = 0; j < h; j++)
			*(it + j * w) = col[j];
	}
	
	//scale
	for (int i = 0; i < HW; i++)
		IMG[i] /= sqrt(HW);

	//output
	for (int i = 0; i < IMG.size(); i++)
	{
		double p = abs(IMG.at(i));
		if (p > 255) p = 255;
		if (p < 0) p = 0;
		for (int j = 0; j < 3; j++)
			output[i * 3 + j] = p;
	}
	outputIMG->UnlockBits(outputData);

	return outputIMG;
}
vector<complex<double>>IFFTarray(vector<complex<double>>fftArray)
{
	
	vector<complex<double>>cloneArray = fftArray;
	int points = fftArray.size();
	int stage = log2(points);
	//comput index with bit
	for (int i = 0; i < points; i++)
		fftArray[i] = cloneArray[Index_Bit(i, stage)];

	//fucking compute
	for (int i = 2; i <= points; i <<= 1)
	{
		//e -j2pi/N
		complex<double>w(exp(complex<double>(0.0, (2*PI) / i)));

		for (int j = 0; j != points; j += i)
		{
			//1+j0
			complex<double>theta(1.0, 0.0);

			for (int l = j; l < j + i / 2; l++)
			{
				complex<double>a = fftArray[l];
				complex<double>b = fftArray[l + i / 2] * theta;
				fftArray[l] = a + b;
				fftArray[l + i / 2] = a - b;

				theta *= w;
			}

		}
	}
	return fftArray;
	
}
int Index_Bit(int index,int bits)
{
	vector<char>temp;
	int re = 0;
	for (int i = 0; i < bits; i++)
		temp.push_back(((index >> i) & 0x01));
	for (int i=0;i<temp.size();i++)
		re += temp[i] * pow(2, temp.size() - 1 - i);
	return re;
}
vector<complex<double>>getDebug()
{
	return temppp;
}
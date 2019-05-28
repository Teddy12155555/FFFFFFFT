#pragma once
#include <iostream>
#include "DataManager.h"
#include "FT.h"
bool TaiMing_method = false;
namespace FourierTransform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			fourierTransformMethod = new FT();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadImageToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  methodToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fastFourierTransformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inverseFastFourierTransformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lowpassFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  highpassFilterToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  SourceImageLabel;
	private: System::Windows::Forms::Label^  ResultImageLabel;
	private: System::Windows::Forms::PictureBox^  pictureBox_SourceImage;
	private: System::Windows::Forms::PictureBox^  pictureBox_OutputImage;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		/// <summary>
		DataManager* dataManager;
		FT*	fourierTransformMethod;
	private: System::Windows::Forms::ToolStripMenuItem^  discreteFourierTransformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inverseDiscreteFourierTransformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  setResultImageAsSourceImageToolStripMenuItem;
			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setResultImageAsSourceImageToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->methodToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fastFourierTransformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverseFastFourierTransformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lowpassFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->highpassFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->discreteFourierTransformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverseDiscreteFourierTransformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SourceImageLabel = (gcnew System::Windows::Forms::Label());
			this->ResultImageLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox_SourceImage = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_OutputImage = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_SourceImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_OutputImage))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->menuStrip1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 5)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 95)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(2184, 1400);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->methodToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(13, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(2184, 46);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->loadImageToolStripMenuItem,
					this->setResultImageAsSourceImageToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(64, 38);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// loadImageToolStripMenuItem
			// 
			this->loadImageToolStripMenuItem->Name = L"loadImageToolStripMenuItem";
			this->loadImageToolStripMenuItem->Size = System::Drawing::Size(498, 38);
			this->loadImageToolStripMenuItem->Text = L"Load Image";
			this->loadImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadImageToolStripMenuItem_Click);
			// 
			// setResultImageAsSourceImageToolStripMenuItem
			// 
			this->setResultImageAsSourceImageToolStripMenuItem->Name = L"setResultImageAsSourceImageToolStripMenuItem";
			this->setResultImageAsSourceImageToolStripMenuItem->Size = System::Drawing::Size(498, 38);
			this->setResultImageAsSourceImageToolStripMenuItem->Text = L"Set Result Image as Source Image ";
			this->setResultImageAsSourceImageToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::setResultImageAsSourceImageToolStripMenuItem_Click);
			// 
			// methodToolStripMenuItem
			// 
			this->methodToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->fastFourierTransformToolStripMenuItem,
					this->inverseFastFourierTransformToolStripMenuItem, this->lowpassFilterToolStripMenuItem, this->highpassFilterToolStripMenuItem,
					this->discreteFourierTransformToolStripMenuItem, this->inverseDiscreteFourierTransformToolStripMenuItem
			});
			this->methodToolStripMenuItem->Name = L"methodToolStripMenuItem";
			this->methodToolStripMenuItem->Size = System::Drawing::Size(116, 38);
			this->methodToolStripMenuItem->Text = L"Method";
			// 
			// fastFourierTransformToolStripMenuItem
			// 
			this->fastFourierTransformToolStripMenuItem->BackColor = System::Drawing::SystemColors::Info;
			this->fastFourierTransformToolStripMenuItem->Name = L"fastFourierTransformToolStripMenuItem";
			this->fastFourierTransformToolStripMenuItem->Size = System::Drawing::Size(499, 38);
			this->fastFourierTransformToolStripMenuItem->Text = L"Fast Fourier Transform";
			this->fastFourierTransformToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fastFourierTransformToolStripMenuItem_Click);
			// 
			// inverseFastFourierTransformToolStripMenuItem
			// 
			this->inverseFastFourierTransformToolStripMenuItem->BackColor = System::Drawing::SystemColors::Info;
			this->inverseFastFourierTransformToolStripMenuItem->Name = L"inverseFastFourierTransformToolStripMenuItem";
			this->inverseFastFourierTransformToolStripMenuItem->Size = System::Drawing::Size(499, 38);
			this->inverseFastFourierTransformToolStripMenuItem->Text = L"Inverse Fast Fourier Transform";
			this->inverseFastFourierTransformToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::inverseFastFourierTransformToolStripMenuItem_Click);
			// 
			// lowpassFilterToolStripMenuItem
			// 
			this->lowpassFilterToolStripMenuItem->BackColor = System::Drawing::SystemColors::Info;
			this->lowpassFilterToolStripMenuItem->Name = L"lowpassFilterToolStripMenuItem";
			this->lowpassFilterToolStripMenuItem->Size = System::Drawing::Size(499, 38);
			this->lowpassFilterToolStripMenuItem->Text = L"Lowpass Filter";
			this->lowpassFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::lowPassFilterToolStripMenuItem_Click);
			// 
			// highpassFilterToolStripMenuItem
			// 
			this->highpassFilterToolStripMenuItem->BackColor = System::Drawing::SystemColors::Info;
			this->highpassFilterToolStripMenuItem->Name = L"highpassFilterToolStripMenuItem";
			this->highpassFilterToolStripMenuItem->Size = System::Drawing::Size(499, 38);
			this->highpassFilterToolStripMenuItem->Text = L"Highpass Filter";
			this->highpassFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::highPassFilterToolStripMenuItem_Click);
			// 
			// discreteFourierTransformToolStripMenuItem
			// 
			this->discreteFourierTransformToolStripMenuItem->Name = L"discreteFourierTransformToolStripMenuItem";
			this->discreteFourierTransformToolStripMenuItem->Size = System::Drawing::Size(499, 38);
			this->discreteFourierTransformToolStripMenuItem->Text = L"Discrete Fourier Transform";
			this->discreteFourierTransformToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::discreteFourierTransformToolStripMenuItem_Click);
			// 
			// inverseDiscreteFourierTransformToolStripMenuItem
			// 
			this->inverseDiscreteFourierTransformToolStripMenuItem->Name = L"inverseDiscreteFourierTransformToolStripMenuItem";
			this->inverseDiscreteFourierTransformToolStripMenuItem->Size = System::Drawing::Size(499, 38);
			this->inverseDiscreteFourierTransformToolStripMenuItem->Text = L"Inverse Discrete Fourier Transform";
			this->inverseDiscreteFourierTransformToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::inverseDiscreteFourierTransformToolStripMenuItem_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->flowLayoutPanel1->Controls->Add(this->SourceImageLabel);
			this->flowLayoutPanel1->Controls->Add(this->ResultImageLabel);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox_SourceImage);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox_OutputImage);
			this->flowLayoutPanel1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->flowLayoutPanel1->Location = System::Drawing::Point(6, 75);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(2171, 1320);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// SourceImageLabel
			// 
			this->SourceImageLabel->AutoSize = true;
			this->SourceImageLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->SourceImageLabel->Location = System::Drawing::Point(6, 0);
			this->SourceImageLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->SourceImageLabel->Name = L"SourceImageLabel";
			this->SourceImageLabel->Size = System::Drawing::Size(961, 30);
			this->SourceImageLabel->TabIndex = 0;
			this->SourceImageLabel->Text = L"Source Image                                                                     "
				L"                                                               ";
			// 
			// ResultImageLabel
			// 
			this->ResultImageLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ResultImageLabel->AutoSize = true;
			this->ResultImageLabel->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->ResultImageLabel->Location = System::Drawing::Point(979, 0);
			this->ResultImageLabel->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->ResultImageLabel->Name = L"ResultImageLabel";
			this->ResultImageLabel->Size = System::Drawing::Size(850, 30);
			this->ResultImageLabel->TabIndex = 1;
			this->ResultImageLabel->Text = L"Result Image                                                                     "
				L"                                              ";
			// 
			// pictureBox_SourceImage
			// 
			this->pictureBox_SourceImage->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->pictureBox_SourceImage->Location = System::Drawing::Point(6, 35);
			this->pictureBox_SourceImage->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->pictureBox_SourceImage->Name = L"pictureBox_SourceImage";
			this->pictureBox_SourceImage->Size = System::Drawing::Size(1049, 1352);
			this->pictureBox_SourceImage->TabIndex = 2;
			this->pictureBox_SourceImage->TabStop = false;
			this->pictureBox_SourceImage->Click += gcnew System::EventHandler(this, &MyForm::pictureBox_SourceImage_Click);
			// 
			// pictureBox_OutputImage
			// 
			this->pictureBox_OutputImage->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->pictureBox_OutputImage->Location = System::Drawing::Point(1067, 35);
			this->pictureBox_OutputImage->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->pictureBox_OutputImage->Name = L"pictureBox_OutputImage";
			this->pictureBox_OutputImage->Size = System::Drawing::Size(1083, 1339);
			this->pictureBox_OutputImage->TabIndex = 3;
			this->pictureBox_OutputImage->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2184, 1400);
			this->Controls->Add(this->tableLayoutPanel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"MyForm";
			this->Text = L"FourierTransform";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_SourceImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_OutputImage))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void loadImageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		openFileDialog1->ShowDialog();
	}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	//將影像讀入並設儲存至DataManager的資料結構中
	Bitmap^ OriginalImage = gcnew Bitmap(openFileDialog1->FileName);
	pictureBox_SourceImage->Image = OriginalImage;
	int scale = 1;
	int M = OriginalImage->Height * scale;
	int N = OriginalImage->Width * scale;

	dataManager = new DataManager(M,N);
	for (int i = 0; i < OriginalImage->Height; i++)
	{
		for (int j = 0; j < OriginalImage->Width; j++)
		{
			Color srcColor = OriginalImage->GetPixel(j, i); // 擷取每個點的顏色
			int srcGrey = srcColor.R*0.299 + srcColor.G*0.587 + srcColor.B*0.144; // 彩色三通道轉成灰階
			dataManager->SetPixel(j, i, srcGrey);
		}
	}

	std::cout << "-Image has been loaded-" << std::endl;
}
private: System::Void discreteFourierTransformToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	int w = dataManager->GetImageWidth();
	int h = dataManager->GetImageHeight();
	

	// 利用傅立葉之平移性，平移頻率
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int valuePixeli = dataManager->GetInputImage()[i][j];
			valuePixeli = valuePixeli * pow((float)-1, (float)(i + j)); 
			dataManager->SetPixel(j, i, valuePixeli);
		}
	}

	//將算出頻率資訊傳入輸出影像
	fourierTransformMethod->DiscreteFourierTransform(dataManager->GetInputImage(),dataManager->GetOutputImage(), dataManager->GetFreqReal(),dataManager->GetFreqImag(),h,w);
	Bitmap^ DFTImage = gcnew Bitmap(w, h);
	GetImage(h, w, DFTImage);
	pictureBox_OutputImage->Image = DFTImage;
}
private: System::Void inverseDiscreteFourierTransformToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	int w = dataManager->GetImageWidth();
	int h = dataManager->GetImageHeight();

	// 利用傅立葉之平移性，平移頻率
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int valuePixeli = dataManager->GetInputImage()[i][j];
			valuePixeli = valuePixeli * pow((float)-1, (float)(i + j)); 
			dataManager->SetPixel(j, i, valuePixeli);
		}
	}
	fourierTransformMethod->InverseDiscreteFourierTransform(
		dataManager->GetInputImage(), 
		dataManager->GetOutputImage(), 
		dataManager->GetFreqReal(), 
		dataManager->GetFreqImag(), 
		h, 
		w);

	//將算出頻率資訊傳入輸出影像
	Bitmap^ IDFTImage = gcnew Bitmap(w, h);
	GetImage(h, w, IDFTImage);

	pictureBox_OutputImage->Image = IDFTImage;
}
private: System::Void setResultImageAsSourceImageToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (TaiMing_method)
	{
		pictureBox_SourceImage->Image = pictureBox_OutputImage->Image;
		TaiMing_method = false;
		return;
	}
	int w = dataManager->GetImageWidth();
	int h = dataManager->GetImageHeight();
	Bitmap^ sImage = gcnew Bitmap(w, h);
	GetImage(h, w, sImage);
	pictureBox_SourceImage->Image = sImage;

}
private: void GetImage(int h, int w, Bitmap^& img) {
	for (int i = 0; i <h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int valuePixeli = dataManager->GetOutputImage()[i][j];

			if (valuePixeli > 255)
			{
				valuePixeli = 255;
			}
			else if (valuePixeli < 0)
			{
				valuePixeli = 0;
			}
			dataManager->SetPixel(j, i, valuePixeli);
			img->SetPixel(j, i, Color::FromArgb(valuePixeli, valuePixeli, valuePixeli));
		}
	}
}
private: System::Void lowPassFilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	int w = dataManager->GetImageWidth();
	int h = dataManager->GetImageHeight();
	double ** filter = fourierTransformMethod->Filter(h, w, 1, 10, true);
	
	fourierTransformMethod->LowpassFilter(
		dataManager->GetFreqReal(),
		dataManager->GetOutputImage(),
		filter, h, w);
	Bitmap^ DFTImage = gcnew Bitmap(w, h);
	GetImage(h, w, DFTImage);
	pictureBox_OutputImage->Image = DFTImage;

}
private: System::Void highPassFilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	int w = dataManager->GetImageWidth();
	int h = dataManager->GetImageHeight();
	double ** filter = fourierTransformMethod->Filter(h, w, 1, 10, false);

	fourierTransformMethod->LowpassFilter(
		dataManager->GetFreqReal(),
		dataManager->GetOutputImage(),
		filter, h, w);
	Bitmap^ DFTImage = gcnew Bitmap(w, h);
	GetImage(h, w, DFTImage);
	pictureBox_OutputImage->Image = DFTImage;

}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void fastFourierTransformToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	TaiMing_method = true;
	int w = dataManager->GetImageWidth(); int h = dataManager->GetImageHeight();
	
	Bitmap^ inputIMG = gcnew Bitmap(pictureBox_SourceImage->Image, w, h);
	Bitmap^ OriginalImage = FFTtest(inputIMG);
	
	pictureBox_OutputImage->Image = OriginalImage;


	

	
}
private: System::Void pictureBox_SourceImage_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void inverseFastFourierTransformToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	int w = dataManager->GetImageWidth(); int h = dataManager->GetImageHeight();
	pictureBox_SourceImage->Image = pictureBox_OutputImage->Image;
	Bitmap^ inputIMG = gcnew Bitmap(pictureBox_SourceImage->Image, w, h);
	Bitmap^ OriginalImage = IFFTtest(inputIMG);
	pictureBox_OutputImage->Image = OriginalImage;
}
};
}

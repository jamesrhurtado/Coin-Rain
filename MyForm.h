#pragma once
#include "Controller.h"

namespace SecondGradedLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//Buffer
			g = this->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, this->ClientRectangle);

			//Controller
			_game = new Controller();

			//Bitmap
			bmpSoldier = gcnew Bitmap("soldier.png");
			bmpCoins = gcnew Bitmap("coin.jpg");
			bmpBullets = gcnew Bitmap("bullet.png");
			bmpMap = gcnew Bitmap("map.png");

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete _game, bmpSoldier, bmpBullets, bmpCoins, bmpMap;
			}
		}

	private:
		//Buffer
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;

		//Bitmap
		Bitmap^ bmpCoins;
		Bitmap^ bmpSoldier;
		Bitmap^ bmpBullets;
		Bitmap^ bmpMap;

		//controller
		Controller* _game;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 572);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Clear
		buffer->Graphics->Clear(Color::White);


		//Draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, this->Width, this->Height);
		_game->drawEverything(buffer->Graphics, bmpSoldier, bmpCoins, bmpBullets);
		//Move
		_game->moveBullet(g);
		_game->addCoin();
		_game->moveCoin(g);
		 
		//Collision
		_game->collision();
		 
		//conditional
		if (_game->getSoldierLose()) {
			timer1->Enabled = false;
			MessageBox::Show("Silver coins must not be eliminated! You have lost.");
		}
		//Render
		buffer->Render(g);
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A: case Keys::Left:
			_game->moveSoldier(buffer->Graphics, 'A'); break;
		case Keys::D: case Keys::Right:
			_game->moveSoldier(buffer->Graphics, 'D'); break;
		case Keys::W: case Keys::Up:
			_game->moveSoldier(buffer->Graphics, 'W'); break;
		case Keys::S: case Keys::Down:
			_game->moveSoldier(buffer->Graphics, 'S'); break;
		case Keys::Space:
			_game->shootBullet(); break;
	}
	}
	};
}

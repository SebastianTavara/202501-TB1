#pragma once

#include <iostream>

#include <Windows.h>



using namespace std;

using namespace System;



class Introduccion {

public:



#define ma 40

#define mh 120

	void consolaBase() {

		Console::CursorVisible = false;

		SetConsoleOutputCP(850);

	}



	void cambiarTamanoBuffer(int ancho, int alto) {

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		COORD tamanoBuffer;

		tamanoBuffer.X = ancho;

		tamanoBuffer.Y = alto;

		SetConsoleScreenBufferSize(hOut, tamanoBuffer);

	}

	/*
	void lineas() {

		for (int k = 0; k < 2; ++k) {

			for (int i = 0; i < 70; ++i) {

				gotoxy(25 + i, 6 + k * 18); color(DARK_GREEN); cout << "-";
			}

			gotoxy(25, 6 + k * 18); cout << "+";
			gotoxy(60, 6 + k * 18); cout << "+";
			gotoxy(94, 6 + k * 18); cout << "+";
		}
		clearColor();

	}




	void detectarColision() {
	// Lógica para detectar colisiones aquí

	N_agua--; // Por ejemplo, si se reduce agua al detectar colisión

	N_semillas--; // Decrementar semillas también si es necesario

	N_reciclables--; // O residuos reciclables



	// Redibujar los recursos con los valores actualizados

	recursos();

	}

	*/



	void Color(int a) {



		switch (a) {



		case 0: Console::ForegroundColor = ConsoleColor::Black;    break;

		case 1: Console::ForegroundColor = ConsoleColor::DarkBlue;  break;

		case 2: Console::ForegroundColor = ConsoleColor::DarkGreen;  break;

		case 3: Console::ForegroundColor = ConsoleColor::DarkCyan;  break;

		case 4: Console::ForegroundColor = ConsoleColor::Red;     break;

		case 5: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;

		case 6: Console::ForegroundColor = ConsoleColor::DarkYellow; break;

		case 7: Console::ForegroundColor = ConsoleColor::Gray;    break;

		case 8: Console::ForegroundColor = ConsoleColor::DarkGray;  break;

		case 9: Console::ForegroundColor = ConsoleColor::Blue;    break;

		case 10: Console::ForegroundColor = ConsoleColor::Green;    break;

		case 11: Console::ForegroundColor = ConsoleColor::Cyan;    break;

		case 12: Console::ForegroundColor = ConsoleColor::Red;     break;

		case 13: Console::ForegroundColor = ConsoleColor::Magenta;   break;

		case 14: Console::ForegroundColor = ConsoleColor::Yellow;   break;

		case 15: Console::ForegroundColor = ConsoleColor::White;   break;



		}

	}





	void pintarUPC() {

		int InitX = 43;
		int initY = 5;

		_sleep(100);
		Color(12); Console::SetCursorPosition(InitX, initY); cout << "           -=          " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 1); cout << "           -##.          " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 2); cout << "    ::      =###:          .-    " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 3); cout << "   .*:      :####*.        .*:   " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 4); cout << "  :#=      +######=.        :#=  " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 5); cout << "  :##      +########=       *#=  " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 6); cout << "  ###      .#########*       +##: " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 7); cout << " -###       :#########+      *##+ " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 8); cout << " +###-       .+########     .#### " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 9); cout << " +####:       .+######      *#### " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 10); cout << " -#####-       -####-     .*####+ " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 11); cout << "  *#####*:      ###=     .+######. " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 12); cout << "  .#######*=.     #*:  .-+#######  " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 13); cout << "  .*#########*+=--++==+#########  " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 14); cout << "    =##########################*.   " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 15); cout << "     .=######################+:    " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 16); cout << "       :+################+-.     " << endl;
		_sleep(100);						  
		Color(12); Console::SetCursorPosition(InitX, initY + 17); cout << "           .:-=++**++==:.       " << endl;

		_sleep(3000);
		clear();


		Color(15); Console::SetCursorPosition(5, 1); cout << "/$$$$$$$$/$$$$$$$  /$$$$$$ /$$$$$$$  /$$$$$$    /$$$$$ /$$$$$$    " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 2); cout << "|__ $$__/|$$__ $$ /$$__ $$| $$__ $$ /$$__ $$   |__ $$ /$$__ $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 3); cout << "  | $$  | $$ \\ $$| $$ \\ $$| $$ \\ $$| $$ \\ $$     | $$| $$ \\ $$ " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 4); cout << "  | $$  | $$$$$$$/|$$$$$$$$|$$$$$$$|$$$$$$$$     | $$| $$ | $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 5); cout << "  | $$  | $$__ $$| $$__ $$| $$__ $$| $$__ $$ /$$ | $$| $$ | $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 6); cout << "  | $$  | $$ \\ $$| $$ | $$| $$ \\ $$| $$ | $$| $$ | $$| $$ | $$  " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 7); cout << "  | $$  | $$ | $$| $$ | $$| $$$$$$$/|$$ | $$| $$$$$$/| $$$$$$/   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(5, 8); cout << "  |__/  |__/ |__/|__/ |__/|_______/ |__/ |__/ \\______/\\______/   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 15); cout << " /$$$$$$$   /$$$$$$ /$$$$$$$   /$$$$$$/$$$$$$ /$$$$$$ /$$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 16); cout << " | $$__ $$ /$$__ $$ | $$__ $$ /$$__ $$|_ $$_/ /$$__ $$| $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 17); cout << " | $$ \\ $$ | $$ \\ $$| $$ \\ $$| $$ \\__/ |  $$ | $$ \\ $$| $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 18); cout << " | $$$$$$$/|$$$$$$$$| $$$$$$$/|$$      | $$ |  $$$$$$$| $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 19); cout << " | $$____/ | $$__ $$| $$__ $$| $$      | $$ |  $$__ $$| $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 20); cout << " | $$      | $$ | $$| $$ \\ $$| $$  $$  | $$ |  $$ | $$| $$   " << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 21); cout << " | $$      | $$ | $$| $$ | $$| $$$$$$//$$$$$$| $$ | $$| $$$$$$$$" << endl;
		_sleep(100);
		Color(15); Console::SetCursorPosition(8, 22); cout << " |__/      |__/ |__/|__/ |__/ \\______/|______/|__/ |__/|________/" << endl;




		_sleep(2000);

		clear();

		initY = 1;


		Color(10); Console::SetCursorPosition(36, initY + 1); cout << "		     -===+++++++===-" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 2); cout << "            .=+++++++++++++++++++++=." << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 3); cout << "          =++++++++++++++++++++++++++++." << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 4); cout << "	 :+++++++++++++++++++++++++++++++++-" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 5); cout << "     .+++++++++++++++++++++++++++++++++++++:" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 6); cout << "     =+++++++++++++++++++++++++++++++++++++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 7); cout << "    +++++++++++++++++++++++++++++++++++++++++++" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 8); cout << "   =+++++====.                -===++++++++++=+++" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 9); cout << "  ++++++                              =++++++++++" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 10); cout << " -+++++=                                  -+++++++" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 11); cout << " +++=+++=  .-=++++++++++++++++=:.           -+++++." << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 12); cout << ".++++++++++++++++++=====+++++++++++++-      -+++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 13); cout << "=+++++++++=-                   :++=+++++=====+++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 14); cout << "+++++++++-                          .=++++++++++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 15); cout << "=+++++++++     .:========-.             =+++++++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 16); cout << "-++++++++++++=+++++++++++++++++++:       =++++++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 17); cout << " ++++++++++=++++-::.   ..:-+++++++++=:  ++++++++++-" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 18); cout << " =++++++++=                      -++++++++++++++++" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 19); cout << " :++++++++=     .::-===--:.         .=+++++++++++:" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 20); cout << "  :+++++++++++++++++++++++++++++:     ++++++++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 21); cout << "   -+++++++++++++++++++++++++++++++==+++++++++++" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 22); cout << "    :+++++++++++++++++++++++++++++++++++++++++=" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 23); cout << "      =++++++++++++++++++++++++++++++++++++++." << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 24); cout << " 	   :+++++++++++++++++++++++++++++++-" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 25); cout << "            -+++++++++++++++++++++++++=." << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 26); cout << "              :=+++++++++++++++++=-" << endl;
		_sleep(100);
		Color(10); Console::SetCursorPosition(36, initY + 27); cout << " 		    .:=========-:" << endl;




		/*

		 /$$$$$$$  /$$$$$$ /$$$$$$$  /$$$$$$ /$$$$$$ /$$$$$$ /$$

		| $$__ $$ /$$__ $$| $$__ $$ /$$__ $$|_ $$_/ /$$__ $$| $$

		| $$ \ $$| $$ \ $$| $$ \ $$| $$ \__/ | $$ | $$ \ $$| $$

		| $$$$$$$/| $$$$$$$$| $$$$$$$/| $$    | $$ | $$$$$$$$| $$

		| $$____/ | $$__ $$| $$__ $$| $$    | $$ | $$__ $$| $$

		| $$   | $$ | $$| $$ \ $$| $$  $$ | $$ | $$ | $$| $$

		| $$   | $$ | $$| $$ | $$| $$$$$$/ /$$$$$$| $$ | $$| $$$$$$$$

		|__/   |__/ |__/|__/ |__/ \______/ |______/|__/ |__/|________/



		*/

	}





	void computadora() {

		_sleep(200);



		//COMPUTADORA

		Color(15); Console::SetCursorPosition(44, 1); cout << "  +--------------+  ";

		Color(15); Console::SetCursorPosition(44, 2); cout << "  |.------------.| ";

		Color(15); Console::SetCursorPosition(44, 3); cout << "  ||            || ";
																	       
		Color(15); Console::SetCursorPosition(44, 4); cout << "  ||            || ";
																	       
		Color(15); Console::SetCursorPosition(44, 5); cout << "  ||            || ";
																	       
		Color(15); Console::SetCursorPosition(44, 6); cout << "  ||            || ";

		Color(15); Console::SetCursorPosition(44, 7); cout << "  |+------------+| ";

		Color(15); Console::SetCursorPosition(44, 8); cout << "  +-..--------..-+ ";

		Color(15); Console::SetCursorPosition(44, 9); cout << "  .--------------. ";

		Color(15); Console::SetCursorPosition(44, 10); cout << " / /============\\ \\ ";

		Color(15); Console::SetCursorPosition(44, 11); cout << " / /==============\\ \\ ";

		Color(15); Console::SetCursorPosition(44, 12); cout << "/____________________\\ ";

		Color(15); Console::SetCursorPosition(44, 13); cout << "\\____________________/ ";



		_sleep(300);



	}



	void auriculares() {

		_sleep(200);



		Color(15); Console::SetCursorPosition(42, 8); cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠂⠉⠉⠉⠀⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 9); cout << "⠀⠀⠀⠀⢀⠀⣶⡟⢀⣴⣶⣿⣾⣶⣶⣄⡀⠈⠑⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 10); cout << "⠀⠀⠀⡴⣫⣼⡿⣴⡟⠛⠉⠉⠛⠛⠿⣿⣿⣷⣦⡀⠙⢄⠀⠀⠀⠀⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 11); cout << "⠀⠀⣼⢁⣟⡟⣷⠁⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣷⣆⠈⢣⡀⠀⠀⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 12); cout << "⠀⢰⣿⢼⣿⣷⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⡆⠀⢱⠀⠀⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 13); cout << "⠀⢸⡵⣾⣇⣸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣧⠀⠀⢧⠀⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 14); cout << "⠀⠘⣴⣿⢯⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡿⠛⠉⠹⡆⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 15); cout << "⢀⣼⣿⣧⠟⠁⢀⢀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢯⣴⣶⣴⡇⠀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 16); cout << " ⢸⣿⣼⣿⣋⣉⠀⠀⠀⠈⠙⠦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣷⣷⡀⠀⠀";

		Color(15); Console::SetCursorPosition(42, 17); cout << "⢸⠁⠊⣿⠛⢛⢟⣦⡀⠀⠀⠀⠈⢆⠀⠀⠀⠀⢀⠔⣨⣶⡜⠂⠈⠽⣧⡀⠀";

		Color(15); Console::SetCursorPosition(42, 18); cout << "⠸⣶⣾⡯⠤⢄⡀⠵⢿⣦⡀⠀⠀⠀⡷⡄⠀⡰⢁⣾⣿⣿⣿⠀⠀⠀⣿⡹⡄";

		Color(15); Console::SetCursorPosition(42, 19); cout << "⠀⣿⣡⠦⢄⡀⠈⠳⣬⣹⣿⣆⠀⠀⢉⠻⣴⠇⣾⣿⡟⢻⠁⠀⠀⠀⣿⠁⡇";

		Color(15); Console::SetCursorPosition(42, 20); cout << "⠀⣿⣡⠦⢄⡀⠈⠳⣬⣹⣿⣆⠀⠀⢉⠻⣴⠇⣾⣿⡟⢻⠁⠀⠀⠀⣿⠁⡇";

		Color(15); Console::SetCursorPosition(42, 21); cout << "⠀⣿⡭⡀⠀⠈⠲⣦⣸⣿⣿⣿⣧⣀⠈⡔⣜⣴⣿⡟⢀⡎⡈⠀⠀⢰⡿⢠⣷";

		Color(15); Console::SetCursorPosition(42, 22); cout << " ⢸⣿⣄⣒⡀⡀⣿⣷⡿⣿⢿⣿⣷⡰⡸⣯⣏⣿⡷⢋⣼⣁⡢⢠⠟⠀⣼⣿";

		Color(15); Console::SetCursorPosition(42, 23); cout << "⠀⠀⠀⠘⠿⣿⣿⣽⣽⣷⣿⣿⣿⣿⣿⡶⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⠀";

		Color(15); Console::SetCursorPosition(42, 24); cout << "⠀⠀⠀⠀⠀⠀⠉⠙⠿⢿⣿⣿⣿⣿⠟⠁⠀⠘⠿⣿⣿⣿⠿⠟⠉⠀⠀⠀⠀";



		_sleep(300);





	}



	void pintarSpotify() {



		Color(12); Console::SetCursorPosition(66, 10); cout << "		     -===+++++++===-" << endl;

		Color(12); Console::SetCursorPosition(66, 11); cout << "            .=+++++++++++++++++++++=." << endl;
																    
		Color(12); Console::SetCursorPosition(66, 12); cout << "          =++++++++++++++++++++++++++++." << endl;
																    
		Color(12); Console::SetCursorPosition(66, 13); cout << "	 :+++++++++++++++++++++++++++++++++-" << endl;
																    
		Color(12); Console::SetCursorPosition(66, 14); cout << "     .+++++++++++++++++++++++++++++++++++++:" << endl;
																    
		Color(12); Console::SetCursorPosition(66, 15); cout << "     =+++++++++++++++++++++++++++++++++++++++=" << endl;
																    
		Color(12); Console::SetCursorPosition(66, 16); cout << "    +++++++++++++++++++++++++++++++++++++++++++" << endl;

		Color(12); Console::SetCursorPosition(66, 17); cout << "   =+++++====.                -===++++++++++=+++" << endl;

		Color(12); Console::SetCursorPosition(66, 18); cout << "  ++++++                              =++++++++++" << endl;

		Color(12); Console::SetCursorPosition(66, 19); cout << " -+++++=                                  -+++++++" << endl;

		Color(12); Console::SetCursorPosition(66, 20); cout << " +++=+++=  .-=++++++++++++++++=:.           -+++++." << endl;

		Color(12); Console::SetCursorPosition(66, 21); cout << ".++++++++++++++++++=====+++++++++++++-      -+++++=" << endl;

		Color(12); Console::SetCursorPosition(66, 22); cout << "=+++++++++=-                   :++=+++++=====+++++=" << endl;

		Color(12); Console::SetCursorPosition(66, 23); cout << "+++++++++-                          .=++++++++++++=" << endl;

		Color(12); Console::SetCursorPosition(66, 24); cout << "=+++++++++     .:========-.             =+++++++++=" << endl;
																
		Color(12); Console::SetCursorPosition(66, 25); cout << "-++++++++++++=+++++++++++++++++++:       =++++++++=" << endl;
																
		Color(12); Console::SetCursorPosition(66, 26); cout << " ++++++++++=++++-::.   ..:-+++++++++=:  ++++++++++-" << endl;
																
		Color(12); Console::SetCursorPosition(66, 27); cout << " =++++++++=                      -++++++++++++++++" << endl;
																
		Color(12); Console::SetCursorPosition(66, 28); cout << " :++++++++=     .::-===--:.         .=+++++++++++:" << endl;
																
		Color(12); Console::SetCursorPosition(66, 29); cout << "  :+++++++++++++++++++++++++++++:     ++++++++++=" << endl;
																
		Color(12); Console::SetCursorPosition(66, 30); cout << "   -+++++++++++++++++++++++++++++++==+++++++++++" << endl;
																
		Color(12); Console::SetCursorPosition(66, 31); cout << "    :+++++++++++++++++++++++++++++++++++++++++=" << endl;
																   
		Color(12); Console::SetCursorPosition(66, 32); cout << "      =++++++++++++++++++++++++++++++++++++++." << endl;
																   
		Color(12); Console::SetCursorPosition(66, 33); cout << " 	 :+++++++++++++++++++++++++++++++-" << endl;
																   
		Color(12); Console::SetCursorPosition(66, 34); cout << "           -+++++++++++++++++++++++++=." << endl;
		Color(12); Console::SetCursorPosition(66, 35); cout << "             :=+++++++++++++++++=-" << endl;
		Color(12); Console::SetCursorPosition(66, 36); cout << " 		   .:=========-:" << endl;



	}





};


/*
				  -===+++++++===-
			 .=+++++++++++++++++++++=.
		   =++++++++++++++++++++++++++++.
		:+++++++++++++++++++++++++++++++++-
	  .+++++++++++++++++++++++++++++++++++++:
	 =+++++++++++++++++++++++++++++++++++++++=
	+++++++++++++++++++++++++++++++++++++++++++
   =+++++====.                -===++++++++++=+++
  ++++++                              =++++++++++
 -+++++=                                  -+++++++
 +++=+++=  .-=++++++++++++++++=:.           -+++++.
.++++++++++++++++++=====+++++++++++++-      -+++++=
=+++++++++=-                   :++=+++++=====+++++=
+++++++++-                          .=++++++++++++=
=+++++++++     .:========-.             =+++++++++=
-++++++++++++=+++++++++++++++++++:       =++++++++=
 ++++++++++=++++-::.   ..:-+++++++++=:  ++++++++++-
 =++++++++=                      -++++++++++++++++
 :++++++++=     .::-===--:.         .=+++++++++++:
  :+++++++++++++++++++++++++++++:     ++++++++++=
   -+++++++++++++++++++++++++++++++==+++++++++++
	:+++++++++++++++++++++++++++++++++++++++++=
	  =++++++++++++++++++++++++++++++++++++++.
	   -+++++++++++++++++++++++++++++++++++=
		 :+++++++++++++++++++++++++++++++-
			-+++++++++++++++++++++++++=.
			   :=+++++++++++++++++=-
					 .:=====-:
*/
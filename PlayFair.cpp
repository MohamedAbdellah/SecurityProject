/*
 * PlayFair.cpp
 *
 *  Created on: Nov 6, 2018
 *      Author: chrollo
 */

#include<iostream>
#include <string>
#include<stdio.h>
#include<string.h>
#include"PlayFair.hpp"

void Play_fair(string message, string p_key) {

	int str_len = p_key.length();
	char arr[5][5];
	int lim = str_len / 5;
	int arraycunt = 0, cunt = 0;
	string c_message;
	//============insert the keyword to the beginning of the matrix===============//

	for (int i = 0; i <= lim; i++) {
		for (int j = 0; j < 5; j++) {
			if (((lim) + j) >= str_len) {
				break;
			}
			if (p_key[(i * 5) + j] == 'j')
				p_key[(i * 5) + j] = 'i';
			arr[(i * 5) / 5][j] = p_key[(i * 5) + j];
		}
	}

	//===========insert the rest of the alphabet into the matrix===============//
	//========== & replace in letter j with letter i & eliminate repetition====//

	for (char c = 'a'; c <= 'z'; c++) {
		for (int j = 0; j < str_len; j++) {
			if (arr[j / 5][j % 5] != c)
				cunt++;
		}
		if (cunt == str_len && c != 'j') {
			arr[(str_len + arraycunt) / 5][(str_len + arraycunt) % 5] = c;
			arraycunt++;
		}
		cunt = 0;
	}

	//==============replace any letter j with letter i in the message==========//

	int mess_length = message.length();
	for (int i = 0; i < mess_length; i++) {

		if (message[i] == 'j') {
			message[i] = 'i';
		}
		//=============insert x between 2 identical chars in a row===========//
		else if (message[i] == message[i + 1]) {

			message.insert(i + 1, "x");
			i++;
		} else {

		}
	}
	mess_length = message.length();

	//==================check that message length is even ==================//

	if (mess_length % 2 != 0)
		message +="x";
	mess_length = message.length();

	//===============  divide the message into pairs =========================//

	int index_row_1, index_row_2, index_col_1, index_col_2, cunt0 = 0,
			cunt1 = 0;
	for (int i = 0; i < mess_length; i += 2) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (message[i] == arr[j][k]) {
					index_row_1 = j;
					index_col_1 = k;
					cunt0++;
				}
				if (message[i + 1] == arr[j][k]) {
					index_row_2 = j;
					index_col_2 = k;
					cunt0++;
				}
				if (cunt0 == 2)
					break;

			}
			if (cunt0 == 2) {
				cunt0 = 0;
				break;
			}
		}

		//================First rule for playfait =======================//

		if ((index_col_1 != index_col_2) && (index_row_1 != index_row_2)) {
			c_message += arr[index_row_1][index_col_2];
			c_message += arr[index_row_2][index_col_1];
			cunt1++;
		}

		//==============Second rule for PlayFair =======================//

		else if (index_col_1 == index_col_2) {
			if ((index_row_1 + 1) >= 5)
				index_row_1 = -1;
			if ((index_row_2 + 1) >= 5)
				index_row_2 = -1;
			c_message += arr[(index_row_1 + 1)][index_col_2];
			c_message += arr[(index_row_2 + 1)][index_col_1];
			cunt1++;
		}

		//================Third Rule for PlayFair ====================//

		else if (index_row_1 == index_row_2) {
			if ((index_col_1 + 1) >= 5)
				index_col_1 = -1;
			if ((index_col_2 + 1) >= 5)
				index_col_2 = -1;
			c_message += arr[(index_row_2)][(index_col_1 + 1)];
			c_message += arr[(index_row_1)][(index_col_2 + 1)];

			cunt1++;
		} else {

		}

	}


	//=======================================================================//

//print the result matrix

	cout<<"paly fair matrix"<<endl;
	 for (int i = 0; i < 5; i++) {
	 for (int j = 0; j < 5; j++) {
	 cout << arr[i][j] << " ";
	 }
	 cout << endl;
	 }


	 cout<<"the Transformed text"<<endl;
		cout << c_message<<endl;

}


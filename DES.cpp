/*
 * DES.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: chrollo
 */

#include<iostream>
#include <string>
#include<stdio.h>
#include<string.h>
#include"DES.hpp"
#include"DES_configure.hpp"

void convertToBinary(int n, char m[]) {
	static int c = 0;
	for (int i = 3; i >= 0; --i, n = n / 2) {
		m[(i + c) % 32] = (n & 1) + '0';
	}

	c = c + 4;

}

void shift(int shift_arr[], char key_56[], char n_key[][28]) {

	for (int i = 0; i < 28; i++) {
		n_key[0][i] = key_56[i];
		n_key[17][i] = key_56[i + 28];
	}

	for (int i = 1; i <= 16; i++) {
		for (int j = 0; j < 28; j++) {
			n_key[i][j] = n_key[i - 1][j];
		}

		for (int var = 0; var < shift_arr[i]; ++var) {
			int temp = (int) n_key[i][0];
			for (int var1 = 0; var1 < 27; ++var1) {
				n_key[i][var1] = n_key[i][var1 + 1];
			}
			n_key[i][27] = (char) temp;
		}

		for (int j = 0; j < 28; j++) {
			n_key[i + 17][j] = n_key[i + 16][j];
		}
		for (int var = 0; var < shift_arr[i]; ++var) {
			int temp1 = (int) n_key[i + 17][0];
			for (int var1 = 0; var1 < 27; ++var1) {
				n_key[i + 17][var1] = n_key[i + 17][var1 + 1];
			}
			n_key[i + 17][27] = (char) temp1;
		}
	}
}

void GEN_KEY(string p_key, char lst_key[17][56], char llst_k[16][48]) {

	char fst_key[56];
	char key[34][28];

	for (int j = 0; j < 56; j++)
		fst_key[j] = p_key[pc1[j] - 1];

	for (int j = 0; j < 56; j++)
		cout << fst_key[j];

	shift(shift_arr, fst_key, key);

	cout << endl << "New key" << endl;

	for (int var = 0; var < 34; ++var) {
		for (int j = 0; j < 28; j++)
			cout << key[var][j];
		cout << " key" << var << endl;

	}

	for (int var = 1; var <= 16; ++var) {
		for (int j = 0; j < 28; j++) {
			lst_key[var][j] = key[var][j];
			lst_key[var][j + 28] = key[var + 17][j];

		}
	}

	for (int var = 0; var < 16; ++var) {
		for (int j = 0; j < 48; j++) {

			llst_k[var][j] = lst_key[var + 1][pc2[j] - 1];
		}
	}
}

void DES(string message, string p_key) {
	char lst_key[17][56];
	char llst_k[16][48];
	char e_r[17][48];
	char l[17][32], r[17][32];
	int row[17][8], col[17][8];
	int s_f_d[17][8];
	char messages2[64];
	char end_messaage[64];
	char mes[32];
	char mess2[32];
	int cunt = 0, r0w = 0, c0l = 0, index = 0, temp = 0, temp1 = 0;
	GEN_KEY(p_key, lst_key, llst_k);

	for (int var = 0; var < 16; ++var) {
		for (int j = 0; j < 48; j++)
			cout << llst_k[var][j];
		cout << " llst k" << var << endl;
	}

	//
	cout << "message" << endl;
	for (int j = 0; j < 64; j++) {
		messages2[j] = message[ip[j] - 1];
		cout << messages2[j];
	}

	for (int j = 0; j < 32; j++) {

		r[0][j] = messages2[j + 32];
		l[0][j] = messages2[j];
	}

	cout << endl << "l0" << endl;

	for (int j = 0; j < 32; j++)
		cout << l[0][j];

	cout << endl << "r0" << endl;

	for (int j = 0; j < 32; j++) {
		cout << r[0][j];
		l[1][j] = r[0][j];
	}

// ===============================================================================
// ========================= Calc R1 ,L1 ----> Rn ,Ln ============================
// ===============================================================================

	for (int i = 1; i < 17; i++) {
		cout << endl << "l " << i << " " << endl;
		for (int k = 0; k < 32; k++) {
			l[i][k] = r[i - 1][k];
			cout << l[i][k];
		}

		for (int j = 0; j < 48; j++) {
			e_r[i][j] = r[i - 1][(e_tab[j] - 1)]; //expansion

		}

		for (int j = 0; j < 48; j++) {
			e_r[i][j] = e_r[i][j] == llst_k[i - 1][j] ? '0' : '1'; //xor

		}

// ========================== sec SBOX ===========================================

		for (int j = 0; j < 48; j++) {
			if (cunt == 0) {
				cunt++;
				r0w = e_r[i][j];
				r0w = r0w - 48;
				r0w = r0w * 2;
				temp1 = r0w;

			} else if (cunt == 1) {
				c0l = e_r[i][j];
				c0l = c0l - 48;
				c0l = c0l * 8;
				temp = c0l;
				cunt++;

			} else if (cunt == 2) {
				c0l = e_r[i][j];
				c0l = c0l - 48;
				c0l = c0l * 4;
				c0l = c0l + temp;
				temp = c0l;
				cunt++;
			} else if (cunt == 3) {
				c0l = e_r[i][j];
				c0l = c0l - 48;
				c0l = c0l * 2;
				c0l = c0l + temp;
				temp = c0l;
				cunt++;
			} else if (cunt == 4) {
				c0l = e_r[i][j];
				c0l = c0l - 48;
				c0l = c0l * 1;
				c0l = c0l + temp;
				temp = c0l;
				cunt++;
			} else if (cunt == 5) {
				r0w = e_r[i][j];
				r0w = r0w - 48;
				r0w = r0w * 1;
				r0w = r0w + temp1;
				cunt = 0;
				row[i - 1][index] = r0w;
				col[i - 1][index] = c0l;
				index++;
				r0w = 0;
				c0l = 0;
				temp = 0, temp1 = 0;
			} else {
				cout << endl << " *********YOU CANNOT BE HERE*********" << endl;
			}
		}
		index = 0;

//-----------------------------reduce using sbox----------------------------------

		for (int j = 0; j < 8; j++) {

			s_f_d[i][j] = sbox[j][((row[i - 1][j] * 16) + col[i - 1][j])];

		}
		cout << endl;
///*
// =============================Conv to binary ===================================

		for (int j = 0; j < 8; j++) {
			convertToBinary(s_f_d[i][j], mes);
		}

		for (int j = 0; j < 32; j++)

//--------------------------------perm------------------------------------

			for (int j = 0; j < 32; j++) {
				mess2[j] = mes[pc3[j] - 1];

			}

//------------------------------------ xor with l --------------------------

		cout << endl << "r " << i << " " << endl;
		for (int j = 0; j < 32; j++) {
			r[i][j] = mess2[j] == l[i - 1][j] ? '0' : '1';
			cout << r[i][j];
		}

	}

	for (int j = 0; j < 32; j++) {

		messages2[j] = r[16][j];
		messages2[j + 32] = l[16][j];

	}
	cout << endl << "message = ";
	for (int j = 0; j < 64; j++)

		cout << messages2[j];

// ============================= final permutation ===============================

	cout << endl << " ==================== Cipher Text ====================== "
			<< endl;
	for (int j = 0; j < 64; j++) {

		end_messaage[j] = messages2[f_perm[j] - 1];
		cout << end_messaage[j];

	}
	cout << endl << " ====================  ====================== " << endl;
}


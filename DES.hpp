/*
 * DES.hpp
 *
 *  Created on: Nov 19, 2018
 *      Author: chrollo
 */

#ifndef DES_HPP_
#define DES_HPP_

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

extern string message;
extern string p_key;

void convertToBinary(int ,char m[32]);
void DES(string, string);
void GEN_KEY(string, char lst_key[][48] ,char llst_k[16][48]);
void shift(int shift_arr[], char key[],char a[][28]);

#endif /* DES_HPP_ */

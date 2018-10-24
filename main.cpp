/*
 * main.cpp
 *
 *  Created on: Oct 23, 2018
 *      Author: Mohamed abdellah
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include"Caesar_Cipher.hpp"
using namespace std;
int key;
string message;
int main(){
printf("Enter your message \n");
getline(cin,message);
printf("Enter the key \n");
cin>>key;
Caesar_Cipher(message,key);
}

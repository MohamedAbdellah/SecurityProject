/*
 * Caesar_Cipher.cpp
 *
 *  Created on: Oct 23, 2018
 *      Author: chrollo
 */
#include<iostream>
#include<stdio.h>
#include<string.h>
#include"Caesar_Cipher.hpp"
void Caesar_Cipher(string message,int key){
	int str_len=0;
	int num;
	string message2="";
	str_len=message.length();
	for(int i=0;i<str_len;i++){
		num=message[i];
	    if(num==' '){
	     message2.insert(i, " ");
	    }
	    else {
	          if(num>=97){
	    		num=(((num-97)+(key%26))%26)+97;
	    		message2 +=char(num);
	          	}
	          else if(num>=49 && num<=57)
	        	  message2 +=char(num);
	          else {
	      		num=(((num-65)+(key%26))%26)+65;
	      		message2 +=char(num);
	            	}
	    }

	}
	cout<<message2;
	}







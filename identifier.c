/*Identifier code - Software Test */
//#include "identifier.h"

//#include <stdio.h>

int valid_s (char ch){
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
	{
		return (1); 
	}		   
	else       
		return (0); 
} 
      
int valid_f(ch) char ch; {
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))       
		return (1);    
	else        
		return (0); 
}

int identifier (char *word)
{ 	
	char  *achar; 
	int   length, valid_id;
	length = 0;

	achar = word;

	//printf ("Identificador: ");

	valid_id = valid_s(achar[0]);
	if (valid_id) 
		length = 1; 
	int i = 1;	
	while (achar[i] != '\0'){
		if (!(valid_f(achar[i]))) 
			valid_id = 0; 
		length++; 
		i++;
	} 
	if (valid_id && (length >= 1) && (length < 6) ) {
        return 0;
    }else {	
        return 1;
    }

}


/*#include "identifier.h"

int valid_s (char ch){
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		return (1);    
	else       
		return (0); 
} 
      
int valid_f(ch) char ch; {
	if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))       
		return (1);    
	else        
		return (0); 
}

int identifier(const char *word) {
    char  achar; 
	int   length, valid_id;
	length = 0;
    achar = fgetc (word);
	valid_id = valid_s(achar);
	if (valid_id) 
		length = 1; 
		
    achar = fgetc (word);
	while (achar != '\n'){
		if (!(valid_f(achar))) 
			valid_id = 0; 
		length++; 
        achar = fgetc (word);
	} 
	if (valid_id && (length >= 1) && (length < 6) ) {
        return 0;
    }else {	
        return 1;
    }   
}*/

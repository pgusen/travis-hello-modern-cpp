/*Identifier code - SOftware Test */

#include <stdio.h>

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

int main ()
{ 
	char  achar; 
	int   length, valid_id;
	length = 0;
	printf ("Identificador: ");
	achar = fgetc (stdin);
	valid_id = valid_s(achar);
	if (valid_id) 
		length = 1; 
		
	achar = fgetc (stdin);
	while (achar != '\n'){
		if (!(valid_f(achar))) 
			valid_id = 0; 
		length++; 
		achar = fgetc (stdin);
	} 
	if (valid_id && (length >= 1) && (length < 6) ) {
		printf ("Valido\n"); 
        return 0;
    }else {
		printf ("Invalido\n");	
        return 1;
    }

}

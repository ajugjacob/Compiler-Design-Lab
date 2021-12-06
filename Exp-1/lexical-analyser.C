#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char keys[32][10] = {"auto","break","case","char","const","continue","default",
						"do","double","else","enum","extern","float","for","goto",
						"if","int","long","register","return","short","signed",
						"sizeof","static","struct","switch","typedef","union",
						"unsigned","void","volatile","while"};

int isNumber(char s[]) 
{
  if(!strlen(s))
  	return -1;
  for(int i=0;i<strlen(s);i++){
      if(!isdigit(s[i]) && s[i]!='.')
          return 0;
  }
  return 1;
}	

int isKeyword(char buffer[]){
	for(int i = 0; i < 32; ++i){
		if(strcmp(keys[i], buffer) == 0){
			return 1;
		}
    	}	
	return 0;
}


int main()
{
	char ch, buffer[15], operators[] = "+-*/%=", symbols[] = ";:!^\"\'";
	FILE *fp;
	int i,j=0;
	fp = fopen("p.txt","r");
	if(fp == NULL){
		printf("Error while opening the file\n");
		exit(0);
	}
	while((ch = fgetc(fp)) != EOF){
 		if(isalnum(ch)||ch=='.'){
 			buffer[j++] = ch;
 		}
 		else if (ch == ' ' || ch == '\n' || ch == '=' || ch == ';' || ch == '+' 
 			|| ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '.'
 			|| ch == ',' && ch != '\t') {
				buffer[j] = '\0';
				j = 0;   				
				if(isKeyword(buffer) == 1)
					printf("%s is keyword\n", buffer);
				else {
					int f=isNumber(buffer);
		      if(f==1)
						printf("%s is constant\n", buffer);
					else if(f==0)
						printf("%s is identifier\n", buffer);
				}
 		}
 		for(i = 0; i < 6; ++i){
 			if(ch == operators[i]) {
   			printf("%c is operator\n", ch);
				break;
			}
      else if(ch == symbols[i]) {
 				printf("%c is symbol\n", ch);
				break;
			}
 		}
	}
	return 0;
}
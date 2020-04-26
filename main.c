#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define veryLong long long

typedef struct Number {
	
	char *value;
	veryLong size;
		
} Number;

void printResult(Number result);
int charToInt(char numero);
Number suma(Number num1,Number num2);
Number smallestNumber(Number num1,Number num2);
Number biggestNumber(Number num1,Number num2);
veryLong length(char *str);
Number __INIT__(veryLong size);


int main(int argc, char *argv[]) {
		
		
	if(argv[2] == NULL || argv[1] == NULL) {
		printf("Deben ingresarse 2 numeros");
		return 20;
	}
	
	Number num,num2;
	num.value = argv[1];
	num.size = length(num.value);
	
	num2.value = argv[2];
	num2.size = length(num2.value);
	
	suma(num,num2);

	return 0;
}





veryLong length(char *str){
	veryLong i = 0;	
	//for(;*str != '\0';str++,i++);
	for(;str[i] != '\0';i++);
	return i;
}

int charToInt(char numero) {return numero - '0';} 
char intToChar(int numero) {return numero + '0';} 
Number biggestNumber(Number num1,Number num2){return num1.size >= num2.size ? num1:num2;}
Number smallestNumber(Number num1,Number num2){return num1.size < num2.size ? num1:num2;}

int sumaChar(char n1, char n2){
	return charToInt(n1) + charToInt(n2);
}


Number __INIT__(veryLong size){
	Number RESULT;
	
	RESULT.value = (char*) malloc(sizeof(char)*(size + 1));
	
	int i = 0;
	
	for(;i <= size;i++){RESULT.value[i] = '0';}
	RESULT.value[size + 1] = '\0';	
	RESULT.size = length(RESULT.value);
	
	return RESULT;
}



Number suma(Number num1,Number num2) {
	
	Number biggest = biggestNumber(num1,num2);
	Number smallest = smallestNumber(num1,num2);
	
	Number result = __INIT__(biggest.size);

	veryLong bigIndex = biggest.size - 1;
	veryLong smallIndex = smallest.size - 1;
	veryLong resultIndex = result.size - 1;
	char carry = '1';	
	veryLong aux;

	for(;bigIndex >= 0;bigIndex--,smallIndex--,resultIndex--){
		
		if(smallIndex < 0) aux = charToInt(biggest.value[bigIndex]);
		else aux = sumaChar(biggest.value[bigIndex],smallest.value[smallIndex]);
	
					
		if(aux >= 10){
			result.value[resultIndex - 1] = carry;
			aux -= 10;
		}
		
		if(aux + charToInt(result.value[resultIndex]) == 10){
			result.value[resultIndex] = '0'; 
			result.value[resultIndex - 1] = '1';
		} else result.value[resultIndex] = intToChar(sumaChar(intToChar(aux),result.value[resultIndex]));
	}
	printResult(result);
}


void printResult(Number result){

	if(result.value[0] == '0') result.value++; 
	printf("Resultado: %s\n", result.value);
	
	
}

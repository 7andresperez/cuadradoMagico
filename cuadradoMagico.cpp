#include <iostream>

using namespace std;

int main(){
	int cuadradoMagico[3][3];
	int contador =1, opcion, k = 1;
	cout<<"Este programa genera cuadrado magico de orden 3x3."<<endl;
	//llenar la matriz de ceros
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			cuadradoMagico[a][b] = 0;
		}
	}
	cuadradoMagico[0][1] = contador;

	//imprime la matriz inicial
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			cout<<cuadradoMagico[a][b]<<" ";//espacio de division de columna
		}
		cout << endl;//salto de division de fila
	}
	cout << endl;

	//Inicio metodo siames
	int i = 0;
	int j = 1;
	while (k < 10) {//k es la cantidad de numeros que se pueden almacenar en el cuadrado magico. 9 porque el cuadrado es de 3x3
		//avance diagonal
		int filas = i - 1;//comienza en la fila -1 (donde esta el primer numero)
		int columnas = j + 1;//comienza en la columna 2 (donde esta el primer numero)
		contador = contador + 1; //siguiente numero en el cuadrado magico
		if (filas < 0 && columnas < 3) {//if columna<0 && fila<3
			opcion = 1;
		}
		else {
			if (filas < 3 && filas >= 0 && columnas>2) {
				opcion = 2;
			}
			else {
				if (filas < 0 && columnas>2) {
					opcion = 3;
				}
				else {
					if (filas >= 0 && filas < 3 && columnas >= 0 && columnas < 3) {
						opcion = 4;
					}
				}
			}
		}
		switch (opcion)
		{
			case 1:
				filas = 2;
				cuadradoMagico[filas][columnas] = contador;
				break;
			case 2:
				columnas = 0;
				cuadradoMagico[filas][columnas] = contador;
				break;
			case 3:
				filas = -1 * filas;
				columnas = columnas - 1;
				cuadradoMagico[filas][columnas] = contador;
				break;
			case 4:
				if (cuadradoMagico[filas][columnas] == 0) {
					cuadradoMagico[filas][columnas] = contador;
				}
				else {
					i++;
					cuadradoMagico[i][j] = contador;
					filas = i;
					columnas = j;
				}
				break;
		}
		i = filas;
		j = columnas;
		k++;

		//impresion paso a paso
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				cout << cuadradoMagico[a][b] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

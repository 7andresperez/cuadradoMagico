#include <iostream>

using namespace std;

int main{
	int cuadradoMagico[3][3];
	int inicial =1, opcion, k = 1;

	//llenar la matriz de ceros
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			cuadrado[a][b] = 0;
		}
	}
	cuadradoMagico[0][1] = inicial;

	//imprime la matriz inicial
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			cout<<cuadrado[a][b]<<" ";//espacio de division de columna
		}
		cout << endl;//salto de division de fila
	}
	cout << endl;
	
	//Inicio método siamés
	int i = 0;
	int j = 1;
	while (k < 10) {
		//avance diagonal
		int m = i - 1;
		int n = j + 1;
		inicial = inicial + 1; //siguiente numero en el cuadrado magico
		if (i < 0 && j < 3) {
			opcion = 1;
		}
		else {
			if (i < 3 && i >= 0 && j>2) {
				opcion = 2;
			}
			else {
				if (i < 0 && j>2) {
					opcion = 3;
				}
				else {
					if (i >= 0 && i < 3 && j >= 0 && j < 3) {
						opcion = 4;
					}
				}
			}
		}
		switch (opcion)
		{
			case 1:
				m = 2;
				cuadrado[m][n] = inicial;
				break;
			case 2:
				n = 0;
				cuadrado[m][n] = inicial;
				break;
			case 3:
				m = -1 * m;
				n = n - 1;
				cuadrado[m][n] = inicial;
				break;
			case 4:
				if (cuadrado[m][n] == 0) {
					cuadrado[m][n] = inicial;
				}
				else {
					i++;
					cuadrado[i][j] = inicial;
					m = i;
					n = j;
				}
				break;
		}
		i = m;
		j = n;
		k++;

		//impresion paso a paso
		for (int a = 0; a < 3; a++) {
			for (int b = 0; b < 3; b++) {
				cout << cuadrado[a][b] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
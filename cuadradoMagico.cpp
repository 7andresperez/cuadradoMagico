#include <iostream>

using namespace std;

int main(){
	int cuadradoMagico[3][3];
	int inicial =1, opcion, k = 1;

	//llenar la matriz de ceros
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			cuadradoMagico[a][b] = 0;
		}
	}
	cuadradoMagico[0][1] = inicial;

	//imprime la matriz inicial
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			cout<<cuadradoMagico[a][b]<<" ";//espacio de division de columna
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
		if (m < 0 && n < 3) {
			opcion = 1;
		}
		else {
			if (m < 3 && m >= 0 && n>2) {
				opcion = 2;
			}
			else {
				if (m < 0 && n>2) {
					opcion = 3;
				}
				else {
					if (m >= 0 && m < 3 && n >= 0 && n < 3) {
						opcion = 4;
					}
				}
			}
		}
		switch (opcion)
		{
			case 1:
				m = 2;
				cuadradoMagico[m][n] = inicial;
				break;
			case 2:
				n = 0;
				cuadradoMagico[m][n] = inicial;
				break;
			case 3:
				m = -1 * m;
				n = n - 1;
				cuadradoMagico[m][n] = inicial;
				break;
			case 4:
				if (cuadradoMagico[m][n] == 0) {
					cuadradoMagico[m][n] = inicial;
				}
				else {
					i++;
					cuadradoMagico[i][j] = inicial;
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
				cout << cuadradoMagico[a][b] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}

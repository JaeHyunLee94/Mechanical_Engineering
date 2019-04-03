#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
double determinant(double matrix[][3]) {
	return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
		- matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2])
		+ matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main(void) {
	double strain[3];
	double angle[3];
	double rosette_strain[3];
	printf_s("input angle and  strain in right order!!\n\n");
	
	
		printf_s("Input rosette strain1 (a): ");
		scanf_s("%lf",&rosette_strain[0]);
		printf_s("Input first angle: ");
		scanf_s("%lf", &angle[0]);
		angle[0] *= (M_PI / 180);

		printf_s("Input rosette stain2 (b): ");
		scanf_s("%lf", &rosette_strain[1]);
		printf_s("Input second angle: ");
		scanf_s("%lf", &angle[1]);
		angle[1] *= (M_PI / 180);

		printf_s("Input rosette stain3 (c): ");
		scanf_s("%lf", &rosette_strain[2]);
		printf_s("Input third angle: ");
		scanf_s("%lf", &angle[2]);
		angle[2] *= (M_PI / 180);
	
	
	double matrix[3][3];
	for (int i = 0; i < 3; i++) {
		matrix[i][0] = cos(angle[i])*cos(angle[i]);
		matrix[i][1] = sin(angle[i])*sin(angle[i]);
		matrix[i][2]= sin(angle[i])*cos(angle[i]);
	}
	
	double detA = determinant(matrix);
	double matrix1[3][3][3];
	for (int j = 0; j < 3; j++) {
		matrix1[0][j][0] = rosette_strain[j];
		matrix1[0][j][1]= sin(angle[j])*sin(angle[j]);
		matrix1[0][j][2]= sin(angle[j])*cos(angle[j]);
	}
	for (int j = 0; j < 3; j++) {
		matrix1[1][j][0] = cos(angle[j])*cos(angle[j]);
		matrix1[1][j][1] = rosette_strain[j];
		matrix1[1][j][2] = sin(angle[j])*cos(angle[j]);
	}
	for (int j = 0; j < 3; j++) {
		matrix1[2][j][0] = cos(angle[j])*cos(angle[j]);
		matrix1[2][j][1] = sin(angle[j])*sin(angle[j]);
		matrix1[2][j][2] = rosette_strain[j];
	}
	double detX[3];
	for (int i = 0; i < 3; i++) {
		detX[i] = determinant(matrix1[i]);
		strain[i] = detX[i] / detA;
	}
	printf("\n¥å(x) is: %lf\n", strain[0]);
	printf("¥å(y) is: %lf\n",strain[1]);
	printf("¥ã(xy) is: %lf\n\n", strain[2]);
	system("pause");
	
	




}

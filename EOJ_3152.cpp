#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	double f;
	scanf("%lf",&f);
	double c=5.0/9.0*(f-32.0);
	printf("fahrenheit=%.6f, celsius=%.6f\n",f,c);
	return 0;
	// double c,f;
	// scanf("%lf",&c);
	// f=9.0/5.0*c+32;
	// printf("celsius=%f, fahrenheit=%f\n",c,f);
	// return 0;
}

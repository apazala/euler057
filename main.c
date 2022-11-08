#include <stdio.h>
#include <math.h>

int qualifies(double den) {
	double ld = log10(den);
	double frac = ld - (int)ld - 1;
	return (pow(10.0, 2.0 * frac) > 0.5);
}

int main()
{
    const int n = 1000;

	double oldnum = 3;
	double oldden = 2;
	double num;
	double den;

	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		den = oldden + oldnum;
		num = den + oldden;
		while (den > 10.0)
		{
			den *= 0.1;
			num *= 0.1;
		}

		if (qualifies(den)) {
			printf("%d\n", i);
			count++;
		}

		oldden = den;
		oldnum = num;
	}

	printf("Count: %d\n", count);


    return 0;
}

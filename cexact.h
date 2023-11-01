#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int numerator;
  int denominator;
} Fraction;

Fraction *fractionCreate(int numerator, int denominator)
{
  if(denominator < 0)
  {
    numerator *= -1;
    denominator *= -1;
  }

  int i = 2;
  while(i <= abs(numerator))
  {
    if(numerator % i == 0 && denominator % i == 0)
    {
      numerator /= i;
      denominator /= i;
    }
    else
    {
      i++;
    }
  }

  Fraction *fraction;
  fraction = (Fraction *)malloc(sizeof(Fraction));
  fraction->numerator = numerator;
  fraction->denominator = denominator;

  return fraction;
}

Fraction *fractionAdd(Fraction *a, Fraction *b)
{
  int newDenominator = a->denominator * b->denominator;
  int newNumerator = a->numerator * b->denominator + b->numerator * a->denominator;
  return fractionCreate(newNumerator, newDenominator);
}

int *primeFactorize(int k, int *length)
{
  int *primeArray;
  primeArray = (int *)malloc(32 * sizeof(int));
  int *p = primeArray;

  int i = 2;
  while(i <= k)
  {
    if(k == 1)
    {
      break;
    }

    if(k % i == 0)
    {
      k /= i;
      *p = i;
      p++;
      (*length)++;
    }
    else
    {
      i++;
    }
  }

  return primeArray;
}
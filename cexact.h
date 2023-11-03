#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  EquationElementIntegerLiteral,
  EquationElementConstLiteral,
  EquationElementIntegerFractionLiteral,
  EquationElementRadicalLiteral,
  EquationElementEquation,
  EquationElementVariable,
  EquationElementOperation,
  EquationElementFunction
} EquationElement;

typedef struct
{
  EquationElement equationElementType;
} EquationElementHeader;

EquationElementHeader equationElementHeaderCreate(EquationElement element)
{
  EquationElementHeader header;
  header.equationElementType = element;
  return header;
}

typedef enum
{
  EquationElementConstPi,
  EquationElementConstE,
  EquationElementConstLog2,
} EquationElementConst;

typedef enum
{
  OperationAdd,
  OperationSubtract,
  OperationMultiply,
  OperationDivide,
  OperationPower
} BinaryOperation;

typedef struct
{
  EquationElementHeader header;
  BinaryOperation operation;
} BinaryOperationElement;

BinaryOperationElement *BinaryOperationElementCreate(BinaryOperation operation)
{
  BinaryOperationElement *newBinaryOperationElement;
  newBinaryOperationElement = (BinaryOperationElement *)malloc(sizeof(BinaryOperationElement));
  newBinaryOperationElement->header = equationElementHeaderCreate(EquationElementOperation);
  newBinaryOperationElement->operation = operation;
  return newBinaryOperationElement;
}

typedef struct
{
  EquationElementHeader header;
  int numerator;
  int denominator;
} IntegerFraction;

IntegerFraction *integerFractionCreate(int numerator, int denominator)
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

  IntegerFraction *fraction;
  fraction = (IntegerFraction *)malloc(sizeof(IntegerFraction));
  fraction->header = equationElementHeaderCreate(EquationElementIntegerFractionLiteral);
  fraction->numerator = numerator;
  fraction->denominator = denominator;

  return fraction;
}

IntegerFraction *integerFractionAdd(IntegerFraction *a, IntegerFraction *b)
{
  int newDenominator = a->denominator * b->denominator;
  int newNumerator = a->numerator * b->denominator + b->numerator * a->denominator;
  return integerFractionCreate(newNumerator, newDenominator);
}

IntegerFraction *integerFractionMultiply(IntegerFraction *a, IntegerFraction *b)
{
  int newNumerator = a->numerator * b->numerator;
  int newDenominator = a->denominator * b->denominator;
  return integerFractionCreate(newNumerator, newDenominator);
}

float integerFractionToFloat(IntegerFraction a)
{
  return (float)a.numerator / (float)a.denominator;
}


typedef struct
{
  EquationElementHeader header;
  EquationElementHeader **equationHeaders;
  int lengthOfEquation;
} Equation;

Equation *equationCreate(char *string, int stringLength)
{
  Equation *newEquation;
  newEquation = (Equation *)malloc(sizeof(Equation));
  int equationLength = 0;

  EquationElementHeader **headers;
  headers = (EquationElementHeader **)malloc(sizeof(EquationElementHeader **) * stringLength);

  int i;
  while(i < stringLength)
  {
    
  }

  newEquation->header = equationElementHeaderCreate(EquationElementEquation);
  newEquation->equationHeaders = headers;
  return newEquation;
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

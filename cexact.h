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
  EquationElementFunction,
  EquationElementEndOfEquation,
  EquationElementSkipMe
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

typedef struct
{
  EquationElementHeader header;
  int value;
} IntegerLiteral;

IntegerLiteral *integerCreate(int value)
{
  IntegerLiteral *newIntegerLiteral;
  newIntegerLiteral = (IntegerLiteral *)malloc(sizeof(IntegerLiteral));
  newIntegerLiteral->header = equationElementHeaderCreate(EquationElementIntegerLiteral);
  newIntegerLiteral->value = value;
  return newIntegerLiteral;
}

typedef enum
{
  EquationElementConstPi,
  EquationElementConstE,
  EquationElementConstLog2,
  EquationElementConstLn2
} EquationElementConst;

typedef struct 
{
  EquationElementHeader header;
  EquationElementConst constValue;
} ConstLiteral;

ConstLiteral *constLiteralCreate(EquationElementConst equationElementConst)
{
  ConstLiteral *newConstLiteral;
  newConstLiteral = (ConstLiteral *)malloc(sizeof(ConstLiteral));
  newConstLiteral->header = equationElementHeaderCreate(EquationElementConstLiteral);
  newConstLiteral->constValue = equationElementConst;
  return newConstLiteral;
}

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

BinaryOperationElement *binaryOperationElementCreate(BinaryOperation operation)
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
  EquationElementHeader *numerator;
  EquationElementHeader *denominator;
} Fraction;

Fraction *fractionCreate(EquationElementHeader *numerator, EquationElementHeader *denominator)
{
  Fraction *fraction;
  fraction = (Fraction *)malloc(sizeof(Fraction));
  fraction->header = equationElementHeaderCreate(EquationElementIntegerFractionLiteral);
  fraction->numerator = numerator;
  fraction->denominator = denominator;

  return fraction;
}

typedef struct
{
  EquationElementHeader header;
  EquationElementHeader *radicand;
  EquationElementHeader *degree;
} RadicalLiteral;

RadicalLiteral *radicalLiteralCreate(EquationElementHeader *radicand, EquationElementHeader *degree)
{
  RadicalLiteral *newRadicalLiteral;
  newRadicalLiteral = (RadicalLiteral *)malloc(sizeof(RadicalLiteral));
  newRadicalLiteral->header = equationElementHeaderCreate(EquationElementRadicalLiteral);
  newRadicalLiteral->radicand = radicand;
  newRadicalLiteral->degree = degree;
  return newRadicalLiteral;
}

typedef enum
{
  FunctionTypeNone,

  FunctionTypeSin,
  FunctionTypeCos,
  FunctionTypeTan,
  FunctionTypeCot,
  FunctionTypeCsc,
  FunctionTypeSec,
  FunctionTypeAbs,

  FunctionTypeMax,
  FunctionTypeMin
} FunctionType;

typedef struct
{
  EquationElementHeader header;
  int parameterCount;
  EquationElementHeader **parameterHeaders;
} Function;

Function *functionCreate(int parameterCount, EquationElementHeader **parameterHeaders, FunctionType functionType)
{
  Function *newFunction;
  newFunction = (Function *)malloc(sizeof(Function));
  newFunction->header = equationElementHeaderCreate(EquationElementFunction);
  newFunction->parameterCount = parameterCount;
  newFunction->parameterHeaders = parameterHeaders;
  return newFunction;
}

typedef enum
{
  VariableNameA,
  VariableNameB,
  VariableNameC,
  VariableNameN,
  VaribaleNameM,
  VariableNameT,
  VariableNameX,
  VariableNameY,
  VariableNameZ,
  VariableNameAlpha,
  VariableNameBeta,
  VariableNameTheta
} VariableName;

typedef enum
{
  VariableWithinRestrictionFalse,
  VariableWithinRestrictionTrue
} VariableWithinRestriction;

typedef struct
{
  EquationElementHeader header;
  VariableName name;
  VariableWithinRestriction (*restrictionFunction)(EquationElementHeader);
} Variable;

Variable *variableCreate(VariableWithinRestriction (*restrictionFunction)(EquationElementHeader), VariableName variableName)
{
  Variable *newVariable;
  newVariable = (Variable *)malloc(sizeof(Variable));
  newVariable->header = equationElementHeaderCreate(EquationElementVariable);
  newVariable->name = variableName;
  newVariable->restrictionFunction = restrictionFunction;
  return newVariable;
}

typedef struct
{
  EquationElementHeader header;
  EquationElementHeader **equationHeaders;
  int lengthOfEquation;
} Equation;

Equation *equationCreate(int headerCount)
{
  Equation *newEquation;
  newEquation = (Equation *)malloc(sizeof(Equation));
  EquationElementHeader **headers;
  headers = (EquationElementHeader **)malloc(sizeof(EquationElementHeader **) * (headerCount + 1));
  newEquation->header = equationElementHeaderCreate(EquationElementEquation);
  newEquation->equationHeaders = headers;
  return newEquation;
}

void equationDestroy(Equation *equation)
{
  int i;
  for(i = 0; i < equation->lengthOfEquation; i++)
  {
    free((equation->equationHeaders)[i]);
  }
  free(equation->equationHeaders);
  free(equation);
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

Fraction *integerFractionCreate(int numerator, int denominator)
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

  EquationElementHeader *numeratorHeader;
  numeratorHeader = (EquationElementHeader *)integerCreate(numerator);
  EquationElementHeader *denominatorHeader;
  denominatorHeader = (EquationElementHeader *)integerCreate(denominator);

  return fractionCreate(numeratorHeader, denominatorHeader);
}
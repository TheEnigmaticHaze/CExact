#include <stdlib.h>

typedef enum
{
  EquationElementIntegerLiteral,
  EquationElementConstLiteral,
  EquationElementFraction,
  EquationElementRadical,
  EquationElementVariable,
  EquationElementEquation,
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
  fraction->header = equationElementHeaderCreate(EquationElementFraction);
  fraction->numerator = numerator;
  fraction->denominator = denominator;

  return fraction;
}

void fractionDestroy(Fraction *fraction)
{
  free(fraction->numerator);
  free(fraction->denominator);
  free(fraction);
}

typedef struct
{
  EquationElementHeader header;
  EquationElementHeader *radicand;
  EquationElementHeader *degree;
} Radical;

Radical *radicalLiteralCreate(EquationElementHeader *radicand, EquationElementHeader *degree)
{
  Radical *newRadicalLiteral;
  newRadicalLiteral = (Radical *)malloc(sizeof(Radical));
  newRadicalLiteral->header = equationElementHeaderCreate(EquationElementRadical);
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

const unsigned char KEEP_PARAMETERS = 0;
const unsigned char FREE_PARAMETERS = 1;

EquationElementHeader *integerLiteralAddIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralAddConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralAddFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralAddRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralAddEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralAddVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *constLiteralAddIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralAddConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralAddFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *constLiteralAddRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *constLiteralAddEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *constLiteralAddVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *fractionAddIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionAddConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionAddFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *fractionAddRadical(Fraction *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *fractionAddEquation(Fraction *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *fractionAddVariable(Fraction *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *radicalAddIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalAddConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalAddFraction(Radical *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *radicalAddRadical(Radical *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *radicalAddEquation(Radical *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *radicalAddVariable(Radical *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *equationAddIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationAddConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationAddFraction(Equation *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *equationAddRadical(Equation *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *equationAddEquation(Equation *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *equationAddVariable(Equation *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *variableAddIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableAddConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableAddFraction(Variable *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *variableAddRadical(Variable *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *variableAddEquation(Variable *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *variableAddVariable(Variable *a, Variable *b, unsigned char freeParameters);
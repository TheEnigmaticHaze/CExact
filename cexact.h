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

EquationElementHeader *variableAddIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableAddConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableAddFraction(Variable *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *variableAddRadical(Variable *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *variableAddEquation(Variable *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *variableAddVariable(Variable *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *equationAddIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationAddConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationAddFraction(Equation *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *equationAddRadical(Equation *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *equationAddEquation(Equation *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *equationAddVariable(Equation *a, Variable *b, unsigned char freeParameters);



EquationElementHeader *integerLiteralMultiplyIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralMultiplyConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralMultiplyFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralMultiplyRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralMultiplyEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralMultiplyVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *constLiteralMultiplyIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralMultiplyConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralMultiplyFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *constLiteralMultiplyRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *constLiteralMultiplyEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *constLiteralMultiplyVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *fractionMultiplyIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionMultiplyConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionMultiplyFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *fractionMultiplyRadical(Fraction *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *fractionMultiplyEquation(Fraction *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *fractionMultiplyVariable(Fraction *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *radicalMultiplyIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalMultiplyConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalMultiplyFraction(Radical *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *radicalMultiplyRadical(Radical *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *radicalMultiplyEquation(Radical *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *radicalMultiplyVariable(Radical *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *variableMultiplyIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableMultiplyConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableMultiplyFraction(Variable *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *variableMultiplyRadical(Variable *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *variableMultiplyEquation(Variable *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *variableMultiplyVariable(Variable *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *equationMultiplyIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationMultiplyConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationMultiplyFraction(Equation *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *equationMultiplyRadical(Equation *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *equationMultiplyEquation(Equation *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *equationMultiplyVariable(Equation *a, Variable *b, unsigned char freeParameters);



EquationElementHeader *integerLiteralSubtractIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralSubtractConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralSubtractFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralSubtractRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralSubtractEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralSubtractVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *constLiteralSubtractIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralSubtractConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralSubtractFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *constLiteralSubtractRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *constLiteralSubtractEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *constLiteralSubtractVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *fractionSubtractIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionSubtractConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionSubtractFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *fractionSubtractRadical(Fraction *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *fractionSubtractEquation(Fraction *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *fractionSubtractVariable(Fraction *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *radicalSubtractIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalSubtractConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalSubtractFraction(Radical *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *radicalSubtractRadical(Radical *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *radicalSubtractEquation(Radical *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *radicalSubtractVariable(Radical *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *variableSubtractIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableSubtractConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableSubtractFraction(Variable *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *variableSubtractRadical(Variable *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *variableSubtractEquation(Variable *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *variableSubtractVariable(Variable *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *equationSubtractIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationSubtractConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationSubtractFraction(Equation *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *equationSubtractRadical(Equation *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *equationSubtractEquation(Equation *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *equationSubtractVariable(Equation *a, Variable *b, unsigned char freeParameters);



EquationElementHeader *integerLiteralDivideIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralDivideConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralDivideFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralDivideRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralDivideEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralDivideVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *constLiteralDivideIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralDivideConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralDivideFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *constLiteralDivideRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *constLiteralDivideEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *constLiteralDivideVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *fractionDivideIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionDivideConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionDivideFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *fractionDivideRadical(Fraction *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *fractionDivideEquation(Fraction *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *fractionDivideVariable(Fraction *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *radicalDivideIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalDivideConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalDivideFraction(Radical *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *radicalDivideRadical(Radical *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *radicalDivideEquation(Radical *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *radicalDivideVariable(Radical *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *variableDivideIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableDivideConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *variableDivideFraction(Variable *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *variableDivideRadical(Variable *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *variableDivideEquation(Variable *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *variableDivideVariable(Variable *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *equationDivideIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationDivideConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationDivideFraction(Equation *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *equationDivideRadical(Equation *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *equationDivideEquation(Equation *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *equationDivideVariable(Equation *a, Variable *b, unsigned char freeParameters);



EquationElementHeader *integerLiteralPowerIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralPowerConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralPowerFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralPowerRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralPowerEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *integerLiteralPowerVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *constLiteralPowerIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralPowerConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *constLiteralPowerFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *constLiteralPowerRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *constLiteralPowerEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *constLiteralPowerVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *fractionPowerIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionPowerConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *fractionPowerFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *fractionPowerRadical(Fraction *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *fractionPowerEquation(Fraction *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *fractionPowerVariable(Fraction *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *radicalPowerIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalPowerConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *radicalPowerFraction(Radical *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *radicalPowerRadical(Radical *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *radicalPowerEquation(Radical *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *radicalPowerVariable(Radical *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *variablePowerIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *variablePowerConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *variablePowerFraction(Variable *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *variablePowerRadical(Variable *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *variablePowerEquation(Variable *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *variablePowerVariable(Variable *a, Variable *b, unsigned char freeParameters);

EquationElementHeader *equationPowerIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationPowerConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
EquationElementHeader *equationPowerFraction(Equation *a, Fraction *b, unsigned char freeParameters);
EquationElementHeader *equationPowerRadical(Equation *a, Radical *b, unsigned char freeParameters);
EquationElementHeader *equationPowerEquation(Equation *a, Equation *b, unsigned char freeParameters);
EquationElementHeader *equationPowerVariable(Equation *a, Variable *b, unsigned char freeParameters);



EquationElementHeader *integerSimplify(IntegerLiteral *a);
EquationElementHeader *constLiteralSimplify(IntegerLiteral *a);
EquationElementHeader *fractionSimplify(IntegerLiteral *a);
EquationElementHeader *radicalSimplify(IntegerLiteral *a);
EquationElementHeader *variableSimplify(IntegerLiteral *a);
EquationElementHeader *equationSimplify(IntegerLiteral *a);


int *primeFactorize(int k, int *length){
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
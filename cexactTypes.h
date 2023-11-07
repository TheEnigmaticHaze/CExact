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

IntegerLiteral *integerLiteralCreate(int value)
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
} FunctionType;

typedef struct
{
  EquationElementHeader header;
  EquationElementHeader *parameterHeader;
} Function;

Function *functionCreate(EquationElementHeader *parameterHeader, FunctionType functionType)
{
  Function *newFunction;
  newFunction = (Function *)malloc(sizeof(Function));
  newFunction->header = equationElementHeaderCreate(EquationElementFunction);
  newFunction->parameterHeader = parameterHeader;
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
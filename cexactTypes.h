#include <stdlib.h>

typedef enum
{
  EquationElementIntegerLiteral,
  EquationElementConstLiteral,
  EquationElementFraction,
  EquationElementRadical,
  EquationElementVariable,
  EquationElementEquation,
  EquationElementBinaryOperation,
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

extern EquationElementHeader *equationElementHeaderCopy(EquationElementHeader *toCopy);

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

void integerLiteralDestroy(IntegerLiteral *toDestroy)
{
  free(toDestroy);
}

IntegerLiteral *integerLiteralCopy(IntegerLiteral *toCopy)
{
  return integerLiteralCreate(toCopy->value);
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

void constLiteralDestroy(ConstLiteral *toDestroy)
{
  free(toDestroy);
}

ConstLiteral *constLiteralCopy(ConstLiteral *toCopy)
{
  return constLiteralCreate(toCopy->constValue);
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
  newBinaryOperationElement->header = equationElementHeaderCreate(EquationElementBinaryOperation);
  newBinaryOperationElement->operation = operation;
  return newBinaryOperationElement;
}

void binaryOperationElementDestroy(BinaryOperationElement *toDestroy)
{
  free(toDestroy);
}

BinaryOperationElement *binaryOperationElementCopy(BinaryOperationElement *toCopy)
{
  return binaryOperationElementCreate(toCopy->operation);
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

Fraction *fractionCopy(Fraction *toCopy)
{
  EquationElementHeader *newNumerator = equationElementHeaderCopy(toCopy->numerator);
  EquationElementHeader *newDenominator = equationElementHeaderCopy(toCopy->denominator);
  return fractionCreate(newNumerator, newDenominator);
}


typedef struct
{
  EquationElementHeader header;
  EquationElementHeader *radicand;
  EquationElementHeader *degree;
} Radical;

Radical *radicalCreate(EquationElementHeader *radicand, EquationElementHeader *degree)
{
  Radical *newRadicalLiteral;
  newRadicalLiteral = (Radical *)malloc(sizeof(Radical));
  newRadicalLiteral->header = equationElementHeaderCreate(EquationElementRadical);
  newRadicalLiteral->radicand = radicand;
  newRadicalLiteral->degree = degree;
  return newRadicalLiteral;
}

void radicalFree(Radical *toDestroy)
{
  free(toDestroy->degree);
  free(toDestroy->radicand);
  free(toDestroy);
}

Radical *radicalCopy(Radical *toCopy)
{
  EquationElementHeader *newRadicand = equationElementHeaderCopy(toCopy->radicand);
  EquationElementHeader *newDegree = equationElementHeaderCopy(toCopy->degree);
  return radicalCreate(newRadicand, newDegree);
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
  FunctionType functionType;
} Function;

Function *functionCreate(EquationElementHeader *parameterHeader, FunctionType functionType)
{
  Function *newFunction;
  newFunction = (Function *)malloc(sizeof(Function));
  newFunction->header = equationElementHeaderCreate(EquationElementFunction);
  newFunction->parameterHeader = parameterHeader;
  newFunction->functionType = functionType;
  return newFunction;
}

void functionDestroy(Function *toDestroy)
{
  free(toDestroy->parameterHeader);
  free(toDestroy);
}

Function *functionCopy(Function *toCopy)
{
  EquationElementHeader *newParameter = equationElementHeaderCopy(toCopy->parameterHeader);
  return functionCreate(newParameter, toCopy->functionType);
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
} Variable;

Variable *variableCreate(VariableName variableName)
{
  Variable *newVariable;
  newVariable = (Variable *)malloc(sizeof(Variable));
  newVariable->header = equationElementHeaderCreate(EquationElementVariable);
  newVariable->name = variableName;
  return newVariable;
}

void variableDestroy(Variable *toDestroy)
{
  free(toDestroy);
}

Variable *variableCopy(Variable *toCopy)
{
  return variableCreate(toCopy->name);
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
  EquationElementHeader endOfEquation = equationElementHeaderCreate(EquationElementEndOfEquation);
  (newEquation->equationHeaders)[headerCount] = &endOfEquation;
  return newEquation;
}

void equationDestroy(Equation *toDestroy)
{
  int i;
  for(i = 0; i < toDestroy->lengthOfEquation; i++)
  {
    free((toDestroy->equationHeaders)[i]);
  }
  free(toDestroy->equationHeaders);
  free(toDestroy);
}

Equation *equationCopy(Equation *toCopy)
{
  Equation *newEquation = equationCreate(toCopy->lengthOfEquation);
  int headerIndex;
  for(headerIndex = 0; headerIndex < newEquation->lengthOfEquation; headerIndex++)
  {
    (newEquation->equationHeaders)[headerIndex] = equationElementHeaderCopy((toCopy->equationHeaders)[headerIndex]);
  }
  return newEquation;
}


EquationElementHeader * equationElementHeaderCopy(EquationElementHeader *toCopy)
{
  switch (toCopy->equationElementType)
  {
  case EquationElementIntegerLiteral:
    return (EquationElementHeader *)integerLiteralCopy((IntegerLiteral *)toCopy);
  
  case EquationElementConstLiteral:
    return (EquationElementHeader *)constLiteralCopy((ConstLiteral *)toCopy);
  
  case EquationElementFraction:
    return (EquationElementHeader *)fractionCopy((Fraction *)toCopy);

  case EquationElementRadical:
    return (EquationElementHeader *)radicalCopy((Radical *)toCopy);

  case EquationElementVariable:
    return (EquationElementHeader *)variableCopy((Variable *)toCopy);

  case EquationElementEquation:
    return (EquationElementHeader *)equationCopy((Equation *)toCopy);
  
  case EquationElementBinaryOperation:
    return (EquationElementHeader *)binaryOperationElementCopy((BinaryOperationElement *)toCopy);

  case EquationElementFunction:
    return (EquationElementHeader *)functionCopy((Function *)toCopy);

  default:
    EquationElementHeader newHeader =  equationElementHeaderCreate(toCopy->equationElementType);
    return &newHeader;
  }
}


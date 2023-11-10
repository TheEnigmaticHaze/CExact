#include "..\cexactTypes.h"

extern EquationElementHeader *equationElementHeaderAddEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
extern EquationElementHeader *equationElementHeaderMultiplyEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
extern EquationElementHeader *equationElementHeaderSubtractEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
extern EquationElementHeader *equationElementHeaderDivideEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
extern EquationElementHeader *equationElementHeaderPowerEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);



EquationElementHeader *integerLiteralAddIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b)
{
  return (EquationElementHeader *)integerLiteralCreate(a->value + b->value);
}
EquationElementHeader *integerLiteralAddConstLiteral(IntegerLiteral *a, ConstLiteral *b)
{
  Equation *newEquation = equationCreate(3);
  (newEquation->equationHeaders)[0] = (EquationElementHeader *)integerLiteralCopy(a);
  (newEquation->equationHeaders)[1] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[2] = (EquationElementHeader *)constLiteralCopy(b);
  return (EquationElementHeader *)newEquation;
}
EquationElementHeader *integerLiteralAddFraction(IntegerLiteral *a, Fraction *b)
{
  EquationElementHeader *newNumerator = equationElementHeaderMultiplyEquationElementHeader((EquationElementHeader *)a, b->denominator);
  newNumerator = equationElementHeaderAddEquationElementHeader(newNumerator, b->numerator);
  return (EquationElementHeader *)fractionCreate(newNumerator, equationElementHeaderCopy(b->denominator));
}
EquationElementHeader *integerLiteralAddRadical(IntegerLiteral *a, Radical *b)
{
  Equation *newEquation = equationCreate(3);
  (newEquation->equationHeaders)[0] = (EquationElementHeader *)integerLiteralCopy(a);
  (newEquation->equationHeaders)[1] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[2] = (EquationElementHeader *)radicalCopy(b);
  return (EquationElementHeader *)newEquation;
}
EquationElementHeader *integerLiteralAddVariable(IntegerLiteral *a, Variable *b)
{
  Equation *newEquation = equationCreate(3);
  (newEquation->equationHeaders)[0] = (EquationElementHeader *)integerLiteralCopy(a);
  (newEquation->equationHeaders)[1] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[2] = (EquationElementHeader *)variableCopy(b);
  return (EquationElementHeader *)newEquation;
}
EquationElementHeader *integerLiteralAddEquation(IntegerLiteral *a, Equation *b)
{
  Equation *newEquation = equationCopy(b);
  EquationElementHeader **currentHeader = newEquation->equationHeaders;
  while(typeOfHeader(*currentHeader) != EquationElementEndOfEquation)
  {
    if((*currentHeader)->equationElementType == EquationElementIntegerLiteral && isTerm(currentHeader))
    {
      int currentHeaderValue = ((IntegerLiteral *)(*currentHeader))->value; 
      IntegerLiteral *newInteger = integerLiteralCreate(currentHeaderValue + a->value);
      *currentHeader = (EquationElementHeader *)newInteger;
      return (EquationElementHeader *)newEquation;
    }
    currentHeader++;
  }
  newEquation->equationHeaders = (EquationElementHeader **)realloc(newEquation->equationHeaders, newEquation->lengthOfEquation + 3);
  (newEquation->equationHeaders)[newEquation->lengthOfEquation] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[newEquation->lengthOfEquation + 1] = (EquationElementHeader *)integerLiteralCopy(a);
  EquationElementHeader endOfEquation = equationElementHeaderCreate(EquationElementEndOfEquation);
  (newEquation->equationHeaders)[newEquation->lengthOfEquation + 2] = &endOfEquation;
  return (EquationElementHeader *)newEquation;
}

EquationElementHeader *constLiteralAddIntegerLiteral(ConstLiteral *a, IntegerLiteral *b)
{
  return integerLiteralAddConstLiteral(b, a);
}
EquationElementHeader *constLiteralAddConstLiteral(ConstLiteral *a, ConstLiteral *b)
{
  Equation *newEquation = equationCreate(3);
  (newEquation->equationHeaders)[0] = (EquationElementHeader *)constLiteralCopy(a);
  (newEquation->equationHeaders)[1] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[2] = (EquationElementHeader *)constLiteralCopy(b);
  return (EquationElementHeader *)newEquation;
}
EquationElementHeader *constLiteralAddFraction(ConstLiteral *a, Fraction *b)
{
  EquationElementHeader *newNumerator = equationElementHeaderMultiplyEquationElementHeader((EquationElementHeader *)a, b->denominator);
  newNumerator = equationElementHeaderAddEquationElementHeader(newNumerator, b->numerator);
  return (EquationElementHeader *)fractionCreate(newNumerator, equationElementHeaderCopy(b->denominator));
}
EquationElementHeader *constLiteralAddRadical(ConstLiteral *a, Radical *b)
{
  Equation *newEquation = equationCreate(3);
  (newEquation->equationHeaders)[0] = (EquationElementHeader *)constLiteralCopy(a);
  (newEquation->equationHeaders)[1] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[2] = (EquationElementHeader *)radicalCopy(b);
  return (EquationElementHeader *)newEquation;
}
EquationElementHeader *constLiteralAddVariable(ConstLiteral *a, Variable *b)
{
  Equation *newEquation = equationCreate(3);
  (newEquation->equationHeaders)[0] = (EquationElementHeader *)constLiteralCopy(a);
  (newEquation->equationHeaders)[1] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[2] = (EquationElementHeader *)variableCopy(b);
  return (EquationElementHeader *)newEquation;
}
EquationElementHeader *constLiteralAddEquation(ConstLiteral *a, Equation *b)
{
  Equation *newEquation = equationCopy(b);
  newEquation->equationHeaders = (EquationElementHeader **)realloc(newEquation->equationHeaders, newEquation->lengthOfEquation + 3);
  (newEquation->equationHeaders)[newEquation->lengthOfEquation] = (EquationElementHeader *)binaryOperationElementCreate(OperationAdd);
  (newEquation->equationHeaders)[newEquation->lengthOfEquation + 1] = (EquationElementHeader *)constLiteralCopy(a);
  EquationElementHeader endOfEquation = equationElementHeaderCreate(EquationElementEndOfEquation);
  (newEquation->equationHeaders)[newEquation->lengthOfEquation + 2] = &endOfEquation;
  return (EquationElementHeader *)newEquation;
}

EquationElementHeader *fractionAddIntegerLiteral(Fraction *a, IntegerLiteral *b)
{
  return integerLiteralAddFraction(b, a);
}
EquationElementHeader *fractionAddConstLiteral(Fraction *a, ConstLiteral *b)
{
  return constLiteralAddFraction(b, a);
}
EquationElementHeader *fractionAddFraction(Fraction *a, Fraction *b)
{
  EquationElementHeader *newNumeratorA = equationElementHeaderMultiplyEquationElementHeader(a->numerator, b->denominator);
  EquationElementHeader *newNumeratorB = equationElementHeaderMultiplyEquationElementHeader(b->numerator, a->denominator);
  EquationElementHeader *newNumerator = equationElementHeaderAddEquationElementHeader(newNumeratorA, newNumeratorB);
  EquationElementHeader *newDenominator = equationElementHeaderMultiplyEquationElementHeader(a->denominator, b->denominator);
  return fractionCreate(newNumerator, newDenominator);
}
EquationElementHeader *fractionAddRadical(Fraction *a, Radical *b)
{
  EquationElementHeader *newNumerator = equationElementHeaderMultiplyEquationElementHeader((EquationElementHeader *)b, a->denominator);
  newNumerator = equationElementHeaderAddEquationElementHeader(newNumerator, a->numerator);
  return (EquationElementHeader *)fractionCreate(newNumerator, equationElementHeaderCopy(a->denominator));
}
EquationElementHeader *fractionAddVariable(Fraction *a, Variable *b)
{
  EquationElementHeader *newNumerator = equationElementHeaderMultiplyEquationElementHeader((EquationElementHeader *)b, a->denominator);
  newNumerator = equationElementHeaderAddEquationElementHeader(newNumerator, a->numerator);
  return (EquationElementHeader *)fractionCreate(newNumerator, equationElementHeaderCopy(a->denominator));
}
EquationElementHeader *fractionAddEquation(Fraction *a, Equation *b)
{
  EquationElementHeader *newNumerator = equationElementHeaderMultiplyEquationElementHeader((EquationElementHeader *)b, a->denominator);
  newNumerator = equationElementHeaderAddEquationElementHeader(newNumerator, a->numerator);
  return (EquationElementHeader *)fractionCreate(newNumerator, equationElementHeaderCopy(a->denominator));
}

EquationElementHeader *radicalAddIntegerLiteral(Radical *a, IntegerLiteral *b);
EquationElementHeader *radicalAddConstLiteral(Radical *a, ConstLiteral *b);
EquationElementHeader *radicalAddFraction(Radical *a, Fraction *b);
EquationElementHeader *radicalAddRadical(Radical *a, Radical *b);
EquationElementHeader *radicalAddVariable(Radical *a, Variable *b);
EquationElementHeader *radicalAddEquation(Radical *a, Equation *b);

EquationElementHeader *variableAddIntegerLiteral(Variable *a, IntegerLiteral *b);
EquationElementHeader *variableAddConstLiteral(Variable *a, ConstLiteral *b);
EquationElementHeader *variableAddFraction(Variable *a, Fraction *b);
EquationElementHeader *variableAddRadical(Variable *a, Radical *b);
EquationElementHeader *variableAddVariable(Variable *a, Variable *b);
EquationElementHeader *variableAddEquation(Variable *a, Equation *b);

EquationElementHeader *equationAddIntegerLiteral(Equation *a, IntegerLiteral *b);
EquationElementHeader *equationAddConstLiteral(Equation *a, ConstLiteral *b);
EquationElementHeader *equationAddFraction(Equation *a, Fraction *b);
EquationElementHeader *equationAddRadical(Equation *a, Radical *b);
EquationElementHeader *equationAddVariable(Equation *a, Variable *b);
EquationElementHeader *equationAddEquation(Equation *a, Equation *b);



EquationElementHeader *integerLiteralMultiplyIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
EquationElementHeader *integerLiteralMultiplyConstLiteral(IntegerLiteral *a, ConstLiteral *b);
EquationElementHeader *integerLiteralMultiplyFraction(IntegerLiteral *a, Fraction *b);
EquationElementHeader *integerLiteralMultiplyRadical(IntegerLiteral *a, Radical *b);
EquationElementHeader *integerLiteralMultiplyVariable(IntegerLiteral *a, Variable *b);
EquationElementHeader *integerLiteralMultiplyEquation(IntegerLiteral *a, Equation *b);

EquationElementHeader *constLiteralMultiplyIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
EquationElementHeader *constLiteralMultiplyConstLiteral(ConstLiteral *a, ConstLiteral *b);
EquationElementHeader *constLiteralMultiplyFraction(ConstLiteral *a, Fraction *b);
EquationElementHeader *constLiteralMultiplyRadical(ConstLiteral *a, Radical *b);
EquationElementHeader *constLiteralMultiplyVariable(ConstLiteral *a, Variable *b);
EquationElementHeader *constLiteralMultiplyEquation(ConstLiteral *a, Equation *b);

EquationElementHeader *fractionMultiplyIntegerLiteral(Fraction *a, IntegerLiteral *b);
EquationElementHeader *fractionMultiplyConstLiteral(Fraction *a, ConstLiteral *b);
EquationElementHeader *fractionMultiplyFraction(Fraction *a, Fraction *b);
EquationElementHeader *fractionMultiplyRadical(Fraction *a, Radical *b);
EquationElementHeader *fractionMultiplyVariable(Fraction *a, Variable *b);
EquationElementHeader *fractionMultiplyEquation(Fraction *a, Equation *b);

EquationElementHeader *radicalMultiplyIntegerLiteral(Radical *a, IntegerLiteral *b);
EquationElementHeader *radicalMultiplyConstLiteral(Radical *a, ConstLiteral *b);
EquationElementHeader *radicalMultiplyFraction(Radical *a, Fraction *b);
EquationElementHeader *radicalMultiplyRadical(Radical *a, Radical *b);
EquationElementHeader *radicalMultiplyVariable(Radical *a, Variable *b);
EquationElementHeader *radicalMultiplyEquation(Radical *a, Equation *b);

EquationElementHeader *variableMultiplyIntegerLiteral(Variable *a, IntegerLiteral *b);
EquationElementHeader *variableMultiplyConstLiteral(Variable *a, ConstLiteral *b);
EquationElementHeader *variableMultiplyFraction(Variable *a, Fraction *b);
EquationElementHeader *variableMultiplyRadical(Variable *a, Radical *b);
EquationElementHeader *variableMultiplyVariable(Variable *a, Variable *b);
EquationElementHeader *variableMultiplyEquation(Variable *a, Equation *b);

EquationElementHeader *equationMultiplyIntegerLiteral(Equation *a, IntegerLiteral *b);
EquationElementHeader *equationMultiplyConstLiteral(Equation *a, ConstLiteral *b);
EquationElementHeader *equationMultiplyFraction(Equation *a, Fraction *b);
EquationElementHeader *equationMultiplyRadical(Equation *a, Radical *b);
EquationElementHeader *equationMultiplyVariable(Equation *a, Variable *b);
EquationElementHeader *equationMultiplyEquation(Equation *a, Equation *b);



EquationElementHeader *integerLiteralSubtractIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
EquationElementHeader *integerLiteralSubtractConstLiteral(IntegerLiteral *a, ConstLiteral *b);
EquationElementHeader *integerLiteralSubtractFraction(IntegerLiteral *a, Fraction *b);
EquationElementHeader *integerLiteralSubtractRadical(IntegerLiteral *a, Radical *b);
EquationElementHeader *integerLiteralSubtractVariable(IntegerLiteral *a, Variable *b);
EquationElementHeader *integerLiteralSubtractEquation(IntegerLiteral *a, Equation *b);

EquationElementHeader *constLiteralSubtractIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
EquationElementHeader *constLiteralSubtractConstLiteral(ConstLiteral *a, ConstLiteral *b);
EquationElementHeader *constLiteralSubtractFraction(ConstLiteral *a, Fraction *b);
EquationElementHeader *constLiteralSubtractRadical(ConstLiteral *a, Radical *b);
EquationElementHeader *constLiteralSubtractVariable(ConstLiteral *a, Variable *b);
EquationElementHeader *constLiteralSubtractEquation(ConstLiteral *a, Equation *b);

EquationElementHeader *fractionSubtractIntegerLiteral(Fraction *a, IntegerLiteral *b);
EquationElementHeader *fractionSubtractConstLiteral(Fraction *a, ConstLiteral *b);
EquationElementHeader *fractionSubtractFraction(Fraction *a, Fraction *b);
EquationElementHeader *fractionSubtractRadical(Fraction *a, Radical *b);
EquationElementHeader *fractionSubtractVariable(Fraction *a, Variable *b);
EquationElementHeader *fractionSubtractEquation(Fraction *a, Equation *b);

EquationElementHeader *radicalSubtractIntegerLiteral(Radical *a, IntegerLiteral *b);
EquationElementHeader *radicalSubtractConstLiteral(Radical *a, ConstLiteral *b);
EquationElementHeader *radicalSubtractFraction(Radical *a, Fraction *b);
EquationElementHeader *radicalSubtractRadical(Radical *a, Radical *b);
EquationElementHeader *radicalSubtractVariable(Radical *a, Variable *b);
EquationElementHeader *radicalSubtractEquation(Radical *a, Equation *b);

EquationElementHeader *variableSubtractIntegerLiteral(Variable *a, IntegerLiteral *b);
EquationElementHeader *variableSubtractConstLiteral(Variable *a, ConstLiteral *b);
EquationElementHeader *variableSubtractFraction(Variable *a, Fraction *b);
EquationElementHeader *variableSubtractRadical(Variable *a, Radical *b);
EquationElementHeader *variableSubtractVariable(Variable *a, Variable *b);
EquationElementHeader *variableSubtractEquation(Variable *a, Equation *b);

EquationElementHeader *equationSubtractIntegerLiteral(Equation *a, IntegerLiteral *b);
EquationElementHeader *equationSubtractConstLiteral(Equation *a, ConstLiteral *b);
EquationElementHeader *equationSubtractFraction(Equation *a, Fraction *b);
EquationElementHeader *equationSubtractRadical(Equation *a, Radical *b);
EquationElementHeader *equationSubtractVariable(Equation *a, Variable *b);
EquationElementHeader *equationSubtractEquation(Equation *a, Equation *b);



EquationElementHeader *integerLiteralDivideIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
EquationElementHeader *integerLiteralDivideConstLiteral(IntegerLiteral *a, ConstLiteral *b);
EquationElementHeader *integerLiteralDivideFraction(IntegerLiteral *a, Fraction *b);
EquationElementHeader *integerLiteralDivideRadical(IntegerLiteral *a, Radical *b);
EquationElementHeader *integerLiteralDivideVariable(IntegerLiteral *a, Variable *b);
EquationElementHeader *integerLiteralDivideEquation(IntegerLiteral *a, Equation *b);

EquationElementHeader *constLiteralDivideIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
EquationElementHeader *constLiteralDivideConstLiteral(ConstLiteral *a, ConstLiteral *b);
EquationElementHeader *constLiteralDivideFraction(ConstLiteral *a, Fraction *b);
EquationElementHeader *constLiteralDivideRadical(ConstLiteral *a, Radical *b);
EquationElementHeader *constLiteralDivideVariable(ConstLiteral *a, Variable *b);
EquationElementHeader *constLiteralDivideEquation(ConstLiteral *a, Equation *b);

EquationElementHeader *fractionDivideIntegerLiteral(Fraction *a, IntegerLiteral *b);
EquationElementHeader *fractionDivideConstLiteral(Fraction *a, ConstLiteral *b);
EquationElementHeader *fractionDivideFraction(Fraction *a, Fraction *b);
EquationElementHeader *fractionDivideRadical(Fraction *a, Radical *b);
EquationElementHeader *fractionDivideVariable(Fraction *a, Variable *b);
EquationElementHeader *fractionDivideEquation(Fraction *a, Equation *b);

EquationElementHeader *radicalDivideIntegerLiteral(Radical *a, IntegerLiteral *b);
EquationElementHeader *radicalDivideConstLiteral(Radical *a, ConstLiteral *b);
EquationElementHeader *radicalDivideFraction(Radical *a, Fraction *b);
EquationElementHeader *radicalDivideRadical(Radical *a, Radical *b);
EquationElementHeader *radicalDivideVariable(Radical *a, Variable *b);
EquationElementHeader *radicalDivideEquation(Radical *a, Equation *b);

EquationElementHeader *variableDivideIntegerLiteral(Variable *a, IntegerLiteral *b);
EquationElementHeader *variableDivideConstLiteral(Variable *a, ConstLiteral *b);
EquationElementHeader *variableDivideFraction(Variable *a, Fraction *b);
EquationElementHeader *variableDivideRadical(Variable *a, Radical *b);
EquationElementHeader *variableDivideVariable(Variable *a, Variable *b);
EquationElementHeader *variableDivideEquation(Variable *a, Equation *b);

EquationElementHeader *equationDivideIntegerLiteral(Equation *a, IntegerLiteral *b);
EquationElementHeader *equationDivideConstLiteral(Equation *a, ConstLiteral *b);
EquationElementHeader *equationDivideFraction(Equation *a, Fraction *b);
EquationElementHeader *equationDivideRadical(Equation *a, Radical *b);
EquationElementHeader *equationDivideVariable(Equation *a, Variable *b);
EquationElementHeader *equationDivideEquation(Equation *a, Equation *b);



EquationElementHeader *integerLiteralPowerIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
EquationElementHeader *integerLiteralPowerConstLiteral(IntegerLiteral *a, ConstLiteral *b);
EquationElementHeader *integerLiteralPowerFraction(IntegerLiteral *a, Fraction *b);
EquationElementHeader *integerLiteralPowerRadical(IntegerLiteral *a, Radical *b);
EquationElementHeader *integerLiteralPowerVariable(IntegerLiteral *a, Variable *b);
EquationElementHeader *integerLiteralPowerEquation(IntegerLiteral *a, Equation *b);

EquationElementHeader *constLiteralPowerIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
EquationElementHeader *constLiteralPowerConstLiteral(ConstLiteral *a, ConstLiteral *b);
EquationElementHeader *constLiteralPowerFraction(ConstLiteral *a, Fraction *b);
EquationElementHeader *constLiteralPowerRadical(ConstLiteral *a, Radical *b);
EquationElementHeader *constLiteralPowerVariable(ConstLiteral *a, Variable *b);
EquationElementHeader *constLiteralPowerEquation(ConstLiteral *a, Equation *b);

EquationElementHeader *fractionPowerIntegerLiteral(Fraction *a, IntegerLiteral *b);
EquationElementHeader *fractionPowerConstLiteral(Fraction *a, ConstLiteral *b);
EquationElementHeader *fractionPowerFraction(Fraction *a, Fraction *b);
EquationElementHeader *fractionPowerRadical(Fraction *a, Radical *b);
EquationElementHeader *fractionPowerVariable(Fraction *a, Variable *b);
EquationElementHeader *fractionPowerEquation(Fraction *a, Equation *b);

EquationElementHeader *radicalPowerIntegerLiteral(Radical *a, IntegerLiteral *b);
EquationElementHeader *radicalPowerConstLiteral(Radical *a, ConstLiteral *b);
EquationElementHeader *radicalPowerFraction(Radical *a, Fraction *b);
EquationElementHeader *radicalPowerRadical(Radical *a, Radical *b);
EquationElementHeader *radicalPowerVariable(Radical *a, Variable *b);
EquationElementHeader *radicalPowerEquation(Radical *a, Equation *b);

EquationElementHeader *variablePowerIntegerLiteral(Variable *a, IntegerLiteral *b);
EquationElementHeader *variablePowerConstLiteral(Variable *a, ConstLiteral *b);
EquationElementHeader *variablePowerFraction(Variable *a, Fraction *b);
EquationElementHeader *variablePowerRadical(Variable *a, Radical *b);
EquationElementHeader *variablePowerVariable(Variable *a, Variable *b);
EquationElementHeader *variablePowerEquation(Variable *a, Equation *b);

EquationElementHeader *equationPowerIntegerLiteral(Equation *a, IntegerLiteral *b);
EquationElementHeader *equationPowerConstLiteral(Equation *a, ConstLiteral *b);
EquationElementHeader *equationPowerFraction(Equation *a, Fraction *b);
EquationElementHeader *equationPowerRadical(Equation *a, Radical *b);
EquationElementHeader *equationPowerVariable(Equation *a, Variable *b);
EquationElementHeader *equationPowerEquation(Equation *a, Equation *b);



EquationElementHeader *integerLiteralSimplify(IntegerLiteral *a);
EquationElementHeader *constLiteralSimplify(ConstLiteral *a);
EquationElementHeader *fractionSimplify(Fraction *a);
EquationElementHeader *radicalSimplify(Radical *a);
EquationElementHeader *variableSimplify(Variable *a);
EquationElementHeader *equationSimplify(Equation *a);


EquationElementHeader *equationElementHeaderAddEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b)
{
  EquationElement typeOfA = typeOfHeader(a);
  EquationElement typeOfB = typeOfHeader(b);

  switch(typeOfA)
  {
    case EquationElementIntegerLiteral:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return integerLiteralAddIntegerLiteral((IntegerLiteral *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return integerLiteralAddConstLiteral((IntegerLiteral *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return integerLiteralAddFraction((IntegerLiteral *)a, (Fraction *)b);
        case EquationElementRadical:
          return integerLiteralAddRadical((IntegerLiteral *)a, (Radical *)b);
        case EquationElementVariable:
          return integerLiteralAddVariable((IntegerLiteral *)a, (Variable *)b);
        case EquationElementEquation:
          return integerLiteralAddEquation((IntegerLiteral *)a, (Equation *)b);
      }
    case EquationElementConstLiteral:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return constLiteralAddIntegerLiteral((ConstLiteral *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return constLiteralAddConstLiteral((ConstLiteral *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return constLiteralAddFraction((ConstLiteral *)a, (Fraction *)b);
        case EquationElementRadical:
          return constLiteralAddRadical((ConstLiteral *)a, (Radical *)b);
        case EquationElementVariable:
          return constLiteralAddVariable((ConstLiteral *)a, (Variable *)b);
        case EquationElementEquation:
          return constLiteralAddEquation((ConstLiteral *)a, (Equation *)b);
      }
    case EquationElementFraction:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return fractionAddIntegerLiteral((Fraction *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return fractionAddConstLiteral((Fraction *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return fractionAddFraction((Fraction *)a, (Fraction *)b);
        case EquationElementRadical:
          return fractionAddRadical((Fraction *)a, (Radical *)b);
        case EquationElementVariable:
          return fractionAddVariable((Fraction *)a, (Variable *)b);
        case EquationElementEquation:
          return fractionAddEquation((Fraction *)a, (Equation *)b);
      }
    case EquationElementRadical:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return radicalAddIntegerLiteral((Radical *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return radicalAddConstLiteral((Radical *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return radicalAddFraction((Radical *)a, (Fraction *)b);
        case EquationElementRadical:
          return radicalAddRadical((Radical *)a, (Radical *)b);
        case EquationElementVariable:
          return radicalAddVariable((Radical *)a, (Variable *)b);
        case EquationElementEquation:
          return radicalAddEquation((Radical *)a, (Equation *)b);
      }
    case EquationElementVariable:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return variableAddIntegerLiteral((Variable *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return variableAddConstLiteral((Variable *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return variableAddFraction((Variable *)a, (Fraction *)b);
        case EquationElementRadical:
          return variableAddRadical((Variable *)a, (Radical *)b);
        case EquationElementVariable:
          return variableAddVariable((Variable *)a, (Variable *)b);
        case EquationElementEquation:
          return variableAddEquation((Variable *)a, (Equation *)b);
      }
    case EquationElementEquation:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return equationAddIntegerLiteral((Equation *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return equationAddConstLiteral((Equation *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return equationAddFraction((Equation *)a, (Fraction *)b);
        case EquationElementRadical:
          return equationAddRadical((Equation *)a, (Radical *)b);
        case EquationElementVariable:
          return equationAddVariable((Equation *)a, (Variable *)b);
        case EquationElementEquation:
          return equationAddEquation((Equation *)a, (Equation *)b);
      }
  }
}
EquationElementHeader *equationElementHeaderMultiplyEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b)
{
  EquationElement typeOfA = typeOfHeader(a);
  EquationElement typeOfB = typeOfHeader(b);

  
  switch(typeOfA)
  {
    case EquationElementIntegerLiteral:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return integerLiteralMultiplyIntegerLiteral((IntegerLiteral *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return integerLiteralMultiplyConstLiteral((IntegerLiteral *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return integerLiteralMultiplyFraction((IntegerLiteral *)a, (Fraction *)b);
        case EquationElementRadical:
          return integerLiteralMultiplyRadical((IntegerLiteral *)a, (Radical *)b);
        case EquationElementVariable:
          return integerLiteralMultiplyVariable((IntegerLiteral *)a, (Variable *)b);
        case EquationElementEquation:
          return integerLiteralMultiplyEquation((IntegerLiteral *)a, (Equation *)b);
      }
    case EquationElementConstLiteral:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return constLiteralMultiplyIntegerLiteral((ConstLiteral *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return constLiteralMultiplyConstLiteral((ConstLiteral *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return constLiteralMultiplyFraction((ConstLiteral *)a, (Fraction *)b);
        case EquationElementRadical:
          return constLiteralMultiplyRadical((ConstLiteral *)a, (Radical *)b);
        case EquationElementVariable:
          return constLiteralMultiplyVariable((ConstLiteral *)a, (Variable *)b);
        case EquationElementEquation:
          return constLiteralMultiplyEquation((ConstLiteral *)a, (Equation *)b);
      }
    case EquationElementFraction:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return fractionMultiplyIntegerLiteral((Fraction *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return fractionMultiplyConstLiteral((Fraction *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return fractionMultiplyFraction((Fraction *)a, (Fraction *)b);
        case EquationElementRadical:
          return fractionMultiplyRadical((Fraction *)a, (Radical *)b);
        case EquationElementVariable:
          return fractionMultiplyVariable((Fraction *)a, (Variable *)b);
        case EquationElementEquation:
          return fractionMultiplyEquation((Fraction *)a, (Equation *)b);
      }
    case EquationElementRadical:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return radicalMultiplyIntegerLiteral((Radical *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return radicalMultiplyConstLiteral((Radical *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return radicalMultiplyFraction((Radical *)a, (Fraction *)b);
        case EquationElementRadical:
          return radicalMultiplyRadical((Radical *)a, (Radical *)b);
        case EquationElementVariable:
          return radicalMultiplyVariable((Radical *)a, (Variable *)b);
        case EquationElementEquation:
          return radicalMultiplyEquation((Radical *)a, (Equation *)b);
      }
    case EquationElementVariable:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return variableMultiplyIntegerLiteral((Variable *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return variableMultiplyConstLiteral((Variable *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return variableMultiplyFraction((Variable *)a, (Fraction *)b);
        case EquationElementRadical:
          return variableMultiplyRadical((Variable *)a, (Radical *)b);
        case EquationElementVariable:
          return variableMultiplyVariable((Variable *)a, (Variable *)b);
        case EquationElementEquation:
          return variableMultiplyEquation((Variable *)a, (Equation *)b);
      }
    case EquationElementEquation:
      switch(typeOfB)
      {
        case EquationElementIntegerLiteral:
          return equationMultiplyIntegerLiteral((Equation *)a, (IntegerLiteral *)b);
        case EquationElementConstLiteral:
          return equationMultiplyConstLiteral((Equation *)a, (ConstLiteral *)b);
        case EquationElementFraction:
          return equationMultiplyFraction((Equation *)a, (Fraction *)b);
        case EquationElementRadical:
          return equationMultiplyRadical((Equation *)a, (Radical *)b);
        case EquationElementVariable:
          return equationMultiplyVariable((Equation *)a, (Variable *)b);
        case EquationElementEquation:
          return equationMultiplyEquation((Equation *)a, (Equation *)b);
      }
  }
}
EquationElementHeader *equationElementHeaderSubtractEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
EquationElementHeader *equationElementHeaderDivideEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
EquationElementHeader *equationElementHeaderPowerEquationElementHeader(EquationElementHeader *a, EquationElementHeader *b);
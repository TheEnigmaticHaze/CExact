#include "..\cexactTypes.h"

const unsigned char KEEP_PARAMETERS = 0;
const unsigned char FREE_PARAMETERS = 1;

extern EquationElementHeader *integerLiteralAddIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralAddConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralAddFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralAddRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralAddEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralAddVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *constLiteralAddIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralAddConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralAddFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralAddRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralAddEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralAddVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *fractionAddIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionAddConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionAddFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *fractionAddRadical(Fraction *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *fractionAddEquation(Fraction *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *fractionAddVariable(Fraction *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *radicalAddIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalAddConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalAddFraction(Radical *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *radicalAddRadical(Radical *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *radicalAddEquation(Radical *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *radicalAddVariable(Radical *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *variableAddIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableAddConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableAddFraction(Variable *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *variableAddRadical(Variable *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *variableAddEquation(Variable *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *variableAddVariable(Variable *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *equationAddIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationAddConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationAddFraction(Equation *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *equationAddRadical(Equation *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *equationAddEquation(Equation *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *equationAddVariable(Equation *a, Variable *b, unsigned char freeParameters);



extern EquationElementHeader *integerLiteralMultiplyIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralMultiplyConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralMultiplyFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralMultiplyRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralMultiplyEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralMultiplyVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *constLiteralMultiplyIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralMultiplyConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralMultiplyFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralMultiplyRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralMultiplyEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralMultiplyVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *fractionMultiplyIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionMultiplyConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionMultiplyFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *fractionMultiplyRadical(Fraction *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *fractionMultiplyEquation(Fraction *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *fractionMultiplyVariable(Fraction *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *radicalMultiplyIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalMultiplyConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalMultiplyFraction(Radical *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *radicalMultiplyRadical(Radical *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *radicalMultiplyEquation(Radical *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *radicalMultiplyVariable(Radical *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *variableMultiplyIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableMultiplyConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableMultiplyFraction(Variable *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *variableMultiplyRadical(Variable *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *variableMultiplyEquation(Variable *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *variableMultiplyVariable(Variable *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *equationMultiplyIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationMultiplyConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationMultiplyFraction(Equation *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *equationMultiplyRadical(Equation *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *equationMultiplyEquation(Equation *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *equationMultiplyVariable(Equation *a, Variable *b, unsigned char freeParameters);



extern EquationElementHeader *integerLiteralSubtractIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralSubtractConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralSubtractFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralSubtractRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralSubtractEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralSubtractVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *constLiteralSubtractIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralSubtractConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralSubtractFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralSubtractRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralSubtractEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralSubtractVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *fractionSubtractIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionSubtractConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionSubtractFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *fractionSubtractRadical(Fraction *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *fractionSubtractEquation(Fraction *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *fractionSubtractVariable(Fraction *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *radicalSubtractIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalSubtractConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalSubtractFraction(Radical *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *radicalSubtractRadical(Radical *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *radicalSubtractEquation(Radical *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *radicalSubtractVariable(Radical *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *variableSubtractIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableSubtractConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableSubtractFraction(Variable *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *variableSubtractRadical(Variable *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *variableSubtractEquation(Variable *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *variableSubtractVariable(Variable *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *equationSubtractIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationSubtractConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationSubtractFraction(Equation *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *equationSubtractRadical(Equation *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *equationSubtractEquation(Equation *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *equationSubtractVariable(Equation *a, Variable *b, unsigned char freeParameters);



extern EquationElementHeader *integerLiteralDivideIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralDivideConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralDivideFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralDivideRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralDivideEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralDivideVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *constLiteralDivideIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralDivideConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralDivideFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralDivideRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralDivideEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralDivideVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *fractionDivideIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionDivideConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionDivideFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *fractionDivideRadical(Fraction *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *fractionDivideEquation(Fraction *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *fractionDivideVariable(Fraction *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *radicalDivideIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalDivideConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalDivideFraction(Radical *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *radicalDivideRadical(Radical *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *radicalDivideEquation(Radical *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *radicalDivideVariable(Radical *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *variableDivideIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableDivideConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variableDivideFraction(Variable *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *variableDivideRadical(Variable *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *variableDivideEquation(Variable *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *variableDivideVariable(Variable *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *equationDivideIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationDivideConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationDivideFraction(Equation *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *equationDivideRadical(Equation *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *equationDivideEquation(Equation *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *equationDivideVariable(Equation *a, Variable *b, unsigned char freeParameters);



extern EquationElementHeader *integerLiteralPowerIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralPowerConstLiteral(IntegerLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralPowerFraction(IntegerLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralPowerRadical(IntegerLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralPowerEquation(IntegerLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *integerLiteralPowerVariable(IntegerLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *constLiteralPowerIntegerLiteral(ConstLiteral *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralPowerConstLiteral(ConstLiteral *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralPowerFraction(ConstLiteral *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralPowerRadical(ConstLiteral *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralPowerEquation(ConstLiteral *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *constLiteralPowerVariable(ConstLiteral *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *fractionPowerIntegerLiteral(Fraction *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionPowerConstLiteral(Fraction *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *fractionPowerFraction(Fraction *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *fractionPowerRadical(Fraction *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *fractionPowerEquation(Fraction *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *fractionPowerVariable(Fraction *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *radicalPowerIntegerLiteral(Radical *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalPowerConstLiteral(Radical *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *radicalPowerFraction(Radical *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *radicalPowerRadical(Radical *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *radicalPowerEquation(Radical *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *radicalPowerVariable(Radical *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *variablePowerIntegerLiteral(Variable *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variablePowerConstLiteral(Variable *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *variablePowerFraction(Variable *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *variablePowerRadical(Variable *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *variablePowerEquation(Variable *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *variablePowerVariable(Variable *a, Variable *b, unsigned char freeParameters);

extern EquationElementHeader *equationPowerIntegerLiteral(Equation *a, IntegerLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationPowerConstLiteral(Equation *a, ConstLiteral *b, unsigned char freeParameters);
extern EquationElementHeader *equationPowerFraction(Equation *a, Fraction *b, unsigned char freeParameters);
extern EquationElementHeader *equationPowerRadical(Equation *a, Radical *b, unsigned char freeParameters);
extern EquationElementHeader *equationPowerEquation(Equation *a, Equation *b, unsigned char freeParameters);
extern EquationElementHeader *equationPowerVariable(Equation *a, Variable *b, unsigned char freeParameters);



extern EquationElementHeader *integerLiteralSimplify(IntegerLiteral *a);
extern EquationElementHeader *constLiteralSimplify(ConstLiteral *a);
extern EquationElementHeader *fractionSimplify(Fraction *a);
extern EquationElementHeader *radicalSimplify(Radical *a);
extern EquationElementHeader *variableSimplify(Variable *a);
extern EquationElementHeader *equationSimplify(Equation *a);
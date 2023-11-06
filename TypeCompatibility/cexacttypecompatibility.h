#include "..\cexactTypes.h"


extern EquationElementHeader *integerLiteralAddIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *integerLiteralAddConstLiteral(IntegerLiteral *a, ConstLiteral *b);
extern EquationElementHeader *integerLiteralAddFraction(IntegerLiteral *a, Fraction *b);
extern EquationElementHeader *integerLiteralAddRadical(IntegerLiteral *a, Radical *b);
extern EquationElementHeader *integerLiteralAddEquation(IntegerLiteral *a, Equation *b);
extern EquationElementHeader *integerLiteralAddVariable(IntegerLiteral *a, Variable *b);

extern EquationElementHeader *constLiteralAddIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *constLiteralAddConstLiteral(ConstLiteral *a, ConstLiteral *b);
extern EquationElementHeader *constLiteralAddFraction(ConstLiteral *a, Fraction *b);
extern EquationElementHeader *constLiteralAddRadical(ConstLiteral *a, Radical *b);
extern EquationElementHeader *constLiteralAddEquation(ConstLiteral *a, Equation *b);
extern EquationElementHeader *constLiteralAddVariable(ConstLiteral *a, Variable *b);

extern EquationElementHeader *fractionAddIntegerLiteral(Fraction *a, IntegerLiteral *b);
extern EquationElementHeader *fractionAddConstLiteral(Fraction *a, ConstLiteral *b);
extern EquationElementHeader *fractionAddFraction(Fraction *a, Fraction *b);
extern EquationElementHeader *fractionAddRadical(Fraction *a, Radical *b);
extern EquationElementHeader *fractionAddEquation(Fraction *a, Equation *b);
extern EquationElementHeader *fractionAddVariable(Fraction *a, Variable *b);

extern EquationElementHeader *radicalAddIntegerLiteral(Radical *a, IntegerLiteral *b);
extern EquationElementHeader *radicalAddConstLiteral(Radical *a, ConstLiteral *b);
extern EquationElementHeader *radicalAddFraction(Radical *a, Fraction *b);
extern EquationElementHeader *radicalAddRadical(Radical *a, Radical *b);
extern EquationElementHeader *radicalAddEquation(Radical *a, Equation *b);
extern EquationElementHeader *radicalAddVariable(Radical *a, Variable *b);

extern EquationElementHeader *variableAddIntegerLiteral(Variable *a, IntegerLiteral *b);
extern EquationElementHeader *variableAddConstLiteral(Variable *a, ConstLiteral *b);
extern EquationElementHeader *variableAddFraction(Variable *a, Fraction *b);
extern EquationElementHeader *variableAddRadical(Variable *a, Radical *b);
extern EquationElementHeader *variableAddEquation(Variable *a, Equation *b);
extern EquationElementHeader *variableAddVariable(Variable *a, Variable *b);

extern EquationElementHeader *equationAddIntegerLiteral(Equation *a, IntegerLiteral *b);
extern EquationElementHeader *equationAddConstLiteral(Equation *a, ConstLiteral *b);
extern EquationElementHeader *equationAddFraction(Equation *a, Fraction *b);
extern EquationElementHeader *equationAddRadical(Equation *a, Radical *b);
extern EquationElementHeader *equationAddEquation(Equation *a, Equation *b);
extern EquationElementHeader *equationAddVariable(Equation *a, Variable *b);



extern EquationElementHeader *integerLiteralMultiplyIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *integerLiteralMultiplyConstLiteral(IntegerLiteral *a, ConstLiteral *b);
extern EquationElementHeader *integerLiteralMultiplyFraction(IntegerLiteral *a, Fraction *b);
extern EquationElementHeader *integerLiteralMultiplyRadical(IntegerLiteral *a, Radical *b);
extern EquationElementHeader *integerLiteralMultiplyEquation(IntegerLiteral *a, Equation *b);
extern EquationElementHeader *integerLiteralMultiplyVariable(IntegerLiteral *a, Variable *b);

extern EquationElementHeader *constLiteralMultiplyIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *constLiteralMultiplyConstLiteral(ConstLiteral *a, ConstLiteral *b);
extern EquationElementHeader *constLiteralMultiplyFraction(ConstLiteral *a, Fraction *b);
extern EquationElementHeader *constLiteralMultiplyRadical(ConstLiteral *a, Radical *b);
extern EquationElementHeader *constLiteralMultiplyEquation(ConstLiteral *a, Equation *b);
extern EquationElementHeader *constLiteralMultiplyVariable(ConstLiteral *a, Variable *b);

extern EquationElementHeader *fractionMultiplyIntegerLiteral(Fraction *a, IntegerLiteral *b);
extern EquationElementHeader *fractionMultiplyConstLiteral(Fraction *a, ConstLiteral *b);
extern EquationElementHeader *fractionMultiplyFraction(Fraction *a, Fraction *b);
extern EquationElementHeader *fractionMultiplyRadical(Fraction *a, Radical *b);
extern EquationElementHeader *fractionMultiplyEquation(Fraction *a, Equation *b);
extern EquationElementHeader *fractionMultiplyVariable(Fraction *a, Variable *b);

extern EquationElementHeader *radicalMultiplyIntegerLiteral(Radical *a, IntegerLiteral *b);
extern EquationElementHeader *radicalMultiplyConstLiteral(Radical *a, ConstLiteral *b);
extern EquationElementHeader *radicalMultiplyFraction(Radical *a, Fraction *b);
extern EquationElementHeader *radicalMultiplyRadical(Radical *a, Radical *b);
extern EquationElementHeader *radicalMultiplyEquation(Radical *a, Equation *b);
extern EquationElementHeader *radicalMultiplyVariable(Radical *a, Variable *b);

extern EquationElementHeader *variableMultiplyIntegerLiteral(Variable *a, IntegerLiteral *b);
extern EquationElementHeader *variableMultiplyConstLiteral(Variable *a, ConstLiteral *b);
extern EquationElementHeader *variableMultiplyFraction(Variable *a, Fraction *b);
extern EquationElementHeader *variableMultiplyRadical(Variable *a, Radical *b);
extern EquationElementHeader *variableMultiplyEquation(Variable *a, Equation *b);
extern EquationElementHeader *variableMultiplyVariable(Variable *a, Variable *b);

extern EquationElementHeader *equationMultiplyIntegerLiteral(Equation *a, IntegerLiteral *b);
extern EquationElementHeader *equationMultiplyConstLiteral(Equation *a, ConstLiteral *b);
extern EquationElementHeader *equationMultiplyFraction(Equation *a, Fraction *b);
extern EquationElementHeader *equationMultiplyRadical(Equation *a, Radical *b);
extern EquationElementHeader *equationMultiplyEquation(Equation *a, Equation *b);
extern EquationElementHeader *equationMultiplyVariable(Equation *a, Variable *b);



extern EquationElementHeader *integerLiteralSubtractIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *integerLiteralSubtractConstLiteral(IntegerLiteral *a, ConstLiteral *b);
extern EquationElementHeader *integerLiteralSubtractFraction(IntegerLiteral *a, Fraction *b);
extern EquationElementHeader *integerLiteralSubtractRadical(IntegerLiteral *a, Radical *b);
extern EquationElementHeader *integerLiteralSubtractEquation(IntegerLiteral *a, Equation *b);
extern EquationElementHeader *integerLiteralSubtractVariable(IntegerLiteral *a, Variable *b);

extern EquationElementHeader *constLiteralSubtractIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *constLiteralSubtractConstLiteral(ConstLiteral *a, ConstLiteral *b);
extern EquationElementHeader *constLiteralSubtractFraction(ConstLiteral *a, Fraction *b);
extern EquationElementHeader *constLiteralSubtractRadical(ConstLiteral *a, Radical *b);
extern EquationElementHeader *constLiteralSubtractEquation(ConstLiteral *a, Equation *b);
extern EquationElementHeader *constLiteralSubtractVariable(ConstLiteral *a, Variable *b);

extern EquationElementHeader *fractionSubtractIntegerLiteral(Fraction *a, IntegerLiteral *b);
extern EquationElementHeader *fractionSubtractConstLiteral(Fraction *a, ConstLiteral *b);
extern EquationElementHeader *fractionSubtractFraction(Fraction *a, Fraction *b);
extern EquationElementHeader *fractionSubtractRadical(Fraction *a, Radical *b);
extern EquationElementHeader *fractionSubtractEquation(Fraction *a, Equation *b);
extern EquationElementHeader *fractionSubtractVariable(Fraction *a, Variable *b);

extern EquationElementHeader *radicalSubtractIntegerLiteral(Radical *a, IntegerLiteral *b);
extern EquationElementHeader *radicalSubtractConstLiteral(Radical *a, ConstLiteral *b);
extern EquationElementHeader *radicalSubtractFraction(Radical *a, Fraction *b);
extern EquationElementHeader *radicalSubtractRadical(Radical *a, Radical *b);
extern EquationElementHeader *radicalSubtractEquation(Radical *a, Equation *b);
extern EquationElementHeader *radicalSubtractVariable(Radical *a, Variable *b);

extern EquationElementHeader *variableSubtractIntegerLiteral(Variable *a, IntegerLiteral *b);
extern EquationElementHeader *variableSubtractConstLiteral(Variable *a, ConstLiteral *b);
extern EquationElementHeader *variableSubtractFraction(Variable *a, Fraction *b);
extern EquationElementHeader *variableSubtractRadical(Variable *a, Radical *b);
extern EquationElementHeader *variableSubtractEquation(Variable *a, Equation *b);
extern EquationElementHeader *variableSubtractVariable(Variable *a, Variable *b);

extern EquationElementHeader *equationSubtractIntegerLiteral(Equation *a, IntegerLiteral *b);
extern EquationElementHeader *equationSubtractConstLiteral(Equation *a, ConstLiteral *b);
extern EquationElementHeader *equationSubtractFraction(Equation *a, Fraction *b);
extern EquationElementHeader *equationSubtractRadical(Equation *a, Radical *b);
extern EquationElementHeader *equationSubtractEquation(Equation *a, Equation *b);
extern EquationElementHeader *equationSubtractVariable(Equation *a, Variable *b);



extern EquationElementHeader *integerLiteralDivideIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *integerLiteralDivideConstLiteral(IntegerLiteral *a, ConstLiteral *b);
extern EquationElementHeader *integerLiteralDivideFraction(IntegerLiteral *a, Fraction *b);
extern EquationElementHeader *integerLiteralDivideRadical(IntegerLiteral *a, Radical *b);
extern EquationElementHeader *integerLiteralDivideEquation(IntegerLiteral *a, Equation *b);
extern EquationElementHeader *integerLiteralDivideVariable(IntegerLiteral *a, Variable *b);

extern EquationElementHeader *constLiteralDivideIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *constLiteralDivideConstLiteral(ConstLiteral *a, ConstLiteral *b);
extern EquationElementHeader *constLiteralDivideFraction(ConstLiteral *a, Fraction *b);
extern EquationElementHeader *constLiteralDivideRadical(ConstLiteral *a, Radical *b);
extern EquationElementHeader *constLiteralDivideEquation(ConstLiteral *a, Equation *b);
extern EquationElementHeader *constLiteralDivideVariable(ConstLiteral *a, Variable *b);

extern EquationElementHeader *fractionDivideIntegerLiteral(Fraction *a, IntegerLiteral *b);
extern EquationElementHeader *fractionDivideConstLiteral(Fraction *a, ConstLiteral *b);
extern EquationElementHeader *fractionDivideFraction(Fraction *a, Fraction *b);
extern EquationElementHeader *fractionDivideRadical(Fraction *a, Radical *b);
extern EquationElementHeader *fractionDivideEquation(Fraction *a, Equation *b);
extern EquationElementHeader *fractionDivideVariable(Fraction *a, Variable *b);

extern EquationElementHeader *radicalDivideIntegerLiteral(Radical *a, IntegerLiteral *b);
extern EquationElementHeader *radicalDivideConstLiteral(Radical *a, ConstLiteral *b);
extern EquationElementHeader *radicalDivideFraction(Radical *a, Fraction *b);
extern EquationElementHeader *radicalDivideRadical(Radical *a, Radical *b);
extern EquationElementHeader *radicalDivideEquation(Radical *a, Equation *b);
extern EquationElementHeader *radicalDivideVariable(Radical *a, Variable *b);

extern EquationElementHeader *variableDivideIntegerLiteral(Variable *a, IntegerLiteral *b);
extern EquationElementHeader *variableDivideConstLiteral(Variable *a, ConstLiteral *b);
extern EquationElementHeader *variableDivideFraction(Variable *a, Fraction *b);
extern EquationElementHeader *variableDivideRadical(Variable *a, Radical *b);
extern EquationElementHeader *variableDivideEquation(Variable *a, Equation *b);
extern EquationElementHeader *variableDivideVariable(Variable *a, Variable *b);

extern EquationElementHeader *equationDivideIntegerLiteral(Equation *a, IntegerLiteral *b);
extern EquationElementHeader *equationDivideConstLiteral(Equation *a, ConstLiteral *b);
extern EquationElementHeader *equationDivideFraction(Equation *a, Fraction *b);
extern EquationElementHeader *equationDivideRadical(Equation *a, Radical *b);
extern EquationElementHeader *equationDivideEquation(Equation *a, Equation *b);
extern EquationElementHeader *equationDivideVariable(Equation *a, Variable *b);



extern EquationElementHeader *integerLiteralPowerIntegerLiteral(IntegerLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *integerLiteralPowerConstLiteral(IntegerLiteral *a, ConstLiteral *b);
extern EquationElementHeader *integerLiteralPowerFraction(IntegerLiteral *a, Fraction *b);
extern EquationElementHeader *integerLiteralPowerRadical(IntegerLiteral *a, Radical *b);
extern EquationElementHeader *integerLiteralPowerEquation(IntegerLiteral *a, Equation *b);
extern EquationElementHeader *integerLiteralPowerVariable(IntegerLiteral *a, Variable *b);

extern EquationElementHeader *constLiteralPowerIntegerLiteral(ConstLiteral *a, IntegerLiteral *b);
extern EquationElementHeader *constLiteralPowerConstLiteral(ConstLiteral *a, ConstLiteral *b);
extern EquationElementHeader *constLiteralPowerFraction(ConstLiteral *a, Fraction *b);
extern EquationElementHeader *constLiteralPowerRadical(ConstLiteral *a, Radical *b);
extern EquationElementHeader *constLiteralPowerEquation(ConstLiteral *a, Equation *b);
extern EquationElementHeader *constLiteralPowerVariable(ConstLiteral *a, Variable *b);

extern EquationElementHeader *fractionPowerIntegerLiteral(Fraction *a, IntegerLiteral *b);
extern EquationElementHeader *fractionPowerConstLiteral(Fraction *a, ConstLiteral *b);
extern EquationElementHeader *fractionPowerFraction(Fraction *a, Fraction *b);
extern EquationElementHeader *fractionPowerRadical(Fraction *a, Radical *b);
extern EquationElementHeader *fractionPowerEquation(Fraction *a, Equation *b);
extern EquationElementHeader *fractionPowerVariable(Fraction *a, Variable *b);

extern EquationElementHeader *radicalPowerIntegerLiteral(Radical *a, IntegerLiteral *b);
extern EquationElementHeader *radicalPowerConstLiteral(Radical *a, ConstLiteral *b);
extern EquationElementHeader *radicalPowerFraction(Radical *a, Fraction *b);
extern EquationElementHeader *radicalPowerRadical(Radical *a, Radical *b);
extern EquationElementHeader *radicalPowerEquation(Radical *a, Equation *b);
extern EquationElementHeader *radicalPowerVariable(Radical *a, Variable *b);

extern EquationElementHeader *variablePowerIntegerLiteral(Variable *a, IntegerLiteral *b);
extern EquationElementHeader *variablePowerConstLiteral(Variable *a, ConstLiteral *b);
extern EquationElementHeader *variablePowerFraction(Variable *a, Fraction *b);
extern EquationElementHeader *variablePowerRadical(Variable *a, Radical *b);
extern EquationElementHeader *variablePowerEquation(Variable *a, Equation *b);
extern EquationElementHeader *variablePowerVariable(Variable *a, Variable *b);

extern EquationElementHeader *equationPowerIntegerLiteral(Equation *a, IntegerLiteral *b);
extern EquationElementHeader *equationPowerConstLiteral(Equation *a, ConstLiteral *b);
extern EquationElementHeader *equationPowerFraction(Equation *a, Fraction *b);
extern EquationElementHeader *equationPowerRadical(Equation *a, Radical *b);
extern EquationElementHeader *equationPowerEquation(Equation *a, Equation *b);
extern EquationElementHeader *equationPowerVariable(Equation *a, Variable *b);



extern EquationElementHeader *integerLiteralSimplify(IntegerLiteral *a);
extern EquationElementHeader *constLiteralSimplify(ConstLiteral *a);
extern EquationElementHeader *fractionSimplify(Fraction *a);
extern EquationElementHeader *radicalSimplify(Radical *a);
extern EquationElementHeader *variableSimplify(Variable *a);
extern EquationElementHeader *equationSimplify(Equation *a);
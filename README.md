**Programming Assignment**

**Course #: PROG 2100**

**Assignment #3 ("Rational Number Calculator")**

**(Modified from - Savitch Absolute C++)**

A rational number is a number that can be represented as the quotient of two integers i.e. a fraction. For example, ½, -64/2, 5/1 and so forth are all rational numbers.

Define a class for rational numbers containing two integers, one for the numerator and one for the denominator. Include four constructors:

1. Default – that initializes the object to 0/1
2. One Argument – for whole numbers e.g. 5 (5 becomes 5/1)
3. Two Argument – for when both numerator and denominator are provided
4. String – for when the number is provided as a string i.e. "-1/2" or "5"

Overload all the following mathematical operators so that they correctly apply to the type Rational: +, -, \*, and / (these will normalize the answers provided)

Overload all the following comparison operators so that they correctly apply to the type Rational: \>, \< , == (these will all have Boolean returns).

Overload the output operator \<\< (only i.e. not the input operator \>\>) so that it correctly applies to the type Rational.

Validation will be required to prevent acceptance of decimal numbers or non-numeric entry

Write a driver that demonstrates the functionality of all constructors and overloaded operators asked for above one after the other (i.e. do not ask for the operator, just the numbers to be processed. Make it loop after each calculation is complete.

**Notes:**

- Note that the numerator, the denominator, or both may contain a minus sign.

- Your input may not accept decimal numbers nor display numbers in decimal format. However, internally, you may use decimals in calculations if needed.
- Your solution must actually use the operators with rational objects when you do the operations i.e. RN = RN + RN, cout \<\< RN, etc.
- Only the answer to each mathematical equation needs to be displayed normalized.
- Put a System.out.printl() in each overload and constructor to show that they fired.

**Hints:**

- Two rational numbers a/b and c/d are equal if a\*d equals c\*b. If b and d are positive rational numbers, a/b is less than c/d provided a\*d is less than c\*b.
- You should include a function to normalize the values stored so that, after normalization, the denominator is positive and the numerator and denominator are as small as possible. For example, after normalization 4/-8 would be represented the same as -1/2.
- Division is normally calculated by flipping one of the rational numbers and then multiplying the two rational numbers together. Remember to account for division by zero.

**Interface description (i.e. how the user interacts with your program):**

- User inputs entire first fraction (or whole number) as a string.
- User inputs entire second fraction (or whole number) as a string.
- Output should list **all the mathematical, comparison, and overloaded output operators** required in the assignment.
- In addition to the above, you will also need to code additional demonstrations in order to demonstrate the functionality of all the constructors and overloaded operators you have created.
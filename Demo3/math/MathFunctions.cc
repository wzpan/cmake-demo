/**
 * power - Calculate the power of number.
 * @param base:	Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */
extern double power(double base, int exponent)
{
    int result = base;
    int i;
    
    for(i = 1; i < exponent; ++i){
        result = result * base;
    }

    return result;
}


#ifndef BIT_MATH_H
#define BIT_MATH_H

// THIS FILE TO HELP IN BIT WISE OPERATIONS.

//macro functions .
#define SET_BIT(PORT_REG,PIN_NO) PORT_REG |= (1<<PIN_NO)
#define CLR_BIT(PORT_REG,PIN_NO) PORT_REG &= ~(1<<PIN_NO)
#define TGL_BIT(PORT_REG,PIN_NO) PORT_REG ^= (1<<PIN_NO)
#define GET_BIT(PORT_REG,PIN_NO) ((PORT_REG>>PIN_NO)&1)






#endif
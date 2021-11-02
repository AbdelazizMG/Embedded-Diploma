/*
 * macros.h
 *
 *  Created on: Sep 17, 2021
 *      Author: sigmaa
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SetBit(REG,BIT)     REG |= (1<<BIT)
#define ClearBit(REG,BIT)   REG &= ~(1<<BIT)
#define ToggleBit(REG,BIT)  REG ^= (1<<BIT)

#endif /* MACROS_H_ */

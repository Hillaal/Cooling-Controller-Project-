
#ifndef TC72_H
#define TC72_H

void TC72_Init(unsigned char Mode);

void TC72_RegisterWrite(unsigned char RegAdd, unsigned char Data);

void TC72_RegisterRead(unsigned char RegAdd, unsigned char * DataPtr);
#endif /* TC72_H */

#pragma once
int Square(int x);
int Double(int x);
int Increment(int x);

using Operation = int(*)(int) ;

void Invoke(Operation op) ;
#pragma once
int Square(int x);
int Double(int x);
int Increment(int x);

using Operation = int(*)(int) ;

int(* GetOperation(int index))(int) ;

Operation GetOp(int index) ;

void Invoke(Operation op) ;
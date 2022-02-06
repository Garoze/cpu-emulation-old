# Instructions
---

## Instructions Table

NOP (0x00) - Does nothing
CLC (0x01) - Clear the Carry flag on Registers.
SLC (0x02) - Sets the Carry flag on Registers, its consumes a byte.
AND (0x03) - Do a bitwise AND (&) on Register A, its consumes a byte to performe the operation.
BOR (0x04) - Do a bitwise  OR (|) on Register A, its consumes a byte to performe the operation.
XOR (0x05) - Do a bitwise XOR (^) on Register A, its consumes a byte to performe the operation.
NOT (0x06) - Do a bitwise NOT (~) on Register A, its consumes a byte to performe the operation.
SHL (0x07) - Do a bitwise SHL (<<) on Register A, its consumes a byte to performe the operation.
SHR (0x08) - Do a bitwise SHR (>>) on Register A, its consumes a byte to performe the operation.

LDI (0x09) - imm8/16 <- Loads a value on Register A, its consumes a byte.
LDA (0x10) - abs16 <- Load a value from an absolute address on Register A.
LDR (0x11) - rel16 <- Load a value from a relative address on Register A.
LDS (0x12) - stc16 <- Load a value from the stack + offset on Register A.
STA (0x13) - imm8/16 -> Stores A values into a absolute address.
STR (0x14) - imm8/16 -> Stores A value into a relative address.
STS (0x15) - imm8/16 -> Stores A value into the Stack.
INC (0x16) - Increment A value by 1.
DEC (0x17) - Decrement A value by 1.

PSH (0x18) - imm8/16 -> Push a value to the stack, its consumes a Byte.
POP (0x19) - imm8/16 <- Pop a value from the stack to Register A.

SUB (0x20) - Calls a Subrotine and push the address to the stack.
RET (0x21) - Returne from a subrotine

HLT (0x22) - Stops the CPU.


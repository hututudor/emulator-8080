NOP
NOP
NOP
JMP 0x0000
NOP
NOP
PUSH PSW
PUSH B
PUSH D
PUSH H
JMP 0x0000
NOP
PUSH PSW
PUSH B
PUSH D
PUSH H
MVI A, 0x00
STA 0x0000
LXI H, 0x0000
DCR M
CALL 0x0000
IN  0x00
RRC
JC 0x0000
LDA 0x0000
ANA A
JZ 0x0000
LDA 0x0000
CPI 0x00
JZ 0x0000
ADI 0x00
DAA
STA 0x0000
CALL 0x0000
XRA A
STA 0x0000
LDA 0x0000
ANA A
JZ 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
CALL 0x0000
JMP 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
JMP 0x0000
MVI A, 0x00
STA 0x0000
JMP 0x0000
CALL 0x0000
LDA 0x0000
STA 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
NOP
POP H
POP D
POP B
POP PSW
EI
RET
NOP
NOP
NOP
NOP
XRA A
STA 0x0000
LDA 0x0000
ANA A
JZ 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
LDA 0x0000
RRC
JNC 0x0000
LXI H, 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
PUSH H
MOV A,M
INX H
MOV H,M
MOV L,A
SHLD 0x0000
SHLD 0x0000
POP H
DCX H
MOV A,M
CPI 0x00
JNZ 0x0000
DCR A
STA 0x0000
CPI 0x00
MVI A, 0x00
JNZ 0x0000
INR A
STA 0x0000
RET
MVI A, 0x00
STA 0x0000
STA 0x0000
JMP 0x0000
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
LXI H, 0x0000
MOV A,M
ANA A
JNZ 0x0000
PUSH H
LDA 0x0000
MOV L,A
LDA 0x0000
MOV H,A
MOV A,M
ANA A
POP H
JZ 0x0000
INX H
INX H
MOV A,M
INX H
MOV B,M
ANI 0x00
CPI 0x00
RLC
RLC
MOV E,A
MVI D, 0x00
NOP
INR E
DAD D
XCHG
MOV A,B
ANA A
CNZ 0x0000
LHLD 0x0000
MVI B, 0x00
CALL 0x0000
XRA A
STA 0x0000
RET
LXI H, 0x0000
DAD D
XCHG
RET
LDA 0x0000
ANA A
RZ
LDA 0x0000
ANA A
RNZ
LDA 0x0000
MOV H,A
LDA 0x0000
MVI D, 0x00
CPI 0x00
CZ 0x0000
MOV L,A
MOV B,M
DCR B
JNZ 0x0000
STA 0x0000
CALL 0x0000
MOV H,C
SHLD 0x0000
MOV A,L
CPI 0x00
JC 0x0000
MOV A,D
STA 0x0000
MVI A, 0x00
STA 0x0000
RET
MVI D, 0x00
LXI H, 0x0000
MOV B,M
INX H
MOV C,M
CPI 0x00
JM 0x0000
SBI 0x00
MOV E,A
MOV A,B
ADI 0x00
MOV B,A
MOV A,E
INR D
JMP 0x0000
MOV L,B
ANA A
RZ
MOV E,A
MOV A,C
ADI 0x00
MOV C,A
MOV A,E
DCR A
JMP 0x0000
DCR D
JZ 0x0000
LXI H, 0x0000
MVI M, 0x00
INX H
MOV C,M
MVI M, 0x00
CALL 0x0000
LXI H, 0x0000
MOV A,M
INR A
ANI 0x00
LXI B, 0x0000
LXI H, 0x0000
MOV H,M
RET
NOP
LXI H, 0x0000
MVI B, 0x00
MVI M, 0x00
INX H
DCR B
JNZ 0x0000
RET
POP H
RET
MVI A, 0x00
MVI B, 0x00
LXI H, 0x0000
JMP 0x0000
INX H
MOV B,M
INX H
MOV A,C
ADD M
MOV M,A
INX H
MOV A,B
ADD M
MOV M,A
RET
MVI B, 0x00
LXI D, 0x0000
LXI H, 0x0000
JMP 0x0000
LXI H, 0x0000
JMP 0x0000
LXI H, 0x0000
MVI C, 0x00
LXI D, 0x0000
PUSH D
MVI B, 0x00
CALL 0x0000
POP D
DCR C
JNZ 0x0000
RET
MVI A, 0x00
JMP 0x0000
MVI A, 0x00
JMP 0x0000
XRA A
LXI D, 0x0000
JMP 0x0000
XRA A
LXI D, 0x0000
STA 0x0000
LXI B, 0x0000
LXI H, 0x0000
MVI A, 0x00
PUSH PSW
PUSH B
LDA 0x0000
ANA A
JNZ 0x0000
CALL 0x0000
POP B
POP PSW
DCR A
RZ
PUSH D
LXI D, 0x0000
DAD D
POP D
JMP 0x0000
CALL 0x0000
JMP 0x0000
LXI H, 0x0000
MOV A,M
CPI 0x00
RZ
CPI 0x00
JZ 0x0000
INX H
MOV B,M
MOV C,A
ORA B
MOV A,C
JNZ 0x0000
INX H
MOV A,M
ANA A
JNZ 0x0000
INX H
MOV E,M
INX H
MOV D,M
PUSH H
XCHG
PUSH H
LXI H, 0x0000
XTHL
PUSH D
PCHL
POP H
LXI D, 0x0000
DAD D
JMP 0x0000
DCR B
INR B
JNZ 0x0000
DCR A
DCR B
MOV M,B
DCX H
MOV M,A
LXI D, 0x0000
DAD D
JMP 0x0000
DCR M
DCX H
DCX H
JMP 0x0000
POP H
INX H
MOV A,M
CPI 0x00
JZ 0x0000
INX H
DCR M
RNZ
MOV B,A
XRA A
STA 0x0000
STA 0x0000
MVI A, 0x00
STA 0x0000
MOV A,B
MVI M, 0x00
INX H
DCR M
JNZ 0x0000
LHLD 0x0000
MVI B, 0x00
CALL 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI B, 0x00
CALL 0x0000
MVI B, 0x00
CALL 0x0000
LDA 0x0000
ANA A
RNZ
LDA 0x0000
ANA A
RZ
LXI SP, 0x0000
EI
CALL 0x0000
CALL 0x0000
ANA A
JZ 0x0000
CALL 0x0000
MOV A,M
ANA A
JZ 0x0000
LDA 0x0000
ANA A
JZ 0x0000
LDA 0x0000
PUSH PSW
RRC
JC 0x0000
CALL 0x0000
CALL 0x0000
MOV M,E
INX H
MOV M,D
DCX H
DCX H
MOV M,B
NOP
CALL 0x0000
POP PSW
RRC
MVI A, 0x00
MVI B, 0x00
JNC 0x0000
MVI B, 0x00
MVI A, 0x00
STA 0x0000
CALL 0x0000
XRA A
STA 0x0000
MOV A,B
OUT 0x00
INR A
STA 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
JMP 0x0000
NOP
NOP
NOP
LXI H, 0x0000
MVI M, 0x00
INX H
MOV A,M
ANA A
JMP 0x0000
NOP
DCX H
MVI M, 0x00
LDA 0x0000
MOV B,A
LDA 0x0000
ANA A
JNZ 0x0000
LDA 0x0000
RRC
JC 0x0000
RRC
JC 0x0000
JMP 0x0000
CALL 0x0000
RLC
RLC
JC 0x0000
RLC
JC 0x0000
LXI H, 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
MVI A, 0x00
STA 0x0000
RET
MOV A,B
CPI 0x00
JZ 0x0000
INR A
STA 0x0000
JMP 0x0000
MOV A,B
CPI 0x00
JZ 0x0000
DCR A
STA 0x0000
JMP 0x0000
INR A
ANI 0x00
LXI B, 0x0000
NOP
RLC
RLC
RLC
RLC
LXI H, 0x0000
ADD L
MOV L,A
SHLD 0x0000
JMP 0x0000
JNZ 0x0000
INX H
DCR M
JNZ 0x0000
JMP 0x0000
LXI D, 0x0000
CALL 0x0000
POP H
RNC
INX H
MOV A,M
ANA A
RZ
CPI 0x00
JZ 0x0000
CPI 0x00
JZ 0x0000
INX H
CPI 0x00
JNZ 0x0000
DCR M
JZ 0x0000
MOV A,M
CPI 0x00
RNZ
PUSH H
CALL 0x0000
CALL 0x0000
POP H
INX H
INR M
INX H
INX H
DCR M
DCR M
INX H
DCR M
DCR M
DCR M
INX H
MVI M, 0x00
CALL 0x0000
JMP 0x0000
INR A
MOV M,A
LDA 0x0000
ADI 0x00
STA 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
PUSH D
PUSH H
PUSH B
CALL 0x0000
POP B
POP H
POP D
LDA 0x0000
ADD L
MOV L,A
STA 0x0000
CALL 0x0000
LDA 0x0000
ANA A
RZ
STA 0x0000
RET
CPI 0x00
RZ
JMP 0x0000
LXI H, 0x0000
JMP 0x0000
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI B, 0x00
CALL 0x0000
LHLD 0x0000
INR L
MOV A,L
CPI 0x00
JC 0x0000
MVI L, 0x00
SHLD 0x0000
LHLD 0x0000
INR L
SHLD 0x0000
LDA 0x0000
ANA A
RNZ
MOV A,M
ANI 0x00
LXI B, 0x0000
STAX B
JNZ 0x0000
LXI B, 0x0000
LXI H, 0x0000
MOV M,C
INX H
INX H
MOV M,B
RET
POP H
LDA 0x0000
STA 0x0000
LHLD 0x0000
MOV A,L
ORA H
JNZ 0x0000
DCX H
SHLD 0x0000
RET
LXI D, 0x0000
MVI A, 0x00
CALL 0x0000
LDA 0x0000
STA 0x0000
LDA 0x0000
STA 0x0000
CALL 0x0000
LDA 0x0000
ANA A
LXI H, 0x0000
JNZ 0x0000
LXI D, 0x0000
LXI H, 0x0000
MVI B, 0x00
JMP 0x0000
POP H
LDA 0x0000
ANA A
RNZ
LDA 0x0000
CPI 0x00
RNZ
LXI D, 0x0000
MVI A, 0x00
CALL 0x0000
LDA 0x0000
STA 0x0000
LDA 0x0000
STA 0x0000
CALL 0x0000
LDA 0x0000
CPI 0x00
JC 0x0000
LDA 0x0000
STA 0x0000
LDA 0x0000
ANA A
LXI H, 0x0000
JNZ 0x0000
LXI D, 0x0000
LXI H, 0x0000
MVI B, 0x00
CALL 0x0000
LDA 0x0000
DCR A
JNZ 0x0000
MVI A, 0x00
STA 0x0000
LHLD 0x0000
JMP 0x0000
POP H
LXI D, 0x0000
MVI A, 0x00
CALL 0x0000
LDA 0x0000
STA 0x0000
LDA 0x0000
STA 0x0000
CALL 0x0000
LDA 0x0000
CPI 0x00
JC 0x0000
LDA 0x0000
STA 0x0000
LDA 0x0000
ANA A
LXI H, 0x0000
JNZ 0x0000
LXI D, 0x0000
LXI H, 0x0000
MVI B, 0x00
CALL 0x0000
LHLD 0x0000
SHLD 0x0000
RET
STA 0x0000
LXI H, 0x0000
MVI B, 0x00
JMP 0x0000
LXI D, 0x0000
MVI B, 0x00
JMP 0x0000
LXI H, 0x0000
MOV A,M
ANI 0x00
ADD B
JNZ 0x0000
LDA 0x0000
CPI 0x00
LDA 0x0000
JZ 0x0000
ANA A
RZ
INX H
MVI M, 0x00
LDA 0x0000
ANA A
JZ 0x0000
MOV B,A
LDA 0x0000
CMP B
RNC
LDA 0x0000
ANA A
JZ 0x0000
MOV B,A
LDA 0x0000
CMP B
RNC
INX H
MOV A,M
ANA A
JZ 0x0000
LHLD 0x0000
MOV C,M
INX H
NOP
SHLD 0x0000
CALL 0x0000
RNC
CALL 0x0000
MOV A,C
ADI 0x00
MOV H,A
MOV A,L
SUI 0x00
MOV L,A
SHLD 0x0000
LXI H, 0x0000
MOV A,M
ORI 0x00
MOV M,A
INX H
INR M
RET
LXI D, 0x0000
CALL 0x0000
RNC
INX H
MOV A,M
ANI 0x00
LXI B, 0x0000
MVI B, 0x00
INR M
CALL 0x0000
LDA 0x0000
ADI 0x00
LXI H, 0x0000
CMP M
JC 0x0000
SUI 0x00
STA 0x0000
LDA 0x0000
MOV B,A
LDA 0x0000
ADD B
STA 0x0000
CALL 0x0000
LDA 0x0000
CPI 0x00
JC 0x0000
LDA 0x0000
ANA A
RZ
LDA 0x0000
CPI 0x00
JC 0x0000
CPI 0x00
NOP
JNC 0x0000
SUB A
STA 0x0000
LDA 0x0000
ORI 0x00
STA 0x0000
RET
LDA 0x0000
ADI 0x00
MOV H,A
CALL 0x0000
MOV A,C
CPI 0x00
JC 0x0000
MVI C, 0x00
JMP 0x0000
DCR C
LDA 0x0000
MOV H,A
MOV L,C
MVI D, 0x00
ANA A
STC
RNZ
MOV A,L
ADI 0x00
MOV L,A
DCR D
JNZ 0x0000
RET
LXI H, 0x0000
DCR M
MOV A,M
CPI 0x00
JNZ 0x0000
CALL 0x0000
LXI H, 0x0000
SHLD 0x0000
LXI H, 0x0000
DCR M
DCR M
DCX H
DCR M
DCR M
MVI A, 0x00
STA 0x0000
JMP 0x0000
ANA A
RNZ
JMP 0x0000
LXI H, 0x0000
CALL 0x0000
JMP 0x0000
LXI H, 0x0000
CALL 0x0000
JMP 0x0000
SHLD 0x0000
RET
POP H
LDA 0x0000
CPI 0x00
RNZ
LXI H, 0x0000
MOV A,M
ANA A
JZ 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
INX H
MOV A,M
ANA A
JNZ 0x0000
LDA 0x0000
CPI 0x00
JC 0x0000
MVI M, 0x00
CALL 0x0000
LXI D, 0x0000
CALL 0x0000
RNC
LXI H, 0x0000
MOV A,M
ANA A
JNZ 0x0000
LXI H, 0x0000
MOV A,M
INX H
INX H
ADD M
STA 0x0000
CALL 0x0000
LXI H, 0x0000
MOV A,M
CPI 0x00
JC 0x0000
CPI 0x00
JNC 0x0000
RET
MVI B, 0x00
CALL 0x0000
INX H
DCR M
MOV A,M
CPI 0x00
JZ 0x0000
CPI 0x00
JZ 0x0000
ANA A
RNZ
MVI B, 0x00
LXI H, 0x0000
MOV A,M
ANA B
MOV M,A
ANI 0x00
NOP
OUT 0x00
NOP
NOP
NOP
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
MVI B, 0x00
CALL 0x0000
MVI B, 0x00
JMP 0x0000
MVI A, 0x00
STA 0x0000
LHLD 0x0000
MOV B,M
MVI C, 0x00
LXI H, 0x0000
LXI D, 0x0000
LDAX D
CMP B
JZ 0x0000
INX H
INX D
DCR C
JNZ 0x0000
MOV A,M
STA 0x0000
MVI H, 0x00
MOV L,B
DAD H
DAD H
DAD H
DAD H
SHLD 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
JMP 0x0000
LXI H, 0x0000
CALL 0x0000
JMP 0x0000
MVI B, 0x00
LXI H, 0x0000
MOV A,M
ORA B
MOV M,A
CALL 0x0000
LXI H, 0x0000
SHLD 0x0000
JMP 0x0000
LXI D, 0x0000
JMP 0x0000
MVI A, 0x00
STA 0x0000
LXI SP, 0x0000
EI
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
CALL 0x0000
LDA 0x0000
DCR A
LXI H, 0x0000
MVI C, 0x00
JNZ 0x0000
LXI D, 0x0000
CALL 0x0000
IN  0x00
ANI 0x00
INR B
JZ 0x0000
MVI B, 0x00
XRA A
STA 0x0000
LDA 0x0000
ADD B
DAA
STA 0x0000
CALL 0x0000
LXI H, 0x0000
SHLD 0x0000
SHLD 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
MOV A,H
STA 0x0000
SHLD 0x0000
SHLD 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
STA 0x0000
STA 0x0000
CALL 0x0000
XRA A
STA 0x0000
STA 0x0000
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
SHLD 0x0000
SHLD 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
NOP
XRA A
STA 0x0000
CALL 0x0000
LDA 0x0000
RRC
JC 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
MVI B, 0x00
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
LDA 0x0000
ANA A
JZ 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
JZ 0x0000
MVI B, 0x00
CALL 0x0000
CALL 0x0000
OUT 0x00
CALL 0x0000
JMP 0x0000
NOP
NOP
NOP
LXI D, 0x0000
CALL 0x0000
MVI B, 0x00
IN  0x00
RRC
RRC
JC 0x0000
RRC
JC 0x0000
JMP 0x0000
MVI A, 0x00
JMP 0x0000
CALL 0x0000
JMP 0x0000
LDA 0x0000
MOV B,A
LHLD 0x0000
XCHG
JMP 0x0000
NOP
NOP
NOP
LDA 0x0000
MOV H,A
MVI L, 0x00
RET
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
CALL 0x0000
LDA 0x0000
RRC
MVI A, 0x00
LXI H, 0x0000
CNC 0x0000
MVI A, 0x00
STA 0x0000
LDA 0x0000
ANA A
RZ
ANI 0x00
INR B
JNZ 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
MVI B, 0x00
LXI H, 0x0000
LDA 0x0000
RRC
JC 0x0000
LXI H, 0x0000
CALL 0x0000
JMP 0x0000
IN  0x00
ANI 0x00
INX B
ADI 0x00
RET
LDA 0x0000
CPI 0x00
RNC
MVI A, 0x00
STA 0x0000
RET
LDA 0x0000
ANA A
RNZ
LXI H, 0x0000
MVI B, 0x00
JMP 0x0000
MVI C, 0x00
LDAX D
PUSH D
CALL 0x0000
POP D
INX D
DCR C
JNZ 0x0000
RET
LXI D, 0x0000
PUSH H
MVI H, 0x00
MOV L,A
DAD H
DAD H
DAD H
DAD D
XCHG
POP H
MVI B, 0x00
OUT 0x00
JMP 0x0000
LDA 0x0000
CPI 0x00
RNC
LHLD 0x0000
MOV A,L
ORA H
JNZ 0x0000
LXI H, 0x0000
MVI A, 0x00
STA 0x0000
DCX H
SHLD 0x0000
RET
CALL 0x0000
MVI L, 0x00
MOV A,M
RET
CALL 0x0000
DCX H
DCX H
MOV A,M
ANA A
RZ
MVI B, 0x00
IN  0x00
ANI 0x00
NOP
JZ 0x0000
MVI B, 0x00
CALL 0x0000
INX H
MOV A,M
CMP B
RC
CALL 0x0000
INR M
MOV A,M
PUSH PSW
LXI H, 0x0000
INR H
INR H
DCR A
JNZ 0x0000
MVI B, 0x00
LXI D, 0x0000
CALL 0x0000
POP PSW
INR A
CALL 0x0000
CALL 0x0000
DCX H
DCX H
MVI M, 0x00
MVI A, 0x00
STA 0x0000
MVI B, 0x00
JMP 0x0000
LXI H, 0x0000
CPI 0x00
RC
INX H
CPI 0x00
RC
INX H
RET
CALL 0x0000
LDA 0x0000
ANA A
RZ
XRA A
STA 0x0000
PUSH H
LHLD 0x0000
XCHG
POP H
MOV A,M
ADD E
DAA
MOV M,A
MOV E,A
INX H
MOV A,M
ADC D
DAA
MOV M,A
MOV D,A
INX H
MOV A,M
INX H
MOV H,M
MOV L,A
JMP 0x0000
MOV A,D
CALL 0x0000
MOV A,E
PUSH D
PUSH PSW
RRC
RRC
RRC
RRC
ANI 0x00
RRC
CALL 0x0000
POP PSW
ANI 0x00
RRC
CALL 0x0000
POP D
RET
ADI 0x00
JMP 0x0000
LDA 0x0000
RRC
LXI H, 0x0000
RC
LXI H, 0x0000
RET
LXI H, 0x0000
MVI M, 0x00
INX H
MOV A,L
ANI 0x00
RAR
CPI 0x00
JC 0x0000
LXI D, 0x0000
DAD D
MOV A,H
CPI 0x00
JC 0x0000
RET
CALL 0x0000
XRA A
STA 0x0000
CALL 0x0000
LDA 0x0000
PUSH PSW
CALL 0x0000
POP PSW
STA 0x0000
LDA 0x0000
MOV H,A
PUSH H
MVI L, 0x00
MOV A,M
ANI 0x00
RLC
INR A
MOV M,A
LXI H, 0x0000
INX H
DCR A
JNZ 0x0000
MOV A,M
POP H
MVI L, 0x00
MOV M,A
INX H
MVI M, 0x00
MOV A,H
RRC
JC 0x0000
MVI A, 0x00
STA 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
JNZ 0x0000
MVI A, 0x00
STA 0x0000
LDA 0x0000
ANA A
RZ
CALL 0x0000
JZ 0x0000
CALL 0x0000
JNZ 0x0000
RET
LDA 0x0000
CPI 0x00
RET
LDA 0x0000
ANA A
JZ 0x0000
MOV C,B
MVI B, 0x00
CALL 0x0000
MOV B,C
MOV A,B
CALL 0x0000
MOV A,M
LXI H, 0x0000
MVI M, 0x00
DCX H
MOV M,A
DCX H
MVI M, 0x00
LXI H, 0x0000
RET
MVI A, 0x00
STA 0x0000
OUT 0x00
LDA 0x0000
ANA A
JZ 0x0000
XRA A
STA 0x0000
RET
PUSH D
LDAX D
CALL 0x0000
POP D
MVI A, 0x00
STA 0x0000
LDA 0x0000
DCR A
JNZ 0x0000
INX D
DCR C
JNZ 0x0000
RET
LXI H, 0x0000
JMP 0x0000
MVI A, 0x00
JMP 0x0000
MVI A, 0x00
JMP 0x0000
POP H
JMP 0x0000
LDA 0x0000
RRC
JC 0x0000
RRC
JC 0x0000
RRC
JC 0x0000
RET
LXI H, 0x0000
MVI C, 0x00
JMP 0x0000
STA 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
RET
LXI H, 0x0000
MVI B, 0x00
JMP 0x0000
XRA A
OUT 0x00
OUT 0x00
CALL 0x0000
EI
CALL 0x0000
LDA 0x0000
ANA A
LXI H, 0x0000
MVI C, 0x00
JNZ 0x0000
LXI D, 0x0000
CALL 0x0000
LXI D, 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
LXI D, 0x0000
CALL 0x0000
CALL 0x0000
LXI D, 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
LXI D, 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
MVI B, 0x00
CALL 0x0000
CALL 0x0000
CALL 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
CALL 0x0000
STA 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
MVI A, 0x00
STA 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
OUT 0x00
CALL 0x0000
JZ 0x0000
XRA A
STA 0x0000
CALL 0x0000
JNZ 0x0000
XRA A
STA 0x0000
CALL 0x0000
CALL 0x0000
MVI C, 0x00
LXI H, 0x0000
LXI D, 0x0000
CALL 0x0000
LDA 0x0000
CPI 0x00
JNZ 0x0000
LXI H, 0x0000
MVI A, 0x00
CALL 0x0000
LXI B, 0x0000
CALL 0x0000
CALL 0x0000
IN  0x00
RLC
JC 0x0000
LXI B, 0x0000
CALL 0x0000
CALL 0x0000
LDA 0x0000
CPI 0x00
JNZ 0x0000
LXI D, 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
LXI H, 0x0000
MOV A,M
INR A
ANI 0x00
LXI B, 0x0000
SUI 0x00
JMP 0x0000
LXI D, 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
JMP 0x0000
INX D
NOP
NOP
INX D
MVI C, 0x00
STAX B
MVI C, 0x00
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
CALL 0x0000
NOP
PUSH B
PUSH H
LDAX D
OUT 0x00
IN  0x00
ORA M
MOV M,A
INX H
INX D
XRA A
OUT 0x00
IN  0x00
ORA M
MOV M,A
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
NOP
NOP
CALL 0x0000
PUSH B
PUSH H
XRA A
MOV M,A
INX H
MOV M,A
INX H
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
PUSH B
LDAX D
MOV M,A
INX D
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
CALL 0x0000
PUSH B
PUSH H
LDAX D
OUT 0x00
IN  0x00
CMA
ANA M
MOV M,A
INX H
INX D
XRA A
OUT 0x00
IN  0x00
CMA
ANA M
MOV M,A
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
MOV A,L
ANI 0x00
RLC
OUT 0x00
JMP 0x0000
PUSH B
PUSH H
MOV A,M
STAX D
INX D
INX H
DCR C
JNZ 0x0000
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
CALL 0x0000
XRA A
STA 0x0000
PUSH B
PUSH H
LDAX D
OUT 0x00
IN  0x00
PUSH PSW
ANA M
JZ 0x0000
MVI A, 0x00
STA 0x0000
POP PSW
ORA M
MOV M,A
INX H
INX D
XRA A
OUT 0x00
IN  0x00
PUSH PSW
ANA M
JZ 0x0000
MVI A, 0x00
STA 0x0000
POP PSW
ORA M
MOV M,A
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
XRA A
PUSH B
MOV M,A
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
LDA 0x0000
CPI 0x00
RZ
CPI 0x00
RNZ
LDA 0x0000
CPI 0x00
MOV B,A
JNC 0x0000
LDA 0x0000
ANA A
RZ
MOV A,B
CPI 0x00
JNC 0x0000
ADI 0x00
MOV B,A
LDA 0x0000
CPI 0x00
JNC 0x0000
CMP B
JNC 0x0000
MOV L,B
CALL 0x0000
LDA 0x0000
MOV H,A
CALL 0x0000
SHLD 0x0000
MVI A, 0x00
STA 0x0000
CALL 0x0000
MOV A,M
ANA A
JZ 0x0000
MVI M, 0x00
CALL 0x0000
CALL 0x0000
CALL 0x0000
MVI A, 0x00
STA 0x0000
RET
MVI A, 0x00
STA 0x0000
JMP 0x0000
LXI H, 0x0000
DCR M
RNZ
LHLD 0x0000
MVI B, 0x00
CALL 0x0000
MVI A, 0x00
STA 0x0000
XRA A
STA 0x0000
MVI B, 0x00
JMP 0x0000
NOP
MVI C, 0x00
CMP H
CNC 0x0000
CMP H
RNC
ADI 0x00
INR C
JMP 0x0000
LDA 0x0000
MOV H,L
CALL 0x0000
MOV B,C
DCR B
SBI 0x00
MOV L,A
RET
LDA 0x0000
CALL 0x0000
SBI 0x00
MOV H,A
RET
MVI A, 0x00
STA 0x0000
JMP 0x0000
MOV A,B
RLC
RLC
RLC
ADD B
ADD B
ADD B
ADD C
DCR A
MOV L,A
LDA 0x0000
MOV H,A
RET
INR C
ADI 0x00
JM 0x0000
RET
LDA 0x0000
ANA A
JNZ 0x0000
LXI H, 0x0000
CALL 0x0000
RNC
MVI B, 0x00
MVI A, 0x00
STA 0x0000
MOV A,B
STA 0x0000
LDA 0x0000
STA 0x0000
RET
LXI H, 0x0000
CALL 0x0000
RNC
CALL 0x0000
XRA A
JMP 0x0000
MVI B, 0x00
MOV A,M
ANA A
JNZ 0x0000
INX H
DCR B
JNZ 0x0000
RET
NOP
CALL 0x0000
PUSH H
PUSH B
PUSH H
LDAX D
OUT 0x00
IN  0x00
MOV M,A
INX H
INX D
XRA A
OUT 0x00
IN  0x00
MOV M,A
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
POP H
RET
CALL 0x0000
LXI B, 0x0000
MOV A,M
ANA A
JZ 0x0000
INR C
INX H
DCR B
JNZ 0x0000
MOV A,C
STA 0x0000
CPI 0x00
RNZ
LXI H, 0x0000
MVI M, 0x00
RET
MVI L, 0x00
LDA 0x0000
MOV H,A
RET
LDA 0x0000
CPI 0x00
RNZ
LXI H, 0x0000
MOV A,M
INX H
MOV B,M
ORA B
RNZ
LDA 0x0000
ANA A
RNZ
LDA 0x0000
ANA A
JZ 0x0000
LDA 0x0000
ANA A
JNZ 0x0000
CALL 0x0000
ANI 0x00
NOP
RZ
MVI A, 0x00
STA 0x0000
STA 0x0000
RET
CALL 0x0000
ANI 0x00
NOP
RNZ
STA 0x0000
RET
LXI H, 0x0000
MVI M, 0x00
LHLD 0x0000
INX H
MOV A,L
CPI 0x00
JC 0x0000
MVI L, 0x00
SHLD 0x0000
MOV A,M
STA 0x0000
RET
STC
RET
XRA A
CALL 0x0000
CALL 0x0000
MVI M, 0x00
CALL 0x0000
INX H
LXI D, 0x0000
LDAX D
CMP M
DCX D
DCX H
LDAX D
JZ 0x0000
JNC 0x0000
JMP 0x0000
CMP M
JNC 0x0000
MOV A,M
STAX D
INX D
INX H
MOV A,M
STAX D
CALL 0x0000
LDA 0x0000
ANA A
JZ 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
CALL 0x0000
DCR H
DCR H
MVI B, 0x00
LDA 0x0000
RRC
JC 0x0000
MVI B, 0x00
MOV A,B
CALL 0x0000
CALL 0x0000
CALL 0x0000
MOV A,M
ANA A
JZ 0x0000
JMP 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
CALL 0x0000
CALL 0x0000
CALL 0x0000
XRA A
STA 0x0000
OUT 0x00
CALL 0x0000
JMP 0x0000
LXI SP, 0x0000
EI
XRA A
STA 0x0000
CALL 0x0000
MVI B, 0x00
CALL 0x0000
CALL 0x0000
JNZ 0x0000
CALL 0x0000
LXI H, 0x0000
CALL 0x0000
XRA A
CALL 0x0000
MVI B, 0x00
JMP 0x0000
CALL 0x0000
INX H
MOV A,M
LXI D, 0x0000
LXI H, 0x0000
MVI C, 0x00
MOV B,A
LDAX D
CMP B
JNC 0x0000
INX H
INX D
DCR C
JNZ 0x0000
MOV A,M
STA 0x0000
RET
LDA 0x0000
CPI 0x00
JNZ 0x0000
MVI B, 0x00
JMP 0x0000
MVI B, 0x00
JMP 0x0000
NOP
NOP
LXI H, 0x0000
DCR M
CZ 0x0000
LDA 0x0000
ANA A
JZ 0x0000
LXI H, 0x0000
DCR M
RNZ
LXI H, 0x0000
MOV A,M
OUT 0x00
LDA 0x0000
ANA A
JZ 0x0000
DCX H
MOV A,M
DCX H
MOV M,A
DCX H
MVI M, 0x00
MVI A, 0x00
STA 0x0000
RET
LDA 0x0000
ANI 0x00
NOP
OUT 0x00
RET
LDA 0x0000
ANA A
JZ 0x0000
LXI H, 0x0000
LXI D, 0x0000
LDA 0x0000
CMP M
JNC 0x0000
INX H
INX D
JMP 0x0000
LDAX D
STA 0x0000
LXI H, 0x0000
MOV A,M
ANI 0x00
NOP
MOV B,A
MOV A,M
ANI 0x00
RRC
RLC
CPI 0x00
JNZ 0x0000
MVI A, 0x00
ORA B
MOV M,A
XRA A
STA 0x0000
LXI H, 0x0000
DCR M
RNZ
MVI B, 0x00
JMP 0x0000
MVI B, 0x00
LXI H, 0x0000
MOV A,M
ANA B
MOV M,A
OUT 0x00
RET
NOP
LDA 0x0000
RRC
JNC 0x0000
IN  0x00
RET
IN  0x00
RET
IN  0x00
ANI 0x00
INR B
RZ
LDA 0x0000
ANA A
RNZ
LXI SP, 0x0000
MVI B, 0x00
CALL 0x0000
DCR B
JNZ 0x0000
MVI A, 0x00
STA 0x0000
CALL 0x0000
EI
LXI D, 0x0000
LXI H, 0x0000
MVI C, 0x00
CALL 0x0000
CALL 0x0000
XRA A
STA 0x0000
STA 0x0000
JMP 0x0000
LXI H, 0x0000
MOV A,M
ANA A
JZ 0x0000
INX H
MOV A,M
ANA A
RNZ
MVI B, 0x00
JMP 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
CALL 0x0000
MVI A, 0x00
STA 0x0000
LXI B, 0x0000
CALL 0x0000
JC 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
LXI B, 0x0000
CALL 0x0000
RC
CALL 0x0000
JMP 0x0000
PUSH B
MVI B, 0x00
CALL 0x0000
POP B
RET
PUSH B
LDA 0x0000
MOV C,A
CALL 0x0000
POP B
RET
LDAX B
CPI 0x00
STC
RZ
MOV L,A
INX B
LDAX B
MOV H,A
INX B
LDAX B
MOV E,A
INX B
LDAX B
MOV D,A
INX B
ANA A
RET
LXI H, 0x0000
INR M
INX H
MOV C,M
CALL 0x0000
MOV B,A
LDA 0x0000
CMP B
JZ 0x0000
LDA 0x0000
ANI 0x00
INR B
LHLD 0x0000
JNZ 0x0000
LXI D, 0x0000
DAD D
SHLD 0x0000
LXI H, 0x0000
CALL 0x0000
XCHG
JMP 0x0000
NOP
NOP
NOP
MVI A, 0x00
STA 0x0000
RET
LXI H, 0x0000
LXI D, 0x0000
MVI B, 0x00
CALL 0x0000
MVI A, 0x00
STA 0x0000
MVI A, 0x00
STA 0x0000
MVI A, 0x00
STA 0x0000
LDA 0x0000
ANI 0x00
LXI B, 0x0000
NOP
LDA 0x0000
ANI 0x00
LXI B, 0x0000
NOP
LXI H, 0x0000
MVI A, 0x00
NOP
CALL 0x0000
JMP 0x0000
LXI SP, 0x0000
MVI B, 0x00
CALL 0x0000
CALL 0x0000
MVI A, 0x00
STA 0x0000
JMP 0x0000
LDA 0x0000
LXI H, 0x0000
RRC
RNC
INX H
RET
MVI B, 0x00
LDA 0x0000
DCR A
RNZ
INR B
RET
LDA 0x0000
ORA B
STA 0x0000
OUT 0x00
RET
LXI H, 0x0000
JMP 0x0000
CALL 0x0000
JMP 0x0000
LXI H, 0x0000
LDA 0x0000
RRC
RC
INX H
RET
MVI C, 0x00
LXI H, 0x0000
LXI D, 0x0000
JMP 0x0000
LXI H, 0x0000
JMP 0x0000
LXI H, 0x0000
JMP 0x0000
MOV E,M
INX H
MOV D,M
INX H
MOV A,M
INX H
MOV H,M
MOV L,A
JMP 0x0000
MVI C, 0x00
LXI H, 0x0000
LXI D, 0x0000
JMP 0x0000
LDA 0x0000
LXI H, 0x0000
JMP 0x0000
LXI H, 0x0000
JMP 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
CALL 0x0000
JMP 0x0000
MVI A, 0x00
STA 0x0000
JMP 0x0000
CALL 0x0000
CALL 0x0000
JMP 0x0000
STA 0x0000
RET
ADC E
DAD D
JMP 0x0000
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
JMP 0x0000
NOP
NOP
NOP
NOP
LDA 0x0000
ANA A
JNZ 0x0000
IN  0x00
ANI 0x00
HLT
SUI 0x00
RNZ
INR A
STA 0x0000
IN  0x00
ANI 0x00
HLT
CPI 0x00
RNZ
LXI H, 0x0000
LXI D, 0x0000
MVI C, 0x00
JMP 0x0000
NOP
INX D
NOP
NOP
INX D
MVI C, 0x00
STAX B
MVI C, 0x00
RRC
MVI C, 0x00
NOP
INX D
NOP
MVI C, 0x00
NOP
MVI A, 0x00
STA 0x0000
RET
XRA A
JMP 0x0000
NOP
LDA 0x0000
ANA B
STA 0x0000
OUT 0x00
RET
LXI H, 0x0000
JZ 0x0000
LXI D, 0x0000
MVI B, 0x00
MOV C,A
CALL 0x0000
MOV A,C
DCR A
JNZ 0x0000
MVI B, 0x00
CALL 0x0000
MOV A,H
CPI 0x00
JNZ 0x0000
RET
LXI H, 0x0000
MOV B,M
LDAX D
ANI 0x00
ADD B
XRA B
RNZ
STC
RET
STA 0x0000
INR E
MVI D, 0x00
LDAX B
NOP
RLC
MVI B, 0x00
INR B
INX B
STAX B
LXI B, 0x0000
DAA
SHLD 0x0000
DCR D
INX D
NOP
MVI C, 0x00
INR C
DCX B
DAD B
RLC
DCR B
RST 7
LDAX D
MOV M,A
INX H
INX D
DCR B
JNZ 0x0000
RET
MOV E,M
INX H
MOV D,M
INX H
MOV A,M
INX H
MOV C,M
INX H
MOV B,M
MOV H,C
MOV L,A
RET
PUSH B
MVI B, 0x00
MOV A,H
RAR
MOV H,A
MOV A,L
RAR
MOV L,A
DCR B
JNZ 0x0000
MOV A,H
ANI 0x00
CMC
ORI 0x00
MOV H,A
POP B
RET
LXI H, 0x0000
MVI M, 0x00
INX H
MOV A,H
CPI 0x00
JNZ 0x0000
RET
PUSH B
PUSH H
LDAX D
ORA M
MOV M,A
INX D
INX H
DCR C
JNZ 0x0000
POP H
LXI B, 0x0000
DAD B
POP B
DCR B
JNZ 0x0000
RET
CALL 0x0000
ANA A
RZ
PUSH PSW
DCR A
MOV M,A
CALL 0x0000
POP PSW
LXI H, 0x0000
ANI 0x00
RRC
JMP 0x0000
NOP
NOP
NOP
NOP
RST 7
CMP B
CPI 0x00
INR E
NOP
SBB M
NOP
NOP
INR E
NOP
NOP
DCX B
NOP
RLC
MVI B, 0x00
INR C
INR B
MVI H, 0x00
DCR D
INR B
LXI D, 0x0000
RRC
DCX B
NOP
NOP
INR B
LXI D, 0x0000
DCR H
DCX D
MVI H, 0x00
LXI D, 0x0000
RRC
DCX B
NOP
NOP
INR B
LXI D, 0x0000
LXI B, 0x0000
INX D
MVI C, 0x00
MVI H, 0x00
DCR C
DCX B
NOP
MVI H, 0x00
RRC
DCX B
NOP
NOP
INR B
LXI D, 0x0000
LXI B, 0x0000
INX D
MVI C, 0x00
MVI H, 0x00
STAX D
STAX B
MVI C, 0x00
INR B
INR H
DCX D
DCR H
MVI H, 0x00
NOP
CMC
STAX D
STAX B
MVI C, 0x00
INR B
MVI H, 0x00
STAX B
MVI C, 0x00
INR B
INR H
INR E
DCR H
MVI H, 0x00
NOP
NOP
NOP
NOP
NOP
NOP
NOP
STAX B
MOV A,B
NOP
MOV A,B
NOP
NOP
RM
NOP
NOP
ADD B
NOP
ADC M
STAX B
RST 7
DCR B
INR C
MOV H,B
INR E
NOP
NOP
NOP
LXI B, 0x0000
NOP
NOP
NOP
CMP E
INX B
NOP
NOP
SUB B
INR E
NOP
NOP
LXI B, 0x0000
RST 7
RST 7
NOP
NOP
STAX B
HLT
INR B
NOP
NOP
NOP
NOP
NOP
INR B
XRI 0x00
NOP
NOP
INX B
NOP
NOP
NOP
ORA M
INR B
NOP
NOP
LXI B, 0x0000
INR B
JPO 0x0000
NOP
INX B
NOP
NOP
NOP
ADD D
MVI B, 0x00
NOP
LXI B, 0x0000
INR B
RNC
INR E
NOP
NOP
INX B
RST 7
NOP
RNZ
INR E
NOP
NOP
NOP
LXI H, 0x0000
NOP
NOP
STAX D
NOP
NOP
NOP
RRC
DCX B
NOP
NOP
MVI H, 0x00
DCX B
NOP
NOP
INR B
LXI D, 0x0000
DCR H
CM 0x0000
RST 7
RST 7
NOP
NOP
NOP
NOP
MOV H,H
DCR E
RNC
DAD H
NOP
STAX B
MOV D,H
DCR E
NOP
NOP
NOP
MVI B, 0x00
NOP
LXI B, 0x0000
LXI B, 0x0000
NOP
SBB M
NOP
NOP
INR E
NOP
INX B
INR B
MOV A,B
INR D
INX D
NOP
LDAX D
DCR A
MOV L,B
CM 0x0000
DCR A
LDAX D
NOP
NOP
NOP
LXI B, 0x0000
ANA B
DCX D
NOP
RST 7
NOP
ANA B
DCX D
NOP
NOP
NOP
NOP
NOP
NOP
NOP
MVI C, 0x00
NOP
NOP
NOP
NOP
NOP
RLC
RNC
INR E
RZ
SBB E
INX B
NOP
NOP
INX B
INR B
MOV A,B
INR D
DCX B
DAD D
LDA 0x0000
JM 0x0000
DAD D
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
LXI B, 0x0000
LXI B, 0x0000
NOP
ADD B
NOP
NOP
NOP
NOP
NOP
INR E
CMA
NOP
NOP
INR E
DAA
NOP
NOP
INR E
DAD SP
NOP
NOP
DAD SP
MOV A,C
MOV A,D
MOV L,M
CPE 0x0000
CPE 0x0000
MOV A,C
DAD SP
NOP
NOP
NOP
NOP
NOP
MOV A,B
DCR E
CMP M
MOV L,H
INR A
INR A
INR A
MOV L,H
CMP M
DCR E
MOV A,B
NOP
NOP
NOP
NOP
NOP
NOP
DAD D
LDA 0x0000
JM 0x0000
DAD D
NOP
NOP
NOP
NOP
NOP
NOP
NOP
MOV A,D
MOV A,A
MOV L,L
CPE 0x0000
CPE 0x0000
MOV A,D
NOP
NOP
NOP
NOP
NOP
NOP
MVI C, 0x00
CMP M
MOV L,L
DCR A
INR A
DCR A
MOV L,L
CMP M
NOP
MVI C, 0x00
NOP
NOP
NOP
NOP
NOP
LDAX D
DCR A
MOV L,B
CM 0x0000
DCR A
LDAX D
NOP
NOP
NOP
NOP
NOP
NOP
RRC
RAR
RAR
RAR
RAR
MOV A,A
RST 7
MOV A,A
RAR
RAR
RAR
RAR
RRC
NOP
NOP
INR B
LXI B, 0x0000
RLC
ORA E
RRC
CMA
INX B
CMA
MOV C,C
INR B
INX B
NOP
LXI B, 0x0000
DCR B
ANA E
LDAX B
INX B
MOV E,E
RRC
DAA
DAA
DCX B
MOV C,E
MOV B,B
ADD H
LXI D, 0x0000
SBB C
INR A
MOV A,M
DCR A
CMP H
MVI A, 0x00
SBB C
DAA
DCX D
LDAX D
MVI H, 0x00
MVI C, 0x00
DCR C
INX D
STAX D
NOP
STAX D
STAX B
MVI C, 0x00
INR B
MVI H, 0x00
INX B
DCR D
NOP
DCR C
STAX B
INR B
MVI H, 0x00
NOP
LXI B, 0x0000
NOP
STAX B
NOP
NOP
NOP
INX D
NOP
DCX B
INX D
NOP
NOP
MOV C,C
SHLD 0x0000
MOV B,D
NOP
MOV B,D
ADD C
INR D
SHLD 0x0000
NOP
NOP
MOV B,H
XRA D
NOP
ADC B
MOV D,H
SHLD 0x0000
MOV B,H
SHLD 0x0000
MOV C,D
DCR D
CMP M
CMC
MOV E,M
DCR H
INR B
CM 0x0000
CM 0x0000
CM 0x0000
CM 0x0000
CPI 0x00
INR H
CPI 0x00
NOP
CPI 0x00
MOV C,B
CPI 0x00
RRC
DCX B
NOP
DAD H
NOP
NOP
LXI B, 0x0000
LXI B, 0x0000
DCX B
LXI B, 0x0000
LXI B, 0x0000
DAD B
STAX B
NOP
STAX B
DCX B
INR B
RLC
LDAX B
DCR B
STAX B
DCR B
INR B
MVI B, 0x00
NOP
LDAX B
MVI B, 0x00
INX B
RST 7
RRC
RST 7
RAR
RST 7
CMC
RST 7
MOV A,A
RST 7
RST 7
CM 0x0000
RST 7
RP
RST 7
RP
RST 7
RP
RST 7
RP
RST 7
RP
RST 7
RP
RST 7
RP
RST 7
RM
RST 7
CM 0x0000
RST 7
RST 7
RST 7
RST 7
MOV A,A
RST 7
CMC
RST 7
RAR
RST 7
RRC
DCR B
NOP
DCR D
NOP
SUB H
SUB A
SBB D
SBB L
NOP
DCR B
DCR B
NOP
DCR D
NOP
NOP
DCR B
NOP
NOP
NOP
NOP
DCR B
DCR D
NOP
DCR B
NOP
NOP
NOP
NOP
INR B
INR C
MVI E, 0x00
MVI A, 0x00
MOV M,H
MOV A,M
MOV A,M
MOV M,H
MOV A,H
MVI A, 0x00
MVI E, 0x00
INR B
NOP
NOP
NOP
NOP
NOP
SHLD 0x0000
MOV B,B
NOP
SBB B
DCR A
ORA M
INR A
MVI M, 0x00
NOP
MOV C,B
MOV H,D
ORA M
DCR E
SBB B
NOP
MOV B,D
SUB B
NOP
NOP
NOP
MVI H, 0x00
LDAX D
DCX D
LDAX D
LDAX D
DCX D
RAR
LDAX D
DCR E
LDAX D
LDAX D
NOP
NOP
NOP
MOV H,B
MOV D,B
MOV C,B
MOV C,B
MOV C,B
MOV B,B
MOV B,B
MOV B,B
RRC
DCX B
NOP
NOP
STAX D
RRC
NOP
STAX B
INR B
MVI H, 0x00
NOP
DCR C
DCR D
NOP
INX B
INR B
LXI D, 0x0000
INR L
MOV L,B
DCR E
INR C
INR L
NOP
INR E
LDAX B
INR L
MOV B,B
INR E
NOP
INR L
NOP
INR E
RST 7
MVI C, 0x00
RPO
DCR E
INR C
MVI L, 0x00
DCR E
LDAX B
MVI L, 0x00
DCR E
NOP
MVI L, 0x00
INR E
RST 7
DAA
NOP
MVI H, 0x00
NOP
STAX D
INX D
INR B
LXI D, 0x0000
DCR E
LDAX D
MVI H, 0x00
MVI C, 0x00
DCR C
INX D
STAX D
DAA
INR E
LDAX D
MVI H, 0x00
MVI C, 0x00
DCR C
INX D
STAX D
NOP
NOP
NOP
RAR
INR H
MOV B,H
INR H
RAR
NOP
NOP
NOP
MOV A,A
MOV C,C
MOV C,C
MOV C,C
MVI M, 0x00
NOP
NOP
MVI A, 0x00
MOV B,C
MOV B,C
SHLD 0x0000
NOP
MOV A,A
MOV B,C
MOV B,C
MOV B,C
MVI A, 0x00
NOP
NOP
MOV A,A
MOV C,C
MOV C,C
MOV C,C
MOV B,C
NOP
NOP
NOP
MOV A,A
MOV C,B
MOV C,B
MOV C,B
MOV B,B
NOP
NOP
NOP
MVI A, 0x00
MOV B,C
MOV B,L
MOV B,A
NOP
NOP
NOP
MOV A,A
NOP
NOP
NOP
MOV A,A
NOP
NOP
NOP
NOP
MOV B,C
MOV A,A
MOV B,C
NOP
NOP
NOP
NOP
STAX B
LXI B, 0x0000
MOV A,M
NOP
NOP
NOP
MOV A,A
NOP
INR D
SHLD 0x0000
NOP
NOP
MOV A,A
LXI B, 0x0000
LXI B, 0x0000
NOP
MOV A,A
NOP
NOP
NOP
MOV A,A
NOP
NOP
NOP
MOV A,A
NOP
NOP
INR B
MOV A,A
NOP
NOP
NOP
MVI A, 0x00
MOV B,C
MOV B,C
MVI A, 0x00
NOP
NOP
MOV A,A
MOV C,B
MOV C,B
MOV C,B
NOP
NOP
NOP
NOP
MVI A, 0x00
MOV B,L
MOV B,D
DCR A
NOP
NOP
NOP
MOV A,A
MOV C,B
MOV C,H
MOV C,D
LXI SP, 0x0000
NOP
STA 0x0000
MOV C,C
MVI H, 0x00
NOP
NOP
MOV B,B
MOV B,B
MOV A,A
MOV B,B
MOV B,B
NOP
NOP
NOP
MOV A,M
LXI B, 0x0000
MOV A,M
NOP
NOP
NOP
MOV A,H
STAX B
LXI B, 0x0000
NOP
NOP
NOP
MOV A,A
STAX B
INR C
STAX B
MOV A,A
NOP
NOP
NOP
MOV H,E
INR D
NOP
INR D
MOV H,E
NOP
NOP
NOP
MOV H,B
NOP
RRC
NOP
MOV H,B
NOP
NOP
NOP
MOV B,E
MOV B,L
MOV C,C
MOV D,C
MOV H,C
NOP
NOP
NOP
MVI A, 0x00
MOV C,C
MOV D,C
MVI A, 0x00
NOP
NOP
NOP
LXI H, 0x0000
NOP
NOP
NOP
NOP
INX H
MOV B,L
MOV C,C
MOV C,C
LXI SP, 0x0000
NOP
MOV B,D
MOV B,C
MOV C,C
MOV E,C
MOV H,M
NOP
NOP
NOP
INR C
INR D
INR H
MOV A,A
INR B
NOP
NOP
NOP
MOV M,D
MOV D,C
MOV D,C
MOV D,C
MOV C,M
NOP
NOP
NOP
MVI E, 0x00
MOV C,C
MOV C,C
MOV B,M
NOP
NOP
NOP
MOV B,B
MOV B,A
MOV C,B
MOV D,B
MOV H,B
NOP
NOP
NOP
MVI M, 0x00
MOV C,C
MOV C,C
MVI M, 0x00
NOP
NOP
LXI SP, 0x0000
MOV C,D
INR A
NOP
NOP
NOP
NOP
INR D
SHLD 0x0000
NOP
NOP
NOP
NOP
MOV B,C
SHLD 0x0000
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
INR D
INR D
INR D
INR D
INR D
NOP
NOP
NOP
SHLD 0x0000
INR D
SHLD 0x0000
NOP
INX B
INR B
MOV A,B
INR B
INX B
NOP
NOP
INR H
DCX D
MVI H, 0x00
LXI D, 0x0000
MVI H, 0x00
DCX B
NOP
NOP
INR B
LXI D, 0x0000
MVI H, 0x00
NOP
DCX D
MVI H, 0x00
DCX B
NOP
NOP
INR B
LXI D, 0x0000
DCX D
MVI H, 0x00
MVI C, 0x00
DCR C
MVI H, 0x00
LXI B, 0x0000
LXI B, 0x0000
LXI B, 0x0000
LXI B, 0x0000
NOP
RRC
NOP
MOV H,B
NOP
NOP
LDAX D
DCR A
MOV L,B
CM 0x0000
DCR A
LDAX D
NOP
NOP
DCR C
STAX D
INR B
LXI D, 0x0000
MVI H, 0x00
MVI C, 0x00
DCR C
DCR C
LHLD 0x0000
LDAX B
LHLD 0x0000
RLC
LHLD 0x0000
RST 7
STAX B
LXI D, 0x0000
NOP
INX D
MVI H, 0x00
MOV H,B
NOP
RRC
NOP
MOV H,B
NOP
DAD D
LDA 0x0000
JM 0x0000
DAD D
NOP
NOP
NOP
MOV B,B
MOV C,L
MOV D,B
NOP
NOP
NOP
NOP
NOP
NOP
RST 7
CMP B
RST 7
ADD B
RAR
NOP
SUB A
NOP
ADD B
RAR
NOP
NOP
LXI B, 0x0000
NOP
INR E
NOP
SUB H
NOP
NOP
INR E
NOP
INR E
MVI H, 0x00
DCX B
NOP
NOP
INR B
LXI D, 0x0000
INR E
MVI H, 0x00
MVI C, 0x00
DCR C
STAX D
RRC
INR D
STAX D
RLC
MVI H, 0x00
NOP
NOP
NOP
NOP
NOP
NOP
NOP

	AREA knapsack_recursive, CODE, READONLY
	ENTRY
	ALIGN
__main FUNCTION
	export __main
	MOVS R0, #0             ; value to be returned
	LDR R1, =profit         ; address of profit array
	LDR R2, =weight         ; address of weight array
	MOVS R3, #0             ; current index
	MOVS R4, #50            ; current weight
	MOVS R5, #0             ; index * 4
	MOVS R6, #0             ; returned value from recursive call
	MOVS R7, #0             ; profit[i] and weight[i]
	BL knapsack
	
stop B stop

knapsack
	push {LR}
	push {R3, R4}
	
	CMP R3, #3
	BEQ base_case
	CMP R2, #0
	BEQ base_case
	
	MOVS R0, #0
	
	ADDS R3, R3, #1 
	BL knapsack 

	POP {R3, R4}
	
	LSLS R5, R3, #2
	LDR R7, [R2, R5]
	
	CMP R4, R7               
	BCC ret
	
	push {R0}	
	push {R3, R4}
	
	ADDS R3, R3, #1
	SUBS R4, R4, R7
	BL knapsack
	
	POP {R3, R4}
	POP {R6}
	
	LSLS R5, R3, #2
	LDR R7, [R1, R5]
	ADDS R0, R0, R7
	
	CMP R6, R0
	BCC ret
	MOVS R0, R6
ret
	POP {PC}
	
base_case 
	MOVS R0, #0
	POP {R3, R4}
	POP {PC}

weight DCD 10, 20, 30
profit DCD 60, 100, 120
	
	ENDFUNC
	END
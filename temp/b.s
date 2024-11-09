ArraySize	EQU 0x32
	AREA dp_array, DATA, READWRITE
	ALIGN
dp	SPACE	ArraySize
dp_end

	AREA knapsack_recursive, CODE, READONLY
    ENTRY
    ALIGN
__main FUNCTION
	EXPORT __main
	MOVS R0, #0             ; value to be returned
	LDR R1, =profit         ; address of profit array
	LDR R2, =weight         ; address of weight array
    LDR R3, =dp            ; address of dp array
	MOVS R4, #0             ; current i
	MOVS R5, #0             ; current w
    MOVS R6, #0             ; index * 4
    MOVS R7, #0             ; a value in array
	BL knapsack

stop B stop

knapsack
    MOVS R5, #50
    CMP R4, #3
    BEQ ret
 
inner
    CMP R5, #0
    BLT end_outer

    LSLS R6, R4, #2             ; i * 4
    LDR R7, [R2, R6]            ; weight[i]

    CMP R7, R5                  ; weight[i] >? w
    BGT end_outer               ; since w is getting smaller, no need to continue the inner loop

    LSLS R6, R5, #2
    LDR R0, [R3, R6]            ; R0 = dp[w]

    LSLS R6, R4, #2             ; i * 4
    LDR R7, [R2, R6]            ; weight[i]
    SUBS R6, R5, R7             ; w - weight[i]
	LSLS R6, #2
    LDR R7, [R3, R6]            ; dp[w - weight[i]]
    
    LSLS R6, R4, #2             ; i * 4
    LDR R6, [R1, R6]            ; profit[i]

    ADDS R7, R6                 ; dp[w - weight[i]] + profit[i]
    
    CMP R7, R0                  ; max(dp[w], dp[w - weight[i]] + profit[i])
    BLE end_inner

    LSLS R6, R5, #2             ; i * 4
    STR R7, [R3, R6]            ; dp[w] = dp[w - weight[i]] + profit[i]

end_inner
    SUBS R5, #1
    BL inner

end_outer
    ADDS R4, #1
    BL knapsack
ret
	LSLS R5, #2
	LDR R0, [R3, R5]
	BL stop
	
weight DCD 10, 20, 30
profit DCD 60, 100, 120
	
	ENDFUNC
    END
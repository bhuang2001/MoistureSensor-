;    LIST	p=16f18877
;    INCLUDE <P16F18877.inc>
;;FOSC = 2MHz, Period = 1/2MHz = 0.5microseconds
;;1 instruction cycle = 4 Q cycles = 4 x 0.5 microseconds = 2microseconds
;;Creating a 1 second delay hence
;;1000 000/2 = 500 000
;;There are 5 instruction cycles per loop hence 500 000/5 = 100 000
;; We need the delay to loop 100 000 times to delay 1 second
;; let c1 = 250
;; 100 000/250 = 400
;; let c2 = 200;
;; 400/200 = 2
;; Hence c3 = 2;
;
;    
;		    ; 0x20 and onwards are general purpose registers
;c1 EQU 0x20
;c2 EQU 0x21
;c3 EQU 0x22
;
;    
;    
;    ORG 0x00
;    goto main 
;    ORG 0X10
;    
;main
; 
;delay1s movlw d'2'
;	movwf c3
;
;loop2
;	    movlw d'200'
;	    movwf c2
;    
;loop1   movlw d'250'
;	    movwf c1
;	
;loop		    	;once c1 becomes 0, c2 will decrement
;	nop		; 1 instruction cycle
;	nop		; 1 instruction cycle
;	decfsz c1,F	; decrement c1 until it becomes 0 
;	goto  loop	;
;			
;	
;	decfsz c2,F	; decrement c2 which only occurs when c1 decreases to 0
;	goto loop1	; goes back to loop1 which will repeat loop and c1 is 250
;	
;	decfsz c3,F	; decrement c3 only when c2 decreases to 0
;	goto loop2	; goes back to loop2 and sets c2 back to 200
;	
;	return		; when c3 decreases to 0, return and program should delay
;			; 1 second
;
;END

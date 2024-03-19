	PRESERVE8
	THUMB   
		
	export GestionSon_callback
	import LongueurSon
	import Son
	import PeriodeSonMicroSec

; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite	
GestionSon_Index dcd 0x0000
SortieSon dcw 0x0000
	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		


GestionSon_callback proc
	push {R4,R5}
	
	ldr R3,=Son
	ldr R2,=LongueurSon
	ldr R1,=GestionSon_Index
	ldr R0,[R1]
	ldr R2,[R2]

; Condition de fin d'exécution (sortie du tableau)
	cmp R0,R2
	beq fin_exe
	
; Règle de trois 
	mov R4,#65536
	mov R5,#720
	
	ldrsh R3,[R3,R0, lsl #1] ;Récupération de la valeur du tableau
	add R3,#32768 ; Passage de la valeur entre 0 et 65536
	mul R3,R5 ; Règle de trois
	udiv R3,R4 ; Règle de trois
	
	ldr R4,=SortieSon ; Adresse de la variable SortieSon
	str R3,[R4] ; Stockage de la valeur à émettre
	
	add R0,#0x0001 ; Incrémentation de l'indice
	str R0,[R1] ; Incrémentation de l'indice
	
fin_exe
	pop {R4,R5}
	
	bx lr
	ENDP
	
		
		
	END	
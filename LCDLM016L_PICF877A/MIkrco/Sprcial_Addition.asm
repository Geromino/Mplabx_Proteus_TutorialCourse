
_main:

;Sprcial_Addition.c,25 :: 		void main() {
;Sprcial_Addition.c,26 :: 		Lcd_Init();
	CALL       _Lcd_Init+0
;Sprcial_Addition.c,27 :: 		Lcd_cmd(_LCD_CLEAR);
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Sprcial_Addition.c,29 :: 		Lcd_out(1,1,"Subscribe Electroniks Day");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_Sprcial_Addition+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Sprcial_Addition.c,30 :: 		Delay_ms(500);
	MOVLW      13
	MOVWF      R11+0
	MOVLW      175
	MOVWF      R12+0
	MOVLW      182
	MOVWF      R13+0
L_main0:
	DECFSZ     R13+0, 1
	GOTO       L_main0
	DECFSZ     R12+0, 1
	GOTO       L_main0
	DECFSZ     R11+0, 1
	GOTO       L_main0
	NOP
;Sprcial_Addition.c,32 :: 		for(i=0; i<10; i++){
	CLRF       _i+0
L_main1:
	MOVLW      10
	SUBWF      _i+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_main2
;Sprcial_Addition.c,33 :: 		lcd_cmd(_lcd_shift_left);
	MOVLW      24
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Sprcial_Addition.c,34 :: 		delay_ms(250);
	MOVLW      7
	MOVWF      R11+0
	MOVLW      88
	MOVWF      R12+0
	MOVLW      89
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;Sprcial_Addition.c,32 :: 		for(i=0; i<10; i++){
	INCF       _i+0, 1
;Sprcial_Addition.c,36 :: 		}
	GOTO       L_main1
L_main2:
;Sprcial_Addition.c,38 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

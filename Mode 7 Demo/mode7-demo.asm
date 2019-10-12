!src "vera-module.inc"
!cpu 65c02

*=$0801

          ; Place BASIC "1 SYS2061" at program start
          ;         1   0 SYS   2   0   6   1 (2061 = $80d)
!byte     $0d,$08,$01,$00,$9e,$32,$30,$36,$31,$00,$00,$00

          +vgaInit

          ; Set 20-bit VERA_ADDR to start of video RAM - preserve Increment register
          +vSet VREG_VIDEO_RAM | ADDR_INC_1

          ; Load bitmap - Offset stored in zero page $2, $3
          ldx #136 ; 34,816 bytes = 136 x 256
          ldy #0
          lda #<bitmap
          sta $2
          lda #>bitmap
          sta $3
bitLoop:  lda ($2),y
          ; Every time we store to a DATA port, VERA_ADDR is automatically incremented
          sta VERA_DATA_0
          iny
          bne bitLoop
          inc $3
          dex
          bne bitLoop

          ; Set 20-bit VERA_ADDR to start of the palette - preserve Increment register
          +vSet VREG_PALETTE | ADDR_INC_1

          ; Load palette - Offset stored in zero page $2, $3
          ldx #2
          ldy #0
          lda #<palette
          sta $2
          lda #>palette
          sta $3
palLoop:  lda ($2),y
          ; Every time we store to a DATA port, VERA_ADDR is automatically incremented
          sta VERA_DATA_0
          iny
          bne palLoop
          inc $3
          dex
          bne palLoop

          ; Set 20-bit VERA_ADDR to start of Layer 0 Ctrl 0 register - preserve Increment register
          +vSet VREG_LAYER_0_CTRL0 | ADDR_INC_1

          lda #MODE_7_BMAP_8 << 5 | ENABLE  ; Set 8 bpp (256 color) bitmap mode
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_LAYER_0_CTRL0
          
          ; Every time we store to a DATA port, VERA_ADDR is automatically incremented
          
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_LAYER_0_CTRL1      ignored
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_LAYER_0_MAP_BASE_L ignored
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_LAYER_0_MAP_BASE_H ignored
          
          lda #(0 >> 2) & 0xff;
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_LAYER_0_BMAP_BASE_L
          lda #0 >> 10;
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_LAYER_0_BMAP_BASE_H

          +vSet VREG_DC + 1 | ADDR_INC_1

          lda #DC_SCALE_X2
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_DC_HSCALE
          sta VERA_DATA_0 ; VERA_ADDR -> VREG_DC_VSCALE

          jmp *

bitmap:
!bin      "mode7-bitmap.bin"

palette:
!bin      "mode7-palette.bin"
!bin      "mode7-palette.bin"
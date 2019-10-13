; ===========================================================================================
; VERA Includes - Jon Dearden
; Version 1.0 - October 2019
;
; Adapted from https://github.com/commanderx16/x16-demo/blob/master/assembly/vera.inc
; See https://github.com/commanderx16/x16-docs/blob/master/VERA%20Programmer's%20Reference.md
; ===========================================================================================

; ---------------------------
; External address space
; (visible to the CPU)
; ---------------------------
                                
VERA_BASE     = $9f20

VERA_ADDR_LO  = VERA_BASE       ; Address ([7-0])                             20-bit internal address
VERA_ADDR_MID = VERA_BASE + 1   ; Address ([15-8])                            20-bit internal address
VERA_ADDR_HI  = VERA_BASE + 2   ; Increment (7-4), Address (3-0 [19-16])      20-bit internal address
VERA_DATA_0   = VERA_BASE + 3   ; Data port 0
VERA_DATA_1   = VERA_BASE + 4   ; Data port 1
VERA_CTRL     = VERA_BASE + 5   ; RESET (7), ADDRSEL (0)
VERA_IEN      = VERA_BASE + 6   ; UART (3), SPRCOL (2), LINE (1), VSYNC (0)   Interupt sources
VERA_ISR      = VERA_BASE + 7   ; UART (3), SPRCOL (2), LINE (1), VSYNC (0)   Interupt status

ADDR_INC_0     =  $000000
ADDR_INC_1     =  $100000
ADDR_INC_2     =  $200000
ADDR_INC_4     =  $300000
ADDR_INC_8     =  $400000
ADDR_INC_16    =  $500000
ADDR_INC_32    =  $600000
ADDR_INC_64    =  $700000
ADDR_INC_128   =  $800000
ADDR_INC_256   =  $900000
ADDR_INC_512   = $1000000
ADDR_INC_1024  = $1100000
ADDR_INC_2048  = $1200000
ADDR_INC_4096  = $1300000
ADDR_INC_8192  = $1400000
ADDR_INC_16384 = $1500000


; ---------------------------
; VERA Internal address space
; ---------------------------

VREG_VIDEO_RAM    = $00000
VREG_DC           = $f0000
VREG_PALETTE      = $f1000
VREG_LAYER_0      = $f2000
VREG_LAYER_1      = $f3000
VREG_SPRITE_REGS  = $f4000
VREG_SPRITE_ATTR  = $f5000
VREG_AUDIO        = $f6000
VREG_SPI          = $f7000
VREG_UART         = $f8000

; Display composer
                                    
VREG_DC_VIDEO       = VREG_DC       ; CURRENT_FIELD (7), CHROMA_DISABLE (2), OUT_MODE (1-0)
VREG_DC_HSCALE      = VREG_DC + 1   ; HSCALE
VREG_DC_VSCALE      = VREG_DC + 2   ; VSCALE
VREG_DC_BORDER_CLR  = VREG_DC + 3   ; BORDER_COLOR
VREG_DC_HSTART_L    = VREG_DC + 4   ; HSTART ([7-0])
VREG_DC_HSTOP_L     = VREG_DC + 5   ; HSTOP ([7-0])
VREG_DC_VSTART_L    = VREG_DC + 6   ; VSTART ([7-0])
VREG_DC_VSTOP_L     = VREG_DC + 7   ; VSTOP ([7-0])
VREG_DC_STARTSTOP_H = VREG_DC + 8   ; VSTOP(5 [8]), VSTART(4 [8]), HSTOP (3-2 [9-8]), HSTART (1-0 [9-8])
VREG_DC_IRQ_LINE_L  = VREG_DC + 9   ; IRQ_LINE ([7-0])
VREG_DC_IRQ_LINE_H  = VREG_DC + 10  ; IRQ_LINE (0 [8])

OUT_MODE_DISABLED = 0
OUT_MODE_VGA      = 1
OUT_MODE_NTSC     = 2
OUT_MODE_RGB      = 3

DC_SCALE_X2 =  64
DC_SCALE_X1 = 128

; Default palette

CLR_C64_BLACK    =  0 
CLR_C64_WHITE    =  1 
CLR_C64_RED      =  2
CLR_C64_CYAN     =  3
CLR_C64_PURPLE   =  4
CLR_C64_VIOLET   =  4 ; Alias
CLR_C64_GREEN    =  5
CLR_C64_BLUE     =  6
CLR_C64_YELLOW   =  7
CLR_C64_ORANGE   =  8
CLR_C64_BROWN    =  9
CLR_C64_LT_RED   = 10
CLR_C64_PINK     = 10 ; Alias
CLR_C64_DK_GRAY  = 11
CLR_C64_GRAY     = 12
CLR_C64_MED_GRAY = 12 ; Alias
CLR_C64_LT_GREEN = 13
CLR_C64_LT_BLUE  = 14
CLR_C64_LT_GRAY  = 15

CLR_GRAY_0       = 16
CLR_GRAY_1       = 17
CLR_GRAY_2       = 18
CLR_GRAY_3       = 19
CLR_GRAY_4       = 20
CLR_GRAY_5       = 21
CLR_GRAY_6       = 22
CLR_GRAY_7       = 23
CLR_GRAY_8       = 24
CLR_GRAY_9       = 25
CLR_GRAY_10      = 26
CLR_GRAY_11      = 27
CLR_GRAY_12      = 28
CLR_GRAY_13      = 29
CLR_GRAY_14      = 30
CLR_GRAY_15      = 31

; Layer 0 registers

VREG_LAYER_0_CTRL0       = VREG_LAYER_0       ; MODE (7-5), EN (0)
VREG_LAYER_0_CTRL1       = VREG_LAYER_0 + 1   ; TILEH (5), TILEW (4), MAPH (3-2 [1-0]), MAPW ([1-0])
VREG_LAYER_0_MAP_BASE_L  = VREG_LAYER_0 + 2   ; MAP_BASE ([9-2])
VREG_LAYER_0_MAP_BASE_H  = VREG_LAYER_0 + 3   ; MAP_BASE ([17-10])
VREG_LAYER_0_TILE_BASE_L = VREG_LAYER_0 + 4   ; TILE_BASE ([9-2])
VREG_LAYER_0_TILE_BASE_H = VREG_LAYER_0 + 5   ; TILE_BASE ([17-10])
VREG_LAYER_0_TEXT_BASE_L = VREG_LAYER_0 + 4   ; TEXT_BASE ([9-2])   * Alias
VREG_LAYER_0_TEXT_BASE_H = VREG_LAYER_0 + 5   ; TEXT_BASE ([17-10]) * Alias
VREG_LAYER_0_BMAP_BASE_L = VREG_LAYER_0 + 4   ; BMAP_BASE ([9-2])   * Alias
VREG_LAYER_0_BMAP_BASE_H = VREG_LAYER_0 + 5   ; BMAP_BASE ([17-10]) * Alias
VREG_LAYER_0_HSCROLL_L   = VREG_LAYER_0 + 6   ; HSCROLL ([7-0])
VREG_LAYER_0_HSCROLL_H   = VREG_LAYER_0 + 7   ; HSCROLL ([11-8])
VREG_LAYER_0_VSCROLL_L   = VREG_LAYER_0 + 8   ; VSCROLL ([7-0])
VREG_LAYER_0_VSCROLL_H   = VREG_LAYER_0 + 9   ; VSCROLL ([11-8])
                                            
VREG_LAYER_0_BM_PAL_OFFS = VREG_LAYER_0 + 7   ; BM_PALETTE_OFFSET (3-0)         Bitmap modes (5, 6, 7)

; Layer 1 registers

VREG_LAYER_1_CTRL0       = VREG_LAYER_1       ; MODE (7-5), EN (0)
VREG_LAYER_1_CTRL1       = VREG_LAYER_1 + 1   ; TILEH (5), TILEW (4), MAPH (3-2 [1-0]), MAPW ([1-0])
VREG_LAYER_1_MAP_BASE_L  = VREG_LAYER_1 + 2   ; MAP_BASE ([9-2])
VREG_LAYER_1_MAP_BASE_H  = VREG_LAYER_1 + 3   ; MAP_BASE ([17-10])
VREG_LAYER_1_TILE_BASE_L = VREG_LAYER_1 + 4   ; TILE_BASE ([9-2])
VREG_LAYER_1_TILE_BASE_H = VREG_LAYER_1 + 5   ; TILE_BASE ([17-10])
VREG_LAYER_1_TEXT_BASE_L = VREG_LAYER_1 + 4   ; TEXT_BASE ([9-2])   * Alias
VREG_LAYER_1_TEXT_BASE_H = VREG_LAYER_1 + 5   ; TEXT_BASE ([17-10]) * Alias
VREG_LAYER_1_BMAP_BASE_L = VREG_LAYER_1 + 4   ; BMAP_BASE ([9-2])   * Alias
VREG_LAYER_1_BMAP_BASE_H = VREG_LAYER_1 + 5   ; BMAP_BASE ([17-10]) * Alias
VREG_LAYER_1_HSCROLL_L   = VREG_LAYER_1 + 6   ; HSCROLL ([7-0])
VREG_LAYER_1_HSCROLL_H   = VREG_LAYER_1 + 7   ; HSCROLL ([11-8])
VREG_LAYER_1_VSCROLL_L   = VREG_LAYER_1 + 8   ; VSCROLL ([7-0])
VREG_LAYER_1_VSCROLL_H   = VREG_LAYER_1 + 9   ; VSCROLL ([11-8])
                                            
VREG_LAYER_1_BM_PAL_OFFS = VREG_LAYER_1 + 7   ; BM_PALETTE_OFFSET (3-0)         Bitmap modes (5, 6, 7)

; Display modes

MODE_0_TEXT_4 = 0
MODE_1_TEXT_8 = 1
MODE_2_TILE_2 = 2
MODE_3_TILE_4 = 3
MODE_4_TILE_8 = 4
MODE_5_BMAP_2 = 5
MODE_6_BMAP_4 = 6
MODE_7_BMAP_8 = 7

DISABLE = 0
ENABLE  = 1

TILE_SIZE_8  = 0
TILE_SIZE_16 = 1

MAP_SIZE_32  = 0
MAP_SIZE_64  = 1
MAP_SIZE_128 = 2
MAP_SIZE_256 = 3

; Sprite registers

VREG_SPRITE_REG_CTRL      = VREG_SPRITE_REGS     ; EN (0)
VREG_SPRITE_REG_COLLISION = VREG_SPRITE_REGS + 1 ; Collision mask (2-0)

SPRITE_MODE_4 = 0
SPRITE_MODE_8 = 1

SPRITE_Z_DISABLED = 0
SPRITE_Z_BACK     = 1
SPRITE_Z_MIDDLE   = 2
SPRITE_Z_FRONT    = 3

SPRITE_SIZE_8  = 0
SPRITE_SIZE_16 = 1
SPRITE_SIZE_32 = 2
SPRITE_SIZE_64 = 3

; SPI registers

VREG_SPI_DATA = VREG_SPI;
VREG_SPI_CTRL = VREG_SPI + 1;

; UART registers

VREG_UART_DATA      = VREG_UART;
VREG_UART_STATUS    = VREG_UART + 1;
VREG_UART_BAUDDIV_L = VREG_UART + 2;
VREG_UART_BAUDDIV_H = VREG_UART + 3;


; ---------------------------
; Macros
; ---------------------------

; Set 20-bit VERA_ADDR, preserving Increment register
!macro vSet .addr {
  lda #<(.addr >> 16) | $10
  sta VERA_ADDR_HI
  lda #<(.addr >> 8)
  sta VERA_ADDR_MID
  lda #<(.addr)
  sta VERA_ADDR_LO
}

; Write A to 20-bit VERA internal address
!macro vWrite .addr {
  pha ;
  +vSet .addr
  pla ;
  sta VERA_DATA_0 ;
}

; Read value at 20-bit VERA internal address to A
!macro vRead .addr {
  +vSet .addr
  lda VERA_DATA_0
}

; Set sprite data
!macro spriteSet .offset {
  lda #<(VREG_SPRITE_ATTR >> 16) | $10
  sta VERA_ADDR_HI
  txa
  lsr
  lsr
  lsr
  lsr
  lsr
  clc
  adc #<(VREG_SPRITE_ATTR + .offset >> 8)
  sta VERA_ADDR_MID
  txa
  asl
  asl
  asl
  clc
  adc #<((VREG_SPRITE_ATTR + .offset))
  sta VERA_ADDR_LO
}

!macro spriteLoad .offset {
  +spriteSet .offset
  lda VERA_DATA_0
}

!macro spriteStore .offset {
  pha
  +spriteSet .offset
  pla
  sta VERA_DATA_0
}

; Initialize external registers and set output to VGA
!macro vgaInit {
  lda #0
  
  ; set ADDRSEL to 0
  sta VERA_CTRL
  
  ; set VERA_ADDR (HI, MID, and LO) to 0
  sta VERA_ADDR_LO
  sta VERA_ADDR_MID
  ; And set Increment (high nibble) to 1
  lda #%00011111
  sta VERA_ADDR_HI
  
  ; Set output to VGA
  lda #OUT_MODE_VGA
  sta VERA_DATA_0
}
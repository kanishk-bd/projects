# include "dcextra.h"
uint8_t FRAME_BUFFER[SIZE] = {0};


void dc_set_pix(int x, int y, bool state){
int pos = (((y-1)*x)+WIDTH) >> 3;
if (state) {
 FRAME_BUFFER[pos] |= ((0x80) >> (x & 0x7)); 
}
else {
FRAME_BUFFER[pos] &= ~((0x80) >> (x & 0x7));
}
}
bool dc_get_pix(int x, int y ){
    int pos = (((y-1)*x)+WIDTH) >> 3;
    return FRAME_BUFFER[pos] & ((0x80) >> (x & 0x7));
}

void dc_draw_bitmap(int x, int y, int width , int height  ,const uint8_t * bitmap){

uint8_t chkMsk = 0; 
int size = (width * height) >> 3;
int orignalX = x ; 
int orignalY = y ; 
for(int i =0 ; i < size ; i++ ){
     for(int j = 0; j < 8; j++){
        chkMsk = 0x80 >> j ; 
        dc_set_pix(x, y , bitmap[i] & chkMsk );
        x++;
        
        if((x-orignalX)== width){
            y++; 
            x= orignalX;

        }
        if((y-orignalY)== height){

            return; 
        }
    }

}






}
# include "DisplayCraft.c"
# include "image_bit_map.c"
# include <stdio.h>
int main(){
dc_draw_bitmap(50 , 0 , IMAGE_WIDTH, IMAGE_HEIGHT, image_bit_map);
for(int y = 0 ; y< HIGHT ; y++ ){
    for(int x = 0 ; x < WIDTH; x++){
            if(dc_get_pix(x, y)){
                printf("1");
            }
            else{
                printf("0");
            }
            printf("\n");

    }

}



}
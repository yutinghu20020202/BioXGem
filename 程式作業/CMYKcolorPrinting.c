#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};//2^32所以下面是32個bit

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE])
{
    for(int i=0; i<H; i++){//存到image裡
        for(int j=0; j<W; j++){
            image[i][j] = (image[i][j] & 0X00FFFFFF) | (mask[i][j]<<24);//有東西的地方要蜻蛉（記得喔不然會被當掉）
        }
    }
    
}

void print_M(unsigned int mask[][MAX_SIZE])
{   
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            image[i][j] = (image[i][j] & 0XFF00FFFF) | (mask[i][j]<<16);
        }
    }

}

void print_Y(unsigned int mask[][MAX_SIZE])
{   
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            image[i][j] = (image[i][j] & 0XFFFF00FF) | (mask[i][j]<<8);;
        }
    }

}

void print_K(unsigned int mask[][MAX_SIZE])
{   
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            image[i][j] = (image[i][j] & 0XFFFFFF00) | (mask[i][j]);
        }
    }
}

void CMYK_to_RGB()
{
    double C, M, Y, K;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            C = (image[i][j] >> 24) & 0XFF ;
            M = (image[i][j] >> 16) & 0XFF ;
            Y = (image[i][j] >> 8) & 0XFF ;
            K = image[i][j] & 0XFF ;

            C = C/ 100.0;
            M = M/ 100.0;
            Y = Y/ 100.0;
            K = K/ 100.0;

            unsigned int R, G, B;
            R = lround(255*(1-C)*(1-K));
            G = lround(255*(1-M)*(1-K));
            B = lround(255*(1-Y)*(1-K));
            image[i][j] = R << 16 | G << 8 | B;
        }
    }


}
int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
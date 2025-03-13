#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// this will throw an error if you don't have the bitmap library installed
// so be sure to do that before uncommenting this #include line
#include "bitmap_image.hpp"

int main(int argc, char *argv[]) {
    // get a string containing the image name
    // this is necessary because the bitmap_image
    // class expects a string as an argument
    std::string file_name(argv[1]);
    std::string outputname(argv[2]);
    bitmap_image inImage(file_name);
    inImage.convert_to_grayscale();

    // TODO:
    // your implementation of problem #4 should be done in this
    // file. Feel free to create functions etc. if you feel that
    // it will help you.
    int sum =0;
    for(unsigned int i =0; i < inImage.width(); i++){
        for(unsigned int j=0; j<inImage.height(); j++){
            int temp =0;
            temp= (inImage.red_channel(i,j));
            sum = sum + temp;
        }
    }
    // make the avergae 
    int average = 0;
    average = sum /inImage.pixel_count();
    // do the double nested loop for this one then compare it to the rules of if you change it black or white
    // maybe ask about how to add it ti the new image 
    for(unsigned int x=0; x< inImage.width(); x++){
        for(unsigned int y=0; y< inImage.height(); y++){
            int temp2 =0;
            temp2 = (inImage.red_channel(x,y));
            if(temp2 < average){
                // change to black
                inImage.set_pixel(x,y,0,0,0);
            }
            else{
                //change to white
                inImage.set_pixel(x,y,255,255,255);
            }
        }
    }
    // is this how you save it 
    inImage.save_image(outputname);
    // how do i save the image
    // then return that image

    return 0;
}